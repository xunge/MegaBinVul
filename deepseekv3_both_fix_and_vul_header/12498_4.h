#include <linux/socket.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/can/isotp.h>
#include <stdbool.h>

struct sock;
struct socket {
    struct sock *sk;
};

typedef unsigned int u32;

struct isotp_sock {
    struct sock *sk;
    bool bound;
    struct can_isotp_options opt;
    struct can_isotp_fc_options rxfc;
    u32 force_tx_stmin;
    u32 force_rx_stmin;
    struct {
        u32 ll_dl;
    } tx;
    struct can_isotp_ll_options ll;
};

typedef void* sockptr_t;

static inline struct isotp_sock *isotp_sk(struct sock *sk) { return (struct isotp_sock *)sk; }
static inline unsigned int padlen(unsigned int len) { return len; }

static inline int copy_from_sockptr(void *dst, sockptr_t src, unsigned int size) {
    memcpy(dst, src, size);
    return 0;
}

#define EINVAL 22
#define EISCONN 106
#define EFAULT 14
#define ENOPROTOOPT 92