#include <stdint.h>

namespace Network {
    enum class FilterStatus {
        Continue,
        StopIteration
    };
}

struct WasmResult {
    uint64_t u64_;
};

struct Wasm {
    WasmResult (*onDownstreamData_)(void*, int, uint32_t, uint32_t);
};

struct Context {
    bool in_vm_context_created_;
    Wasm* wasm_;
    int id_;
    Network::FilterStatus onDownstreamData(int data_length, bool end_of_stream);
};