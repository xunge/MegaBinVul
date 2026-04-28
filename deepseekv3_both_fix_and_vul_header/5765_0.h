#include <cstddef>

class Utf8DecoderBase {
protected:
    const char* unbuffered_start_;
    size_t unbuffered_length_;
    size_t utf16_length_;
    bool last_byte_of_buffer_unused_;
public:
    Utf8DecoderBase();
};