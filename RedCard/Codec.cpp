#include "

std::string Utf8ToAnsi( std::string utf8Str )
{
    char * szU8 = const_cast<char*>( utf8Str.c_str() );
    //UTF8 to Unicode
    //Ԥת�����õ�����ռ�Ĵ�С
    int wcsLen = ::MultiByteToWideChar( CP_UTF8, NULL, szU8, strlen( szU8 ), NULL, 0 );
    //����ռ�Ҫ��'\0'�����ռ䣬MultiByteToWideChar�����'\0'�ռ�
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //ת��
    ::MultiByteToWideChar( CP_UTF8, NULL, szU8, strlen( szU8 ), wszString, wcsLen );
    //������'\0'
    wszString[wcsLen] = '\0';

    // unicode to ansi
    //Ԥת�����õ�����ռ�Ĵ�С������õĺ��������������෴
    int ansiLen = ::WideCharToMultiByte( CP_ACP, NULL, wszString, wcslen( wszString ), NULL, 0, NULL, NULL );
    //ͬ�ϣ�����ռ�Ҫ��'\0'�����ռ�
    char* szAnsi = new char[ansiLen + 1];
    //ת��
    //unicode���Ӧ��strlen��wcslen
    ::WideCharToMultiByte( CP_ACP, NULL, wszString, wcslen( wszString ), szAnsi, ansiLen, NULL, NULL );
    //������'\0'
    szAnsi[ansiLen] = '\0';

    std::string ansiStr( szAnsi );
    if ( wszString )
    delete wszString;
    if ( szAnsi )
    delete szAnsi;
    return ansiStr;
}