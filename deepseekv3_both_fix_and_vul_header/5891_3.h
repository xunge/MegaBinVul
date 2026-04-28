#include <stddef.h>

#define SHUTDOWN_MASK 3
#define SCTP_SS_CLOSING 3
#define CLOSED 0
#define SOCK_LINGER 1
#define TCP 1

struct list_head {
    struct list_head *next, *prev;
};

struct sk_buff_head {
    struct list_head list;
};

struct sock {
    int sk_shutdown;
    int sk_state;
    struct sk_buff_head sk_receive_queue;
    unsigned long sk_lingertime;
};

struct net {
    struct {
        void *addr_wq_lock;
    } sctp;
};

struct sctp_endpoint {
    struct list_head asocs;
    struct sk_buff_head pd_lobby;
    void *ep;
};

struct sctp_association {
    struct list_head asocs;
    struct {
        struct sk_buff_head lobby;
        struct sk_buff_head reasm;
    } ulpq;
};

struct sctp_chunk;

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline void bh_lock_sock(struct sock *sk) {}
static inline void bh_unlock_sock(struct sock *sk) {}
static inline void sock_hold(struct sock *sk) {}
static inline void sock_put(struct sock *sk) {}
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline int sock_flag(struct sock *sk, int flag) { return 0; }

static inline unsigned int sctp_queue_purge_ulpevents(struct sk_buff_head *list) { return 0; }
static inline int sctp_style(struct sock *sk, int style) { return 0; }
static inline int sctp_state(struct sctp_association *asoc, int state) { return 0; }
static inline void sctp_unhash_established(struct sctp_association *asoc) {}
static inline void sctp_association_free(struct sctp_association *asoc) {}
static inline struct sctp_chunk *sctp_make_abort_user(struct sctp_association *asoc, void *arg, int len) { return NULL; }
static inline void sctp_primitive_ABORT(struct net *net, struct sctp_association *asoc, struct sctp_chunk *chunk) {}
static inline void sctp_primitive_SHUTDOWN(struct net *net, struct sctp_association *asoc, void *arg) {}
static inline void sctp_wait_for_close(struct sock *sk, long timeout) {}
static inline void sk_common_release(struct sock *sk) {}
static inline void spin_lock_bh(void *lock) {}
static inline void spin_unlock_bh(void *lock) {}
static inline int skb_queue_empty(struct sk_buff_head *list) { return 1; }
static inline struct sctp_endpoint *sctp_sk(struct sock *sk) { return (struct sctp_endpoint *)sk; }

#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)
#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#define pr_debug(fmt, ...)
#define SCTP_DBG_OBJCNT_DEC(type)