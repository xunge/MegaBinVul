#include <iostream>
#include <cstdint>
#include <cerrno>
#include <cstring>
#include <string>

typedef unsigned char byte;

namespace Exiv2 {
    enum ErrorCode {
        kerDataSourceOpenFailed,
        kerFailedToReadImageData,
        kerNotAnImage,
        kerCorruptedMetadata
    };

    class Error {
    public:
        Error(ErrorCode code, const std::string& msg1 = "", const std::string& msg2 = "");
    };

    class BasicIo {
    public:
        int open();
        int read(void* buf, size_t count);
        int seek(long offset, int whence);
        long tell();
        bool eof();
        bool error();
        size_t size();
        std::string path();
        enum Whence { beg, cur, end };
    };

    class IoCloser {
    public:
        explicit IoCloser(BasicIo& io);
        ~IoCloser();
    };

    namespace Photoshop {
        bool isIrb(const byte* buf, size_t size);
    }

    class Safe {
    public:
        static uint32_t add(uint32_t a, uint32_t b);
    };

    long getLong(const byte* buf, bool bigEndian);
    uint16_t getUShort(const byte* buf, bool bigEndian);
    uint32_t getULong(const byte* buf, bool bigEndian);

    class PsdImage {
    public:
        void readMetadata();
        void clearMetadata();
        void readResourceBlock(uint16_t resourceId, uint32_t resourceSize);
        BasicIo* io_;
        long pixelWidth_;
        long pixelHeight_;
        bool bigEndian;
    };

    const char* strError();
    void enforce(bool condition, ErrorCode code);
    bool isPsdType(BasicIo& io, bool advance);
}

using namespace Exiv2;