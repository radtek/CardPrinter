#include "ParamValue.h"

ParamValue::ParamValue( int value )
{
    this->type_ = intValue;
    this->allocated_ = 0;
    value_.int_ = value;
}

ParamValue::ParamValue( double value )
{
    this->type_ = realValue;
    this->allocated_ = 0;
    value_.real_ = value;
}

ParamValue::ParamValue( const char *value )
{
    this->type_ = stringValue;
    this->allocated_ = 1;
    value_.string_ = DuplicateStringValue( value );
}

ParamValue::ParamValue( const ParamValue &other )
{
    this->type_ = other.type_;
    switch ( type_ )
    {
    case intValue:
    case realValue:
    this->allocated_ = 0;
    value_ = other.value_;
    break;
    case stringValue:
    if ( other.value_.string_ )
    {
        this->allocated_ = 1;
        value_.string_ = DuplicateStringValue( other.value_.string_ );
    }
    else
        value_.string_ = 0;
    break;
    }
}

ParamValue::~ParamValue()
{
    switch ( type_ )
    {
    case intValue:
    case realValue:
    case stringValue:
    if ( this->allocated_ )
        if ( value_.string_ )
        free( value_.string_ );
    break;
    }
}

std::string ParamValue::asString() const
{
    switch ( type_ )
    {
    case stringValue:
    return value_.string_ ? value_.string_ : "";
    case intValue:
    case realValue:
    default:
    return "";
    }
}

int ParamValue::asInt() const
{
    switch ( type_ )
    {
    case intValue:
    return value_.int_;
    case realValue:
    case stringValue:
    default:
    return 0;
    }
}

double ParamValue::asDouble() const
{
    switch ( type_ )
    {
    case realValue:
    return value_.real_;
    case intValue:
    case stringValue:
    default:
    return 0;
    }
}

ParamType ParamValue::type() const
{
    return type_;
}

char* ParamValue::DuplicateStringValue( const char *value, unsigned int length )
{
    if ( length == -1 )
    length = ( unsigned int )strlen( value );
    char *newString = static_cast<char *>( malloc( length + 1 ) );
    memcpy( newString, value, length );
    newString[length] = 0;
    return newString;
}

ParamValue& ParamValue::operator=( const ParamValue &other )
{
    ParamValue temp( other );
    swap( temp );
    return *this;
}

void ParamValue::swap( ParamValue &other )
{
    ParamType temp = type_;
    type_ = other.type_;
    other.type_ = temp;
    std::swap( value_, other.value_ );
    int temp2 = this->allocated_;
    this->allocated_ = other.allocated_;
    other.allocated_ = temp2;
}