#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#define DCHECK assert

class Utf8DecoderBase {
 protected:
  bool last_byte_of_buffer_unused_;
  const uint8_t* unbuffered_start_;
  size_t unbuffered_length_;
  size_t utf16_length_;
 public:
  void Reset(uint16_t* buffer, size_t buffer_length, const uint8_t* stream, size_t stream_length);
};

namespace Utf8 {
  uint32_t ValueOf(const uint8_t* stream, size_t stream_length, size_t* cursor);
}

namespace Utf16 {
  static const uint32_t kMaxNonSurrogateCharCode = 0xFFFF;
  uint16_t LeadSurrogate(uint32_t character);
  uint16_t TrailSurrogate(uint32_t character);
}