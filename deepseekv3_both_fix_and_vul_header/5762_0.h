#include <cstddef>
#include <cstdint>

namespace unibrow {

class Utf8DecoderBase {
public:
    void WriteUtf16Slow(const uint8_t* stream, uint16_t* data, size_t data_length);
    void WriteUtf16Slow(const uint8_t* stream, size_t stream_length, uint16_t* data, size_t data_length);
};

namespace Utf16 {
    const uint16_t kMaxNonSurrogateCharCode = 0xFFFF;
    inline uint16_t LeadSurrogate(uint32_t character) { return 0xD800 + ((character - 0x10000) >> 10); }
    inline uint16_t TrailSurrogate(uint32_t character) { return 0xDC00 + ((character - 0x10000) & 0x3FF); }
}

namespace Utf8 {
    const size_t kMaxEncodedSize = 4;
    inline uint32_t ValueOf(const uint8_t* stream, size_t size, size_t* cursor) {
        if (size == 0) return 0;
        uint32_t character = *stream;
        *cursor = 1;
        return character;
    }
}

}  // namespace unibrow

#define DCHECK(condition) ((void)0)

using namespace unibrow;