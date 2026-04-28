#include <stdatomic.h>
#include <stddef.h>

#define SOCK_BINDPORT_LOCK 1
#define SOCK_DONE 2
#define SOCK_TIMESTAMP 4
#define SOCK_TIMESTAMPING_RX_SOFTWARE 8
#define unlikely(x) (x)

typedef unsigned int gfp_t;

struct sk_buff;
struct sock;
struct sk_filter;
struct proto;
struct net;

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    unsigned int qlen;
};

struct sock {
    struct {
        struct sk_buff *head;
        struct sk_buff *tail;
        int len;
    } sk_backlog;
    struct sk_buff_head sk_receive_queue;
    struct sk_buff_head sk_write_queue;
    struct sk_buff_head sk_error_queue;
    atomic_int sk_rmem_alloc;
    atomic_int sk_wmem_alloc;
    atomic_int sk_omem_alloc;
    atomic_int sk_refcnt;
    unsigned int sk_wmem_queued;
    unsigned int sk_forward_alloc;
    struct sk_buff *sk_send_head;
    int sk_err;
    int sk_priority;
    unsigned long sk_userlocks;
    struct sk_filter *sk_filter;
    void *sk_destruct;
    void *sk_socket;
    void *sk_sleep;
    void *sk_dst_cache;
    void *sk_node;
    void *sk_dst_lock;
    void *sk_callback_lock;
    struct proto *sk_prot;
    int sk_family;
};

struct proto {
    int *sockets_allocated;
};

static void *af_callback_keys;
static const char *af_family_clock_key_strings[32];

static inline void atomic_set(atomic_int *v, int i) { *v = i; }
static inline void skb_queue_head_init(struct sk_buff_head *list) {
    list->next = (struct sk_buff *)list;
    list->prev = (struct sk_buff *)list;
    list->qlen = 0;
}
static inline void sock_copy(struct sock *newsk, const struct sock *sk) {}
static inline void sock_lock_init(struct sock *sk) {}
static inline void bh_lock_sock(struct sock *sk) {}
static inline void sock_reset_flag(struct sock *sk, int flag) {}
static inline void sk_filter_charge(struct sock *sk, struct sk_filter *filter) {}
static inline void sk_refcnt_debug_inc(struct sock *sk) {}
static inline void sk_set_socket(struct sock *sk, void *sock) {}
static inline void net_enable_timestamp(void) {}
static inline int xfrm_sk_clone_policy(struct sock *sk) { return 0; }
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline void get_net(struct net *net) {}
static inline void sk_node_init(void *node) {}
static inline struct sock *sk_prot_alloc(struct proto *prot, gfp_t priority, int family) { return NULL; }
static inline void rwlock_init(void *lock) {}
static inline void lockdep_set_class_and_name(void *lock, void *keys, const char *name) {}
static inline void smp_wmb(void) {}
static inline void sk_free(struct sock *sk) {}
static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline void percpu_counter_inc(int *counter) { if(counter) (*counter)++; }