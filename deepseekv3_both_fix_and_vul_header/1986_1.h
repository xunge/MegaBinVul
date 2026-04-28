#include <cstdint>

using sal_uInt8 = uint8_t;
using sal_uInt16 = uint16_t; 
using sal_uInt32 = uint32_t;

struct SvStream {
    bool good();
    SvStream& operator>>(sal_uInt16&);
    SvStream& operator>>(sal_uInt32&);
};

namespace sal {
    template<typename T>
    T static_int_cast(int);
}

const sal_uInt32 nMaxLegalRecordLength = 0xFFFFFFFF;

class SvxMSDffManager {
public:
    bool ReadCommonRecordHeader(SvStream& rSt, sal_uInt8& rVer, sal_uInt16& rInst, sal_uInt16& rFbt, sal_uInt32& rLength);
};