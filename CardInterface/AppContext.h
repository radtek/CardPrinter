#ifndef APP_CONTEXT_H_
#define APP_CONTEXT_H_

#include "Config.h"

extern "C" IMAGE_DOS_HEADER  __ImageBase; // DLL HMODULE

#define CFG_NAME "RedCard.cfg"                         //配置文件名称
#define SERVICE_URL "serviceURL"
#define DB_URL "dbURL"

class AppContext
{
    enum { MAX_PATH_SIZE = 1024 };

public:
    AppContext();

    ~AppContext();

    /// @brief 卡引擎工作环境初始化
    ///
    /// @return     :0 表示成功
    int InitContext();

    /// @brief 初始化日志配置
    ///
    void InitLog();

    /// @brief 读取配置文件
    ///
    /// @return     :0 表示成功
    int AppContext::InitConfig();

	Config config;  //加载系统配置参数类

protected:

    /// @brief 获取文件的绝对路径
    ///
    /// @param[in ] :fileName 文件名
    /// @param[out] :path 文件绝对路径
    /// @return     :0 表示成功
    void GetAbsolutePath( char* fileName, char* path );

    /// @brief 获取当前dll所在目录的全路径
    ///
    /// @param[out] :path 当前dll全路径
    /// @return     :0 表示成功
    void AppContext::GetCurrentDirectory( char *path );

    char currentPath[MAX_PATH_SIZE];   //dll所在目录的全路径

};

#endif
