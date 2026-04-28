#include <cstdint>
#include <memory>
#include <vector>

namespace Buffer {
struct RawSlice {
    void* mem_;
    size_t len_;
};
class Instance {
public:
    std::vector<RawSlice> getRawSlices() const;
    size_t length() const;
};
}  // namespace Buffer

namespace Common {
struct BrotliContext {
    BrotliContext(size_t chunk_size, size_t max_size);
    BrotliContext(size_t chunk_size);
    size_t avail_in_;
    uint8_t* next_in_;
    void finalizeOutput(Buffer::Instance& output_buffer);
};
}  // namespace Common

class BrotliDecoderState;
using BrotliDecoderDestroyInstanceFunc = void(*)(BrotliDecoderState*);
bool BrotliDecoderHasMoreOutput(BrotliDecoderState* state);

class BrotliDecompressorImpl {
private:
    std::unique_ptr<BrotliDecoderState, BrotliDecoderDestroyInstanceFunc> state_;
    size_t chunk_size_;
    static constexpr float MaxInflateRatio = 2.0;
    bool process(Common::BrotliContext& ctx, Buffer::Instance& output_buffer);
public:
    void decompress(const Buffer::Instance& input_buffer, Buffer::Instance& output_buffer);
};