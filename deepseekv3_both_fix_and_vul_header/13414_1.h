#include <cstdint>
#include <cmath>
#include <limits>

struct ImmutableBigIntRef {
    const uint64_t *digits;
    uint32_t numDigits;
};

constexpr uint32_t BigIntDigitSizeInBits = 64;

namespace llvh {
    template<typename T>
    class ArrayRef {
    public:
        ArrayRef(const T *data, size_t length) {}
    };

    template<typename T>
    ArrayRef<T> makeArrayRef(const T *data, size_t length) {
        return ArrayRef<T>(data, length);
    }

    class APInt {
    public:
        APInt(uint32_t numBits, ArrayRef<uint64_t> digits) {}
        double roundToDouble(bool isSigned) const { return 0.0; }
    };
}