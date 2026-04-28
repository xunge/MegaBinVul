#include <cstdint>
#include <cstring>
#include <iostream>
#include <cstddef>
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

class Jp2Image {
public:
    void encodeJp2Header(const DataBuf& boxBuf, DataBuf& outBuf);
};

enum {
    kJp2BoxTypeColorHeader,
    kJp2BoxTypeJp2Header
};

namespace Exiv2 {
    const int kerCorruptedMetadata = 1;
}

extern DataBuf iccProfile_;
bool iccProfileDefined();
uint32_t getLong(byte* data, bool bigEndian);
void ul2Data(byte* data, uint32_t val, bool bigEndian);
inline void enforce(bool condition, int errorCode) {
    if (!condition) throw std::runtime_error("Metadata corrupted");
}
std::string toAscii(uint32_t type);

const bool bigEndian = true;