#include <stdatomic.h>
#include <stdint.h>

enum {
    ROSE_STATE_0,
    ROSE_STATE_3
};

#define ROSE_COND_OWN_RX_BUSY 1
#define ROSE_COND_ACK_PENDING 2
#define ROSE_RR 3

struct timer_list {
    int dummy;
};

struct sock {
    int sk_state;
    int sk_rcvbuf;
    _Atomic int sk_rmem_alloc;
    struct timer_list sk_timer;
};

struct rose_sock {
    unsigned int state;
    unsigned int condition;
    unsigned char vl;
    unsigned char vr;
};

#define rose_sk(sk) ((struct rose_sock *)sk)
#define from_timer(var, timer, member) (var)
#define bh_lock_sock(sk) 
#define bh_unlock_sock(sk) 
#define sock_flag(sk, flag) 0
#define SOCK_DESTROY 0
#define SOCK_DEAD 0
#define TCP_LISTEN 0

static inline int atomic_read(const _Atomic int *v) {
    return *v;
}

void rose_destroy_socket(struct sock *sk);
void rose_write_internal(struct sock *sk, int type);
void rose_stop_timer(struct sock *sk);
void rose_start_heartbeat(struct sock *sk);