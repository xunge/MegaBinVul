#include <stddef.h>
#include <errno.h>

struct list_head {
    struct list_head *next, *prev;
};

struct sock;
struct net;

struct sctp_sock {
    int do_auto_asconf;
    struct list_head auto_asconf_list;
};

struct sctp_net {
    struct list_head auto_asconf_splist;
    void *addr_wq_lock;
};

struct net {
    struct sctp_net sctp;
};

extern struct sctp_sock *sctp_sk(struct sock *sk);
extern int sctp_is_ep_boundall(struct sock *sk);
extern struct net *sock_net(struct sock *sk);
extern void spin_lock_bh(void *lock);
extern void spin_unlock_bh(void *lock);
extern void list_del(struct list_head *entry);
extern void list_add_tail(struct list_head *new, struct list_head *head);
extern int get_user(int *val, const void *src);

#define __user
#define EINVAL 22
#define EFAULT 14