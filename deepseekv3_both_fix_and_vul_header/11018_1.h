#include <string.h>

class Exception {
public:
    Exception(const char* message);
};

class ZlibInStream {
protected:
    char* start;
    char* ptr;
    char* end;
    int bufSize;
    int offset;
    bool underlying;
    bool decompress(bool wait);
public:
    int overrun(int itemSize, int nItems, bool wait);
};