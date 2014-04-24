#pragma once

#ifndef __API_H__
#define __API_H__

#ifdef __cplusplus
extern "C" {
#endif

#define MAGICARD_TIMEOUT                       -1
#define MAGICARD_ERROR                         -2
#define MAGICARD_PRINTER_ERROR                 -3
#define MAGICARD_DRIVER_NOTCOMPLIANT           -4
#define MAGICARD_OPENPRINTER_ERROR             -5
#define MAGICARD_REMOTECOMM_ERROR              -6
#define MAGICARD_LOCALCOMM_ERROR               -7
#define MAGICARD_SPOOLER_NOT_EMPTY             -8
#define MAGICARD_REMOTECOMM_IN_USE             -9
#define MAGICARD_LOCALCOMM_IN_USE              -10

#define FEED_CHIPCARD             1
#define FEED_CONTACTLESS          2

#define CONFIG_QUIET              1       // Do not show dialog boxes for fatal errors

#define CARD_MOVEMENT		0
#define SINGLE_PRINT		1
#define DOUBLE_PRINT		2

//#############################################################################

#define PFNESR PFNENABLESTATUSREPORTING
PFNESR pFnEnableStatusReporting;

#define PFNDSR PFNDISABLESTATUSREPORTING
PFNDSR pFnDisableStatusReporting;

#define PFNWFP PFNWAITFORPRINTER
PFNWFP pFnWaitForPrinter;

#define PFNWFPF PFNWAITFORPRINTERFIXED
PFNWFPF pFnWaitForPrinterFixed;

#define PFNWFPV PFNWAITFORPRINTERVAR
PFNWFPV pFnWaitForPrinterVar;

#define PFNGPM PFNGETLASTPRINTERMESSAGE
PFNGPM pFnGetLastPrinterMessage;

#define PFNFCA PFNFEEDCARDA
#define PFNFCW PFNFEEDCARDA
PFNFCA pFnFeedCardA;
PFNFCW pFnFeedCardW;

#define PFNECA PFNEJECTCARDA
#define PFNECW PFNEJECTCARDW
PFNECA pFnEjectCardA;
PFNECW pFnEjectCardW;

#if defined(_UNICODE) || defined(UNICODE)
    #define FEEDCARDPROC  "FeedCardW"
    #define EJECTCARDPROC "EjectCardW"
	#define pFnFeedCard   pFnFeedCardW
	#define pFnEjectCard  pFnEjectCardW
#else
    #define FEEDCARDPROC  "FeedCardA"
    #define EJECTCARDPROC "EjectCardA"
    #define pFnFeedCard   pFnFeedCardA
	#define pFnEjectCard  pFnEjectCardA
#endif


#ifdef __cplusplus
}
#endif

#endif // __API_H__
