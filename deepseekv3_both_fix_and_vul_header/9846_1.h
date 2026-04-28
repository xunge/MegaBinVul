#include <sys/socket.h>
#include <linux/tipc.h>
#include <errno.h>

struct socket {
    struct sock *sk;
    int state;
};

struct sock;

struct tipc_sock {
    struct {
        unsigned int ref;
        unsigned int node;
    } peer_name;
    struct {
        unsigned int ref;
    } *p;
};

static inline struct tipc_sock *tipc_sk(struct sock *sk) { return (struct tipc_sock *)sk; }
static inline void tipc_ownidentity(unsigned int ref, void *id) {}

#define SS_CONNECTED 1
#define SS_DISCONNECTING 2