#include <cstring>
#include <string>

typedef unsigned char byte;
extern const char xmlHeader[];
extern const int xmlHdrCnt;

class BasicIo {
public:
    enum SeekPos { beg, cur, end };
    virtual ~BasicIo() {}
    virtual bool eof() const = 0;
    virtual int error() const = 0;
    virtual void read(byte* buf, long rcount) = 0;
    virtual void seek(long offset, SeekPos whence) = 0;
};