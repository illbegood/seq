#include <cstring>

#include "parserexception.hpp"

ParserException::ParserException(const char *file_, unsigned line_i_, std::string::size_type i_, const char *msg_)
: file(file_), line_i(line_i_), i(i_), msg(msg_)
{
    std::string str;
    str += "Error reading file `";
    str += file;
    str += "`(";
    str += std::to_string(line_i); 
    str += ",";
    str += std::to_string(i);
    str += "): ";
    str += msg;
    _what = new char[str.length() + 1];
    sprintf(_what, "%s", str.c_str());
}

const char * ParserException::what () const throw(){
    return _what;
}
ParserException::~ParserException() 
{
    if (_what) delete(_what);
}
