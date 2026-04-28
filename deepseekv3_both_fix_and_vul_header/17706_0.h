#include <stdint.h>

struct wasm;
struct Context {
    bool in_vm_context_created_;
    wasm* wasm_;
    uint32_t id_;
    void onDelete();
};

struct wasm {
    void (*onDelete_)(Context*, uint32_t);
};