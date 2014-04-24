/***************************************************************************/
/**                                                                       **/
/**                    ULTRA ELECTRONICS CARD SYSTEMS                     **/
/**                                                                       **/
/***************************************************************************/
/**                                                                       **/
/**  PROJECT      : SWI DRIVER MAGAPI                                     **/
/**                                                                       **/
/**  MODULE NAME  : MagAPI.h                                              **/
/**                                                                       **/
/**  SIN No.      : 2118                                                  **/
/**                                                                       **/
/**  COPYRIGHT    : Ultra Electronics Card Systems                        **/
/**                                                                       **/
/***************************************************************************/

#ifndef __MAGAPI_H__
#define __MAGAPI_H__

#if _MSC_VER > 1000
  #pragma once
#endif

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#ifdef _COMPILING_MAGAPI
  #define LIBSPEC __declspec(dllexport)
#else
  #define LIBSPEC __declspec(dllimport)
#endif // _COMPILING_MAGAPI

//API Error Codes - return codes indicating an error
#define MAGICARD_TIMEOUT                -1  // Timed out waiting for a response from the printer
#define MAGICARD_ERROR                  -2  // Win32 API error or a parameter is invalid
#define MAGICARD_PRINTER_ERROR          -3  // The printer has reported an error
#define MAGICARD_DRIVER_NOTCOMPLIANT    -4  // The Printer driver is not compliant with the API DLL
#define MAGICARD_OPENPRINTER_ERROR      -5  // Error opening communication with the printer
#define MAGICARD_REMOTECOMM_ERROR       -6  // Remote communications error
#define MAGICARD_LOCALCOMM_ERROR        -7  // Local communications error
#define MAGICARD_SPOOLER_NOT_EMPTY      -8  // The printer is already busy printing a job
#define MAGICARD_REMOTECOMM_IN_USE      -9  // Remote communications error
#define MAGICARD_LOCALCOMM_IN_USE      -10  // Local communications error

//Card types - used in the FeedCard API functions
//Identifies the type of card being fed into the printer
#define FEED_CHIPCARD       1 
#define FEED_CONTACTLESS    2

//Status monitor configuration - Used as a parameter to EnableStatusReporting
#define CONFIG_QUIET 1 // Do not show dialog boxes for fatal errors

/******************************************************************************
 * Structures used in the acquisition of Magnetic stripe data from the printer
 ******************************************************************************/

typedef struct
{
  char tk1[172]; // ISO max is 79  (7bpc, 210bpi)
  char tk2[172]; // ISO max is 40  (5bpc, 75bpi)
  char tk3[172]; // ISO max is 107 (5bpc, 210bpi)
} RAW_DATA;

// For returning to the host
typedef struct
{
  DWORD    msv_id;    // Unique ID to distinguish this message (we may add others)
  DWORD    msg_len;   // size of message, including this (for var length; see above)
  DWORD    tk1_pass;  // TRUE if this track passed; FALSE if failed or not tested
  DWORD    tk2_pass;
  DWORD    tk3_pass;
  DWORD    tk1_len;   // Number of bytes returned for this track
  DWORD    tk2_len;   //   from start sentinel to LRC inclusive
  DWORD    tk3_len;
  RAW_DATA raw;       // Raw data for each track which has been verified
} MSVDATA;
typedef MSVDATA* PMSVDATA;

#define SERIAL_SIZE		20
typedef struct tag_ENDURO_STATUS
{
	BOOL  bPrinterConnected;
	DWORD eModel;
	char  sModel[30];
	DWORD ePrintheadType;
	char  sPrinterSerial[SERIAL_SIZE];
	char  sPrintheadSerial[SERIAL_SIZE];
	char  sPCBSerial[SERIAL_SIZE];
	TCHAR sFirmwareVersion[SERIAL_SIZE];
	char  sDummy[SERIAL_SIZE - sizeof(DWORD)];

	DWORD iDensity;
	DWORD iHandFeed;
	DWORD iCardsPrinted;
	DWORD iCardsOnPrinthead;
	DWORD iDyePanelsPrinted;
	DWORD iCleansSinceShipped;
	DWORD iDyePanelsSinceClean;
	DWORD iCardsSinceClean;
	DWORD iCardsBetweenCleans;

	DWORD iPrintHeadPosn;
	DWORD iImageStartPosn;
	DWORD iImageEndPosn;
	DWORD iMajorError;
	DWORD iMinorError;

	char  sTagUID[20];
	DWORD iShotsOnFilm;
	DWORD iShotsUsed;
	char  sDyeFilmType[20];
	DWORD iColourLength;
	DWORD iResinLength;
	DWORD iOvercoatLength;
	DWORD eDyeFlags;
	DWORD iCommandCode;
	DWORD iDOB;
	DWORD eDyeFilmManuf;
	DWORD eDyeFilmProg;
} PRINTER_INFO;
typedef PRINTER_INFO* PPRINTER_INFO;

