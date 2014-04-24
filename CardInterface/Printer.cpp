// Printer.cpp: implementation of the CPrinter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Printer.h"
#include <winspool.h>
#include <time.h>
#include "Global.h"
#include "commdlg.h"
#include "../include/MagAPI.h"
#include "../include/API_Test.h"

#define	MAX_STR		1028



//////////////////////////////////////////////////////////////////////
// Constructor/Destructor
//////////////////////////////////////////////////////////////////////

CPrinter::CPrinter()
{
}

CPrinter::~CPrinter()
{	
}

string CPrinter::GetErrorMessage()
{
	return lastErrorMessage;
}

void CPrinter::GetPrinterMessage(HANDLE session)
{
	char message[1024];
	memset(message,0x00,sizeof(message));
	DWORD len;
	GetLastPrinterMessage(session,message,&len);
	lastErrorMessage.clear();
	lastErrorMessage.append(message);
}

bool CPrinter::WriteTrack(int trackNo, string &trackInfo)
{
	bool bStatus = true;
	return (bStatus);
}

bool CPrinter::ReadTrack(int trackNo, string &trackInfo)
{
	return false;
}

bool CPrinter::ReadAllTrack(char *trackInfo1, char *trackInfo2, char *trackInfo3)
{
	bool bStatus = false;

	HDC hdc = CreateDC( "WINSPOOL", this->PrinterName, NULL, NULL);
	HANDLE session;
	int result = 0;

	result = EnableStatusReporting(hdc, &session, CONFIG_QUIET);
	if (result != ERROR_SUCCESS)
    {
		goto exit;
    }

	MSVDATA data;
	result = ReadMagStripe(session,&data,EMS_ENCODING_SPEC_ISO);

	if (result != ERROR_SUCCESS)
	{
		goto exit;
	}

	unsigned int len = 0;
	len = (unsigned int)data.tk2_len;
	if(data.tk1_pass && data.tk1_len>0)
	{
		int len1 = HIBYTE(HIWORD(data.tk1_len));
		for(int i=0;i<len1-1;i++)   
		{   
			trackInfo1[i] = ( data.raw.tk1[i] & 0x3F ) + 0x20;   
		}
	}
	if(data.tk2_pass && data.tk2_len>0)
	{
		int len2 = HIBYTE(HIWORD(data.tk2_len));
		for(int i=0;i<len2-1;i++)   
		{   
			trackInfo2[i] = ( data.raw.tk2[i] & 0x0F ) + 0x30;   
		}
	}
	if(data.tk3_pass && data.tk3_len>0)
	{
		int len3 = HIBYTE(HIWORD(data.tk3_len));
		for(int i=0;i<len3-1;i++)   
		{   
			trackInfo3[i] = ( data.raw.tk3[i] & 0x0F ) + 0x30;   
		} 
	}
	bStatus = true;

exit:
	GetPrinterMessage(session);
	DisableStatusReporting(session);

	return (bStatus);
}

char * CPrinter::GetDriverName()
{
	return(DriverName);
}

void CPrinter::SetDriverName(char * newDriverName)
{
	strcpy(DriverName,newDriverName);
}

char * CPrinter::GetPrinterName()
{
	return(PrinterName);
}

void CPrinter::SetPrinterName(char * newPrinterName)
{
	strcpy(PrinterName,newPrinterName);
}

HFONT CPrinter::GetFont(HDC hdc,int height)
{ 
    HFONT hfont;
	//int lfHeight = -MulDiv(6, GetDeviceCaps(hdc, LOGPIXELSY), 72);
	//int lfHeight = 32;
	hfont = CreateFont(height,0,0,0,FW_BOLD,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("RedCard"));
    return hfont;
}

bool CPrinter::Print(char* expiredDate, int parValue, char * password, int permission,bool back)
{
	int printedItem = 0;
	return Print(expiredDate,parValue,password,"","",permission,back,printedItem);
}

