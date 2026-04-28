#include <stdbool.h>
#include <errno.h>

#define TCPF_ESTABLISHED  (1 << 1)
#define TCPF_SYN_RECV     (1 << 2) 
#define TCPF_CLOSE_WAIT   (1 << 3)
#define TCPF_CLOSE        (1 << 4)

#define SS_CONNECTED 1

#define WARN_ON(condition) ((void)0)
#define READ_ONCE(x) (x)

struct socket {
    struct sock *sk;
    int state;
};

struct sock {
    int sk_state;
    struct {
        struct sock* (*accept)(struct sock*, int, int*, bool);
    } *sk_prot;
};

void lock_sock(struct sock *sk);
void release_sock(struct sock *sk);
void sock_rps_record_flow(struct sock *sk);
void sock_graft(struct sock *sk, struct socket *sock);