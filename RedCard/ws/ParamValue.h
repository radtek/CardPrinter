/*
  参数值

  Author:       yiming.you
	Version:      1.0
	Create Date:  2012-06-15
	Review Date:
*/
#ifndef ParamValue_H_
#define ParamValue_H_

#include <string>

enum ParamType
{
    nullValue = 0, ///< 'null' value
    intValue,      ///< signed integer value
    uintValue,     ///< unsigned integer value
    realValue,     ///< double value
    stringValue,   ///< UTF-8 string value
    booleanValue,  ///< bool value
    arrayValue,    ///< array value (ordered list)
    objectValue    ///< object value (collection of name/value pairs).
};

class ParamValue
{
public:
    ParamValue( int value );

    ParamValue( double value );

    ParamValue( const char *value );

    ParamValue( const ParamValue &other );

    ~ParamValue();

    std::string asString() const;

    int asInt() const;

    double asDouble() const;

    ParamType type() const;

    char* DuplicateStringValue( const char *value, unsigned int length = -1 );

    ParamValue &operator=( const ParamValue &other );

    void swap( ParamValue &other );

private:
    union ValueHolder  //暂时只支持以下三种
    {
    int int_;
    double real_;
    char *string_;
    } value_;

    ParamType type_ : 8;
		int allocated_ : 1;
};

#endif