typedef struct tag_VERSION
{
	DWORD Major;
	DWORD Minor;
	DWORD Build;
	DWORD Private;
} SDK_VERSION;



//======================== Magicard API Functions =============================

/******************************************************************************
 * Initializes the API and its communication channel
 * Returns:
 *   ERROR_SUCCESS - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error or a parameter is invalid,
 *   MAGICARD_DRIVER_NOTCOMPLIANT - The driver does not support the MAGICARD API,
 *   MAGICARD_LOCALCOMM_ERROR - Failed to open client communications,
 *   MAGICARD_REMOTECOMM_ERROR - Failed to open monitor communications,
 *   MAGICARD_OPENPRINTER_ERROR - Failed to open the printer the DC belongs to,
 *   MAGICARD_SPOOLER_NOT_EMPTY - There are print jobs queued for this printer,
 *   MAGICARD_REMOTECOMM_IN_USE - Monitor communication is already active,
 *   MAGICARD_LOCALCOMM_IN_USE - Client communication is already active,
 * The application may also check the result of the Win32 API GetLastError() to try to obtain
 * more information about any error that has occurred
 ******************************************************************************/
LIBSPEC int WINAPI EnableStatusReporting
(
	HDC hDC,			// Device Context handle for the printer driver
	HANDLE* phSession,	// Pointer to a handle that will identify the new Session
	DWORD dwFlags		// Defines how the Status Monitor will behave:
						//   0            - Unchanged,
						//   CONFIG_QUIET - The Status Monitor will abort when a non-recoverable error occurs
);

/******************************************************************************
 * Closes the communications channel with the status monitor, returns the status monitor to its
 * normal behavior and releases all resources used
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error or a parameter is invalid
 ******************************************************************************/
LIBSPEC int WINAPI DisableStatusReporting
(
	HANDLE hSession   // The Handle to the active Session
);

/******************************************************************************
 * Instructs the printer to feed a card to one of the chip encoding positions available 
 * (Provided in both ASCII version and UNICODE versions)
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error or a parameter is invalid
 ******************************************************************************/
LIBSPEC int WINAPI FeedCardA
(
	HANDLE hSession,	// The Handle to the active Session
	DWORD dwMode,		// The card type. Can be FEED_CHIPCARD, or FEED_CONTACTLESS
	int iParam,			// An optional positive integer parameter that is to be appended to the end of the
						// printer command used to feed the card. Can be in the range 0-99
	LPSTR lpszJobName	// The name of the secondary print job
);

LIBSPEC int WINAPI FeedCardW
(
	HANDLE hSession,	// The Handle to the active Session
	DWORD dwMode,		// The card type. Can be FEED_CHIPCARD, or FEED_CONTACTLESS
	int iParam,			// An optional positive integer parameter that is to be appended to the end of the
						// printer command used to feed the card. Can be in the range 0-99
	LPWSTR lpwszJobName	// The name of the secondary print job
);

#if defined(_UNICODE) || defined(UNICODE)
    #define FeedCard FeedCardW
#else
    #define FeedCard FeedCardA
#endif

/******************************************************************************
 * Instructs the printer to eject any card that may be present in the mechanism (ASCII version)
 * (Provided in both ASCII version and UNICODE versions)
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error or a parameter is invalid
 ******************************************************************************/
LIBSPEC int WINAPI EjectCardA
(
	HANDLE hSession,	// The Handle to the active Session
	LPSTR lpszJobName	// The name of the secondary print job
);

LIBSPEC int WINAPI EjectCardW
(
	HANDLE hSession,	// The Handle to the active Session
	LPWSTR lpwszJobName	// The name of the secondary print job
);

#if defined(_UNICODE) || defined(UNICODE)
    #define EjectCard EjectCardW
#else
    #define EjectCard EjectCardA
#endif

