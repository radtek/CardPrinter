#include "Codec.h"
#include <windows.h>
#include "json.h"
using namespace Json;
#include "ParamValue.h"

std::string Utf8ToAnsi( std::string utf8Str )
{
	return Utf8ToAnsi(utf8Str.c_str(),utf8Str.length());
}

std::string Utf8ToAnsi( const char* szU8, int len )
{
    //UTF8 to Unicode
    //预转换，得到所需空间的大小
    int wcsLen = ::MultiByteToWideChar( CP_UTF8, NULL, szU8, len, NULL, 0 );
    //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //转换
    ::MultiByteToWideChar( CP_UTF8, NULL, szU8, len, wszString, wcsLen );
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

void AddParameter( WSRequestData &request, std::string key, ParamValue paramValue )
{
    if ( request.entities.size() == 0 )
    {
		std::map<std::string, ParamValue> entity;
		request.entities.push_back( entity );
    }
    std::map<std::string, ParamValue> *entity = &( request.entities.back() );
    entity->insert( std::make_pair<std::string, ParamValue>( key, paramValue ) );
}

void AddParameter( WSRequestData &request, std::string key, const char* value )
{
    ParamValue paramValue( value );
    AddParameter( request, key, paramValue );
}

void AddParameter( WSRequestData &request, std::string key, int value )
{
    ParamValue paramValue( value );
    AddParameter( request, key, paramValue );
}

void AddParameter( WSRequestData &request, std::string key, double value )
{
    ParamValue paramValue( value );
    AddParameter( request, key, paramValue );
}

void AddEntity( WSRequestData &request, std::map<std::string, ParamValue> entity )
{
    request.entities.push_back( entity );
}

std::string Encode( WSRequestData &request )
{
    Json::Value root;
    Json::Value params;

    root["pageNo"] = request.pageNo;
    root["pageSize"] = request.pageSize;

    std::list<std::map<std::string, ParamValue>>::iterator entityIter = request.entities.begin();
	int i=0;
    for ( ; entityIter != request.entities.end() ; ++entityIter )
    {
    Json::Value entity;
    std::map<std::string, ParamValue>::iterator paramIter = entityIter->begin();
    for ( ; paramIter != entityIter->end(); ++paramIter )
    {
        ParamType paramType = paramIter->second.type();
        switch ( paramType )
        {
        case Json::intValue:
        entity[paramIter->first] = paramIter->second.asInt();
        break;
        case Json::realValue:
        entity[paramIter->first] = paramIter->second.asDouble();
        break;
        case Json::stringValue:
        entity[paramIter->first] = paramIter->second.asString();
        break;
        default:
        entity[paramIter->first] = "";
        }
    }
    params[i++] = entity;
    }

    root["content"] = params;

    return root.toStyledString();
}

bool Decode( std::string src, WSResponseData &response )
{
    Json::Reader reader;
    Json::Value root;
    Json::Value head;
    Json::Value body;
    Json::Value node;
    std::string ansiStr = Utf8ToAnsi( src );
    if ( reader.parse( ansiStr, root ) )
    {
		body = root["content"];
		std::string s = body.toStyledString();
		response.isError = root["isError"].asBool();
		response.errorCode = root["errorCode"].asInt();
		response.message = root["message"].asString();

		if(body.isArray())
		{
			for (int i=0; i<body.size(); i++)
			{
				   std::map<std::string, ParamValue> entity;
				   Json::Value item = body[i];
				   Json::Value::Members members = item.getMemberNames();
				   int size = members.size();
				   for ( int i = 0; i < size; i++ )
				   {
						node = item[members[i]];
						ValueType type = node.type();
						ParamValue* paramValue;
						switch ( type )
						{
						case Json::intValue:
						paramValue = new ParamValue( node.asInt() );
						case Json::realValue:
						paramValue = new ParamValue( node.asDouble() );
						case Json::stringValue:
						paramValue = new ParamValue( node.asString().c_str() );
						break;
						default:
						continue;
						}
						entity.insert( std::make_pair<std::string, ParamValue>( members[i], *paramValue ) );
						if ( paramValue )
						delete paramValue;
					}
				   response.entities.push_back( entity );
			  }
		} else 
		{
			Json::Value::Members members = body.getMemberNames();
			std::map<std::string, ParamValue> entity;
			int size = members.size();
			for ( int i = 0; i < size; i++ )
			{
				node = body[members[i]];
				ValueType type = node.type();
				ParamValue* paramValue;
				switch ( type )
				{
				case Json::intValue:
				paramValue = new ParamValue( node.asInt() );
				case Json::realValue:
				paramValue = new ParamValue( node.asDouble() );
				case Json::stringValue:
				paramValue = new ParamValue( node.asString().c_str() );
				break;
				default:
				continue;
				}
				entity.insert( std::make_pair<std::string, ParamValue>( members[i], *paramValue ) );
				if ( paramValue )
				delete paramValue;
			}
			response.entities.push_back( entity );
		}
    }
    else
    {
		return false;
    }

    return true;
}

ParamValue* GetParameter( std::map<std::string, ParamValue>& map, const char* key )
{
	std::map<std::string, ParamValue>::iterator iter;
    iter = map.find(key);
	if(iter != map.end())
	{
		return &iter->second;
	}
	return NULL;
}