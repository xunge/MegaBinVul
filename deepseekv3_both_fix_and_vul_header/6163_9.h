#include <iostream>
#include <cstring>
#include <algorithm>
#include <cerrno>
#include <string>
#include <memory>

typedef unsigned char byte;
typedef unsigned long ulong;

enum PrintStructureOption {
    kpsBasic,
    kpsRecursive,
    kpsIccProfile,
    kpsXMP,
    kpsIptcErase
};

struct Jp2BoxHeader {
    ulong length;
    ulong type;
};

struct Jp2UuidBox {
    byte uuid[16];
};

const ulong kJp2BoxTypeClose = 0x6A703263;
const ulong kJp2BoxTypeJp2Header = 0x6A703268;
const ulong kJp2BoxTypeColorHeader = 0x636F6C72;
const ulong kJp2BoxTypeUuid = 0x75756964;

const byte kJp2UuidExif[16] = {0};
const byte kJp2UuidIptc[16] = {0};
const byte kJp2UuidXmp[16] = {0};

class DataBuf {
public:
    byte* pData_;
    long size_;
    DataBuf() : pData_(nullptr), size_(0) {}
    DataBuf(long size) : pData_(new byte[size]), size_(size) {}
    DataBuf(byte* data, long size) : pData_(data), size_(size) {}
    void alloc(long size) { delete[] pData_; pData_ = new byte[size]; size_ = size; }
    ~DataBuf() { delete[] pData_; }
    byte* data() { return pData_; }
    const byte* data() const { return pData_; }
};

class BasicIo {
public:
    enum SeekMode { beg, cur, end };
    virtual int open() = 0;
    virtual long tell() = 0;
    virtual long read(byte* buf, long rcount) = 0;
    virtual long seek(long offset, SeekMode whence) = 0;
    virtual long size() = 0;
    virtual bool eof() = 0;
    virtual bool error() = 0;
    virtual const std::string& path() const = 0;
    class AutoPtr {
    public:
        BasicIo* ptr;
        AutoPtr(BasicIo* p) : ptr(p) {}
        ~AutoPtr() { delete ptr; }
        BasicIo* operator->() { return ptr; }
        BasicIo& operator*() { return *ptr; }
    };
};

class MemIo : public BasicIo {
public:
    MemIo(byte* data, long size) {}
    int open() override { return 0; }
    long tell() override { return 0; }
    long read(byte* buf, long rcount) override { return 0; }
    long seek(long offset, SeekMode whence) override { return 0; }
    long size() override { return 0; }
    bool eof() override { return false; }
    bool error() override { return false; }
    const std::string& path() const override { static std::string s; return s; }
};

class Error {
public:
    Error(int code, const std::string& arg1 = "", const std::string& arg2 = "") {}
};

namespace Internal {
    std::string stringFormat(const char* format, ...);
    std::string binaryToString(const DataBuf& buf);
}

namespace Exiv2 {
    enum ErrorCode {
        kerDataSourceOpenFailed,
        kerFailedToReadImageData,
        kerNotAJpeg,
        kerCorruptedMetadata,
        kerInputDataReadFailed
    };
}

using namespace Exiv2;

class Jp2Image {
    BasicIo* io_;
    static bool bigEndian;
public:
    void printStructure(std::ostream& out, PrintStructureOption option, int depth);
};

inline ulong getLong(byte* buf, bool bigEndian) {
    if (bigEndian) {
        return (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
    } else {
        return (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
    }
}

inline ulong getULong(byte* buf, bool bigEndian) {
    return getLong(buf, bigEndian);
}

std::string toAscii(ulong type);
void lf(std::ostream& out, bool& flag);
void enforce(bool condition, int errorCode);
bool isJp2Type(BasicIo& io, bool advance);
DataBuf makeSlice(byte* data, long start, long end);
DataBuf makeSlice(const DataBuf& buf, long start, long end);
void printTiffStructure(BasicIo& io, std::ostream& out, PrintStructureOption option, int depth);

class IptcData {
public:
    static void printStructure(std::ostream& out, byte* data, long size, int depth);
    static void printStructure(std::ostream& out, const DataBuf& buf, int depth);
};

inline std::string strError() { return std::string(strerror(errno)); }