// ICCard.cpp : implementation file
//

#include "stdafx.h"
#include <list>
#include "CardManager.h"
#include "ICCard.h"
#include "afxdialogex.h"
#include "../CardEngine/include/CardEngine.h"
#include "../CardInterface/CardInterface.h"


// CICCard dialog

IMPLEMENT_DYNAMIC(CICCard, CDialogEx)

CICCard::CICCard(CWnd* pParent /*=NULL*/)
	: CDialogEx(CICCard::IDD, pParent)
{

}

CICCard::~CICCard()
{
}

void CICCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IC_PORT_SEL, portSelect);
	DDX_Control(pDX, IDC_IC_PSAM_SEL, slotSelect);
	DDX_Control(pDX, IDC_IC_CARDNO, cardNOEdit);
	DDX_Control(pDX, IDC_IC_SECOND_TRACK, track2Edit);
	DDX_Control(pDX, IDC_IC_PHYID, phyidEdit);
	DDX_Control(pDX, IDC_IC_RULE, ruleSelect);
}

BOOL CICCard::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ports.insert(std::pair<std::string,std::string>(std::string("USB"),(std::string("100"))));
    portSelect.AddString("USB");
	portSelect.SetCurSel(0);

	slots.insert(std::pair<std::string,std::string>(std::string("外部卡座"),(std::string("1"))));
    slotSelect.AddString("外部卡座");
	slots.insert(std::pair<std::string,std::string>(std::string("内部卡座"),(std::string("2"))));
    slotSelect.AddString("内部卡座");
	slotSelect.SetCurSel(1);

	if(ENG_Init())
	{
		AfxMessageBox(_T("初始化读卡库失败"),MB_OK|MB_ICONWARNING   );
		return TRUE;
	}
	InitCardTypeRules();

	char mainKey[33];
	memset(mainKey,0x00,sizeof(mainKey));
	if(Card_GetMainKey(mainKey))
	{
		AfxMessageBox(_T("获取根密钥失败"),MB_OK|MB_ICONWARNING   );
		return TRUE;
	}
	ENG_SetMainKey(mainKey);
	ENG_Beep();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CICCard, CDialogEx)
	ON_BN_CLICKED(IDC_IC_RESET, &CICCard::OnPsamReset)
	ON_BN_CLICKED(IDC_IC_READ, &CICCard::OnReadCard)
	ON_BN_CLICKED(IDC_IC_REQUEST, &CICCard::OnRequestCard)
	ON_BN_CLICKED(IDC_IC_STORE, &CICCard::OnStoreCard)
	ON_BN_CLICKED(IDC_IC_READ_STORE, &CICCard::OnReadAndStoreCard)
	ON_BN_CLICKED(IDC_IC_UPDATE, &CICCard::OnUpdateCardKeys)
END_MESSAGE_MAP()


// CICCard message handlers

void CICCard::InitCardTypeRules()
{
	int size = 0;
	if(Card_ReadCardTypeRules(size))
	{
		Card_GetLastError(error);
		AfxMessageBox(_T(error),MB_OK|MB_ICONWARNING   );
		return;
	}
	if(size>0)
	{
		
		char** ids = new char*[size];
		char** names = new char*[size];

		for (int i = 0; i < size; ++i)
		{
			ids[i] = new char[20];
			names[i] = new char[100];
			memset(names[i],0x00,100);
		}

		Card_GetCardTypeRules(ids,names,size);

		cardTypeRules.clear();
		for (int i = 0; i < size; ++i)
        {
		  cardTypeRules.insert(std::pair<std::string,std::string>(std::string(names[i]),(std::string(ids[i]))));
          ruleSelect.AddString(names[i]);
		  delete[] names[i];
		  delete[] ids[i];
		}
		ruleSelect.SetCurSel(0);
		delete [] names;
		delete [] ids;
	} 
}

void CICCard::SetUser(User* user)
{
	this->user = user;
}

