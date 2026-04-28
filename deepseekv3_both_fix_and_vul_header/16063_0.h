#include <stdbool.h>
#include <stdatomic.h>

struct domain {
    unsigned int max_evtchns;
    _Atomic unsigned int valid_evtchns;
};

typedef bool bool_t;

static inline unsigned int read_atomic(_Atomic unsigned int *addr) {
    return atomic_load_explicit(addr, memory_order_relaxed);
}