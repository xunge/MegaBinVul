#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <limits>
#include <cstdint>

using byte = unsigned char;
using int64 = int64_t;

enum PrintStructureOption { kpsRecursive };
enum TiffType { tiffIfd, tiffIfd8 };
enum ErrorCode { kerInvalidMalloc, kerCorruptedMetadata };

class DataBuf {
public:
    byte* pData_;
    explicit DataBuf(long size);
    ~DataBuf();
};

class BasicIo {
public:
    enum SeekMode { beg };
    void seek(int64_t offset, SeekMode mode);
    size_t read(byte* buf, long count);
    DataBuf read(long count);
    size_t tell() const;
    std::string path() const;
    size_t size() const;
};

class Image {
public:
    static BasicIo& io();
};

class Header {
public:
    enum Format { StandardTiff };
    Format format() const;
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
    static size_t add(size_t a, size_t b);
};

class MemIo {
public:
    MemIo(byte* data, long size);
};

class Error {
public:
    explicit Error(ErrorCode code);
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