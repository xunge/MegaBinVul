#include <iostream>
#include <cstring>
#include <cstdint>
#include <string>
#include <vector>

typedef unsigned char byte;

struct Jp2BoxHeader {
    uint32_t length;
    uint32_t type;
};

struct DataBuf {
    byte* pData_;
    long size_;
    DataBuf(long size = 0) : pData_(new byte[size]), size_(size) {}
    DataBuf(const byte* data, long size) : pData_(new byte[size]), size_(size) {
        memcpy(pData_, data, size);
    }
    ~DataBuf() { delete[] pData_; }
};

class BasicIo {
public:
    bool isopen() { return false; }
    long tell() { return 0; }
    long size() { return 0; }
    long read(byte* buf, long count) { return 0; }
    bool error() { return false; }
    bool eof() { return false; }
    int write(const byte* buf, long count) { return 0; }
    std::string path() { return ""; }
};

enum ErrorCode {
    kerInputDataReadFailed,
    kerImageWriteFailed,
    kerNoImageInInputData,
    kerFailedToReadImageData,
    kerCorruptedMetadata
};

class Error {
public:
    Error(ErrorCode code) {}
};

class ExifData {
public:
    int count() { return 0; }
};

class IptcData {
public:
    int count() { return 0; }
};

class XmpData {
public:
    int count() { return 0; }
};

class Jp2Image {
public:
    void doWriteMetadata(BasicIo& outIo);
    BasicIo* io_;
    ExifData exifData_;
    IptcData iptcData_;
    XmpData xmpData_;
    std::string xmpPacket_;
};

const byte Jp2Signature[12] = {};
const uint32_t kJp2BoxTypeJp2Header = 0x6a703268; // 'jp2h'
const uint32_t kJp2BoxTypeUuid = 0x75756964; // 'uuid'
const byte kJp2UuidExif[16] = {};
const byte kJp2UuidIptc[16] = {};
const byte kJp2UuidXmp[16] = {};

bool bigEndian = false;
bool littleEndian = false;

uint32_t getLong(const byte* buf, bool bigEndian) { return 0; }
std::string toAscii(uint32_t type) { return ""; }
void ul2Data(byte* buf, uint32_t val, bool bigEndian) {}

class Blob : public std::vector<byte> {
public:
    size_t size() { return std::vector<byte>::size(); }
    byte& operator[](size_t idx) { return std::vector<byte>::operator[](idx); }
};

class ExifParser {
public:
    static void encode(Blob& blob, bool littleEndian, const ExifData& exifData) {}
};

class IptcParser {
public:
    static DataBuf encode(const IptcData& iptcData) { return DataBuf(0); }
};

class XmpParser {
public:
    static int encode(std::string& xmpPacket, const XmpData& xmpData) { return 0; }
};

#define EXV_ERROR std::cerr
#define SUPPRESS_WARNINGS

bool writeXmpFromPacket() { return false; }
bool isJp2Type(BasicIo& io, bool advance) { return false; }
void encodeJp2Header(DataBuf& inBuf, DataBuf& outBuf) {}

namespace Exiv2 {
    extern bool bigEndian;
    extern bool littleEndian;
}