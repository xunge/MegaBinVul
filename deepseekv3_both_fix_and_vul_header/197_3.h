#include <stddef.h>

struct sock {
    int sk_type;
};

struct inet_sock {
    int inet_num;
};

struct rcu_head {
    struct rcu_head *next;
};

struct ip_ra_chain {
    struct ip_ra_chain *next;
    struct sock *sk;
    void (*destructor)(struct sock *);
    struct sock *saved_sk;
    struct rcu_head rcu;
};

struct ipv4_struct {
    int ra_mutex;
    struct ip_ra_chain *ra_chain;
};

struct net {
    struct ipv4_struct ipv4;
};

#define IPPROTO_RAW 255
#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12
#define EADDRINUSE 98
#define ENOBUFS 105
#define SOCK_RAW 3
#define __rcu

static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline struct inet_sock *inet_sk(struct sock *sk) { return NULL; }
static inline void *kmalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline void mutex_lock(int *mutex) {}
static inline void mutex_unlock(int *mutex) {}
static inline void sock_hold(struct sock *sk) {}
static inline void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *)) {}
static inline struct ip_ra_chain *rcu_dereference_protected(struct ip_ra_chain *p, int condition) { return p; }
static inline void ip_ra_destroy_rcu(struct rcu_head *head) {}
#define RCU_INIT_POINTER(p, v) (p = v)
#define rcu_assign_pointer(p, v) (p = v)
#define lockdep_is_held(mutex) 0