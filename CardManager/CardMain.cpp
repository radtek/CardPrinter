// CardMain.cpp : implementation file
//

#include "stdafx.h"
#include "CardManager.h"
#include "CardMain.h"
#include "afxdialogex.h"


// CCardMain dialog

IMPLEMENT_DYNAMIC(CCardMain, CDialogEx)

CCardMain::CCardMain(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCardMain::IDD, pParent)
{
}

CCardMain::~CCardMain()
{
}

void CCardMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABSET, tabCtrl);
	tabCtrl.InsertItem(0,"´ÅÌõ¿¨");
	tabCtrl.InsertItem(1,"IC¿¨");
	tabCtrl.InsertItem(2,"PSAM¿¨");
}

BOOL CCardMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	msCard.Create(IDD_CARDMANAGER_DIALOG,GetDlgItem(IDC_TABSET)); 
	icCard.Create(IDD_IC,GetDlgItem(IDC_TABSET));
	psamCard.Create(IDD_PSAM,GetDlgItem(IDC_TABSET));

	CRect rect;
	tabCtrl.GetClientRect(&rect);
	rect.top+=21;
	rect.bottom-=1;
	rect.left+=2;
	rect.right-=1;
	msCard.MoveWindow(&rect);
	icCard.MoveWindow(&rect);
	psamCard.MoveWindow(&rect);
	msCard.ShowWindow(TRUE);
	icCard.ShowWindow(FALSE);
	psamCard.ShowWindow(FALSE);
	tabCtrl.SetCurSel(0);
	return TRUE;
}

BEGIN_MESSAGE_MAP(CCardMain, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABSET, &CCardMain::OnChangeTab)
END_MESSAGE_MAP()


// CCardMain message handlers

void CCardMain::SetUser(User* user)
{
	this->icCard.SetUser(user);
	this->msCard.SetUser(user);
	this->psamCard.SetUser(user);
}

void CCardMain::OnChangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	int CurSel = tabCtrl.GetCurSel(); 
	switch(CurSel) 
	{ 
		case 0: 
			msCard.ShowWindow(true); 
			icCard.ShowWindow(false); 
			psamCard.ShowWindow(false);
			break; 
		case 1: 
			msCard.ShowWindow(false); 
			icCard.ShowWindow(true); 
			psamCard.ShowWindow(false);
			break; 
		case 2: 
			msCard.ShowWindow(false); 
			icCard.ShowWindow(false); 
			psamCard.ShowWindow(true);
		break; 
		default:; 
	}
	*pResult = 0;
}
