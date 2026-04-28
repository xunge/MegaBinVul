#include <stdbool.h>
#include <stddef.h>

#define RXRPC_MAXCALLS 4
#define RXRPC_CONN_FINAL_ACK_MASK 0x1
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

struct rb_node {
    struct rb_node *rb_left;
    struct rb_node *rb_right;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct rxrpc_connection {
    unsigned int debug_id;
    unsigned int flags;
    unsigned int bundle_shift;
    struct rxrpc_bundle *bundle;
};

struct rxrpc_bundle {
    int channel_lock;
    unsigned long avail_chans;
    struct rxrpc_connection *conns[4];
    struct rb_node local_node;
    struct {
        struct rxrpc_local *local;
        bool exclusive;
    } params;
};

struct rxrpc_local {
    int client_bundles_lock;
    struct rb_root client_bundles;
};

static void spin_lock(int *lock);
static void spin_unlock(int *lock);
static void rb_erase(struct rb_node *node, struct rb_root *root);
static void clear_bit(int nr, volatile unsigned long *addr);
static void rxrpc_process_delayed_final_acks(struct rxrpc_connection *conn, bool b);
static void rxrpc_put_bundle(struct rxrpc_bundle *bundle);
static void rxrpc_put_connection(struct rxrpc_connection *conn);

#define _enter(fmt, ...)
#define _debug(fmt, ...)
#define _leave(fmt)