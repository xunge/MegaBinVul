#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define EMSGSIZE 90
#define EAGAIN 11
#define ENOTCONN 107

#define DCCPF_OPEN 1
#define DCCPF_PARTOPEN 2
#define DCCP_CLOSED 0

struct sock {
    int sk_state;
    struct {
        int max_header;
    } *sk_prot;
};

struct dccp_sock {
    int dccps_mss_cache;
    void *dccps_xmit_timer;
};

struct sk_buff {
    int dummy;
};

static inline struct dccp_sock *dccp_sk(const struct sock *sk) { return (struct dccp_sock *)sk; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int dccp_qpolicy_full(struct sock *sk) { return 0; }
static inline long sock_sndtimeo(struct sock *sk, int noblock) { return 0; }
static inline int sk_stream_wait_connect(struct sock *sk, long *timeo) { return 0; }
static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, int size, int noblock, int *rc) { return NULL; }
static inline void skb_reserve(struct sk_buff *skb, int size) {}
static inline void *skb_put(struct sk_buff *skb, int len) { return NULL; }
static inline int memcpy_from_msg(void *to, struct msghdr *msg, size_t len) { return 0; }
static inline int dccp_msghdr_parse(struct msghdr *msg, struct sk_buff *skb) { return 0; }
static inline void dccp_qpolicy_push(struct sock *sk, struct sk_buff *skb) {}
static inline int timer_pending(void *timer) { return 0; }
static inline void dccp_write_xmit(struct sock *sk) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void trace_dccp_probe(struct sock *sk, size_t len) {}