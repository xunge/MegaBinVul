#include <vector>
#include <cstdint>
#include <cstddef>

using std::vector;

class SparseBitSet {
public:
    void initFromRanges(const uint32_t* ranges, size_t numRanges);
};

class CmapCoverage {
public:
    bool getCoverage(SparseBitSet& coverage, const uint8_t* cmap_data, size_t cmap_size);
};

uint16_t readU16(const uint8_t* data, size_t offset);
uint32_t readU32(const uint8_t* data, size_t offset);
bool getCoverageFormat4(vector<uint32_t>& coverageVec, const uint8_t* tableData, size_t tableSize);
bool getCoverageFormat12(vector<uint32_t>& coverageVec, const uint8_t* tableData, size_t tableSize);