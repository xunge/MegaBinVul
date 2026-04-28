#include <cstring>
#include <cstdint>

typedef unsigned char byte;

namespace Exiv2 {
    enum ErrorCode { kerCorruptedMetadata };
}

class BasicIo {
public:
    virtual ~BasicIo() {}
    virtual long size() const = 0;
    virtual int seek(long offset, int whence) = 0;
    virtual long read(byte* buf, long rcount) = 0;
    virtual int readOrThrow(byte* buf, long rcount, Exiv2::ErrorCode err) = 0;
    enum SeekPos { cur };
};

void readOrThrow(BasicIo& io, byte* buf, long len, Exiv2::ErrorCode err) {
    io.readOrThrow(buf, len, err);
}