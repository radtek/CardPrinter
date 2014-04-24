#pragma once
#include "CardManagerDlg.h"
#include "ICCard.h"
#include "PsamCard.h"

// CCardMain dialog

class CCardMain : public CDialogEx
{
	DECLARE_DYNAMIC(CCardMain)

public:
	CCardMain(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCardMain();
	void SetUser(User* user);

// Dialog Data
	enum { IDD = IDD_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	CTabCtrl tabCtrl;
	CCardManagerDlg msCard;   //´ÅÌõ¿¨
	CICCard icCard;           //IC¿¨
	CPsamCard psamCard;           //PSAM¿¨
public:
	afx_msg void OnChangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
