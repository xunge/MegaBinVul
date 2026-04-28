#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <vector>

using std::vector;

static uint16_t readU16(const uint8_t* data, size_t offset) {
    return (data[offset] << 8) | data[offset + 1];
}

static void addRange(vector<uint32_t>& coverage, uint32_t start, uint32_t end) {
    coverage.push_back(start);
    coverage.push_back(end);
}