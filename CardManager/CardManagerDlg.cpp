
// CardManagerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CardManager.h"
#include "CardManagerDlg.h"
#include "afxdialogex.h"
#include <list>
#include "../CardInterface/CardInterface.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCardManagerDlg 对话框




CCardManagerDlg::CCardManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCardManagerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCardManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PRINTERS, printerSelect);
	DDX_Control(pDX, IDC_COMBO_RULE, ruleSelect);
	DDX_Control(pDX, IDC_EDIT_CARDNO, cardNOEdit);
	DDX_Control(pDX, IDC_EDIT_TRACK2, track2Edit);
	DDX_Control(pDX, IDC_EDIT_EXPIRED_DATE, expiredDateEdit);
	DDX_Control(pDX, IDC_EDIT_PAR_VALUE, parValueEdit);
	DDX_Control(pDX, IDC_EDIT_NUMBER, numberEdit);
	DDX_Control(pDX, IDC_EDIT_PRINTED_NUMBER, printedEdit);
	DDX_Control(pDX, IDC_EDIT_NAME, nameEdit);
	DDX_Control(pDX, IDC_EDIT_LEVEL, levelEdit);
	DDX_Control(pDX, IDC_OPTION_DATE, dateOption);
	DDX_Control(pDX, IDC_OPTION_VALUE, valueOption);
	DDX_Control(pDX, IDC_OPTION_PASSWORD, passwordOption);
	DDX_Control(pDX, IDC_OPTION_RANDOM, randomOption);
	DDX_Control(pDX, IDC_OPTION_NAME, nameOption);
	DDX_Control(pDX, IDC_OPTION_LEVEL, levelOption);
	DDX_Control(pDX, IDC_LIST_CARD, cardList);
}

BEGIN_MESSAGE_MAP(CCardManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON_EJECTION, &CCardManagerDlg::OnEjectCard)
ON_BN_CLICKED(IDC_BUTTON_PRINT, &CCardManagerDlg::OnPrintCard)
ON_BN_CLICKED(IDC_BUTTON_RESET, &CCardManagerDlg::OnResetNumber)
ON_CBN_SELCHANGE(IDC_COMBO_PRINTERS, &CCardManagerDlg::OnCbnSelchangeComboPrinters)
ON_BN_CLICKED(IDC_BUTTON_EJECT, &CCardManagerDlg::OnBnClickedButtonEject)
ON_BN_CLICKED(IDC_BUTTON_READ, &CCardManagerDlg::OnReadCard)
ON_NOTIFY(NM_CLICK, IDC_LIST_CARD, &CCardManagerDlg::OnClick)
ON_BN_CLICKED(IDC_BTN_REVERT, &CCardManagerDlg::OnRevertAll)
ON_BN_CLICKED(IDC_BTN_ALL, &CCardManagerDlg::OnSelectAll)
ON_BN_CLICKED(IDC_BTN_STORE, &CCardManagerDlg::OnStore)
ON_BN_CLICKED(IDC_BTN_DELETE, &CCardManagerDlg::OnDelete)
ON_WM_CLOSE()
ON_BN_CLICKED(IDC_BTN_PRINT_STORE, &CCardManagerDlg::OnPrintAndStore)
END_MESSAGE_MAP()


// CCardManagerDlg 消息处理程序

BOOL CCardManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//change the frame size manually
	//SetWindowPos(NULL,0,0,400,320,SWP_NOMOVE);

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//额外的初始化代码
	if(Card_Init())
	{
		AfxMessageBox(_T("初始化打印机失败"),MB_OK|MB_ICONWARNING   );
	} else 
	{
		ShowPrinters();
	}	
	
	InitCardList();
	InitCardTypeRules();

	((CEdit*)GetDlgItem(IDC_EDIT_NUMBER))->SetWindowTextA("1");
	((CEdit*)GetDlgItem(IDC_EDIT_PRINTED_NUMBER))->SetWindowTextA("0");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCardManagerDlg::ShowPrinters()
{
	int printerCount = Card_GetPrinterCount();
	char defaultPrinter[128];
	memset(defaultPrinter,0,sizeof(defaultPrinter));
	if(printerCount>0)
	{
		CComboBox* printerSelect=(CComboBox*)GetDlgItem(IDC_COMBO_PRINTERS); 
		char** printers = new char*[printerCount];
		for (int i = 0; i < printerCount; ++i)
		{
			printers[i] = new char[100];
			memset(printers[i],0x00,100);
		}

		Card_GetPrinters(printers,printerCount);

		for (int i = 0; i < printerCount; ++i)
        {
          printerSelect->AddString(printers[i]);
		  delete[] printers[i];
		}
		delete [] printers;

		printerSelect->SetCurSel(0);
		printerSelect->GetLBText(0,defaultPrinter);
		Card_SetPrinter(defaultPrinter);
	} 
}

