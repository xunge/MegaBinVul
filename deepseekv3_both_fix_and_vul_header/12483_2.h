#include <cstring>
#include <cstdint>
#include <stdexcept>

using byte = unsigned char;

struct Jp2BoxHeader {
    uint32_t length;
    uint32_t type;
};

struct DataBuf {
    size_t size_;
    byte* pData_;
    DataBuf(size_t size) : size_(size), pData_(new byte[size]) {}
    ~DataBuf() { delete[] pData_; }
    void alloc(size_t size) {
        delete[] pData_;
        pData_ = new byte[size];
        size_ = size;
    }
};

enum {
    kJp2BoxTypeColorHeader,
    kJp2BoxTypeJp2Header
};

bool bigEndian = false;
DataBuf iccProfile_(0);

bool iccProfileDefined() { return iccProfile_.size_ > 0; }

uint32_t getLong(const byte* buf, bool bigEndian) {
    if (bigEndian) {
        return (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
    } else {
        return (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
    }
}

void ul2Data(byte* buf, uint32_t val, bool bigEndian) {
    if (bigEndian) {
        buf[0] = (val >> 24) & 0xFF;
        buf[1] = (val >> 16) & 0xFF;
        buf[2] = (val >> 8) & 0xFF;
        buf[3] = val & 0xFF;
    } else {
        buf[3] = (val >> 24) & 0xFF;
        buf[2] = (val >> 16) & 0xFF;
        buf[1] = (val >> 8) & 0xFF;
        buf[0] = val & 0xFF;
    }
}

#define enforce(condition, error) \
    if (!(condition)) throw std::runtime_error(#error)

class Jp2Image {
public:
    void encodeJp2Header(const DataBuf& boxBuf, DataBuf& outBuf);
};