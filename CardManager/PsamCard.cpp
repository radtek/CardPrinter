// PsamCard.cpp : implementation file
//

#include "stdafx.h"
#include "CardManager.h"
#include "PsamCard.h"
#include "afxdialogex.h"
#include "../CardEngine/include/CardEngine.h"
#include "../CardInterface/CardInterface.h"

// CPsamCard dialog

IMPLEMENT_DYNAMIC(CPsamCard, CDialogEx)

CPsamCard::CPsamCard(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPsamCard::IDD, pParent)
{

}

CPsamCard::~CPsamCard()
{
}

BOOL CPsamCard::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	slots.insert(std::pair<std::string,std::string>(std::string("Íâ²¿¿¨×ù"),(std::string("1"))));
    slotSelect.AddString("Íâ²¿¿¨×ù");
	slots.insert(std::pair<std::string,std::string>(std::string("ÄÚ²¿¿¨×ù"),(std::string("2"))));
    slotSelect.AddString("ÄÚ²¿¿¨×ù");
	slotSelect.SetCurSel(1);

	return TRUE;
}

void CPsamCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PSAM_SEL, slotSelect);
	DDX_Control(pDX, IDC_PSAM_TERMNO, termNOEdit);
}


BEGIN_MESSAGE_MAP(CPsamCard, CDialogEx)
	ON_BN_CLICKED(IDC_PSAM_RESET, &CPsamCard::OnResetPsam)
	ON_BN_CLICKED(IDC_PSAM_INIT, &CPsamCard::OnInitPsam)
	ON_BN_CLICKED(IDC_PSAM_RECYCLE, &CPsamCard::OnRecyclePsam)
	ON_BN_CLICKED(IDC_PSAM_READ, &CPsamCard::OnReadPsam)
	ON_BN_CLICKED(IDC_PSAM_STORE, &CPsamCard::OnStorePsam)
END_MESSAGE_MAP()


// CPsamCard message handlers


void CPsamCard::OnResetPsam()
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
		AfxMessageBox(_T("ÇëÑ¡ÔñPSAM¿¨×ù"),MB_OK|MB_ICONWARNING   );
		return;
	}

	if(ENG_SetPsamSlot(slot))
		AfxMessageBox(_T("PSAM¿¨ÉÏµç¸´Î»Ê§°Ü"),MB_OK|MB_ICONWARNING   );
	else 
		ENG_Beep();
}


void CPsamCard::OnInitPsam()
{
	PsamCard psamCard;
	memset( &psamCard, 0, sizeof( psamCard ) );

	char startDate[9];
	char expireDate[9];
	memset(startDate,0x00,sizeof(startDate));
	memset(expireDate,0x00,sizeof(expireDate));
	time_t t;
    t = time( NULL );
    struct tm * tx = localtime( &t );
    sprintf( startDate, "%04d%02d%02d", tx->tm_year + 1900, tx->tm_mon + 1, tx->tm_mday);
	sprintf( expireDate, "%04d%02d%02d", tx->tm_year + 1910, tx->tm_mon + 1, tx->tm_mday);

	char psamCardNo[13];
	memset(psamCardNo,0x00,sizeof(psamCardNo));
	if(Card_GeneratePsamCardNo(psamCardNo))
	{
		AfxMessageBox(_T("»ñÈ¡PSAM¿¨ºÅÊ§°Ü"),MB_OK|MB_ICONWARNING   );
		return;
	}
	psamCard.cardType = 2;
	psamCard.cardVersion = 1;
	strcpy( psamCard.publishId, "10" );
	strcpy( psamCard.userId, "10" );
	strcpy( psamCard.psamCardNo, "1234567" );
	strcpy( psamCard.termId, psamCardNo );
	strcpy( psamCard.startDate, startDate );
	strcpy( psamCard.expireDate, expireDate );

	if(ENG_InitPsamCard(&psamCard))
	{
		AfxMessageBox(_T("·¢ÐÐPSAM¿¨Ê§°Ü"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	} else
	{
		termNOEdit.SetWindowTextA(psamCardNo);
		ENG_Beep();
	}
}


void CPsamCard::OnRecyclePsam()
{
	if(ENG_RecyclePsamCard())
	{
		AfxMessageBox(_T("»ØÊÕPSAM¿¨Ê§°Ü"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	} else
	{
		ENG_Beep();
	}
}


void CPsamCard::OnReadPsam()
{
	char termNo[100];
	memset(termNo,0x00,sizeof(termNo));
	if(ENG_ReadPsamTermNo(termNo))
	{
		AfxMessageBox(_T("¶ÁÈ¡PSAM¿¨Ê§°Ü"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	} else
	{
		termNOEdit.SetWindowTextA(termNo);
		ENG_Beep();
	}
}


void CPsamCard::OnStorePsam()
{
	PsamCard psamCard;
	memset( &psamCard, 0, sizeof( psamCard ) );
	if(ENG_ReadPsamCard(&psamCard))
	{
		AfxMessageBox(_T("¶ÁÈ¡PSAM¿¨Ê§°Ü"),MB_OK|MB_ICONWARNING   );
		ENG_BeepError();
		return;
	}
	termNOEdit.SetWindowTextA(psamCard.termId);

	Psam psam;
	memset(&psam,0x00,sizeof(psam));
	strcpy(psam.cardNo,psamCard.termId);
	strcpy(psam.operateId,this->user->userId);

	if(Card_StorePsamCard(&psam))
	{
		AfxMessageBox(_T("PSAM¿¨Èë¿âÊ§°Ü"),MB_OK|MB_ICONWARNING   );
	} else 
	{
		ENG_Beep();
	}
}

void CPsamCard::SetUser(User* user)
{
	this->user = user;
}
