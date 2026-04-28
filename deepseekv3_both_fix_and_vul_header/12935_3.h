#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum BrotliDecoderResult {
    BROTLI_DECODER_RESULT_ERROR,
    BROTLI_DECODER_RESULT_SUCCESS,
    BROTLI_DECODER_RESULT_NEEDS_MORE_INPUT,
    BROTLI_DECODER_RESULT_NEEDS_MORE_OUTPUT
};

typedef struct BrotliDecoderState BrotliDecoderState;

namespace Buffer {
class Instance {
public:
    size_t length();
};
}

namespace Common {
struct BrotliContext {
    size_t avail_in_;
    const uint8_t* next_in_;
    size_t avail_out_;
    uint8_t* next_out_;
    size_t max_output_size_;
    
    void updateOutput(Buffer::Instance& output_buffer);
};
}

namespace Runtime {
bool runtimeFeatureEnabled(const char* feature);
}

class BrotliDecompressorImpl {
public:
    bool process(Common::BrotliContext& ctx, Buffer::Instance& output_buffer);
private:
    struct {
        BrotliDecoderState* get();
    } state_;
    struct {
        struct {
            void inc();
        } brotli_error_;
    } stats_;
};

BrotliDecoderResult BrotliDecoderDecompressStream(BrotliDecoderState* state,
                                                size_t* available_in,
                                                const uint8_t** next_in,
                                                size_t* available_out,
                                                uint8_t** next_out,
                                                void* unused);