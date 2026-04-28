#include <cstdint>
#include <cstring>
#include <iostream>

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

class Jp2Image {
public:
    void encodeJp2Header(const DataBuf& boxBuf, DataBuf& outBuf);
};

namespace Exiv2 {
    enum ErrorCode {
        kerCorruptedMetadata
    };
    void enforce(bool condition, ErrorCode code);
}

bool bigEndian;
DataBuf iccProfile_{0};
bool iccProfileDefined();
uint32_t getLong(byte* data, bool bigEndian);
void ul2Data(byte* data, uint32_t value, bool bigEndian);

enum {
    kJp2BoxTypeColorHeader,
    kJp2BoxTypeJp2Header
};