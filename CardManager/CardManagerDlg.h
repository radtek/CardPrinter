
// CardManagerDlg.h : 头文件
//

#pragma once

#include <string>
#include <map>
#include "../CardInterface/Global.h"

// CCardManagerDlg 对话框
class CCardManagerDlg : public CDialogEx
{
// 构造
public:
	CCardManagerDlg(CWnd* pParent = NULL);	// 标准构造函数
	void SetUser(User* user);

// 对话框数据
	enum { IDD = IDD_CARDMANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	//重载OnOk事件，去掉回车关闭窗口功能
	void OnOK();
public:
	afx_msg void OnExecuteCommand();
private:
	void ShowPrinters();
	void InitCardList();
	void InitCardTypeRules();
	std::string GetCardNo(char* trackInfo);
	void AddPendingCard(char* expiredDate, char* parValue, char* trackInfo, char* password, char* comment, FILE * logFile=NULL);
	void StoreOneCard(char* cardTypeRule, char* expiredDate, char* parValue, char* trackInfo, char* password, FILE * logFile=NULL);
public:
	afx_msg void OnReadTracks();
	afx_msg void OnEjectCard();
	afx_msg void OnPrintCard();
	afx_msg void OnResetNumber();
	afx_msg void OnCbnSelchangeComboPrinters();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);

private:
	CComboBox printerSelect;
	CComboBox ruleSelect;
	CEdit cardNOEdit;
	CEdit track2Edit;
	CEdit expiredDateEdit;
	CEdit parValueEdit;
	CEdit numberEdit;
	CEdit printedEdit;
	CEdit nameEdit;
	CEdit levelEdit;
	CButton dateOption;
	CButton valueOption;
	CButton passwordOption;
	CButton randomOption;
	CButton nameOption;
	CButton levelOption;
	CMFCListCtrl cardList;
	char error[3000];
	std::map<std::string,std::string> cardTypeRules;
	User *user;
public:
	afx_msg void OnBnClickedButtonEject();
	afx_msg void OnReadCard();
	afx_msg void OnClick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnRevertAll();
	afx_msg void OnSelectAll();
	afx_msg void OnStore();
	afx_msg void OnDelete();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnPrintAndStore();
};
