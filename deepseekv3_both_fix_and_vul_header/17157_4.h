#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdint>
#include <limits>

typedef unsigned char byte;

enum PrintStructureOption {
    kpsRecursive
};

enum TiffType {
    tiffIfd = 13,
    tiffIfd8 = 16
};

enum ErrorCode {
    kerInvalidMalloc
};

struct DataBuf {
    long size_;
    byte* pData_;
    DataBuf(long size) : size_(size), pData_(new byte[size]) {}
    ~DataBuf() { delete[] pData_; }
};

class BasicIo {
public:
    enum Position { beg };
    virtual void seek(uint64_t offset, Position pos) = 0;
    virtual size_t read(byte* buf, long count) = 0;
    virtual DataBuf read(uint16_t size) = 0;
    virtual uint64_t size() const = 0;
    virtual uint64_t tell() const = 0;
    virtual std::string path() const = 0;
};

class MemIo : public BasicIo {
public:
    MemIo(byte* data, long size);
    void seek(uint64_t offset, Position pos) override;
    size_t read(byte* buf, long count) override;
    DataBuf read(uint16_t size) override;
    uint64_t size() const override;
    uint64_t tell() const override;
    std::string path() const override;
private:
    byte* data_;
    long size_;
    uint64_t pos_;
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
    static std::string binaryToString(const DataBuf& buf, size_t count);
};

class IptcData {
public:
    static void printStructure(std::ostream& out, byte* bytes, size_t count, int depth);
};

class Error {
public:
    Error(ErrorCode code);
};

uint64_t readData(uint16_t size);
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

extern Header header_;
extern uint16_t dataSize_;
extern bool doSwap_;