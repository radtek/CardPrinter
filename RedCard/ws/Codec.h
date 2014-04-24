#ifndef CODEC_H_
#define CODEC_H_

#include <string>
#include <map>
#include <list>
#include "ParamValue.h"

typedef struct tagWSRequesetData
{
    std::string tradeCode;
    std::string description;
    std::string date;
    int pageNo;                         //����ҳ��
    int pageSize;                       //ÿҳ��¼��
    std::list<std::map<std::string, ParamValue>> entities; //�������
} WSRequestData;

typedef struct tagWSResponseData
{
    bool isError;
    int errorCode;
    std::string message;
    std::list<std::map<std::string, ParamValue>> entities; //���ؽ����
} WSResponseData;

std::string Utf8ToAnsi( std::string utf8Str );

std::string Utf8ToAnsi( const char* szU8, int len );

void AddParameter( WSRequestData &request, std::string key, ParamValue paramValue );

void AddParameter( WSRequestData &request, std::string key, const char* value );

void AddParameter( WSRequestData &request, std::string key, int value );

void AddParameter( WSRequestData &request, std::string key, double value );

void AddEntity( WSRequestData &request, std::map<std::string, ParamValue> entity );

std::string Encode( WSRequestData &request);
bool Decode( char* src, WSResponseData &response );
bool Decode( std::string src, WSResponseData &response);

ParamValue* GetParameter( std::map<std::string, ParamValue>& map, const char* key );

#endif //CODEC_H_