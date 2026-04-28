#include <stdint.h>

enum class PeerType {};
struct Context;
struct wasm {
  void (*onDownstreamConnectionClose_)(Context*, int, uint32_t);
};
struct Context {
  bool in_vm_context_created_;
  wasm* wasm_;
  int id_;
  void onDownstreamConnectionClose(PeerType peer_type);
};