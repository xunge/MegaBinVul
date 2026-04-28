#include <cstdint>
#include <limits>

class SvStream {
public:
    SvStream& operator>>(uint16_t&);
    SvStream& operator>>(uint32_t&);
    bool good() const;
};

class SvxMSDffManager {
public:
    bool ReadCommonRecordHeader(SvStream& rSt, uint8_t& rVer, uint16_t& rInst, uint16_t& rFbt, uint32_t& rLength);
};

const uint32_t nMaxLegalDffRecordLength = std::numeric_limits<uint32_t>::max();
const uint32_t nMaxLegalRecordLength = std::numeric_limits<uint32_t>::max();

typedef uint8_t sal_uInt8;
typedef uint16_t sal_uInt16; 
typedef uint32_t sal_uInt32;

namespace sal {
    template<typename T, typename U>
    T static_int_cast(U u) {
        return static_cast<T>(u);
    }
}