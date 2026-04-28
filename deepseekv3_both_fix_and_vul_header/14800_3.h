#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

typedef uint32_t __be32;
typedef unsigned int gfp_t;

struct net;
struct hlist_head {
    struct hlist_node *first;
};
struct hlist_node {
    struct hlist_node *next, **pprev;
};
struct list_head {
    struct list_head *next, *prev;
};
struct work_struct {
    void *data;
};

struct rds_transport {
    int t_type;
    int (*t_prefer_loopback)(void);
    int (*conn_alloc)(void *, gfp_t);
    void (*conn_free)(void *);
    char *t_name;
};

struct rds_connection {
    struct hlist_node c_hash_node;
    __be32 c_laddr;
    __be32 c_faddr;
    pthread_spinlock_t c_lock;
    int c_next_tx_seq;
    void *c_waitq;
    struct list_head c_send_queue;
    struct list_head c_retrans;
    int c_loopback;
    struct rds_transport *c_trans;
    void *c_transport_data;
    int c_state;
    int c_send_gen;
    int c_reconnect_jiffies;
    struct work_struct c_send_w;
    struct work_struct c_recv_w;
    struct work_struct c_conn_w;
    struct work_struct c_down_w;
    pthread_mutex_t c_cm_lock;
    int c_flags;
    struct rds_connection *c_passive;
};

#define RDS_TRANS_TCP 0
#define RDS_CONN_DOWN 0
#define ENOMEM (-1)
#define ENODEV (-2)

#define INIT_HLIST_NODE(node) do { \
    (node)->next = NULL; \
    (node)->pprev = NULL; \
} while (0)

#define INIT_LIST_HEAD(head) do { \
    (head)->next = (head); \
    (head)->prev = (head); \
} while (0)

#define INIT_WORK(work, func) 
#define INIT_DELAYED_WORK(work, func) 
#define spin_lock_init(lock) pthread_spin_init(lock, 0)
#define spin_lock_irqsave(lock, flags) pthread_spin_lock(lock)
#define spin_unlock_irqrestore(lock, flags) pthread_spin_unlock(lock)
#define mutex_init(lock) pthread_mutex_init(lock, NULL)
#define atomic_set(ptr, val) (*(ptr) = val)
#define rcu_read_lock() 
#define rcu_read_unlock() 
#define ERR_PTR(err) ((void*)(long)(err))

extern struct kmem_cache *rds_conn_slab;
extern pthread_spinlock_t rds_conn_lock;
extern int rds_conn_count;
extern struct rds_transport rds_loop_transport;

static inline void hlist_add_head_rcu(struct hlist_node *n, struct hlist_head *h) {
    n->next = h->first;
    n->pprev = &h->first;
    if (h->first)
        h->first->pprev = &n->next;
    h->first = n;
}

static inline void rdsdebug(const char *fmt, ...) {}

struct hlist_head *rds_conn_bucket(__be32 laddr, __be32 faddr);
struct rds_connection *rds_conn_lookup(struct net *net, struct hlist_head *head,
                                      __be32 laddr, __be32 faddr,
                                      struct rds_transport *trans);
struct rds_transport *rds_trans_get_preferred(struct net *net, __be32 addr);
void rds_trans_put(struct rds_transport *trans);
int rds_cong_get_maps(struct rds_connection *conn);
void rds_cong_add_conn(struct rds_connection *conn);
void rds_conn_net_set(struct rds_connection *conn, struct net *net);
void rds_send_worker(struct work_struct *work);
void rds_recv_worker(struct work_struct *work);
void rds_connect_worker(struct work_struct *work);
void rds_shutdown_worker(struct work_struct *work);

static inline void *kmem_cache_zalloc(struct kmem_cache *cache, gfp_t flags) {
    return calloc(1, sizeof(struct rds_connection));
}

static inline void kmem_cache_free(struct kmem_cache *cache, void *obj) {
    free(obj);
}

static inline void init_waitqueue_head(void *q) {}