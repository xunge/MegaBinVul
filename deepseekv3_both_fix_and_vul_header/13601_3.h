#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    unsigned long data;
};

struct socket {
    struct sock *sk;
};

struct sock {
    struct proto *sk_prot;
};

struct proto {
    void (*disconnect)(struct sock *sk, int flags);
};

struct net;

struct rds_connection {
    struct net *c_net;
    struct rds_connection *c_passive;
};

struct rds_tcp_connection {
    struct rds_connection *conn;
    struct socket *t_sock;
    struct list_head t_tcp_node;
};

struct rds_tcp_net {
    struct socket *rds_tcp_listen_sock;
    struct work_struct rds_tcp_accept_w;
};

typedef int spinlock_t;

extern struct list_head rds_tcp_conn_list;
extern spinlock_t rds_tcp_conn_lock;
extern int rds_tcp_netid;

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void rds_tcp_listen_stop(struct socket *sock);
void flush_work(struct work_struct *work);
struct net *read_pnet(const void *pnet);
void tcp_done(struct sock *sk);
void rds_conn_destroy(struct rds_connection *conn);
void spin_lock_irq(spinlock_t *lock);
void spin_unlock_irq(spinlock_t *lock);
void list_move_tail(struct list_head *list, struct list_head *head);
struct rds_tcp_net *net_generic(struct net *net, int id);