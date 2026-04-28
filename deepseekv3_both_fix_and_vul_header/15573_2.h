#include <stddef.h>

struct sock;
struct net;

struct list_head {
    struct list_head *next, *prev;
};

struct inet_sock {
    struct sock *sk;
};

struct sctp_net {
    int default_auto_asconf;
    int addr_wq_lock;
    struct list_head auto_asconf_splist;
};

struct sctp_sock {
    struct inet_sock inet;
    struct list_head auto_asconf_list;
    int do_auto_asconf;
};

struct net {
    struct sctp_net sctp;
};

static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }
static inline void list_add_tail(struct list_head *new, struct list_head *head) { (void)new; (void)head; }
static inline struct net *sock_net(struct sock *sk) { (void)sk; return NULL; }