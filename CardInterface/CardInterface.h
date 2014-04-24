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

#define IN         //���
#define OUT        //����
#include "Global.h"

#ifdef __cplusplus
extern "C"
{
#endif

	CARDINTERFACE_API void Card_InitHandler(HMODULE *hModule);

    /// @brief ��ʼ��CardInterface��������
	///
    /// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_Init();

	/// @brief ��ȡ��ǰ���ô�ӡ��������ֻ����Evolis��ӡ��
	///
	/// @return     :��ӡ������
	CARDINTERFACE_API int Card_GetPrinterCount();

	/// @brief ��ȡ��ǰ���ô�ӡ������
	///
	/// int printerCount = Card_GetPrinterCount();
	/// char** printers = new char*[printerCount];
	///	for (int i = 0; i < printerCount; ++i)
    ///		{
	///		printers[i] = new char[100];
	///		memset(printers[i],0x00,100);
	///	}
	///
	/// @param[out] :printers ��ӡ����������
	/// @param[in ] :size ��ӡ������
	CARDINTERFACE_API void Card_GetPrinters(OUT char **printers,IN int size);

	CARDINTERFACE_API int Card_SetPrinter(IN char *printerName);

	/// @brief ִ��ָ������
	///
	/// @param[in ] :command ��ִ������
	/// @param[out] :answer ��Ӧ
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_ExecuteCommand(IN const char* command, OUT char* answer);

	/// @brief ��ȡָ���ŵ���Ϣ
	///
	/// @param[in ] :trackNo �ŵ�����(1-3)
	/// @param[out] :trackInfo �ŵ���Ϣ
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_ReadTrack(IN int trackNo, OUT char* trackInfo);

	/// @brief ��ȡ���дŵ���Ϣ
	///
	/// @param[out] :trackInfo1 1�ŵ���Ϣ
	/// @param[out] :trackInfo2 2�ŵ���Ϣ
	/// @param[out] :trackInfo3 3�ŵ���Ϣ
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_ReadAllTrack(OUT char* trackInfo1,OUT char* trackInfo2,OUT char* trackInfo3);

	/// @brief д�ŵ���Ϣ
    ///
    /// @param[in ] :trackNumber �ŵ�
    /// @param[in ] :trackInfo ��Ӧ�ŵ���Ϣ
    /// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_WriteTrack(IN int trackNo,IN char *trackInfo);

	/// @brief ��ִ������ʧ��֮�󣬵��ô˷������ش�����Ϣ
	///
	/// @param[out] :message ������Ϣ
	CARDINTERFACE_API void Card_GetLastError(OUT char *message);

	/// @brief ������Ƭ
	///
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_EjectCard();

	/// @brief ��ӡ��Ƭ��������Ч���ں���ֵ
	///
	/// @param[in ] :expiredDate ��Ч����
	/// @param[in ] :parValue ��ֵ
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_Print(IN char* expiredDate, IN int parValue);

	/// @brief ��ӡ��Ƭ��������Ч���ں���ֵ
	///
	/// @param[in ] :expiredDate ��Ч����
	/// @param[in ] :parValue ��ֵ
	/// @param[in ] :password ��Ƭ����
	/// @param[in ] :permission �����ж���Ҫ��ӡ��Щֵ expiredDate(1)+parValue(2)+password(4)
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_PrintAll(IN char* expiredDate, IN int parValue, IN char* password, int permission);

	/// @brief ��ӡ��Ƭ��������Ч���ں���ֵ
	///
	/// @param[in ] :expiredDate ��Ч����
	/// @param[in ] :parValue ��ֵ
	/// @param[in ] :password ��Ƭ����
	/// @param[in ] :name ����
	/// @param[in ] :level �ͻ��㼶
	/// @param[in ] :permission �����ж���Ҫ��ӡ��Щֵ expiredDate(1)+parValue(2)+password(4)
	/// @param[out ] :printedItem ���ڼ�¼��ǰ�Ѿ���ӡ����Щ�� expiredDate(1)+parValue(2)+password(4)
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_PrintAllWithPrintStatus(IN char* expiredDate, IN int parValue, IN char* password, IN char* name, IN char* level, int permission,OUT int & printedItem);

	/// @brief ��ӡ��Ƭ����
	///
	/// @param[in ] :password ��Ƭ����
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_PrintPassword(IN char* password);

	/// @brief ��¼
	///
	/// @param[in ] :loginName ��¼�û���
	/// @param[in ] :password ��¼����
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_Login(IN char* loginName, IN char* password, OUT User* user);

	/// @brief ���ɿ�����
	///
	/// @param[out] :password ������
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_GeneratePassword(OUT char* password);

	/// @brief ��ȡ������
	///
	/// @param[out] :password ����������
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_ReadCardTypeRules(OUT int& size);

	/// @brief ��ȡ�Ѷ�������
	///
	/// @param[out] :ids ������ID
	/// @param[out] :names ����������
	/// @param[in ] :password ����������
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_GetCardTypeRules(OUT char **ids, OUT char **names, IN int size);

	CARDINTERFACE_API int Card_StoreCard(IN Card **cards, int size, OUT Card ** pendingList,OUT int& pendingSize);

	CARDINTERFACE_API int Card_StorePsamCard(IN Psam *psam);

	/// @brief ��ȡ��Ƭ����Կ
	///
	/// @param[out] :mainKey ����Կ
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_GetMainKey(OUT char* mainKey);

	/// @brief ��ȡPSAM����
	///
	/// @param[out] :cardNo PSAM����
	/// @return     :0 ��ʾ�ɹ�
	CARDINTERFACE_API int Card_GeneratePsamCardNo(OUT char* cardNo);

#ifdef __cplusplus
}
#endif