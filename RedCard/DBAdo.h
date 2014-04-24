#ifndef DBADO_H_
#define DBADO_H_

#import "C:\Program Files\Common Files\System\ADO\msado15.dll"	rename_namespace("ADOWE") rename("EOF","EndOfFile")
using namespace ADOWE;

#include "StdAfx.h"

#include "math.h"
#include <string>
using namespace std;

class CDBAdo
{
public:
	_CommandPtr		m_ptrCommand;		//命令对象
	_RecordsetPtr	m_ptrRecordset;		//记录集对象
	_ConnectionPtr	m_ptrConnection;	//数据库对象

	string			m_strConnect,		//连接字符串
					m_strErrorMsg;		//错误信息

public:
	CDBAdo(void);
	~CDBAdo(void);

	void	DetectResult(HRESULT hResult);
	void	RecordErrorMsg(_com_error comError);
	const char*	GetLastError(){return m_strErrorMsg.c_str();}

	bool	CreateInstance();
	bool	SetConnectionString(const char* strDriver, const char* strIP, WORD wPort, const char* strCatalog, const char* strUserID, const char* strPassword);
	bool	SetConnectionString(const char* connectionString);
	bool	OpenConnection();
	bool	CloseConnection();
	bool	IsConnecting();

	void	ClearAllParameters();
	void	AddParamter(LPCTSTR lpcsrName, ADOWE::ParameterDirectionEnum Direction, ADOWE::DataTypeEnum Type, long lSize, _variant_t & vtValue);
	void	SetSPName(LPCTSTR lpcsrSPName);
	bool	ExecuteCommand(bool bIsRecordset);
	bool	Execute(LPCTSTR lpcsrCommand);
	long	GetReturnValue();

	bool	OpenRecordset(char* szSQL);
	bool	CloseRecordset();
	bool	IsRecordsetOpened();
	bool	IsEndRecordset();
	void	MoveToNext();
	void	MoveToFirst();
	void	MoveToLast();
	long	GetRecordCount();

	bool	GetFieldValue(LPCTSTR lpcsrFieldName, WORD& wValue);
	bool	GetFieldValue(LPCTSTR lpcsrFieldName, string& strValue);
	bool	GetFieldValue(LPCTSTR lpcsrFieldName, INT& nValue);
	bool	GetFieldValue(LPCTSTR lpcsrFieldName, BYTE& bValue);
	bool	GetFieldValue(LPCTSTR lpcsrFieldName, LONG& lValue);
	bool	GetFieldValue(LPCTSTR lpcsrFieldName, DWORD& dwValue);
	bool	GetFieldValue(LPCTSTR lpcsrFieldName, UINT& ulValue);
	bool	GetFieldValue(LPCTSTR lpcsrFieldName, DOUBLE& dbValue);
	bool	GetFieldValue(LPCTSTR lpcsrFieldName, __int64& llValue);
	//bool	GetFieldValue(LPCTSTR lpcsrFieldName, COleDateTime& Time);
	bool	GetFieldValue(LPCTSTR lpcsrFieldName, bool& bValue);
};

#endif // DBADO_H_