/******************************************************************************
 * Waits until the printer reports that itis no longer busy or until a time-out
 * period elapses.
 * This function should be expected to time out during lengthy operations. It is
 * up to the application to determine how long it is going to wait, by repeating 
 * calls to this function, before deciding that the printer is not responding.
 * The timeout granularity can not be changed. It is currently set to 30 seconds.
 * If a printer error is reported, the application may call the GetLastPrinterMessage()
 * function to retrieve the error message sent by the printer.
 * Returns:
 *   ERROR_SUCCESS          - The operation completed successfully,
 *   MAGICARD_ERROR         - Win32 API error or a parameter is invalid
 *   MAGICARD_TIMEOUT       - A 30-second period has elapsed without receiving any 
 *                            status information from the printer
 *   MAGICARD_PRINTER_ERROR - The printer has aborted the operation, due to an error
 ******************************************************************************/
LIBSPEC int WINAPI WaitForPrinter
(
	HANDLE hSession		//< The Handle to the active Session
);

/******************************************************************************
 * Retrieves a string containing the last status message sent by the printer.
 * The error code is embedded in the string returned,at the end.
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error, the message buffer is too small or a parameter is invalid
 ******************************************************************************/
LIBSPEC int WINAPI GetLastPrinterMessage
(
	HANDLE hSession,		// The Handle to the active Session
	LPSTR lpszBuffer,		// Pointer to the buffer that will be filled with the status message
	LPDWORD pdwBufferSize	// Pointer to a variable containing the buffer size
);

/******************************************************************************
 * Retrieves a string containing the last status message sent by the Enduro printer.
 * The error code is embedded in the string returned, at the end.
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error, the message buffer is too small or a parameter is invalid
 ******************************************************************************/
LIBSPEC int WINAPI GetLastEnduroMessage
(
	HANDLE hSession,		// The Handle to the active Session
	LPTSTR lptchBuffer,		// Pointer to the buffer that will be filled with the status message
	LPDWORD pdwBufferSize	// Pointer to a variable containing the buffer size
);

/******************************************************************************
 * Instructs the printer to read the magnetic stripe data from the card into memory
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error or a parameter is invalid
 ******************************************************************************/
LIBSPEC int WINAPI RequestMagData
(
	HANDLE hSession		// The Handle to the active Session
);


/******************************************************************************
 * Reads the magnetic stripe data (previously read from the card using the RequestMagData
 * API call
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error or a parameter is invalid
 ******************************************************************************/
LIBSPEC int WINAPI ReadMagData
(
	HANDLE hSession,	// The Handle to the active Session
	PMSVDATA pMSV		// Pointer to the buffer that will be filled with the mag data
);

/******************************************************************************
 * Send the command string to the printer
 * Returns:
 *   ERROR_SUCCESS          - The operation completed successfully,
 *   MAGICARD_ERROR         - Win32 API error or a parameter is invalid
 ******************************************************************************/
LIBSPEC int WINAPI GeneralCommand
(
	HANDLE hSession,		// The Handle to the active Session
	LPSTR  CommandString	// The CommandString to be sent to the printer
);

/******************************************************************************
 * Writes the given magnetic stripe data to the card
 *
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error or a parameter is invalid
 ******************************************************************************/
enum {EMS_ENCODING_SPEC_ISO,
	  EMS_ENCODING_SPEC_JIS2
};
enum {EMS_VERIFY_OFF,
	  EMS_VERIFY_ON
};
enum {EMS_COERCIVITY_DEFAULT,
	  EMS_COERCIVITY_HICO,
	  EMS_COERCIVITY_LOCO
};
enum {EMS_BITSPERCHAR_DEFAULT,
	  EMS_BITSPERCHAR_1,
	  EMS_BITSPERCHAR_5,
	  EMS_BITSPERCHAR_7
};
enum {EMS_BITSPERINCH_DEFAULT,
	  EMS_BITSPERINCH_75,
	  EMS_BITSPERINCH_210
};
enum {EMS_PARITY_DEFAULT,
	  EMS_PARITY_OFF,
	  EMS_PARITY_ODD,
	  EMS_PARITY_EVEN
};
enum {EMS_LRC_DEFAULT,
	  EMS_LRC_OFF,
	  EMS_LRC_ODD,
	  EMS_LRC_EVEN
};

LIBSPEC int WINAPI EncodeMagStripe
(
	HANDLE hSession,		// The Handle to the active Session
	int	   iTrackNo,		// The number of the track being encoded
	int	   iCharCount,		// Number of characters in the mag string
	char  *lpszData,		// Pointer to the encoding data 
	int	   iEncodingSpec,	// The following are all defined above
	int    iVerify,
	int	   iCoercivity,
	int	   iBitsPerChar,
	int	   iBitsPerInch,
	int	   iParity,
	int	   iLRC
);

/******************************************************************************
 * Reads the Magnetic Stripe on the card, using the given encoding specification
 *
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error or a parameter is invalid
 ******************************************************************************/
