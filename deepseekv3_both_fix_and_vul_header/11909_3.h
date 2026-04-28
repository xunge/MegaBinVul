#include <cstdint>
#include <cstring>
#include <iostream>
#include <stdexcept>

using byte = uint8_t;

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

struct Jp2BoxHeader {
    int32_t length;
    int32_t type;
};

enum {
    kJp2BoxTypeColorHeader,
    kJp2BoxTypeJp2Header
};

class Jp2Image {
public:
    static DataBuf iccProfile_;
    static bool iccProfileDefined();
    static bool bigEndian;
    void encodeJp2Header(const DataBuf& boxBuf, DataBuf& outBuf);
};

int32_t getLong(byte* bytes, bool bigEndian);
void ul2Data(byte* dest, uint32_t val, bool bigEndian);
std::string toAscii(int32_t type);

class Error : public std::runtime_error {
public:
    explicit Error(int code) : std::runtime_error("") {}
};

namespace ker {
    const int kerCorruptedMetadata = 0;
}

using namespace ker;