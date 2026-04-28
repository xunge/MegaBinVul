#include <stdint.h>

namespace Http {
    enum class FilterDataStatus {
        Continue,
        StopIterationAndBuffer,
        StopIterationAndWatermark,
        StopIterationNoBuffer
    };
}

struct ReturnValue {
    uint64_t u64_;
};

struct Wasm {
    ReturnValue (*onRequestBody_)(void*, int, uint32_t, uint32_t);
};

class Context {
public:
    bool in_vm_context_created_;
    Wasm* wasm_;
    int id_;
    Http::FilterDataStatus onRequestBody(int body_buffer_length, bool end_of_stream);
};