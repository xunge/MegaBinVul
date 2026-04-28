#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>

typedef _Atomic long atomic_long_t;

struct sock {
    void *sk_receive_queue;
    atomic_int sk_wmem_alloc;
    void *sk_prot;
    void *sk_socket;
    unsigned short sk_flags;
};

struct unix_sock {
    void *oob_skb;
    void *addr;
};

struct sk_buff;
struct unix_address;

#define SOCK_DEAD (1 << 0)
#define IS_ENABLED(x) 0
#define DEBUG_NET_WARN_ON_ONCE(x) 
#define UNIX_REFCNT_DEBUG

extern struct unix_sock *unix_sk(struct sock *sk);
extern atomic_long_t unix_nr_socks;
extern void unix_release_addr(struct unix_address *addr);
extern void skb_queue_purge(void *queue);
extern void kfree_skb(struct sk_buff *skb);
extern int sock_flag(struct sock *sk, int flag);
extern void sock_prot_inuse_add(void *net, void *prot, int val);
extern void *sock_net(struct sock *sk);
extern int refcount_read(atomic_int *ref);
extern int sk_unhashed(struct sock *sk);
extern void pr_info(const char *fmt, ...);
extern void pr_debug(const char *fmt, ...);