void CCardManagerDlg::InitCardList()
{
	CFont *m_pFont = new CFont();
m_pFont->CreateFont(20,                        // nHeight
   0,                         // nWidth
   0,                         // nEscapement
   0,                         // nOrientation
   FW_NORMAL,                 // nWeight
   FALSE,                     // bItalic
   FALSE,                     // bUnderline
   0,                         // cStrikeOut
   DEFAULT_CHARSET,              // nCharSet
   OUT_DEFAULT_PRECIS,        // nOutPrecision
   CLIP_DEFAULT_PRECIS,       // nClipPrecision
   DEFAULT_QUALITY,           // nQuality
   DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
   "Arial");   
   //cardList.SetFont(m_pFont);

	DWORD dwStyle = cardList.GetExtendedStyle();
	dwStyle |= LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT;//网格线（只适用与report风格的listctrl）
	cardList.SetExtendedStyle(dwStyle); //设置扩展风格
	//cardList.SetBkColor(RGB(247,247,255));
    //cardList.SetTextColor(RGB(0,0,255));
    //cardList.SetTextBkColor(RGB(247,247,255));

	cardList.InsertColumn (0, _T("行号"), LVCFMT_LEFT, 65);
	cardList.InsertColumn (1, _T("卡号"), LVCFMT_LEFT, 170);
	cardList.InsertColumn (2, _T("有效期"), LVCFMT_LEFT, 100);
	cardList.InsertColumn (3, _T("面值"), LVCFMT_LEFT, 80);
	cardList.InsertColumn (4, _T("二磁道信息"), LVCFMT_LEFT, 300);
	cardList.InsertColumn (5, _T("密码"), LVCFMT_LEFT, 0);
	cardList.InsertColumn (6, _T("备注"), LVCFMT_LEFT, 235);
	/*
	for(int i=0;i<2;i++)
	{
		AddPendingCard("2012-01-01","100",";9800880011922045769=000072003427894?","123456", "");
		AddPendingCard("2012-01-01","100",";9800880011922045768=000072003427894?","123456", "");
		AddPendingCard("2012-01-01","100",";9800880011922045767=000072003427894?","123456", "");
		AddPendingCard("2012-01-01","100",";9800880011922045766=000072003427894?","123456", "");
	}
	*/
	UpdateData(false);
}

void CCardManagerDlg::InitCardTypeRules()
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

void CCardManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCardManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCardManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCardManagerDlg::OnEjectCard()
{
}

void CCardManagerDlg::OnOK()
{
	if(GetDlgItem(IDC_EDIT_EXPIRED_DATE)==GetFocus() || GetDlgItem(IDC_EDIT_PAR_VALUE)==GetFocus())
	{
		OnPrintCard();
		return;
	}
}

