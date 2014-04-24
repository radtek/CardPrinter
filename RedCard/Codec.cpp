#include "

std::string Utf8ToAnsi( std::string utf8Str )
{
    char * szU8 = const_cast<char*>( utf8Str.c_str() );
    //UTF8 to Unicode
    //预转换，得到所需空间的大小
    int wcsLen = ::MultiByteToWideChar( CP_UTF8, NULL, szU8, strlen( szU8 ), NULL, 0 );
    //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //转换
    ::MultiByteToWideChar( CP_UTF8, NULL, szU8, strlen( szU8 ), wszString, wcsLen );
    //最后加上'\0'
    wszString[wcsLen] = '\0';

    // unicode to ansi
    //预转换，得到所需空间的大小，这次用的函数和上面名字相反
    int ansiLen = ::WideCharToMultiByte( CP_ACP, NULL, wszString, wcslen( wszString ), NULL, 0, NULL, NULL );
    //同上，分配空间要给'\0'留个空间
    char* szAnsi = new char[ansiLen + 1];
    //转换
    //unicode版对应的strlen是wcslen
    ::WideCharToMultiByte( CP_ACP, NULL, wszString, wcslen( wszString ), szAnsi, ansiLen, NULL, NULL );
    //最后加上'\0'
    szAnsi[ansiLen] = '\0';

    std::string ansiStr( szAnsi );
    if ( wszString )
    delete wszString;
    if ( szAnsi )
    delete szAnsi;
    return ansiStr;
}