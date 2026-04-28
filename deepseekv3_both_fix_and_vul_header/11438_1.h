#include <algorithm>
#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>
#include <cstring>

typedef unsigned char byte;

enum TxtChunkType {
    zTXt_Chunk,
    tEXt_Chunk,
    iTXt_Chunk
};

struct DataBuf {
    byte* pData_;
    long size_;
    
    DataBuf() : pData_(nullptr), size_(0) {}
    DataBuf(const byte* data, long size) : pData_(new byte[size]), size_(size) {
        std::copy(data, data + size, pData_);
    }
    ~DataBuf() { delete[] pData_; }
    void alloc(long size) {
        delete[] pData_;
        pData_ = new byte[size];
        size_ = size;
    }
};

class Safe {
public:
    static long add(long a, long b) {
        if (a > 0 && b > 0 && a > LONG_MAX - b) throw std::overflow_error("Integer overflow");
        return a + b;
    }
};

void zlibUncompress(const byte* compressedText, unsigned int compressedTextSize, DataBuf& arr) {
}

void enforce(bool condition, int errorCode) {
    if (!condition) throw std::runtime_error("Enforce failed");
}

enum ErrorCode {
    kerFailedToReadImageData,
    kerCorruptedMetadata
};

class Error : public std::exception {
public:
    Error(ErrorCode code) : code_(code) {}
    ErrorCode code() const { return code_; }
private:
    ErrorCode code_;
};

namespace Exiv2 {
    const int kerCorruptedMetadata = 0;
}

std::string string_from_unterminated(const char* str, size_t max_len) {
    return std::string(str, strnlen(str, max_len));
}

class PngChunk {
public:
    static DataBuf parseTXTChunk(const DataBuf& data, int keysize, TxtChunkType type);
};