void CCardManagerDlg::OnPrintCard()
{	
	char expiredDate[200];
	char parValueString[10];
	char number[10];
	char error[100];
	int total;
	int parValue = 0;
	char name[200];
	char level[200];
	memset(error,0x00,sizeof(error));
	memset(expiredDate,0x00,sizeof(expiredDate));
	memset(parValueString,0x00,sizeof(parValueString));
	memset(number,0x00,sizeof(number));
	memset(name,0x00,sizeof(name));
	memset(level,0x00,sizeof(level));

	this->expiredDateEdit.GetWindowTextA(expiredDate,200);
	this->parValueEdit.GetWindowTextA(parValueString,10);
	this->numberEdit.GetWindowTextA(number,10);
	this->nameEdit.GetWindowTextA(name,200);
	this->levelEdit.GetWindowTextA(level,200);

	if(strlen(number)==0)
	{
		//no card number, we use the default value 1
		total = 1;
	} else 
	{
		total = atoi(number);
	}

	if(total==0)
	{
		//the input number is not correct
		AfxMessageBox(_T("请输入正确的卡片张数，值必须为整数"),MB_OK|MB_ICONWARNING   );
		return;
	} else if(total>200)
	{
		AfxMessageBox(_T("卡片张数必须小于200"),MB_OK|MB_ICONWARNING   );
		return;
	}

	if(total>1)
	{
		char info[200];
		memset(info,0x00,sizeof(info));
		sprintf(info,"确定要打印 %d 张卡片吗？",total);
		if(AfxMessageBox(_T(info),MB_OKCANCEL|MB_ICONQUESTION)==IDCANCEL)
		{
			return;
		}
	}

	//get print option
	int permission = 0;
	if(dateOption.GetCheck()==1)
	{
		if(strlen(expiredDate)==0)
		{
			AfxMessageBox(_T("请输入有效期"),MB_OK|MB_ICONWARNING   );
			return;
		}
		permission = permission +1;
	}
	if(valueOption.GetCheck()==1)
	{
		if(strlen(parValueString)==0)
		{
			AfxMessageBox(_T("请输入面值"),MB_OK|MB_ICONWARNING   );
			return;
		}
		parValue = atoi(parValueString);
		permission = permission +2;
	}
	if(passwordOption.GetCheck()==1)
	{
		permission = permission +4;
	}
	if(randomOption.GetCheck()==1)
	{
		permission = permission +8;
	}
	if(nameOption.GetCheck()==1)
	{
		permission = permission +16;
	}
	if(levelOption.GetCheck()==1)
	{
		permission = permission +32;
	}

	if(permission==0)
	{
		AfxMessageBox(_T("请选择打印选项"),MB_OK|MB_ICONWARNING   );
		return;
	}

	int i;
	int printedItem = 0;
	char trackInfo[50];
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

	for(i=0;i<total;i++)
	{
		printedItem = 0;
		memset(trackInfo,0,sizeof(trackInfo));
		memset(password,0,sizeof(password));
		if((permission & 0x04) == 0x04)
		{
			if(Card_GeneratePassword(password))
			{
				AfxMessageBox(_T("生成密码失败"),MB_OK|MB_ICONWARNING   );
				break;
			}
		}
		
		if(Card_ReadTrack(2,trackInfo))
		{
			memset(error,0x00,sizeof(error));
			//Card_GetLastError(error);
			AfxMessageBox(_T("打印机出现问题，请检查打印机状态"),MB_OK|MB_ICONWARNING);
			break;
		}

		std::string cardNo = GetCardNo(trackInfo).c_str();

		if(0==cardNo.length()){
			AfxMessageBox(_T("读卡失败，未读出卡号信息，请检查打印机或卡片"),MB_OK|MB_ICONWARNING   );	
			break;
		}

		cardNOEdit.SetWindowTextA(cardNo.c_str());
		track2Edit.SetWindowTextA(trackInfo);
		
		if(Card_PrintAllWithPrintStatus(expiredDate,parValue,password,name,level,permission,printedItem))
		{
			//Card_GetLastError(error);
			if(printedItem > 0)
			{
				AddPendingCard(expiredDate,parValueString,trackInfo,password, "",pFile);
			}
			AfxMessageBox(_T("打印机出现问题，请检查打印机状态"),MB_OK|MB_ICONWARNING);
			break;
		}
		AddPendingCard(expiredDate,parValueString,trackInfo,password, "",pFile);
	}
	
	fclose(pFile); 

	char printedNumber[10];
	memset(printedNumber,0x00,sizeof(printedNumber));
	printedEdit.GetWindowTextA(printedNumber,10);
	
	int tmp = atoi(printedNumber)+i;
	memset(printedNumber,0x00,sizeof(printedNumber));
	sprintf(printedNumber,"%d",tmp);
	printedEdit.SetWindowTextA(printedNumber);
}

void CCardManagerDlg::OnResetNumber()
{
	((CEdit*)GetDlgItem(IDC_EDIT_PRINTED_NUMBER))->SetWindowTextA("0");
}

void CCardManagerDlg::OnCbnSelchangeComboPrinters()
{
	CComboBox* printerSelect=(CComboBox*)GetDlgItem(IDC_COMBO_PRINTERS); 
	int index = printerSelect->GetCurSel();
	char printerName[128];
	if(index!=LB_ERR)
	{
		printerSelect->GetLBText(index,printerName);
		Card_SetPrinter(printerName);
	}
}

