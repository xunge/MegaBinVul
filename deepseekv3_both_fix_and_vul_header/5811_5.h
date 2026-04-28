#include <stdint.h>

uintptr_t m_loader;
struct ScriptState {
    void (*clear)();
} m_scriptState = {0};

static void dummy_clear() {}
__attribute__((constructor)) static void init_scriptState() {
    m_scriptState.clear = dummy_clear;
}