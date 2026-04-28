#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <limits>
#include <cstdint>
#include <stdexcept>

typedef unsigned char byte;
typedef int64_t int64;

enum PrintStructureOption { kpsRecursive };
enum HeaderFormat { StandardTiff };
enum TiffType { tiffIfd, tiffIfd8 };
enum ErrorCode { kerInvalidMalloc, kerCorruptedMetadata };

class DataBuf {
public:
    byte* pData_;
    DataBuf(long size);
    ~DataBuf();
};

class BasicIo {
public:
    enum SeekMode { beg };
    void seek(int64 offset, SeekMode mode);
    size_t read(byte* buf, long count);
    DataBuf read(uint64_t size);
    size_t tell() const;
    uint64_t size() const;
    std::string path() const;
};

class Header {
public:
    HeaderFormat format() const;
    static const HeaderFormat StandardTiff;
};

class Image {
public:
    static BasicIo& io();
};

class Internal {
public:
    static std::string indent(int depth);
    static std::string stringFormat(const char* format, ...);
    static std::string binaryToString(const DataBuf& buf);
};

class IptcData {
public:
    static void printStructure(std::ostream& out, const DataBuf& buf, int depth);
};

class Safe {
public:
    static uint64_t add(uint64_t a, uint64_t b);
};

class MemIo {
public:
    MemIo(byte* data, long size);
};

class Error {
public:
    Error(ErrorCode code);
};

uint64_t readData(uint64_t size);
uint16_t byteSwap2(const DataBuf& buf, size_t offset, bool doSwap);
uint32_t byteSwap4(const DataBuf& buf, size_t offset, bool doSwap);
uint64_t byteSwap8(const DataBuf& buf, size_t offset, bool doSwap);
bool isStringType(uint16_t type);
bool is2ByteType(uint16_t type);
bool is4ByteType(uint16_t type);
bool is8ByteType(uint16_t type);
bool isShortType(uint16_t type);
bool isLongType(uint16_t type);
bool isLongLongType(uint16_t type);
bool isRationalType(uint16_t type);
std::string tagName(uint16_t tag);
std::string typeName(uint16_t type);
DataBuf makeSlice(const DataBuf& buf, size_t start, size_t end);
DataBuf makeSliceUntil(const byte* buf, size_t end);

extern Header header_;
extern uint64_t dataSize_;
extern bool doSwap_;