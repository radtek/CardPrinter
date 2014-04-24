/*
  CardEngine����ӿ�
*/
#ifdef CARDENGINE_EXPORTS
#define CARDENGINE_API __declspec(dllexport)
#else
#define CARDENGINE_API __declspec(dllimport)
#endif
#include "Header.h"

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief ��ʼ��CardInterface��������
	///
    /// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_Init();

	/// @brief ���CardEngine�汾��
	///
	/// @return     :CardEngine�汾��
	CARDENGINE_API const char* ENG_GetVersion();

	/// @brief ���CardEngine��������
	///
	/// @return     :CardEngine��������
	CARDENGINE_API const char* ENG_GetCompiledDate();

	/// @brief ��ʼ��ͨѶ�˿�
	///
	/// ��ʹ�ö������Կ����в���֮ǰ�������ȵ��ø÷���
	/// @param[in ] :port �˿ںţ�ȡֵΪ0-19����ʾ����1-20��Ϊ100ʱ��ʾUSB��ͨѶ
	/// @param[in ] :baud ͨѶ������9600��115200������USB��ͨѶʱ����������Ч
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_OpenPort( int port, int baud );

	/// @brief �رն˿�
	///
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ClosePort();

	/// @brief ����������
	///
	/// һ��ִ��ĳ������ɹ���ʱ�򣬿��Ե��ø÷�����ʾ�û������ɹ�
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API void ENG_Beep();

	/// @brief ����������ʱ����
	///
	/// ����ʱ���Beep��һ��
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API void ENG_BeepError();

	/// @brief Ѱ��
	///
	/// ������ֵ�ο�typedef enum {MFCARD = 1, CPUCARD, FIXCARD, PSAM, KEYCARD, SIMCARD} CARD_TYPE
	/// @param[out] :phyid ������ID
	/// @param[out] :cardType ������
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_RequestCard( char *phyid, int& cardType );

	/// @brief ��ȡ��������Ϣ
	///
	/// @param[in ] :errorMsg ������Ϣ
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API char* ENG_GetLastErrorMsg( char *errorMsg );

	/// @brief ��ֹ�Ըÿ�����
	///
	/// �ڶԿ����в�����Ϻ�ִ��ENG_Halt();��ÿ�����HALTģʽ
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_Halt();

	/// @brief �����ֶζ�ģʽ
	///
	/// @param[in ] :fieldId �ֶ�����
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_SetFieldReadMode( int fieldId );

	/// @brief ����
	/// ��ȡ���е���Ϣ���÷�����:
	///      ENG_SetFieldReadMode(field1);
	///      ENG_SetFieldReadMode(field2);
	///      ......
	///      ENG_ReadCard();
	///      ENG_GetFieldValue(field1,field1Vlaue);
	///      ENG_GetFieldValue(field2,field2Vlaue);
	///      ......
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ReadCard();

	/// @brief �����û���
	///
	/// ���û����ָ�������״̬
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_RecycleUserCard();

	/// @brief �û�����ʼ��
	///
	/// ��ʼ���û����и�����������
	/// @param[in ] :phyid ������ID
	/// @param[in ] :showCardNo ��ʾ����
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_InitUserCard( const char *phyid, const char *showCardNo );

	/// @brief ��������ֶεĶ�дģʽ
	///
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ClearAllFieldAllMode();

	/// @brief д��
	/// ����Ϣд�뿨�У��÷�����:
	///      ENG_SetFieldValue(field1,field1value);
	///      ENG_SetFieldValue(field2,field2value);
	///      ......
	///      ENG_WriteCard();
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_WriteCard ( const char *phyid = 0 );

	/// @brief �����ֶ�дģʽ
	///
	/// ����ENG_SetFieldValue����ʱ�����Զ����ø÷���
	/// @param[in ] :fieldId �ֶ�����
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_SetFieldWriteMode( int fieldId );

	/// @brief ��ȡ�ֶ�ֵ
	///
	/// ����֮����ø÷������������Ϊ��ģʽ���ֶε�ֵ
	/// @param[in ] :fieldId �ֶ�����
	/// @param[out] :fieldValue �ֶ�ֵ
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_GetFieldValue( int fieldId, char *fieldValue );

	/// @brief ����д�ֶ�ֵ
	///
	/// @param[in ] :fieldId �ֶ�����
	/// @param[in ] :fieldValue �ֶ�ֵ
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_SetFieldValue( int fieldId, const char *fieldValue );

	/// @brief �����ֶζ�дģʽ
	///
	/// @param[in ] :fieldId �ֶ�����
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_SetFieldAllMode( int fieldId );

	/// @brief ����ֶζ�ģʽ
	///
	/// @param[in ] :fieldId �ֶ�����
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ClearFieldReadMode( int fieldId );

	/// @brief ����ֶ�дģʽ
	///
	/// @param[in ] :fieldId �ֶ�����
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ClearFieldWriteMode( int fieldId );

	/// @brief ����ֶ�����ģʽ
	///
	/// @param[in ] :fieldId �ֶ�����
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ClearFieldAllMode( int fieldId );

	/// @brief ��������ֶεĶ�ģʽ
	///
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ClearAllFieldReadMode();

	/// @brief ��������ֶε�дģʽ
	///
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ClearAllFieldWriteMode();

	/// @brief ��ȡ�ֶ�ֵ
	///
	/// ���ø÷�����ȡ�ֶε�ֵ
	/// @param[in ] :fieldId �ֶ�����
	/// @param[out] :fieldValue �ֶ�ֵ
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ReadFieldValue( int fieldId, char *fieldValue );

	/// @brief д�ֶ�
	///
	/// @param[in ] :fieldId �ֶ�����
	/// @param[in ] :fieldValue �ֶ�ֵ
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_WriteFieldValue( int fieldId, const char *fieldValue );

	/// @brief ��ȡ���źͶ��ŵ���Ϣ
	///
	/// ���ø÷�����ȡ�ֶε�ֵ
	/// @param[out] :cardNo ����
	/// @param[out] :secondTrack ���ŵ���Ϣ
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ReadCardNoAndSecondTrack( char *cardNo,char *secondTrack );

	/// @brief ����Ҫ������psam����
	///
	/// @param[in ] :slot psam������1�� 2�� 3 ��ΪSAM1(����)��SAM2��SAM3
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_SetPsamSlot( int slot );

	/// @brief PSAM���ϵ縴λ
	///
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ResetPsam();

	/// @brief ��ȡPSAM���ն˱��
	///
	/// @param[out] :termNo psam���ն˱��
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ReadPsamTermNo( char *termNo );

	/// @brief ����PSAMK��
	///
	/// @param[in ] :psamCard psam����Ϣ
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_InitPsamCard( PsamCard* psamCard );

	/// @brief ����PSAM��
	///
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_RecyclePsamCard();

	/// @brief ��ȡPSAM����Ϣ
	///
	/// @param[out] :psamCard psam����Ϣ
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_ReadPsamCard( PsamCard* psamCard );

	/// @brief ���³�ʼ����Կ
	///
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_UpdateCardKeys();

	/// @brief ���ø���Կ
	///
	/// @return     :0 ��ʾ�ɹ�
	CARDENGINE_API int ENG_SetMainKey(char mainKey[33]);
 
#ifdef __cplusplus
}
#endif
