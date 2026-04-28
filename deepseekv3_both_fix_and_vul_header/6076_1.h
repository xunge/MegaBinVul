#include <string.h>

namespace QTC {
    class TC {
    public:
        TC(const char*, const char*);
        TC(const char*, const char*, int);
    };
}

class Pl_ASCII85Decoder {
protected:
    unsigned char inbuf[5];
    int pos;
    virtual Pl_ASCII85Decoder* getNext();
    virtual void write(unsigned char*, int);
public:
    void flush();
};