// CardInterfaceTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <assert.h>
#include <windows.h>
#include <winspool.h>
#include "../CardInterface/CardInterface.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char printerName[20] = "Magicard Rio Pro";
	char password[7] = "860609";
	int ret = 0;
	ret = Card_Init();
	cout<<"Card Init:"<<ret;

	Card_SetPrinter(printerName);

	cout<<password<<endl;

	ret = Card_EjectCard();

	//ret = Card_PrintPassword(password);
	//cout<<"Card Print Password:"<<ret;

	char trackInfo1[100], trackInfo2[100], trackInfo3[100];
	memset(trackInfo1,0,sizeof(trackInfo1));
	memset(trackInfo2,0,sizeof(trackInfo2));
	memset(trackInfo3,0,sizeof(trackInfo3));
	ret = Card_ReadAllTrack(trackInfo1, trackInfo2, trackInfo3);
	cout<<"Card Read Track:"<<ret;
	cout<<"Track Info:"<<trackInfo2;

	return 0;
}