void CCardManagerDlg::OnBnClickedButtonEject()
{
	Card_EjectCard();
}

std::string CCardManagerDlg::GetCardNo(char* trackInfo)
{
	std::string str(trackInfo);
	int startPos = str.find_first_of(";");
	if(startPos==std::string::npos)
	{
		startPos = -1;
	}
	int endPos = str.find_first_of("=");
	if(endPos==std::string::npos)
	{
		endPos = str.length();
	} else 
	{
		endPos = endPos-1;
	}
	return str.substr(startPos+1,endPos-startPos);
}

void CCardManagerDlg::AddPendingCard(char* expiredDate, char* parValue, char* trackInfo, char* password, char* comment, FILE * logFile)
{
	int count=cardList.GetItemCount(); 
	char rowNo[20] = {0};
	int currentRowNo = 0;
	if(count>0)
	{
		strcpy(rowNo,cardList.GetItemText(count-1,0));
		currentRowNo = atol(rowNo);
	}
	char nextRowNo[20] = {0};
	itoa(currentRowNo+1,nextRowNo,10); 
	cardList.InsertItem(count, nextRowNo);

	std::string cardNo = GetCardNo(trackInfo);
	if(NULL!=logFile)
	{
		char logStr[100];
		memset(logStr,0x00,sizeof(logStr));
		long tmp1 = 0;
		if(NULL!=password){
			tmp1 = atol(password)<<8;
		}
		sprintf(logStr,"%s,%s,%s,%d\n",cardNo.c_str(),expiredDate,parValue,tmp1);
		fputs(logStr,logFile);
	}
	cardList.SetItemText(count,1, cardNo.c_str());
	cardList.SetItemText(count, 2, expiredDate);
	cardList.SetItemText(count, 3, parValue);
	cardList.SetItemText(count, 4, trackInfo);
	cardList.SetItemText(count, 5, password);
	cardList.SetItemText(count, 6, comment);

	UpdateData(false);
}

void CCardManagerDlg::SetUser(User* user)
{
	this->user = user;
}

void CCardManagerDlg::OnReadCard()
{
	char number[10];
	memset(number,0x00,sizeof(number));
	this->numberEdit.GetWindowTextA(number,10);
	int total;
	if(strlen(number)==0)
	{
		//no card number, we use the default value 1
		total = 1;
	} else 
	{
		total = atoi(number);
	}

	if(total==0)
	{
		//the input number is not correct
		AfxMessageBox(_T("请输入正确的卡片张数，值必须为整数"),MB_OK|MB_ICONWARNING   );
		this->numberEdit.SetFocus();
		return;
	} else if(total>200)
	{
		AfxMessageBox(_T("卡片张数必须小于200"),MB_OK|MB_ICONWARNING   );
		this->numberEdit.SetFocus();
		return;
	}

	char expiredDate[200] = {0};
	char parValueString[10] = {0};
	memset(expiredDate,0x00,sizeof(expiredDate));
	memset(parValueString,0x00,sizeof(parValueString));

	this->expiredDateEdit.GetWindowTextA(expiredDate,200);
	this->parValueEdit.GetWindowTextA(parValueString,10);

	int i;
	char trackInfo[50];
	for(i=0;i<total;i++)
	{
		memset(trackInfo,0,sizeof(trackInfo));
		if(Card_ReadTrack(2,trackInfo))
		{
			memset(error,0x00,sizeof(error));
			Card_GetLastError(error);
			AfxMessageBox(_T(error),MB_OK|MB_ICONWARNING   );
			break;
		}
		std::string cardNo = GetCardNo(trackInfo);
		cardNOEdit.SetWindowTextA(cardNo.c_str());
		track2Edit.SetWindowTextA(trackInfo);
		UpdateData(false);
		if(total>1)
		{
			Card_EjectCard();
		}
		AddPendingCard(expiredDate,parValueString,trackInfo,"","");
	}
}

void CCardManagerDlg::OnClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	cardList.SetCheck(pNMItemActivate->iItem, !cardList.GetCheck(pNMItemActivate->iItem));
	*pResult = 0;
}


