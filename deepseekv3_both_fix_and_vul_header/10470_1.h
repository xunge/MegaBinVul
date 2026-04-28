#include <stdatomic.h>
#include <string.h>
#include <netinet/in.h>

typedef unsigned int gfp_t;

#define TCP_SYN_RECV 0
#define SOCK_RCU_FREE 0

struct sock {
    int sk_state;
    void (*sk_write_space)(struct sock *sk);
    unsigned long sk_mark;
    atomic_ullong sk_cookie;
};

struct inet_connection_sock {
    void *icsk_bind_hash;
    int icsk_retransmits;
    int icsk_backoff;
    int icsk_probes_out;
    struct {
        int dummy;
    } icsk_accept_queue;
};

struct inet_sock {
    unsigned short inet_dport;
    unsigned short inet_num;
    unsigned short inet_sport;
    void *mc_list;
};

struct inet_request_sock {
    unsigned short ir_rmt_port;
    unsigned short ir_num;
    unsigned long ir_mark;
    atomic_ullong ir_cookie;
};

struct request_sock;

void sk_stream_write_space(struct sock *sk);
void security_inet_csk_clone(struct sock *newsk, const struct request_sock *req);

static inline struct inet_connection_sock *inet_csk(const struct sock *sk) { 
    return (struct inet_connection_sock *)sk; 
}
static inline struct inet_sock *inet_sk(const struct sock *sk) { 
    return (struct inet_sock *)sk; 
}
static inline struct inet_request_sock *inet_rsk(const struct request_sock *req) { 
    return (struct inet_request_sock *)req; 
}

struct sock *sk_clone_lock(const struct sock *sk, gfp_t priority);
void sock_reset_flag(struct sock *sk, int flag);