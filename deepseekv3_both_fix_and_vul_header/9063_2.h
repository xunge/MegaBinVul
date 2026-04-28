#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

typedef uint32_t __be32;
typedef unsigned int gfp_t;

#define ENOMEM 12
#define ENODEV 19
#define ERR_PTR(err) ((void *)(long)(err))
#define RDS_CONN_DOWN 0

struct net;
struct rds_transport;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    void (*func)(struct work_struct *work);
};

struct delayed_work {
    struct work_struct work;
};

struct rds_connection {
    struct hlist_node c_hash_node;
    __be32 c_laddr;
    __be32 c_faddr;
    pthread_spinlock_t c_lock;
    unsigned int c_next_tx_seq;
    pthread_cond_t c_waitq;
    struct list_head c_send_queue;
    struct list_head c_retrans;
    int c_loopback;
    struct rds_transport *c_trans;
    void *c_transport_data;
    atomic_int c_state;
    unsigned int c_send_gen;
    int c_outgoing;
    unsigned long c_reconnect_jiffies;
    struct delayed_work c_send_w;
    struct delayed_work c_recv_w;
    struct delayed_work c_conn_w;
    struct work_struct c_down_w;
    pthread_mutex_t c_cm_lock;
    unsigned long c_flags;
    struct rds_connection *c_passive;
    struct net *c_net;
};

struct rds_transport {
    const char *t_name;
    int (*conn_alloc)(struct rds_connection *conn, gfp_t gfp);
    void (*conn_free)(void *transport_data);
    int t_prefer_loopback;
};

extern struct rds_transport rds_loop_transport;
extern pthread_spinlock_t rds_conn_lock;
extern atomic_int rds_conn_count;
extern void *rds_conn_slab;

static inline void INIT_HLIST_NODE(struct hlist_node *h) {
    h->next = NULL;
    h->pprev = NULL;
}

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void spin_lock_init(pthread_spinlock_t *lock) {
    pthread_spin_init(lock, 0);
}

static inline void mutex_init(pthread_mutex_t *mutex) {
    pthread_mutex_init(mutex, NULL);
}

static inline void init_waitqueue_head(pthread_cond_t *cond) {
    pthread_cond_init(cond, NULL);
}

static inline void atomic_set(atomic_int *v, int i) {
    atomic_store(v, i);
}

static inline void *kmem_cache_zalloc(void *cache, gfp_t gfp) {
    return calloc(1, sizeof(struct rds_connection));
}

static inline void kmem_cache_free(void *cache, void *obj) {
    free(obj);
}

static inline void rds_conn_net_set(struct rds_connection *conn, struct net *net) {
    conn->c_net = net;
}

static inline struct hlist_head *rds_conn_bucket(__be32 laddr, __be32 faddr) {
    return NULL;
}

static inline struct rds_connection *rds_conn_lookup(struct net *net, struct hlist_head *head,
                    __be32 laddr, __be32 faddr, struct rds_transport *trans) {
    return NULL;
}

static inline struct rds_transport *rds_trans_get_preferred(struct net *net, __be32 addr) {
    return NULL;
}

static inline void rds_trans_put(struct rds_transport *trans) {
}

static inline int rds_cong_get_maps(struct rds_connection *conn) {
    return 0;
}

static inline void rds_cong_add_conn(struct rds_connection *conn) {
}

static inline void rdsdebug(const char *fmt, ...) {
}

static inline void hlist_add_head_rcu(struct hlist_node *n, struct hlist_head *h) {
    n->next = h->first;
    if (h->first)
        h->first->pprev = &n->next;
    h->first = n;
    n->pprev = &h->first;
}

static inline void INIT_WORK(struct work_struct *work, void (*func)(struct work_struct *)) {
    work->func = func;
}

static inline void INIT_DELAYED_WORK(struct delayed_work *dwork, void (*func)(struct work_struct *)) {
    INIT_WORK(&dwork->work, func);
}

static void rds_send_worker(struct work_struct *work) {
}

static void rds_recv_worker(struct work_struct *work) {
}

static void rds_connect_worker(struct work_struct *work) {
}

static void rds_shutdown_worker(struct work_struct *work) {
}