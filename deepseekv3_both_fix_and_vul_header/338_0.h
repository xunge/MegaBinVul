#include <iostream>
#include <cstring>
#include <string>
#include <cstdint>
#include <cerrno>

namespace Exiv2 {
    enum ErrorCode {
        kerDataSourceOpenFailed,
        kerNotAnImage,
        kerFailedToReadImageData,
        kerCorruptedMetadata
    };

    enum SeekMode {
        smBeg, smCur, smEnd
    };

    class Error {
    public:
        Error(ErrorCode code, const std::string& arg1, const std::string& arg2 = "") {}
        explicit Error(ErrorCode code, const char* arg1) {}
        explicit Error(ErrorCode code) {}
    };

    class BasicIo {
    public:
        static const SeekMode cur = smCur;
        virtual ~BasicIo() {}
        virtual int open() = 0;
        virtual bool eof() const = 0;
        virtual long tell() const = 0;
        virtual size_t size() const = 0;
        virtual int seek(long offset, SeekMode whence) = 0;
        virtual int error() const = 0;
        virtual std::string path() const = 0;
    };

    class DataBuf {
    public:
        DataBuf(size_t size) : pData_(new unsigned char[size]), size_(size) {}
        ~DataBuf() { delete[] pData_; }
        unsigned char* pData_;
        size_t size_;
    };

    class IoCloser {
    public:
        IoCloser(BasicIo& io) {}
        ~IoCloser() {}
    };

    class PngImage {
    public:
        void readMetadata();
        BasicIo* io_;
        long pixelWidth_;
        long pixelHeight_;
        std::string profileName_;
        DataBuf iccProfile_{0};
        void clearMetadata() {}
    };

    uint32_t getULong(const unsigned char* buf, bool bigEndian) { return 0; }
    extern bool bigEndian;

    namespace Internal {
        struct PngImageHeader {
            uint32_t width;
            uint32_t height;
        };
    }

    namespace PngChunk {
        enum ChunkType {
            tEXt_Chunk,
            zTXt_Chunk,
            iTXt_Chunk
        };

        void decodeIHDRChunk(const DataBuf& data, Internal::PngImageHeader& header) {}
        void decodeTXTChunk(PngImage* image, const DataBuf& data, ChunkType type) {}
    }

    void zlibToDataBuf(const unsigned char* compressedData, size_t compressedSize, DataBuf& out) {}
    bool isPngType(BasicIo& io, bool advance) { return false; }
    void readChunk(DataBuf& buf, BasicIo& io) {}
    const char* strError() { return ""; }

    inline void enforce(bool condition, ErrorCode code) {
        if (!condition) throw Error(code);
    }
}

using namespace Exiv2;