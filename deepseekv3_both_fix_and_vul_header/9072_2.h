#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

struct socket {
    struct sock *sk;
};

struct sock;

struct sockaddr_pppox {
    unsigned short sa_family;
    unsigned short sa_protocol;
    struct {
        unsigned short pptp;
        unsigned int sin_addr;
    } sa_addr;
};

struct pptp_opt {
    unsigned short src_addr;
};

struct pppox_sock {
    struct sock *sk;
    struct {
        struct pptp_opt pptp;
    } proto;
};

#define pppox_sk(sk) ((struct pppox_sock *)(sk))

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int add_chan(struct pppox_sock *po) { return 0; }