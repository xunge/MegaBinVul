#include <stdint.h>
#include <stdbool.h>

struct wasm {
  void (*onLog_)(void*, uint32_t);
};

struct Context {
  bool in_vm_context_created_;
  struct wasm* wasm_;
  uint32_t id_;
  void onLog();
};