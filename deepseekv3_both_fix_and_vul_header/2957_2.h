#include <sys/socket.h>
#include <stdatomic.h>

struct kiocb;
struct socket {
    struct sock *sk;
};
struct msghdr;
struct sock {
    atomic_int sk_rmem_alloc;
    int sk_rcvbuf;
};
struct rfcomm_dlc {
    unsigned long flags;
};
struct rfcomm_pi {
    struct rfcomm_dlc *dlc;
};

#define RFCOMM_DEFER_SETUP 0

int test_and_clear_bit(int nr, volatile unsigned long *addr);
void rfcomm_dlc_accept(struct rfcomm_dlc *d);
int bt_sock_stream_recvmsg(struct kiocb *iocb, struct socket *sock, struct msghdr *msg, size_t size, int flags);
void lock_sock(struct sock *sk);
void release_sock(struct sock *sk);
void rfcomm_dlc_unthrottle(struct rfcomm_dlc *d);
struct rfcomm_pi *rfcomm_pi(struct sock *sk);