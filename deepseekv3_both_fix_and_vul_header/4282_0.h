#include <vector>
#include <cstdint>
#include <cstddef>

using std::vector;
using std::size_t;

static uint32_t readU32(const uint8_t* data, size_t offset);
static void addRange(vector<uint32_t>& coverage, uint32_t start, uint32_t end);
static void android_errorWriteLog(uint32_t tag, const char* string);