void CICCard::OnPsamReset()
{
	int slot = 1;
	char slotStr[20] = {0};
	memset(slotStr,0x00,sizeof(slotStr));
	this->slotSelect.GetWindowTextA(slotStr,200);
	std::map<std::string,std::string>::iterator slotIter;
	slotIter = this->slots.find(slotStr);
	if(slotIter!=slots.end())
	{
		slot = atoi(slotIter->second.c_str());
	} else 
	{
		AfxMessageBox(_T("请选择PSAM卡座"),MB_OK|MB_ICONWARNING   );
		return;
	}

	if(ENG_SetPsamSlot(slot))
		AfxMessageBox(_T("PSAM卡上电复位失败"),MB_OK|MB_ICONWARNING   );
	else 
		ENG_Beep();
}


void CICCard::OnReadCard()
{
	char phyid[17];
	int cardType = 0;

	if(ENG_RequestCard(phyid,cardType))
	{
		AfxMessageBox(_T("寻卡失败"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	}
	phyidEdit.SetWindowTextA(phyid);

	char cardNo[100];
	char secondTrack[100];
	memset(cardNo,0,sizeof(cardNo));
	memset(secondTrack,0,sizeof(secondTrack));
	if(ENG_ReadCardNoAndSecondTrack(cardNo,secondTrack))
	{
		AfxMessageBox(_T("读卡失败，请检查卡密钥是否已更新"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
	} else 
	{
		cardNOEdit.SetWindowTextA(cardNo);
		track2Edit.SetWindowTextA(secondTrack);
		ENG_Beep();
	}
}


void CICCard::OnRequestCard()
{
	char phyid[17];
	int cardType = 0;

	if(ENG_RequestCard(phyid,cardType))
	{
		AfxMessageBox(_T("寻卡失败"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	} else
	{
		phyidEdit.SetWindowTextA(phyid);
		ENG_Beep();
	}
}


void CICCard::OnStoreCard()
{
	char cardNo[100];
	char trackInfo[100];
	char phyid[100];
	memset(cardNo,0x00,sizeof(cardNo));
	memset(trackInfo,0x00,sizeof(trackInfo));
	memset(phyid,0x00,sizeof(phyid));
	this->cardNOEdit.GetWindowTextA(cardNo,100);
	this->track2Edit.GetWindowTextA(trackInfo,100);
	this->phyidEdit.GetWindowTextA(phyid,100);

	if(strlen(cardNo)==0 || strlen(trackInfo)==0 || strlen(phyid)==0)
	{
		AfxMessageBox(_T("请先读卡"),MB_OK|MB_ICONWARNING   );
		return;
	}

	char cardTypeRule[20] = {0};
	char rule[200];
	memset(rule,0x00,sizeof(rule));
	this->ruleSelect.GetWindowTextA(rule,200);
	std::map<std::string,std::string>::iterator typeIter;
	typeIter = this->cardTypeRules.find(rule);
	if(typeIter!=cardTypeRules.end())
	{
		strcpy(cardTypeRule,typeIter->second.c_str());
	} else 
	{
		AfxMessageBox(_T("请选择卡规则"),MB_OK|MB_ICONWARNING   );
		return;
	}

	char password[20] = {0};
	FILE * pFile = NULL;        
    int iErr = 0;
    iErr = fopen_s(&pFile,"log","a+");

    if (iErr != 0)
    {
		AfxMessageBox(_T("无法打开日志文件"),MB_OK|MB_ICONWARNING   );
		return;
	}

	CString strDateTime = "";
    SYSTEMTIME systime;
    GetLocalTime(&systime);
	strDateTime.Format("%i:%i:%i\\%02i-%02i-%02i",
            systime.wHour,
            systime.wMinute,
            systime.wSecond,
            systime.wYear,
            systime.wMonth,
            systime.wDay);
	
	fputs("======================LoginName = "+ CString(user->userId) +" Date/Time = " + strDateTime+"\n",pFile);

	memset(password,0,sizeof(password));

	if(Card_GeneratePassword(password))
	{
		AfxMessageBox(_T("生成密码失败"),MB_OK|MB_ICONWARNING   );
		fclose(pFile); 
		return;
	}

	StoreOneCard(cardTypeRule,phyid,cardNo,trackInfo,password, pFile);

	fclose(pFile); 
}


void CICCard::OnReadAndStoreCard()
{
	char cardTypeRule[20] = {0};
	char rule[200];
	memset(rule,0x00,sizeof(rule));
	this->ruleSelect.GetWindowTextA(rule,200);
	std::map<std::string,std::string>::iterator typeIter;
	typeIter = this->cardTypeRules.find(rule);
	if(typeIter!=cardTypeRules.end())
	{
		strcpy(cardTypeRule,typeIter->second.c_str());
	} else 
	{
		AfxMessageBox(_T("请选择卡规则"),MB_OK|MB_ICONWARNING   );
		return;
	}

	char phyid[17];
	int cardType = 0;
	if(ENG_RequestCard(phyid,cardType))
	{
		AfxMessageBox(_T("寻卡失败"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	}
	phyidEdit.SetWindowTextA(phyid);

	if(ENG_UpdateCardKeys())
	{
		AfxMessageBox(_T("更新卡秘钥失败"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	}

	char cardNo[100];
	char trackInfo[100];
	char password[20] = {0};
	FILE * pFile = NULL;        
    int iErr = 0;
    iErr = fopen_s(&pFile,"log","a+");

    if (iErr != 0)
    {
		AfxMessageBox(_T("无法打开日志文件"),MB_OK|MB_ICONWARNING   );
		return;
	}

	CString strDateTime = "";
    SYSTEMTIME systime;
    GetLocalTime(&systime);
	strDateTime.Format("%i:%i:%i\\%02i-%02i-%02i",
            systime.wHour,
            systime.wMinute,
            systime.wSecond,
            systime.wYear,
            systime.wMonth,
            systime.wDay);
	
	fputs("======================LoginName = "+ CString(user->userId) +" Date/Time = " + strDateTime+"\n",pFile);

	memset(password,0,sizeof(password));

	if(Card_GeneratePassword(password))
	{
		AfxMessageBox(_T("生成密码失败"),MB_OK|MB_ICONWARNING   );
		fclose(pFile); 
		return;
	}
		
	if(ENG_ReadCardNoAndSecondTrack(cardNo,trackInfo))
	{
		memset(error,0x00,sizeof(error));
		AfxMessageBox(_T("读卡失败"),MB_OK|MB_ICONWARNING);
		fclose(pFile); 
		return;
	} else 
	{
		cardNOEdit.SetWindowTextA(cardNo);
		track2Edit.SetWindowTextA(trackInfo);
	}

	StoreOneCard(cardTypeRule,phyid,cardNo,trackInfo,password, pFile);

	fclose(pFile); 
}

void CICCard::StoreOneCard(char* cardTypeRule,char* phyid, char* cardNo,char* trackInfo, char* password, FILE * logFile)
{
	std::list<Card> list;
	Card card;
	memset(&card,0x00,sizeof(card));
	strcpy(card.cardNo,cardNo);
	strcpy(card.secondTrack,trackInfo);
	//strcpy(card.payPassword,password);
	strcpy(card.cardTypeRuleId,cardTypeRule);
	strcpy(card.operateId,this->user->userId);
	strcpy(card.phyid,phyid);
	list.push_back(card);
	

	Card** cards = new Card*[list.size()];
	Card** pendingList = new Card*[list.size()];
	int pendingSize = 0;
	std::list<Card>::iterator iter;
	int i = 0;
	for(iter=list.begin();iter!=list.end();iter++)
	{
		cards[i++] = &*iter;
	}
	if(Card_StoreCard(cards,list.size(),pendingList,pendingSize))
	{
		AfxMessageBox(_T("系统异常，入库失败"),MB_OK|MB_ICONWARNING   );
	} else 
	{
		if(pendingSize > 0)
		{
			AfxMessageBox(_T(pendingList[0]->comment),MB_OK|MB_ICONWARNING   );
		}else
		{
			ENG_Beep();
		}
	}

	delete [] cards;
	delete [] pendingList;
}


void CICCard::OnUpdateCardKeys()
{
	char phyid[17];
	int cardType = 0;
	if(ENG_RequestCard(phyid,cardType))
	{
		AfxMessageBox(_T("寻卡失败"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	}
	phyidEdit.SetWindowTextA(phyid);
	if(ENG_UpdateCardKeys())
	{
		AfxMessageBox(_T("更新卡密钥失败"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	} else
	{
		ENG_Beep();
	}
}