extern "C" LIBSPEC int WINAPI ReadMagStripe
(
	HANDLE   hSession, 
	MSVDATA *pMSV,
	int	     iEncodingSpec
);

/******************************************************************************
 * Sets the eject mode of the printer
 *
 * Returns:
 *   ERROR_SUCCESS  - The operation completed successfully,
 *   MAGICARD_ERROR - Win32 API error or a parameter is invalid
 ******************************************************************************/
enum {SEM_EJECT_ON,
	  SEM_EJECT_OFF
};

LIBSPEC int WINAPI SetEjectMode
(
	HANDLE hSession,		// The Handle to the active Session
	int	   iMode			// 
);

/******************************************************************************
 * Reads the current printer status
 * Returns:
 *   STATUS_READY
 *   STATUS_BUSY
 *   STATUS_ERROR
 ******************************************************************************/
#define STATUS_READY	0
#define STATUS_BUSY		1
#define STATUS_ERROR	2
#define STATUS_OFFLINE	3
LIBSPEC int WINAPI GetPrinterStatus
(
	HANDLE hSession		// The Handle to the active Session
);

/**
 * Reads the current Enduro Info
 */
LIBSPEC int WINAPI GetEnduroInfo
(
	HANDLE		   hSession, 
	PRINTER_INFO  *pPrinterInfo
);

#define ESC_IS_API_CAPABLE 9001		// Custom driver escape to indicate Magicard API support

/******************************************************************************
 * Reports whether Status Reporting is in use
 * Returns:
 *   TRUE if a session is already active
******************************************************************************/
BOOL __inline MAGICARD_Is_Status_Reporting_In_Use(int iError)
{
    return (MAGICARD_REMOTECOMM_IN_USE == iError || MAGICARD_LOCALCOMM_IN_USE == iError);
}

//*****************************************************************************

/******************************************************************************
 * API function pointers
 *
 * Type definitions for API functions for use in Applications
 ******************************************************************************/

typedef int (WINAPI * PFNENABLESTATUSREPORTING)(HDC, HANDLE*, DWORD);
typedef int (WINAPI * PFNDISABLESTATUSREPORTING)(HANDLE);
typedef int (WINAPI * PFNWAITFORPRINTER)(HANDLE);
typedef int (WINAPI * PFNWAITFORPRINTERFIXED)(HANDLE, int);
typedef int (WINAPI * PFNWAITFORPRINTERVAR)(HANDLE, int);
typedef int (WINAPI * PFNGETLASTPRINTERMESSAGE)(HANDLE, LPSTR, LPDWORD);
typedef int (WINAPI * PFNGETLASTENDUROMESSAGE)(HANDLE, LPTSTR, LPDWORD);
typedef int (WINAPI * PFNREQUESTMAGDATA)(HANDLE);
typedef int (WINAPI * PFNREADMAGDATA)(HANDLE, PMSVDATA);
typedef int (WINAPI * PFNGETENDUROINFO)(HANDLE, PPRINTER_INFO);
typedef int (WINAPI * PFNGETPRINTERSTATUS)(HANDLE);
typedef int (WINAPI * PFNGENERALCOMMAND)(HANDLE, LPSTR);
typedef int (WINAPI * PFNENCODEMAGSTRIPE)(HANDLE hSession,
										  int	 iTrackNo,
										  int	 iCharCount,
										  char  *lpszData,
										  int	 iEncodingSpec,
										  int    iVerify,
										  int	 iCoercivity,
										  int	 iBitsPerChar,
										  int	 iBitsPerInch,
										  int	 iParity,
										  int	 iLRC);
typedef int (WINAPI * PFNREADMAGSTRIPE)(HANDLE, PMSVDATA, int);
typedef int (WINAPI * PFNSETEJECTMODE)(HANDLE, int);

typedef int (WINAPI * PFNFEEDCARDA)(HANDLE, DWORD, int, LPSTR);
typedef int (WINAPI * PFNFEEDCARDW)(HANDLE, DWORD, int, LPWSTR);
typedef int (WINAPI * PFNEJECTCARDA)(HANDLE, LPSTR);
typedef int (WINAPI * PFNEJECTCARDW)(HANDLE, LPWSTR);

#if defined(_UNICODE) || defined(UNICODE)
  #define PFNFEEDCARD	PFNFEEDCARDW
  #define PFNEJECTCARD	PFNEJECTCARDW
#else
  #define PFNFEEDCARD	PFNFEEDCARDA
  #define PFNEJECTCARD	PFNEJECTCARDA
#endif
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAGAPI_H__
