#include <stdint.h>

namespace Network {
enum class FilterStatus { Continue, StopIteration };
} // namespace Network

struct Wasm {
  struct Result {
    uint64_t u64_;
  };
  Result (*onUpstreamData_)(void*, int, uint32_t, uint32_t);
};

struct Context {
  bool in_vm_context_created_;
  Wasm* wasm_;
  int id_;
  Network::FilterStatus onUpstreamData(int data_length, bool end_of_stream);
};