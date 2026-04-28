#include <stdint.h>

namespace Http {
    enum class FilterDataStatus {
        Continue,
        StopIterationAndBuffer,
        StopIterationAndWatermark,
        StopIterationNoBuffer
    };
}

struct wasm {
    struct Result {
        uint64_t u64_;
    };
    Result (*onResponseBody_)(void*, int, uint32_t, uint32_t);
};

class Context {
public:
    bool in_vm_context_created_;
    wasm* wasm_;
    int id_;
    Http::FilterDataStatus onResponseBody(int body_buffer_length, bool end_of_stream);
};