#include <stddef.h>

#define UDP_HTABLE_SIZE 128

typedef struct {
    int lock;
} rwlock_t;

struct proto;

struct sock {
    unsigned short sk_hash;
    int sk_reuse;
    int sk_bound_dev_if;
    struct proto *sk_prot;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct inet_sock {
    int num;
    unsigned long rcv_saddr;
};

static rwlock_t udp_hash_lock;
static int sysctl_local_port_range[2];

#define sk_for_each(__sk, __node, __head) \
    for (__node = (__head)->first; __node != NULL; __node = __node->next)

static inline void write_lock_bh(rwlock_t *lock) { lock->lock = 1; }
static inline void write_unlock_bh(rwlock_t *lock) { lock->lock = 0; }
static inline int hlist_empty(struct hlist_head *h) { return !h->first; }
static inline void sk_add_node(struct sock *sk, struct hlist_head *list) {}
static inline void sock_prot_inc_use(struct proto *prot) {}
static inline int sk_unhashed(struct sock *sk) { return 0; }
static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static inline unsigned int hash_port_and_addr(unsigned int port, unsigned long addr) { return 0; }
static inline int __udp_lib_port_inuse(unsigned int hash, int port, unsigned long addr, struct hlist_head udptable[]) { return 0; }