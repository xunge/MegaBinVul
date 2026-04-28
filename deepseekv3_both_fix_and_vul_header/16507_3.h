#include <sys/socket.h>
#include <stddef.h>
#include <stdbool.h>
#include <errno.h>

#define VMADDR_CID_ANY -1U
#define SS_CONNECTED 1

struct socket {
    struct sock *sk;
    int state;
};

struct sock;

struct sockaddr_vm {
    unsigned int svm_cid;
    unsigned int svm_port;
};

struct vsock_sock {
    struct sock *sk;
    struct sockaddr_vm remote_addr;
    const struct vsock_transport *transport;
};

struct vsock_transport {
    unsigned int (*get_local_cid)(void);
    bool (*dgram_allow)(unsigned int cid, unsigned int port);
    int (*dgram_enqueue)(struct vsock_sock *vsk, struct sockaddr_vm *addr,
                        struct msghdr *msg, size_t len);
};

static inline struct vsock_sock *vsock_sk(struct sock *sk) { return (struct vsock_sock *)sk; }
static inline int vsock_auto_bind(struct vsock_sock *vsk) { return 0; }
static inline int vsock_addr_cast(const struct sockaddr *addr, size_t len, struct sockaddr_vm **out_addr) { return 0; }
static inline bool vsock_addr_bound(const struct sockaddr_vm *addr) { return false; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}