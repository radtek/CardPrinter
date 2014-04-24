// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CARDINTERFACE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CARDINTERFACE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CARDINTERFACE_EXPORTS
#define CARDINTERFACE_API __declspec(dllexport)
#else
#define CARDINTERFACE_API __declspec(dllimport)
#endif

#define IN         //入参
#define OUT        //出参
#include "Global.h"

#ifdef __cplusplus
extern "C"
{
#endif

	CARDINTERFACE_API void Card_InitHandler(HMODULE *hModule);

    /// @brief 初始化CardInterface工作环境
	///
    /// @return     :0 表示成功
	CARDINTERFACE_API int Card_Init();

	/// @brief 获取当前可用打印机数量，只包含Evolis打印机
	///
	/// @return     :打印机数量
	CARDINTERFACE_API int Card_GetPrinterCount();

	/// @brief 获取当前可用打印机名称
	///
	/// int printerCount = Card_GetPrinterCount();
	/// char** printers = new char*[printerCount];
	///	for (int i = 0; i < printerCount; ++i)
    ///		{
	///		printers[i] = new char[100];
	///		memset(printers[i],0x00,100);
	///	}
	///
	/// @param[out] :printers 打印机名称数组
	/// @param[in ] :size 打印机数量
	CARDINTERFACE_API void Card_GetPrinters(OUT char **printers,IN int size);

	CARDINTERFACE_API int Card_SetPrinter(IN char *printerName);

	/// @brief 执行指定命令
	///
	/// @param[in ] :command 待执行命令
	/// @param[out] :answer 响应
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_ExecuteCommand(IN const char* command, OUT char* answer);

	/// @brief 读取指定磁道信息
	///
	/// @param[in ] :trackNo 磁道索引(1-3)
	/// @param[out] :trackInfo 磁道信息
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_ReadTrack(IN int trackNo, OUT char* trackInfo);

	/// @brief 读取所有磁道信息
	///
	/// @param[out] :trackInfo1 1磁道信息
	/// @param[out] :trackInfo2 2磁道信息
	/// @param[out] :trackInfo3 3磁道信息
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_ReadAllTrack(OUT char* trackInfo1,OUT char* trackInfo2,OUT char* trackInfo3);

	/// @brief 写磁道信息
    ///
    /// @param[in ] :trackNumber 磁道
    /// @param[in ] :trackInfo 对应磁道信息
    /// @return     :0 表示成功
	CARDINTERFACE_API int Card_WriteTrack(IN int trackNo,IN char *trackInfo);

	/// @brief 在执行命令失败之后，调用此方法返回错误信息
	///
	/// @param[out] :message 错误信息
	CARDINTERFACE_API void Card_GetLastError(OUT char *message);

	/// @brief 弹出卡片
	///
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_EjectCard();

	/// @brief 打印卡片，包括有效日期和面值
	///
	/// @param[in ] :expiredDate 有效日期
	/// @param[in ] :parValue 面值
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_Print(IN char* expiredDate, IN int parValue);

	/// @brief 打印卡片，包括有效日期和面值
	///
	/// @param[in ] :expiredDate 有效日期
	/// @param[in ] :parValue 面值
	/// @param[in ] :password 卡片密码
	/// @param[in ] :permission 用于判定需要打印哪些值 expiredDate(1)+parValue(2)+password(4)
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_PrintAll(IN char* expiredDate, IN int parValue, IN char* password, int permission);

	/// @brief 打印卡片，包括有效日期和面值
	///
	/// @param[in ] :expiredDate 有效日期
	/// @param[in ] :parValue 面值
	/// @param[in ] :password 卡片密码
	/// @param[in ] :name 姓名
	/// @param[in ] :level 客户层级
	/// @param[in ] :permission 用于判定需要打印哪些值 expiredDate(1)+parValue(2)+password(4)
	/// @param[out ] :printedItem 用于记录当前已经打印了哪些项 expiredDate(1)+parValue(2)+password(4)
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_PrintAllWithPrintStatus(IN char* expiredDate, IN int parValue, IN char* password, IN char* name, IN char* level, int permission,OUT int & printedItem);

	/// @brief 打印卡片密码
	///
	/// @param[in ] :password 卡片密码
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_PrintPassword(IN char* password);

	/// @brief 登录
	///
	/// @param[in ] :loginName 登录用户名
	/// @param[in ] :password 登录密码
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_Login(IN char* loginName, IN char* password, OUT User* user);

	/// @brief 生成卡密码
	///
	/// @param[out] :password 卡密码
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_GeneratePassword(OUT char* password);

	/// @brief 读取卡规则
	///
	/// @param[out] :password 卡规则数量
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_ReadCardTypeRules(OUT int& size);

	/// @brief 获取已读卡规则
	///
	/// @param[out] :ids 卡规则ID
	/// @param[out] :names 卡规则名称
	/// @param[in ] :password 卡规则数量
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_GetCardTypeRules(OUT char **ids, OUT char **names, IN int size);

	CARDINTERFACE_API int Card_StoreCard(IN Card **cards, int size, OUT Card ** pendingList,OUT int& pendingSize);

	CARDINTERFACE_API int Card_StorePsamCard(IN Psam *psam);

	/// @brief 获取卡片根密钥
	///
	/// @param[out] :mainKey 根密钥
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_GetMainKey(OUT char* mainKey);

	/// @brief 获取PSAM卡号
	///
	/// @param[out] :cardNo PSAM卡号
	/// @return     :0 表示成功
	CARDINTERFACE_API int Card_GeneratePsamCardNo(OUT char* cardNo);

#ifdef __cplusplus
}
#endif