#ifndef APP_CONTEXT_H_
#define APP_CONTEXT_H_

#include "Config.h"

extern "C" IMAGE_DOS_HEADER  __ImageBase; // DLL HMODULE

#define CFG_NAME "RedCard.cfg"                         //�����ļ�����
#define SERVICE_URL "serviceURL"
#define DB_URL "dbURL"

class AppContext
{
    enum { MAX_PATH_SIZE = 1024 };

public:
    AppContext();

    ~AppContext();

    /// @brief �����湤��������ʼ��
    ///
    /// @return     :0 ��ʾ�ɹ�
    int InitContext();

    /// @brief ��ʼ����־����
    ///
    void InitLog();

    /// @brief ��ȡ�����ļ�
    ///
    /// @return     :0 ��ʾ�ɹ�
    int AppContext::InitConfig();

	Config config;  //����ϵͳ���ò�����

protected:

    /// @brief ��ȡ�ļ��ľ���·��
    ///
    /// @param[in ] :fileName �ļ���
    /// @param[out] :path �ļ�����·��
    /// @return     :0 ��ʾ�ɹ�
    void GetAbsolutePath( char* fileName, char* path );

    /// @brief ��ȡ��ǰdll����Ŀ¼��ȫ·��
    ///
    /// @param[out] :path ��ǰdllȫ·��
    /// @return     :0 ��ʾ�ɹ�
    void AppContext::GetCurrentDirectory( char *path );

    char currentPath[MAX_PATH_SIZE];   //dll����Ŀ¼��ȫ·��

};

#endif