bool CPrinter::Print(char* expiredDate, int parValue, char * password, char* name, char* level,int permission,bool back, int & printedItem)
{
	bool bStatus = false;
	int cxsize = 0, cxpage = 0;
	int cysize = 0, cypage = 0;
	int bxWidth, bxHeight, flag=0;
	RECT rect;
	HBITMAP hBitmap;
	BITMAP bitmap;
	ZeroMemory(&hBitmap, sizeof(HBITMAP));
	char szFileName[500]= "icon.bmp";
	hBitmap = (HBITMAP)LoadImage(NULL,szFileName,IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION|LR_DEFAULTSIZE|LR_LOADFROMFILE|LR_VGACOLOR);

	HDC hdc = CreateDC( "WINSPOOL", this->PrinterName, NULL, NULL);
	if(hBitmap)
	{
		cxpage = GetDeviceCaps (hdc, HORZRES);
		cypage = GetDeviceCaps (hdc, VERTRES);
		GetObject(hBitmap,sizeof(BITMAP),&bitmap);
		bxWidth = bitmap.bmWidth;
		bxHeight = bitmap.bmHeight;
		rect.left = 0;
		rect.top =0;
		rect.right = (long)&cxpage;
		rect.bottom = (long)&cypage;
	}
	cxpage = GetDeviceCaps (hdc, HORZRES);
	cypage = GetDeviceCaps (hdc, VERTRES);
	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, hBitmap);

	HANDLE session;
	int result = 0;

	result = EnableStatusReporting(hdc, &session, CONFIG_QUIET);
	if (result != ERROR_SUCCESS)
    {
		//TODO Can't enable status report
		goto exit;
    }
	

	DOCINFO di;
    di.cbSize      = sizeof(DOCINFO);
	char jobName[256];
	memset(jobName,0,sizeof(jobName));
	sprintf(jobName,"Print Card-%d",time(0));
	di.lpszDocName = jobName;
    di.lpszOutput  = NULL;

	result = StartDoc(hdc, &di);
	if(result<=0)
	{
		//TODO can't start a print job
		goto exit;
	}

	if(!back)
	{
		StartPage(hdc);
		EndPage(hdc);
	}
	
	StartPage(hdc);
	
	HFONT hfont = GetFont(hdc,24);
	HFONT oldFont = (HFONT)SelectObject(hdc, hfont);
	
	if((permission & PRINT_EXPIRED_DATE) == PRINT_EXPIRED_DATE)
	{
		char text[256];
		memset(text,0x00,sizeof(text));
		sprintf(text,"本卡有效期截止日：%s",expiredDate);
		TextOut(hdc, 60, 550, text, lstrlen(text));
		printedItem = printedItem + 1;
	}
	if((permission & PRINT_PAR_VALUE) == PRINT_PAR_VALUE)
	{
		char text[128];
		memset(text,0x00,sizeof(text));
		sprintf(text,"面值：%d",parValue);
		TextOut(hdc, 500, 550, text, lstrlen(text));
		printedItem = printedItem + 2;
	}
	if((permission & PRINT_NAME) == PRINT_NAME)
	{
		hfont = GetFont(hdc,32);
		SelectObject(hdc, hfont);
		TextOut(hdc, 750, 250, name, lstrlen(name));
		printedItem = printedItem + 16;
	}
	if((permission & PRINT_LEVEL) == PRINT_LEVEL)
	{
		hfont = GetFont(hdc,32);
		SelectObject(hdc, hfont);
		TextOut(hdc, 515, 315, level, lstrlen(level));
		printedItem = printedItem + 32;
	}
	if((permission & PRINT_PASSWORD) == PRINT_PASSWORD && ((permission & PRINT_NAME) == PRINT_NAME || (permission & PRINT_LEVEL) == PRINT_LEVEL))
	{
		hfont = GetFont(hdc,40);
		SelectObject(hdc, hfont);
		TextOut(hdc, 60, 530, "密码:", lstrlen("密码:"));
		TextOut(hdc, 165, 530, password, lstrlen(password));
		printedItem = printedItem + 4;		
	} else if((permission & PRINT_PASSWORD) == PRINT_PASSWORD)
	{
		hfont = GetFont(hdc,48);
		SelectObject(hdc, hfont);
		TextOut(hdc, 796, 263, password, lstrlen(password));
		printedItem = printedItem + 4;
	}
	if((permission & PRINT_RANDOM) == PRINT_RANDOM)
	{
		SetMapMode(hdc, MM_ISOTROPIC);
		SetWindowExtEx(hdc, cxpage,cypage, NULL);
		SetViewportExtEx(hdc, cxpage, cypage,NULL);

		SetViewportOrgEx(hdc, 0, 0, NULL);
		StretchBlt(hdc, 730, 240, 240, 120, hdcMem, 0, 0,bxWidth,bxHeight, SRCCOPY);
		printedItem = printedItem + 8;
	}

	EndPage(hdc);
	EndDoc(hdc);

	do
	{
		result = WaitForPrinter(session);
	} while (MAGICARD_TIMEOUT == result);

	DeleteObject(hfont);
	SelectObject(hdc, oldFont);
	
	SelectObject(hdcMem, hbmOld);
	DeleteDC(hdcMem);

	if (result == MAGICARD_PRINTER_ERROR)
	{
		//TODO get error
		goto exit;
	}
	bStatus = true;

