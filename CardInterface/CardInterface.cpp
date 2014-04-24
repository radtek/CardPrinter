// CardInterface.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;
#include <windows.h>
#include <winspool.h>
#include <vector>

#include "CardInterface.h"
#include "Printer.h"
#include "../RedCard/RedCard.h"
#include "AppContext.h"

HMODULE hInstance = NULL;
CPrinter *printer = NULL;            //默认打印机
vector<string> printerList;   //当前可用打印机列表
CRedCard *redCard = NULL;
string lastErrorMessage;
list<CardTypeRule> cardTypeRules;
AppContext appContext;
bool initialized = FALSE; 

void SetErrorMessage(const char* error)
{
	lastErrorMessage.clear();
	lastErrorMessage.append(error);
}

int InitPrinterList()
{
	printerList.clear();

	bool bStatus = true;
	PRINTER_INFO_2 * InfoPrint=NULL;
	PRINTER_INFO_2 * InfoMemory;
	DWORD Receive, Nbre;
	DWORD Need;
	int i,j=0, base = 0;
	TCHAR error[128];

	EnumPrinters(PRINTER_ENUM_LOCAL, NULL, 2, (LPBYTE) InfoPrint,0, &Receive, &Nbre);
	Need = Receive;
	//memory allocation
	InfoMemory = InfoPrint = (PRINTER_INFO_2 * ) GlobalAlloc(GPTR, Need);
	i = EnumPrinters(PRINTER_ENUM_LOCAL, NULL, 2, (LPBYTE) InfoPrint, Need, &Receive, &Nbre);
	if (i)  {
		for(i=0; i < (int) Nbre; i++)  {
			printerList.push_back(InfoPrint->pPrinterName);
			InfoPrint++;
		}
		
		if(printerList.size()==0) {
			strcpy(error,"No printer available");
			bStatus = false;
		}
	}
	//free memory
	GlobalFree(InfoMemory);
	return (bStatus);
}

void Card_InitHandler(HMODULE *hModule)
{
	hInstance = *hModule;
}

int Card_Init()
{
	if(initialized == TRUE)
	{
		return SUCCESS;
	}
	appContext.InitContext();
	if(InitPrinterList())
	{
		initialized = TRUE;
		return SUCCESS;
	}
	return NO_PRINTER;
}

int Card_GetPrinterCount()
{
	return printerList.size();
}

void Card_GetPrinters(OUT char **printers,IN int size)
{
	for(int i=0;i<size;i++)
	{
		char* printer = printers[i];
		strcpy(printer,printerList[i].c_str());
	}
}

int Card_SetPrinter(IN char *printerName)
{
	if(printer!=NULL && strcmp(printer->GetPrinterName(),printerName)==0)
	{
		return SUCCESS;
	}
	for(int i=0;i<printerList.size();i++)
	{
		string name = printerList[i];
		if(strcmp(name.c_str(),printerName)==0)
		{
			printer = new CPrinter();
			printer->SetPrinterName(printerName);
			return SUCCESS;
		}
	}
	return NO_PRINTER;
}

int Card_ExecuteCommand(IN const char* command, OUT char* answer)
{
	CHECK_PRINTER();
	return SUCCESS;
}

int Card_ReadTrack(IN int trackNo, OUT char* trackInfo)
{
	CHECK_PRINTER();
	int ret = SUCCESS;
	char trackInfo1[100], trackInfo2[100],trackInfo3[100];
	memset(trackInfo1,0,sizeof(trackInfo1));
	memset(trackInfo2,0,sizeof(trackInfo2));
	memset(trackInfo3,0,sizeof(trackInfo3));
	
	if(trackNo==1){
		ret = Card_ReadAllTrack(trackInfo,trackInfo2,trackInfo3);	
	}else if(trackNo==2){
		ret = Card_ReadAllTrack(trackInfo1,trackInfo,trackInfo3);	
	}else if(trackNo==3){
		ret = Card_ReadAllTrack(trackInfo1,trackInfo2,trackInfo);	
	}
	return ret;
}

int Card_ReadAllTrack(OUT char* trackInfo1,OUT char* trackInfo2,OUT char* trackInfo3)
{
	CHECK_PRINTER();
	int ret = SUCCESS;
	string readTrackInfo;

	if (!printer->ReadAllTrack(trackInfo1, trackInfo2, trackInfo3)) 
	{
		ret = ERR_READ;
	}
	return ret;
}

int Card_WriteTrack(IN int trackNo,IN char *trackInfo)
{
	CHECK_PRINTER();
	int ret = SUCCESS;
	return ret;
}

void Card_GetLastError(OUT char *message)
{
	/**
	if(printer==NULL)
	{
		strcpy(message,"没有找到打印机");
		return;
	}
	std::string error = printer->GetErrorMessage();
	strcpy(message,error.c_str());
	*/
	if(message!=NULL){
		strcpy(message,lastErrorMessage.c_str());
	}
	return;
}

int Card_EjectCard()
{
	CHECK_PRINTER();
	int ret = SUCCESS;
	if(!printer->EjectCardApp())
	{
		ret = ERR_EJECT;
	}
	return ret;	
}

