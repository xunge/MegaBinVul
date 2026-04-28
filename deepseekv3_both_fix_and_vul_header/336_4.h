#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>
#include <cerrno>

namespace Exiv2 {
    enum ErrorCode {
        kerDataSourceOpenFailed,
        kerNotAnImage,
        kerFailedToReadImageData,
        kerCorruptedMetadata
    };

    class Error {
    public:
        Error(ErrorCode code, const std::string& arg1, const std::string& arg2 = "");
        explicit Error(ErrorCode code, const char* arg);
        explicit Error(ErrorCode code);
    };

    class DataBuf {
    public:
        DataBuf(size_t size);
        ~DataBuf();
        unsigned char* pData_;
        size_t size_;
    };

    class BasicIo {
    public:
        enum Position { beg, cur, end };
        virtual ~BasicIo();
        virtual int open() = 0;
        virtual bool eof() const = 0;
        virtual long tell() const = 0;
        virtual size_t size() const = 0;
        virtual int seek(long offset, Position pos) = 0;
        virtual int error() const = 0;
        virtual std::string path() const = 0;
    };

    class IoCloser {
    public:
        IoCloser(BasicIo& io);
        ~IoCloser();
    };

    uint32_t getULong(const unsigned char* buf, bool bigEndian);
    void enforce(bool condition, ErrorCode code);
    bool isPngType(BasicIo& io, bool advance);
    void readChunk(DataBuf& buf, BasicIo& io);
    void zlibToDataBuf(const unsigned char* src, size_t srcSize, DataBuf& dest);
    const bool bigEndian = true;

    class PngImage;

    namespace PngChunk {
        enum ChunkType {
            tEXt_Chunk,
            zTXt_Chunk,
            iTXt_Chunk
        };
        void decodeIHDRChunk(const DataBuf& data, uint32_t* width, uint32_t* height);
        void decodeTXTChunk(Exiv2::PngImage* image, const DataBuf& data, ChunkType type);
    };
}

class Exiv2::PngImage {
private:
    Exiv2::BasicIo* io_;
    uint32_t pixelWidth_;
    uint32_t pixelHeight_;
    std::string profileName_;
    Exiv2::DataBuf iccProfile_;
public:
    void readMetadata();
    void clearMetadata();
    std::string strError() const { return strerror(errno); }
};

using namespace Exiv2;