void CCardManagerDlg::OnRevertAll()
{
	int count=cardList.GetItemCount();  
    for(int i=0;i<count;i++)  
    {  
        cardList.SetCheck(i,!cardList.GetCheck(i));  
    } 
}


void CCardManagerDlg::OnSelectAll()
{
	int count=cardList.GetItemCount();  
    for(int i=0;i<count;i++)  
    {  
        cardList.SetCheck(i,true);  
    } 
}

void CCardManagerDlg::OnStore()
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

	int count=cardList.GetItemCount(); 
	std::list<Card> list;
	for(int i=0;i<count;i++)  
    {
		if(cardList.GetCheck(i))
		{
			Card card;
			strcpy(card.cardNo,cardList.GetItemText(i,1));
			strcpy(card.expiredDate,cardList.GetItemText(i,2));
			strcpy(card.cardFaceValue,cardList.GetItemText(i,3));
			strcpy(card.secondTrack,cardList.GetItemText(i,4));
			strcpy(card.payPassword,cardList.GetItemText(i,5));
			strcpy(card.cardTypeRuleId,cardTypeRule);
			strcpy(card.operateId,this->user->userId);
			list.push_back(card);
		}
    }

	if(list.size()==0)
	{
		AfxMessageBox(_T("请选择记录"),MB_OK|MB_ICONWARNING   );
		return;
	}
	
    Card** cards = new Card*[list.size()];
	Card** pendingList = new Card*[list.size()];
	std::list<Card>::iterator iter;
	int i = 0;
	for(iter=list.begin();iter!=list.end();iter++)
	{
		cards[i++] = &*iter;
	}
	int pendingSize = 0;
	if(Card_StoreCard(cards,list.size(),pendingList,pendingSize))
	{
		memset(error,0x00,sizeof(error));
		Card_GetLastError(error);
		AfxMessageBox(_T(error),MB_OK|MB_ICONWARNING   );
	} else 
	{
		memset(error,0x00,sizeof(error));
		Card_GetLastError(error);
		for(int j=count-1;j>=0;j--)  
		{
			if(cardList.GetCheck(j))
			{
				cardList.DeleteItem(j);	
			}
		}
		int currentTotal = cardList.GetItemCount();
		for(int j=0;j<pendingSize;j++)
		{
			Card * card = pendingList[j];
			AddPendingCard(card->expiredDate,card->cardFaceValue,card->secondTrack,card->payPassword, card->comment,NULL);
			cardList.SetCheck(currentTotal+j);
		}
		AfxMessageBox(_T(error),MB_OK   );
	}
}

void CCardManagerDlg::OnDelete()
{
	int count=cardList.GetItemCount();  
    for(int i=count-1;i>=0;i--)  
    {  
		if(cardList.GetCheck(i))
		{
			cardList.DeleteItem(i);
		}
    }
}


void CCardManagerDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	if(IDYES==AfxMessageBox(_T("请确认是否退出，如果退出，尚未执行入库操作数据将丢失？"),MB_YESNO)){
		CDialogEx::OnClose();
	}
}

void CCardManagerDlg::StoreOneCard(char* cardTypeRule, char* expiredDate, char* parValue, char* trackInfo, char* password, FILE * logFile)
{
	std::list<Card> list;
	Card card;
	strcpy(card.cardNo,GetCardNo(trackInfo).c_str());
	strcpy(card.expiredDate,expiredDate);
	strcpy(card.cardFaceValue,parValue);
	strcpy(card.secondTrack,trackInfo);
	strcpy(card.payPassword,password);
	strcpy(card.cardTypeRuleId,cardTypeRule);
	strcpy(card.operateId,this->user->userId);
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
		AddPendingCard(expiredDate,parValue,trackInfo,password, "未入库");
	} else 
	{
		if(pendingSize > 0)
		{
			for(int j=0;j<pendingSize;j++)
			{
				Card * card = pendingList[j];
				AddPendingCard(card->expiredDate,card->cardFaceValue,card->secondTrack,card->payPassword, card->comment);
			}
		}else
		{
			AddPendingCard(expiredDate,parValue,trackInfo,password, "已成功入库");
		}
	}

	delete [] cards;
	delete [] pendingList;
}


