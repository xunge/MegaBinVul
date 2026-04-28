#include <stddef.h>

struct sock {
    struct proto *sk_prot;
};

struct list_head {
    struct list_head *next, *prev;
};

struct sctp_sock {
    struct sctp_endpoint *ep;
    int do_auto_asconf;
    struct list_head auto_asconf_list;
};

struct sctp_endpoint;

struct net {
    struct {
        struct {
            int addr_wq_lock;
        } sctp;
    };
};

struct proto;

typedef struct {
    int lock;
} spinlock_t;

#define pr_debug(fmt, ...) 

extern void sctp_endpoint_free(struct sctp_endpoint *);
extern struct sctp_sock *sctp_sk(const struct sock *sk);
extern void sk_sockets_allocated_dec(struct sock *sk);
extern void sock_prot_inuse_add(struct net *net, struct proto *prot, int val);
extern struct net *sock_net(struct sock *sk);
extern void spin_lock_bh(spinlock_t *lock);
extern void spin_unlock_bh(spinlock_t *lock);
extern void list_del(struct list_head *entry);
extern void local_bh_disable(void);
extern void local_bh_enable(void);