#include <stdlib.h>
#include <stdatomic.h>
#include <stddef.h>

typedef unsigned int gfp_t;

struct rxrpc_peer;

struct rxrpc_conn_parameters {
    struct rxrpc_peer *peer;
};

struct list_head {
    struct list_head *next, *prev;
};

struct rxrpc_bundle {
    struct rxrpc_conn_parameters params;
    atomic_uint ref;
    atomic_int active;
    int channel_lock;
    struct list_head waiting_calls;
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

static inline void *kzalloc(size_t size, gfp_t flags) {
    (void)flags;
    return calloc(1, size);
}

static inline void refcount_set(atomic_uint *r, int value) {
    atomic_store(r, value);
}

static inline void atomic_set(atomic_int *v, int i) {
    atomic_store(v, i);
}

static inline void spin_lock_init(int *lock) {
    *lock = 0;
}

static inline void rxrpc_get_peer(struct rxrpc_peer *peer) {
    (void)peer;
}