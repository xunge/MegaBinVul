#include <vector>
#include <cstdint>
#include <cstddef>

using std::vector;

static uint16_t readU16(const uint8_t* data, size_t offset);
static void addRange(vector<uint32_t>& coverage, uint32_t start, uint32_t end);
extern "C" void android_errorWriteLog(uint32_t tag, const char* msg);