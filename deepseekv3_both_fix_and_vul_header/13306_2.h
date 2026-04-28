#include <stddef.h>

struct rxrpc_sock;
struct rxrpc_call;
struct rxrpc_conn_parameters;
struct sockaddr_rxrpc;
struct rxrpc_bundle;
struct rxrpc_net;

#define RXRPC_CALL_CLIENT_AWAIT_CONN 0
#define RXRPC_CALL_LOCAL_ERROR 0
#define rxrpc_client_chan_wait_failed 0

#define _enter(fmt, ...)
#define _leave(fmt, ...)

#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)

#define smp_rmb()

typedef unsigned int gfp_t;

struct list_head {
    struct list_head *next, *prev;
};

struct rxrpc_call {
    unsigned long debug_id;
    unsigned long user_call_ID;
    int state;
    void *conn;
    struct list_head chan_wait_link;
};

struct rxrpc_conn_parameters {
    struct {
        struct rxrpc_net *rxnet;
    } *local;
};

struct rxrpc_bundle {
    int channel_lock;
};

struct rxrpc_net {
    int client_conn_reaper;
};

static inline void list_del_init(struct list_head *entry) {
    entry->next = entry;
    entry->prev = entry;
}

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}

static inline void rxrpc_discard_expired_client_conns(int *reaper) {}
static inline struct rxrpc_bundle *rxrpc_prep_call(struct rxrpc_sock *rx, struct rxrpc_call *call, struct rxrpc_conn_parameters *cp, struct sockaddr_rxrpc *srx, gfp_t gfp) { return NULL; }
static inline int rxrpc_wait_for_channel(struct rxrpc_bundle *bundle, struct rxrpc_call *call, gfp_t gfp) { return 0; }
static inline void rxrpc_put_bundle(struct rxrpc_bundle *bundle) {}
static inline void trace_rxrpc_client(void *conn, int ret, int type) {}
static inline void rxrpc_set_call_completion(struct rxrpc_call *call, int type, int a, int b) {}
static inline void rxrpc_disconnect_client_call(struct rxrpc_bundle *bundle, struct rxrpc_call *call) {}