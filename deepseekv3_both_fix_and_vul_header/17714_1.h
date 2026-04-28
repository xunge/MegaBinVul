#include <cstdint>

namespace Http {
enum class FilterTrailersStatus {
    Continue,
    StopIteration
};
}

struct Wasm {
    struct Result {
        uint64_t u64_;
    };
    Result (*onRequestTrailers_)(void*, int);
    bool hasRequestTrailers_;
};

class Context {
public:
    bool in_vm_context_created_;
    Wasm* wasm_;
    int id_;
    Http::FilterTrailersStatus onRequestTrailers();
};