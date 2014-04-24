// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CardManager.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "CardManagerDlg.h"
#include "CardMain.h"
#include "../CardInterface/CardInterface.h"

// CLoginDlg dialog

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(ID_BTN_EXIT, &CLoginDlg::OnExit)
	ON_BN_CLICKED(ID_BTN_LOGIN, &CLoginDlg::OnLogin)
END_MESSAGE_MAP()


// CLoginDlg message handlers


void CLoginDlg::OnExit()
{
	PostQuitMessage(0);
}


void CLoginDlg::OnLogin()
{
	CEdit* loginNameEdit=(CEdit*)GetDlgItem(IDC_EDIT_LOGIN_NAME);
	CEdit* passwordEdit=(CEdit*)GetDlgItem(IDC_EDIT_PASSWORD);
	char loginName[100];
	char password[100];
	memset(loginName,0x00,sizeof(loginName));
	memset(password,0x00,sizeof(password));
	loginNameEdit->GetWindowTextA(loginName,10);
	passwordEdit->GetWindowTextA(password,10);

	if(strlen(loginName)==0)
	{
		AfxMessageBox(_T("请输入用户名"),MB_OK|MB_ICONWARNING   );
		loginNameEdit->SetFocus();
		return;
	}
	if(strlen(password)==0)
	{
		AfxMessageBox(_T("请输入密码"),MB_OK|MB_ICONWARNING   );
		passwordEdit->SetFocus();
		return;
	}
	User user;
	if(Card_Login(loginName,password, &user))
	{
		char error[200];
		memset(error,0x00,sizeof(error));
		Card_GetLastError(error);
		AfxMessageBox(_T(error),MB_OK|MB_ICONWARNING   );
		passwordEdit->SetFocus();
		return;
	}
	
	EndDialog(0); 
	CCardMain dlg;
	dlg.SetUser(&user);
	dlg.DoModal();
}
