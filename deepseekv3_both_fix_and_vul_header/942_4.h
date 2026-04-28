#include <stdatomic.h>
#include <pthread.h>

struct sock;
struct list_head {
    struct list_head *next, *prev;
};
struct packet_sock {
    struct packet_fanout *fanout;
    void *rollover;
};
struct packet_fanout {
    atomic_int sk_ref;
    struct list_head list;
    void *prot_hook;
};
struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

extern pthread_mutex_t fanout_mutex;
extern struct rcu_head *rcu;
extern struct packet_sock *pkt_sk(struct sock *sk);
extern void fanout_release_data(struct packet_fanout *f);
extern void kfree(void *ptr);
extern void kfree_rcu(void *ptr, struct rcu_head *head);
extern void list_del(struct list_head *entry);
extern void dev_remove_pack(void *hook);
extern void mutex_lock(pthread_mutex_t *mutex);
extern void mutex_unlock(pthread_mutex_t *mutex);
extern _Bool atomic_dec_and_test(atomic_int *obj);