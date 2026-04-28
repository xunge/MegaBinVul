#include <stdint.h>
#include <stdbool.h>

enum PeerType {};

struct Wasm {
  void (*onUpstreamConnectionClose_)(void*, int, uint32_t);
};

struct Context {
  bool in_vm_context_created_;
  Wasm* wasm_;
  int id_;
  void onUpstreamConnectionClose(PeerType peer_type);
};