int Card_Print(IN char* expiredDate, IN int parValue)
{
	CHECK_PRINTER();
	int ret = SUCCESS;
	if (!printer->Print(expiredDate,parValue,NULL,(PRINT_EXPIRED_DATE+PRINT_PAR_VALUE),true)) 
	{
		ret = ERR_PRINT;
	}
	return ret;
}

int Card_PrintAll(IN char* expiredDate, IN int parValue, IN char* password, int permission)
{
	CHECK_PRINTER();
	int ret = SUCCESS;
	if (!printer->Print(expiredDate,parValue,password,permission,false)) 
	{
		ret = ERR_PRINT;
	}
	return ret;
}

int Card_PrintAllWithPrintStatus(IN char* expiredDate, IN int parValue, IN char* password, IN char* name, IN char* level, int permission,OUT int & printedItem)
{
	CHECK_PRINTER();
	int ret = SUCCESS;
	if (!printer->Print(expiredDate,parValue,password,name,level,permission,false,printedItem)) 
	{
		ret = ERR_PRINT;
	}
	return ret;
}

int Card_PrintPassword(IN char* password)
{
	CHECK_PRINTER();
	int ret = SUCCESS;
	if (!printer->PrintPassword(password)) 
	{
		ret = ERR_PRINT;
	}
	return ret;
}

void InitRedCard()
{
	appContext.InitContext();
	string serviceURL;
	string dbURL;
	appContext.config.ReadInto(serviceURL,SERVICE_URL);
	appContext.config.ReadInto(dbURL,DB_URL);
	redCard = new CRedCard(serviceURL.c_str(),dbURL.c_str());
}

int Card_Login(IN char* loginName, IN char* password, OUT User* user)
{
	if(redCard == NULL)
	{
		InitRedCard();
	}	
	int ret = SUCCESS;
	if(!redCard->Login(loginName,password,user))
	{
		SetErrorMessage(redCard->GetErrorMessage());
		ret = ERR_LOGIN;
	}
	return ret;
}

int Card_GeneratePassword(OUT char* password)
{
	if(redCard == NULL)
	{
		InitRedCard();
	}	
	int ret = SUCCESS;
	if(!redCard->GeneratePassword(password))
	{
		SetErrorMessage(redCard->GetErrorMessage());
		ret = ERR_GENERATE_P;
	}
	return ret;
}

int Card_ReadCardTypeRules(OUT int& size)
{
	cardTypeRules.clear();
	if(redCard == NULL)
	{
		InitRedCard();
	}	
	int ret = SUCCESS;
	if(!redCard->GetCardTypeRules(&cardTypeRules))
	{
		std::string error = redCard->GetErrorMessage();
		SetErrorMessage(error.c_str());
		ret = ERR_GENERATE_P;
	}
	size = cardTypeRules.size();
	return ret;
}

int Card_GetCardTypeRules(OUT char **ids, OUT char **names, IN int size)
{
	list<CardTypeRule>::iterator iter;
	int i = 0;
	for(iter=cardTypeRules.begin();iter!=cardTypeRules.end();iter++)
	{
		if(i>=size)
		{
			break;
		}
		char* id = ids[i];
		char* name = names[i];
		i++;
		strcpy(id,(iter)->id);
		strcpy(name,(iter)->name);
	}
	return SUCCESS;
}

int Card_StoreCard(IN Card **cards, int size, OUT Card ** pendingList,OUT int& pendingSize)
{
	if(redCard == NULL)
	{
		InitRedCard();
	}	
	int ret = SUCCESS;
	if(!redCard->StoreCard(cards, size,pendingList,pendingSize))
	{
		std::string error = redCard->GetErrorMessage();
		SetErrorMessage(error.c_str());
		ret = ERR_GENERATE_P;
	} else 
	{
		std::string error = redCard->GetErrorMessage();
		SetErrorMessage(error.c_str());
	}
	size = cardTypeRules.size();
	return ret;
}

int Card_StorePsamCard(IN Psam *psam)
{
	if(redCard == NULL)
	{
		InitRedCard();
	}	
	int ret = SUCCESS;
	if(!redCard->StorePsamCard(psam))
	{
		std::string error = redCard->GetErrorMessage();
		SetErrorMessage(error.c_str());
		ret = ERR_GENERATE_P;
	} else 
	{
		std::string error = redCard->GetErrorMessage();
		SetErrorMessage(error.c_str());
	}
	return ret;
}

int Card_GetMainKey(OUT char* mainKey)
{
	if(redCard == NULL)
	{
		InitRedCard();
	}	
	int ret = SUCCESS;
	if(!redCard->GetMainKey(mainKey))
	{
		SetErrorMessage(redCard->GetErrorMessage());
		ret = ERR_GENERATE_P;
	}
	return ret;
}

int Card_GeneratePsamCardNo(OUT char* cardNo)
{
	if(redCard == NULL)
	{
		InitRedCard();
	}	
	int ret = SUCCESS;
	if(!redCard->GeneratePsamCardNo(cardNo))
	{
		SetErrorMessage(redCard->GetErrorMessage());
		ret = ERR_GENERATE_P;
	}
	return ret;
}