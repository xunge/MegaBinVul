#include <iostream>
#include <cstdint>
#include <string>
#include <cerrno>
#include <cstring>

namespace Exiv2 {

typedef unsigned char byte;

enum ErrorCode {
    kerDataSourceOpenFailed,
    kerFailedToReadImageData,
    kerNotAnImage
};

class Error {
public:
    Error(ErrorCode code, const std::string& arg1, const std::string& arg2);
    Error(ErrorCode code, const std::string& arg);
    Error(ErrorCode code);
};

class BasicIo {
public:
    virtual int open() = 0;
    virtual int read(byte* buf, long count) = 0;
    virtual int seek(long offset, int whence) = 0;
    virtual long tell() const = 0;
    virtual bool eof() const = 0;
    virtual bool error() const = 0;
    virtual std::string path() const = 0;
    enum Position {
        beg, cur, end
    };
};

class IoCloser {
public:
    explicit IoCloser(BasicIo& io);
    ~IoCloser();
};

namespace Photoshop {
    bool isIrb(const byte* buf, size_t len);
}

class Safe {
public:
    static uint32_t add(uint32_t a, uint32_t b);
};

class PsdImage {
public:
    BasicIo* io_;
    long pixelWidth_;
    long pixelHeight_;
    bool bigEndian;
    
    void readMetadata();
    void readResourceBlock(uint16_t resourceId, uint32_t resourceSize);
    void clearMetadata();
    bool isPsdType(BasicIo& io, bool advance);
    long getLong(const byte* buf, bool bigEndian);
    uint32_t getULong(const byte* buf, bool bigEndian);
    uint16_t getUShort(const byte* buf, bool bigEndian);
};

const char* strError();

} // namespace Exiv2

using namespace Exiv2;