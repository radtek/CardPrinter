#pragma once
#include <string>
#include <map>
#include "../CardInterface/Global.h"

// CICCard dialog

class CICCard : public CDialogEx
{
	DECLARE_DYNAMIC(CICCard)

public:
	CICCard(CWnd* pParent = NULL);   // standard constructor
	virtual ~CICCard();
	void SetUser(User* user);

// Dialog Data
	enum { IDD = IDD_IC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	void InitCardTypeRules();
	void StoreOneCard(char* cardTypeRule, char* phyid, char* cardNo,char* trackInfo, char* password, FILE * logFile=NULL);

private:
	CComboBox portSelect;
	CComboBox slotSelect;
	CEdit cardNOEdit;
	CEdit track2Edit;
	CEdit phyidEdit;
	CComboBox ruleSelect;
	char error[3000];
	std::map<std::string,std::string> ports;   //¶Ë¿Ú
	std::map<std::string,std::string> slots;   //PSAM¿¨×ù
	std::map<std::string,std::string> cardTypeRules;
	User *user;
public:
	afx_msg void OnPsamReset();
	afx_msg void OnReadCard();
	afx_msg void OnRequestCard();
	afx_msg void OnStoreCard();
	afx_msg void OnReadAndStoreCard();
	afx_msg void OnUpdateCardKeys();
};
