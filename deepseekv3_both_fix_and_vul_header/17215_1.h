#include <iostream>
#include <cstring>
#include <string>

typedef unsigned char byte;

enum PrintStructureOption {
    kpsBasic,
    kpsRecursive,
    kpsIccProfile,
    kpsXMP,
    kpsIptcErase
};

enum ErrorCode {
    kerDataSourceOpenFailed,
    kerFailedToReadImageData,
    kerNotAJpeg,
    kerCorruptedMetadata,
    kerInputDataReadFailed
};

enum BoxType {
    kJp2BoxTypeClose,
    kJp2BoxTypeJp2Header,
    kJp2BoxTypeColorHeader,
    kJp2BoxTypeUuid
};

struct Jp2BoxHeader {
    long length;
    long type;
};

struct Jp2UuidBox {
    byte uuid[16];
};

static const byte kJp2UuidExif[16] = {0};
static const byte kJp2UuidIptc[16] = {0};
static const byte kJp2UuidXmp[16] = {0};

class DataBuf {
public:
    byte* pData_;
    long size_;
    DataBuf() : pData_(nullptr), size_(0) {}
    DataBuf(long size) : pData_(new byte[size]), size_(size) {}
    ~DataBuf() { delete[] pData_; }
    void alloc(long size) { delete[] pData_; pData_ = new byte[size]; size_ = size; }
};

class BasicIo {
public:
    class AutoPtr {
    public:
        BasicIo* p_;
        AutoPtr(BasicIo* p) : p_(p) {}
        ~AutoPtr() { delete p_; }
        BasicIo* operator->() { return p_; }
        BasicIo& operator*() { return *p_; }
    };
    enum Position { beg };
    virtual int open() = 0;
    virtual long tell() = 0;
    virtual int seek(long offset, Position pos) = 0;
    virtual long read(byte* buf, long count) = 0;
    virtual long size() = 0;
    virtual bool error() = 0;
    virtual bool eof() = 0;
    virtual const std::string& path() = 0;
    virtual ~BasicIo() {}
};

class MemIo : public BasicIo {
public:
    MemIo(const byte* data, long size) : data_(data), size_(size), pos_(0) {}
    int open() override { return 0; }
    long tell() override { return pos_; }
    int seek(long offset, Position pos) override { pos_ = offset; return 0; }
    long read(byte* buf, long count) override { memcpy(buf, data_ + pos_, count); pos_ += count; return count; }
    long size() override { return size_; }
    bool error() override { return false; }
    bool eof() override { return pos_ >= size_; }
    const std::string& path() override { static std::string s; return s; }
private:
    const byte* data_;
    long size_;
    long pos_;
};

class Error {
public:
    Error(ErrorCode code, const std::string& msg1, const std::string& msg2) {}
    Error(ErrorCode code) {}
};

namespace Internal {
    std::string stringFormat(const char* format, ...) { return ""; }
    std::string binaryToString(const DataBuf& buf, int maxLen, int start) { return ""; }
}

namespace IptcData {
    void printStructure(std::ostream& out, const byte* data, long size, int depth) {}
}

void printTiffStructure(BasicIo& io, std::ostream& out, PrintStructureOption option, int depth) {}

void lf(std::ostream& out, bool& flag) { out << std::endl; flag = false; }

bool isJp2Type(BasicIo& io, bool advance) { return true; }

long getLong(const byte* buf, bool bigEndian) { return 0; }
long getULong(const byte* buf, bool bigEndian) { return 0; }

std::string toAscii(long type) { return ""; }

std::string strError() { return ""; }

class Jp2Image {
public:
    BasicIo* io_;
    static const bool bigEndian = true;
    void printStructure(std::ostream& out, PrintStructureOption option, int depth);
};