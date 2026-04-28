#include <cstdint>
#include <memory>

struct BrotliContext {
    uint32_t max_output_size_;
    uint32_t chunk_size_;
    std::unique_ptr<uint8_t[]> chunk_ptr_;
    const uint8_t* next_in_;
    uint8_t* next_out_;
    size_t avail_in_;
    size_t avail_out_;

    BrotliContext(uint32_t chunk_size, uint32_t max_output_size);
    BrotliContext(const uint32_t chunk_size);
};