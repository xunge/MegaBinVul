#include <stdint.h>

namespace Http {
enum class FilterMetadataStatus {
  Continue
};
} // namespace Http

struct Wasm {
  struct Result {
    uint64_t u64_;
  };
  Result (*onRequestMetadata_)(void*, uint32_t);
};

struct Context {
  bool in_vm_context_created_;
  Wasm* wasm_;
  uint32_t id_;
  Http::FilterMetadataStatus onRequestMetadata();
};