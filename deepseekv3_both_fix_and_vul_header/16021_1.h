#include <cstdint>
#include <cstddef>

struct WirePointer;
class PointerReader {
public:
    PointerReader(void* segment, void* capTable, const WirePointer* ptr, uint32_t nestingLimit);
};
using ElementCount = uint32_t;

struct ListReader {
    const uint8_t* ptr;
    uint32_t structDataSize;
    uint32_t step;
    void* segment;
    void* capTable;
    uint32_t nestingLimit;
    
    PointerReader getPointerElement(ElementCount index) const;
};

template<typename T>
inline T upgradeBound(T value);

constexpr size_t BITS_PER_BYTE = 8;