#include <cstdint>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>

#define WEBP_TAG_SIZE 4

typedef unsigned char byte;
const bool littleEndian = true;
const bool bigEndian = false;

struct DataBuf {
    byte* pData_;
    uint32_t size_;
    DataBuf(uint32_t size) : pData_(new byte[size]), size_(size) {}
    ~DataBuf() { delete[] pData_; }
};

class BasicIo {
public:
    virtual ~BasicIo() = default;
    virtual bool eof() const = 0;
    virtual long tell() const = 0;
    virtual void read(byte* buf, uint32_t size) = 0;
    virtual void seek(long offset, int whence) = 0;
    static const int cur = 1;
};

struct XmpData {};
struct ExifData { void clear() {} };
enum ByteOrder { invalidByteOrder };

class WebPImage {
protected:
    BasicIo* io_;
    uint32_t pixelWidth_;
    uint32_t pixelHeight_;
    std::string xmpPacket_;
    ExifData exifData_;
    XmpData xmpData_;
    
    void setIccProfile(const DataBuf&);
    void setByteOrder(ByteOrder);
public:
    void decodeChunks(uint64_t filesize);
};

namespace Exiv2 {
    uint32_t getULong(const byte* buf, bool littleEndian);
    uint16_t getUShort(const byte* buf, bool littleEndian);
    enum ErrorCode { kerCorruptedMetadata };
    void enforce(bool condition, ErrorCode error);
}

namespace Internal {
    std::string binaryToHex(const byte* buf, uint32_t size);
}

class XmpParser {
public:
    static bool decode(XmpData& xmpData, const std::string& xmpPacket);
};

class ExifParser {
public:
    static ByteOrder decode(ExifData& exifData, const byte* buf, uint32_t size);
};

#define DEBUG
#define SUPPRESS_WARNINGS
#define EXV_WARNING std::cerr

void us2Data(byte* buf, uint16_t val, bool bigEndian);
long getHeaderOffset(const byte* buf, uint32_t size, byte* header, uint32_t headerSize);
bool equalsWebPTag(const DataBuf& buf, const char* tag);

#define WEBP_CHUNK_HEADER_VP8X "VP8X"
#define WEBP_CHUNK_HEADER_VP8 "VP8 "
#define WEBP_CHUNK_HEADER_VP8L "VP8L"
#define WEBP_CHUNK_HEADER_ANMF "ANMF"
#define WEBP_CHUNK_HEADER_ICCP "ICCP"
#define WEBP_CHUNK_HEADER_EXIF "EXIF"
#define WEBP_CHUNK_HEADER_XMP "XMP "