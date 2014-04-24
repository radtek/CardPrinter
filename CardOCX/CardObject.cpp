// CardObject.cpp : Implementation of CCardObject


#include "stdafx.h"
#include<comdef.h>
#include <comutil.h>
#include "CardObject.h"
#include "../CardInterface/CardInterface.h"
#include "../CardEngine/include/CardEngine.h"

const char * COMPILED_DATE = __DATE__;

// CCardObject

STDMETHODIMP CCardObject::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_ICardObject
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CCardObject::OCX_Init(LONG* retValue)
{
	*retValue = Card_Init();
	if(*retValue==0)
	{
		*retValue = ENG_Init();
	}
	return S_OK;
}


STDMETHODIMP CCardObject::OCX_About(BSTR* message)
{
    char cMessage[255]; 
    sprintf(cMessage,"Card Interface %s %s","V1.0",COMPILED_DATE);
 	*message = _com_util::ConvertStringToBSTR(cMessage);
	return S_OK;
}


STDMETHODIMP CCardObject::OCX_ReadTrack(SHORT trackNo, BSTR* trackInfo)
{
	char trackInfo1[100], trackInfo2[100],trackInfo3[100];
	memset(trackInfo1,0,sizeof(trackInfo1));
	memset(trackInfo2,0,sizeof(trackInfo2));
	memset(trackInfo3,0,sizeof(trackInfo3));
	
	int ret = Card_ReadAllTrack(trackInfo1,trackInfo2,trackInfo3);
	if(ret==0)
	{
		if(trackNo==1){
			*trackInfo = _com_util::ConvertStringToBSTR(trackInfo1);	
		}else if(trackNo==2){
			*trackInfo = _com_util::ConvertStringToBSTR(trackInfo2);	
		}else if(trackNo==3){
			*trackInfo = _com_util::ConvertStringToBSTR(trackInfo3);	
		}
	}
	return S_OK;
}


STDMETHODIMP CCardObject::OCX_WriteTrack(SHORT trackNo, BSTR* trackInfo, LONG* retValue)
{
	*retValue = Card_WriteTrack(trackNo,_com_util::ConvertBSTRToString(*trackInfo));
	return S_OK;
}


STDMETHODIMP CCardObject::OCX_GetLastError(BSTR* message)
{
	char cMessage[250];
	memset(cMessage,0,sizeof(cMessage));
	Card_GetLastError(cMessage);
	*message = _com_util::ConvertStringToBSTR(cMessage);
	return S_OK;
}


STDMETHODIMP CCardObject::OCX_EjectCard(LONG* retValue)
{
	*retValue = Card_EjectCard();
	return S_OK;
}


STDMETHODIMP CCardObject::OCX_PrintPassword(BSTR* password, LONG* retValue)
{
	*retValue = Card_PrintPassword(_com_util::ConvertBSTRToString(*password));
	return S_OK;
}

STDMETHODIMP CCardObject::OCX_PrintAll(BSTR* expiredDate, BSTR* parValue, BSTR* password, LONG permission, LONG* retValue)
{
	*retValue = Card_PrintAll(_com_util::ConvertBSTRToString(*expiredDate),_wtoi(*parValue),_com_util::ConvertBSTRToString(*password),permission);
	return S_OK;
}

STDMETHODIMP CCardObject::OCX_SetPrinter(BSTR* printerName, LONG* retValue)
{
	*retValue = Card_SetPrinter(_com_util::ConvertBSTRToString(*printerName));
	return S_OK;
}

STDMETHODIMP CCardObject::OCX_GetPrinters(VARIANT* printers)
{
	int printerCount = Card_GetPrinterCount();
	if(printerCount>0)
	{
		char** list = new char*[printerCount];
		for (int i = 0; i < printerCount; ++i)
		{
			list[i] = new char[100];
			memset(list[i],0x00,100);
		}

		Card_GetPrinters(list,printerCount);

		SAFEARRAYBOUND saBound;
		SAFEARRAY* pSA;
		
		saBound.cElements = printerCount;
		saBound.lLbound = 0;

		pSA = SafeArrayCreate( VT_VARIANT, 1, &saBound );

		VARIANT row;
		row.vt = VT_BSTR;
		for (long i = 0; i < printerCount; ++i)
        {
		  row.bstrVal = _com_util::ConvertStringToBSTR(list[i]);
          SafeArrayPutElement( pSA, &i, &row);
		  //delete[] list[i];
		}
		VariantInit( printers );
		printers->vt = VT_ARRAY | VT_VARIANT;
		printers->parray = pSA;
	}
	
	return S_OK;
}

STDMETHODIMP CCardObject::OCX_IC_ReadCardNoAndTrack(VARIANT* fieldValue)
{
	char cardNo[150];
	char secondTrack[150];
	memset(cardNo,0x00,sizeof(cardNo));
	memset(secondTrack,0x00,sizeof(secondTrack));
	char phyid[17];
	int cardType = 0;
	int ret = ENG_RequestCard(phyid,cardType);
	if(ret)
	{
		ENG_BeepError();
		return ret;
	}

	char** list = new char*[2];
	list[0] = cardNo;
	list[1] = secondTrack;
	ret = ENG_ReadCardNoAndSecondTrack(cardNo,secondTrack);
	if(ret==0)
		ENG_Beep();
	else 
		ENG_BeepError();

	SAFEARRAYBOUND saBound;
	SAFEARRAY* pSA;
		
	saBound.cElements = 2;
	saBound.lLbound = 0;

	pSA = SafeArrayCreate( VT_VARIANT, 1, &saBound );

	VARIANT row;
	row.vt = VT_BSTR;
	for (long i = 0; i < 2; ++i)
    {
		row.bstrVal = _com_util::ConvertStringToBSTR(cardNo);
        SafeArrayPutElement( pSA, &i, &row);
		//delete[] list[i];
	}

	VariantInit( fieldValue );
	fieldValue->vt = VT_ARRAY | VT_VARIANT;
	fieldValue->parray = pSA;

	return S_OK;
}
