#include <stddef.h>

namespace QTC {
    void TC(const char*, const char*);
    void TC(const char*, const char*, int);
}

class Pl_ASCIIHexDecoder {
public:
    void flush();
    void write(const unsigned char*, size_t);
    Pl_ASCIIHexDecoder* getNext();
private:
    int pos;
    char inbuf[3];
};