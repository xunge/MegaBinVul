#include <stdint.h>

struct Network {
    enum FilterStatus {
        Continue,
        StopIteration
    };
};

union WasmResult {
    uint64_t u64_;
};

class Context {
public:
    Network::FilterStatus onNetworkNewConnection();
    void onCreate(uint32_t root_context_id);
    
    uint32_t root_context_id_;
    bool in_vm_context_created_;
    struct {
        WasmResult (*onNewConnection_)(Context*, uint32_t);
    } *wasm_;
    uint32_t id_;
};