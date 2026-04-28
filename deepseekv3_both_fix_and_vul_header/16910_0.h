#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdint>
#include <memory>
#include <algorithm>
#include <stdexcept>

typedef unsigned char byte;

enum PrintStructureOption {
    kpsBasic,
    kpsXMP,
    kpsIccProfile,
    kpsRecursive
};

enum KerError {
    kerDataSourceOpenFailed,
    kerNotAnImage,
    kerFailedToReadImageData,
    kerInputDataReadFailed,
    kerCorruptedMetadata
};

class Error {
public:
    Error(KerError, const std::string&, const std::string&);
    Error(KerError, const std::string&);
    Error(KerError);
};

class BasicIo {
public:
    enum Position { beg, cur };
    virtual int open() = 0;
    virtual bool eof() const = 0;
    virtual long tell() const = 0;
    virtual size_t read(byte*, size_t) = 0;
    virtual int seek(long, Position) = 0;
    virtual bool error() const = 0;
    virtual long size() const = 0;
    virtual std::string path() const = 0;
    typedef std::unique_ptr<BasicIo> AutoPtr;
};

class DataBuf {
public:
    DataBuf(size_t size) : pData_(new byte[size]), size_(size) {}
    DataBuf() : pData_(nullptr), size_(0) {}
    DataBuf(const DataBuf& other) : pData_(new byte[other.size_]), size_(other.size_) {
        std::memcpy(pData_, other.pData_, size_);
    }
    DataBuf(byte* data, size_t size) : pData_(new byte[size]), size_(size) {
        std::memcpy(pData_, data, size);
    }
    ~DataBuf() { delete[] pData_; }
    byte* pData_;
    size_t size_;
};

class MemIo : public BasicIo {
public:
    MemIo(byte* data, long size) : data_(data), size_(size), pos_(0) {}
    int open() override { return 0; }
    bool eof() const override { return pos_ >= size_; }
    long tell() const override { return pos_; }
    size_t read(byte* buf, size_t count) override {
        size_t toRead = std::min(count, static_cast<size_t>(size_ - pos_));
        if(toRead > 0) {
            std::memcpy(buf, data_ + pos_, toRead);
            pos_ += toRead;
        }
        return toRead;
    }
    int seek(long offset, Position pos) override {
        if(pos == beg) pos_ = offset;
        else if(pos == cur) pos_ += offset;
        return 0;
    }
    bool error() const override { return false; }
    long size() const override { return size_; }
    std::string path() const override { return ""; }
private:
    byte* data_;
    long size_;
    long pos_;
};

namespace Exiv2 {
    static const bool bigEndian = true;
    uint32_t getULong(const byte*, bool);
    class Error {
    public:
        Error(KerError);
    };
}

namespace Internal {
    std::string binaryToString(const DataBuf&, size_t = 0, size_t = 0);
    std::string stringFormat(const char*, ...);
    std::string indent(int);
}

class PngChunk {
public:
    enum ChunkType { iTXt_Chunk };
    static DataBuf readRawProfile(const DataBuf&, bool);
    static DataBuf decodeTXTChunk(const DataBuf&, ChunkType);
};

class IptcData {
public:
    static void printStructure(std::ostream&, const DataBuf&, int);
};

class PngImage {
private:
    BasicIo* io_;
    bool isPngType(BasicIo&, bool);
    bool tEXtToDataBuf(byte*, size_t, DataBuf&);
    bool zlibToDataBuf(byte*, size_t, DataBuf&);
    size_t findi(const std::string&, const std::string&);
    void printTiffStructure(BasicIo&, std::ostream&, PrintStructureOption, int);
    DataBuf makeSlice(const DataBuf& buf, size_t offset, size_t size) {
        return DataBuf(buf.pData_ + offset, size);
    }
    DataBuf makeSlice(byte* data, size_t offset, size_t size) {
        return DataBuf(data + offset, size);
    }
public:
    void printStructure(std::ostream&, PrintStructureOption, int);
};

std::string strError();

inline void enforce(bool condition, KerError error) {
    if (!condition) throw Error(error);
}