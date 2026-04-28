#include <stdint.h>

namespace Http {
enum class FilterMetadataStatus {
  Continue
};
}

struct WasmResult {
  uint64_t u64_;
};

struct wasm {
  WasmResult (*onResponseMetadata_)(void*, int32_t);
};

class Context {
public:
  bool in_vm_context_created_;
  wasm* wasm_;
  int32_t id_;
  Http::FilterMetadataStatus onResponseMetadata();
};