void CCardManagerDlg::OnPrintAndStore()
{
	char expiredDate[200];
	char parValueString[10];
	char number[10];
	char error[100];
	int total;
	int parValue = 0;
	memset(error,0x00,sizeof(error));
	memset(expiredDate,0x00,sizeof(expiredDate));
	memset(parValueString,0x00,sizeof(parValueString));
	memset(number,0x00,sizeof(number));

	this->expiredDateEdit.GetWindowTextA(expiredDate,200);
	this->parValueEdit.GetWindowTextA(parValueString,10);
	this->numberEdit.GetWindowTextA(number,10);

	if(strlen(number)==0)
	{
		//no card number, we use the default value 1
		total = 1;
	} else 
	{
		total = atoi(number);
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

	if(total==0)
	{
		//the input number is not correct
		AfxMessageBox(_T("请输入正确的卡片张数，值必须为整数"),MB_OK|MB_ICONWARNING   );
		return;
	} else if(total>200)
	{
		AfxMessageBox(_T("卡片张数必须小于200"),MB_OK|MB_ICONWARNING   );
		return;
	}

	if(total>1)
	{
		char info[200];
		memset(info,0x00,sizeof(info));
		sprintf(info,"确定要打印 %d 张卡片吗？",total);
		if(AfxMessageBox(_T(info),MB_OKCANCEL|MB_ICONQUESTION)==IDCANCEL)
		{
			return;
		}
	}

	//get print option
	int permission = 0;
	if(dateOption.GetCheck()==1)
	{
		if(strlen(expiredDate)==0)
		{
			AfxMessageBox(_T("请输入有效期"),MB_OK|MB_ICONWARNING   );
			return;
		}
		permission = permission +1;
	}
	if(valueOption.GetCheck()==1)
	{
		if(strlen(parValueString)==0)
		{
			AfxMessageBox(_T("请输入面值"),MB_OK|MB_ICONWARNING   );
			return;
		}
		parValue = atoi(parValueString);
		permission = permission +2;
	}
	if(passwordOption.GetCheck()==1)
	{
		permission = permission +4;
	}
	if(randomOption.GetCheck()==1)
	{
		permission = permission +8;
	}

	if(permission==0)
	{
		AfxMessageBox(_T("请选择打印选项"),MB_OK|MB_ICONWARNING   );
		return;
	}

	int i;
	int printedItem = 0;
	char trackInfo[50];
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

	for(i=0;i<total;i++)
	{
		printedItem = 0;
		memset(trackInfo,0,sizeof(trackInfo));
		memset(password,0,sizeof(password));
		if((permission & 0x04) == 0x04)
		{
			if(Card_GeneratePassword(password))
			{
				AfxMessageBox(_T("生成密码失败"),MB_OK|MB_ICONWARNING   );
				break;
			}
		}
		
		if(Card_ReadTrack(2,trackInfo))
		{
			memset(error,0x00,sizeof(error));
			//Card_GetLastError(error);
			AfxMessageBox(_T("打印机出现问题，请检查打印机状态"),MB_OK|MB_ICONWARNING);
			break;
		}

		std::string cardNo = GetCardNo(trackInfo).c_str();

		if(0==cardNo.length()){
			AfxMessageBox(_T("读卡失败，未读出卡号信息，请检查打印机或卡片"),MB_OK|MB_ICONWARNING   );	
			break;
		}

		cardNOEdit.SetWindowTextA(cardNo.c_str());
		track2Edit.SetWindowTextA(trackInfo);
		
		if(Card_PrintAllWithPrintStatus(expiredDate,parValue,password,"","",permission,printedItem))
		{
			//Card_GetLastError(error);
			if(printedItem > 0)
			{
				StoreOneCard(cardTypeRule,expiredDate,parValueString,trackInfo,password, pFile);
			}
			AfxMessageBox(_T("打印机出现问题，请检查打印机状态"),MB_OK|MB_ICONWARNING);
			break;
		}
		StoreOneCard(cardTypeRule,expiredDate,parValueString,trackInfo,password, pFile);
	}
	
	fclose(pFile); 

	char printedNumber[10];
	memset(printedNumber,0x00,sizeof(printedNumber));
	printedEdit.GetWindowTextA(printedNumber,10);
	
	int tmp = atoi(printedNumber)+i;
	memset(printedNumber,0x00,sizeof(printedNumber));
	sprintf(printedNumber,"%d",tmp);
	printedEdit.SetWindowTextA(printedNumber);
}
