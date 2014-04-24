#pragma once
#include <string>
#include <map>
#include "../CardInterface/Global.h"

// CPsamCard dialog

class CPsamCard : public CDialogEx
{
	DECLARE_DYNAMIC(CPsamCard)

public:
	CPsamCard(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPsamCard();
	void SetUser(User* user);

// Dialog Data
	enum { IDD = IDD_PSAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	CComboBox slotSelect;
	CEdit termNOEdit;
	std::map<std::string,std::string> slots;   //PSAM¿¨×ù
	User *user;
public:
	afx_msg void OnResetPsam();
	afx_msg void OnInitPsam();
	afx_msg void OnRecyclePsam();
	afx_msg void OnReadPsam();
	afx_msg void OnStorePsam();
};
