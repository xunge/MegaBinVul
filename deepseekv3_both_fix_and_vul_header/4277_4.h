#include <cstdint>
#include <memory>
#include <cstring>

constexpr uint32_t kPageMask = 0x1FFF;
constexpr uint32_t kLogValuesPerPage = 13;
constexpr uint32_t kLogBitsPerEl = 5;
constexpr uint32_t kElMask = 0x1F;
constexpr uint32_t kElAllOnes = 0xFFFFFFFF;
constexpr uint32_t noZeroPage = 0xFFFFFFFF;

using element = uint32_t;

class SparseBitSet {
public:
    uint32_t mMaxVal;
    std::unique_ptr<uint32_t[]> mIndices;
    std::unique_ptr<element[]> mBitmaps;
    uint32_t mZeroPageIndex;

    uint32_t calcNumPages(const uint32_t* ranges, size_t nRanges);
    void initFromRanges(const uint32_t* ranges, size_t nRanges);
};

#define LOG_ALWAYS_FATAL_IF(condition)