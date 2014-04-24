#include "stdafx.h"
#include "AppContext.h"
#include "Global.h"

AppContext::AppContext()
{
}

AppContext::~AppContext()
{
}

int AppContext::InitContext()
{
    int ret;

    //º”‘ÿ≈‰÷√Œƒº˛
    ret = InitConfig();
    if ( ret )
    {
    return ret;
    }

    return SUCCESS;
}

void AppContext::GetCurrentDirectory( char *path )
{
    memset( currentPath, 0, sizeof currentPath );

    HMODULE dll = reinterpret_cast <HMODULE> ( &__ImageBase );
    ::GetModuleFileName( dll, currentPath, MAX_PATH_SIZE );
    char * p = strrchr( currentPath, '\\' );
    if ( p )
    {
    *p = '\0';
    }

    if ( path )
    {
    memcpy( path, currentPath, sizeof( currentPath ) );
    }
}

void AppContext::GetAbsolutePath( char* fileName, char* path )
{
    memset( path, 0, sizeof( path ) );
    sprintf( path, "%s\\%s", currentPath, fileName );
}

int AppContext::InitConfig()
{
    GetCurrentDirectory( NULL );

    char cfgFile[MAX_PATH_SIZE];
    GetAbsolutePath( CFG_NAME, cfgFile );
	this->config.ReadFile( cfgFile );
	
    return SUCCESS;
}

void AppContext::InitLog()
{
}
