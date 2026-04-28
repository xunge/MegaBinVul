#include <stdatomic.h>
#include <stddef.h>

#define SK_FLAGS_TIMESTAMP 0x1

struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct sock {
    void (*sk_destruct)(struct sock *);
    struct sk_filter *sk_filter;
    atomic_int sk_wmem_alloc;
    atomic_int sk_omem_alloc;
    struct {
        void *page;
    } sk_frag;
    void *sk_peer_cred;
    void *sk_peer_pid;
    int sk_net_refcnt;
    void *sk_prot_creator;
    struct rcu_head sk_rcu;
};

struct sk_filter;

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define rcu_dereference_check(p, c) (p)
#define RCU_INIT_POINTER(p, v) ((p) = (v))
#define refcount_read(r) atomic_load(r)
#define likely(x) (x)

static inline int atomic_read(const atomic_int *v) {
    return atomic_load(v);
}

void sock_disable_timestamp(struct sock *sk, int flags);
void sk_filter_uncharge(struct sock *sk, struct sk_filter *filter);
void put_cred(void *cred);
void put_pid(void *pid);
void *sock_net(struct sock *sk);
void put_net(void *net);
void sk_prot_free(void *prot, struct sock *sk);
void bpf_sk_storage_free(struct sock *sk);
int pr_debug(const char *fmt, ...);
void put_page(void *page);