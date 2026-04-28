#include <string>
#include <list>
#include <cstdio>
#include <cstdarg>

class DataItemFormat;
class Tracer;
class CAsterixFormat;

class DataItemFormatExplicit {
public:
    std::list<DataItemFormat*> m_lSubItems;
    bool getText(std::string &strResult, std::string &strHeader, const unsigned int formatType,
                 unsigned char *pData, long nLength);
};

class DataItemFormat {
public:
    virtual int getLength(unsigned char *pData) = 0;
    virtual bool getText(std::string &tmpStr, std::string &strHeader, const unsigned int formatType,
                         unsigned char *pData, int bodyLength) = 0;
};

class Tracer {
public:
    static void Error(const char* format, ...);
};

class CAsterixFormat {
public:
    enum {
        EJSON,
        EJSONH,
        EJSONE
    };
};

static inline std::string format(const char* fmt, ...) {
    char buf[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    return std::string(buf);
}