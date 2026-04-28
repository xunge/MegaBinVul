#include <stdbool.h>
#include <stdatomic.h>
#include <stddef.h>

typedef unsigned int gfp_t;
typedef _Atomic int atomic_t;
typedef _Atomic long atomic64_t;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct proto {
    int (*sockets_allocated)(void);
};

struct sk_filter {
    // filter structure members
};

struct cgroup_sk {
    // cgroup structure members
};

struct socket {
    // socket structure members
};

struct sock {
    struct proto *sk_prot;
    int sk_family;
    struct proto *sk_prot_creator;
    atomic_t sk_net_refcnt;
    struct hlist_node sk_node;
    struct {
        void *head;
        void *tail;
        int len;
    } sk_backlog;
    atomic_t sk_rmem_alloc;
    atomic_t sk_wmem_alloc;
    atomic_t sk_omem_alloc;
    atomic_t sk_drops;
    atomic_t sk_zckey;
    void *sk_dst_cache;
    int sk_dst_pending_confirm;
    int sk_wmem_queued;
    int sk_forward_alloc;
    void *sk_send_head;
    int sk_userlocks;
    void *sk_memcg;
    struct cgroup_sk sk_cgrp_data;
    struct sk_filter *sk_filter;
    void *sk_reuseport_cb;
    int sk_err;
    int sk_err_soft;
    int sk_priority;
    int sk_incoming_cpu;
    atomic64_t sk_cookie;
    atomic_t sk_refcnt;
    void *sk_wq;
    int sk_flags;
};

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#define RCU_INIT_POINTER(p, v) ((p) = (v))
#define SOCK_BINDPORT_LOCK 0x01
#define SOCK_DONE 0x02
#define SK_FLAGS_TIMESTAMP 0x04

static inline void atomic_set(atomic_t *v, int i) { atomic_store(v, i); }
static inline void atomic64_set(atomic64_t *v, long i) { atomic_store(v, i); }
static inline void refcount_set(atomic_t *r, int n) { atomic_store(r, n); }

struct sock *sk_prot_alloc(const struct proto *prot, gfp_t priority, int family);
void sock_copy(struct sock *newsk, const struct sock *sk);
void *sock_net(const struct sock *sk);
void get_net(void *net);
void sk_node_init(struct hlist_node *node);
void sock_lock_init(struct sock *sk);
void bh_lock_sock(struct sock *sk);
void sk_init_common(struct sock *sk);
void sock_reset_flag(struct sock *sk, int flag);
void cgroup_sk_alloc(struct cgroup_sk *sk_cgrp_data);
bool sk_filter_charge(struct sock *sk, struct sk_filter *filter);
int xfrm_sk_clone_policy(struct sock *sk, const struct sock *osk);
void sk_free_unlock_clone(struct sock *sk);
void sk_refcnt_debug_inc(struct sock *sk);
void sk_set_socket(struct sock *sk, struct socket *sock);
void sk_tx_queue_clear(struct sock *sk);
void sk_sockets_allocated_inc(struct sock *sk);
bool sock_needs_netstamp(const struct sock *sk);
void net_enable_timestamp(void);
int raw_smp_processor_id(void);
void rcu_read_lock(void);
void rcu_read_unlock(void);
struct sk_filter *rcu_dereference(struct sk_filter *filter);
void smp_wmb(void);