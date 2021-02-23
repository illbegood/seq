#ifndef BE8F3390_5DA2_4FA1_8376_5DDD470550B8
#define BE8F3390_5DA2_4FA1_8376_5DDD470550B8

#include <exception>
#include <string>

struct ParserException : public std::exception{
    ParserException(const char *file_, unsigned line_i_, std::string::size_type i_, const char *msg_);
    ~ParserException();
    const char * what () const throw();
private:
    const char* msg;
    const char* file;
    unsigned line_i;
    std::string::size_type i;
    char* _what = nullptr;
};

#endif /* BE8F3390_5DA2_4FA1_8376_5DDD470550B8 */
