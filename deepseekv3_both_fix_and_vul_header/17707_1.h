#include <cstdint>

namespace Http {
enum class FilterTrailersStatus {
    Continue,
    StopIteration
};
}

struct wasm {
    struct result {
        uint64_t u64_;
    };
    result (*onResponseTrailers_)(void*, int);
};

class Context {
public:
    bool in_vm_context_created_;
    wasm* wasm_;
    int id_;
    Http::FilterTrailersStatus onResponseTrailers();
};