exit:
	DisableStatusReporting(session);
	DeleteDC(hdc);

	return (bStatus);
}

bool CPrinter::PrintPassword(char* password)
{
	bool bStatus = true;

	HDC hdc = CreateDC( "WINSPOOL", this->PrinterName, NULL, NULL);
	HANDLE session;
	int result = 0;

	result = EnableStatusReporting(hdc, &session, CONFIG_QUIET);
	if (result != ERROR_SUCCESS)
    {
		goto exit;
    }

	DOCINFO di;
    di.cbSize      = sizeof(DOCINFO);
	char jobName[256];
	memset(jobName,0,sizeof(jobName));
	sprintf(jobName,"Print Card-%d",time(0));
	di.lpszDocName = jobName;
    di.lpszOutput  = NULL;

	result = StartDoc(hdc, &di);
	if(result<=0)
	{
		goto exit;
	}
	
	StartPage(hdc);
	HFONT hfont = GetFont(hdc,48);
	HFONT oldFont = (HFONT)SelectObject(hdc, hfont);

	TextOut(hdc, 796, 263, password, lstrlen(password));

	EndPage(hdc);
	EndDoc(hdc);

	do
	{
		result = WaitForPrinter(session);
	} while (MAGICARD_TIMEOUT == result);

	DeleteObject(hfont);
	SelectObject(hdc, oldFont);

	if (result == MAGICARD_PRINTER_ERROR)
	{
		goto exit;
	}

exit:
	GetPrinterMessage(session);
	DisableStatusReporting(session);
	DeleteDC(hdc);

	return (bStatus);
}

bool CPrinter::EjectCardApp()
{
	bool bStatus = true;
	HDC hdc = CreateDC( "WINSPOOL", this->PrinterName, NULL, NULL);
	HANDLE session;
	int result = 0;

	result = EnableStatusReporting(hdc, &session, CONFIG_QUIET);
	if (result != ERROR_SUCCESS)
    {
		goto exit;
    }

	result = EjectCard(session,"EjectCard");
	do 
	{ 
		result = WaitForPrinter(session); 
	} while(MAGICARD_TIMEOUT == result);

	if(result == MAGICARD_PRINTER_ERROR) 
	{ 
		goto exit;
	} 

	exit:
	GetPrinterMessage(session);
	DisableStatusReporting(session);
	DeleteDC(hdc);

	return (bStatus);
}

void CPrinter::GetRandom(char* random, int size)
{
	srand(time(NULL));
     for(int i=0;i<size;i++)
	 {	 
		sprintf(random+i,"%d",random(10));
	 }
}