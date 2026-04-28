#include <stdbool.h>
#include <stdint.h>

struct rxrpc_bundle {
    unsigned int debug_id;
    int ref;
};

extern void _debug(const char *fmt, ...);
extern bool __refcount_dec_and_test(int *ref, int *ret);
extern void rxrpc_free_bundle(struct rxrpc_bundle *bundle);