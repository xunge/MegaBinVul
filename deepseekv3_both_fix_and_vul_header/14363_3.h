#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t u8;
typedef unsigned int gfp_t;
typedef unsigned long flags_t;

struct net;
struct hlist_head {
    struct hlist_node *first;
};
struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct in6_addr {
    unsigned char s6_addr[16];
};

struct rds_conn_path {
    void *cp_transport_data;
    int cp_index;
};

struct rds_connection;

struct rds_transport {
    int t_mp_capable;
    int t_prefer_loopback;
    char t_name[32];
    int (*conn_alloc)(struct rds_connection *, gfp_t);
    void (*conn_free)(void *);
};

struct rds_connection {
    struct hlist_node c_hash_node;
    struct in6_addr c_laddr;
    struct in6_addr c_faddr;
    int c_isv6;
    int c_dev_if;
    int c_bound_if;
    u8 c_tos;
    int c_loopback;
    struct rds_transport *c_trans;
    struct rds_conn_path *c_path;
    struct rds_connection *c_passive;
    unsigned int c_my_gen_num;
    unsigned int c_peer_gen_num;
    void *c_hs_waitq;
};

#define RDS_MPATH_WORKERS 1
#define ENOMEM 12
#define EOPNOTSUPP 95
#define ENETDOWN 100
#define GFP_ATOMIC 0
#define IS_ENABLED(x) 0
#define IPV6_ADDR_LINKLOCAL 0
#define likely(x) (x)

extern struct kmem_cache *rds_conn_slab;
extern struct rds_transport rds_loop_transport;
extern unsigned int rds_gen_num;
extern int rds_conn_count;

static inline int ipv6_addr_equal(const struct in6_addr *a1, const struct in6_addr *a2) {
    return memcmp(a1, a2, sizeof(struct in6_addr)) == 0;
}

static inline int ipv6_addr_v4mapped(const struct in6_addr *a) {
    return 0;
}

static inline unsigned int ipv6_addr_type(const struct in6_addr *a) {
    return 0;
}

#define INIT_HLIST_NODE(node) do { (node)->next = NULL; (node)->pprev = NULL; } while (0)
#define rcu_read_lock() do { } while (0)
#define rcu_read_unlock() do { } while (0)
#define spin_lock_irqsave(lock, flags) do { } while (0)
#define spin_unlock_irqrestore(lock, flags) do { } while (0)
#define hlist_add_head_rcu(node, head) do { } while (0)

static void *kmem_cache_zalloc(struct kmem_cache *cache, gfp_t flags) {
    return calloc(1, sizeof(struct rds_connection));
}

static void kmem_cache_free(struct kmem_cache *cache, void *obj) {
    free(obj);
}

static void *kcalloc(size_t n, size_t size, gfp_t flags) {
    return calloc(n, size);
}

static void kfree(void *ptr) {
    free(ptr);
}

#define ERR_PTR(err) ((void *)(intptr_t)(err))

static void init_waitqueue_head(void *wq) {}

static struct hlist_head *rds_conn_bucket(const struct in6_addr *laddr, const struct in6_addr *faddr) {
    return NULL;
}

static struct rds_connection *rds_conn_lookup(struct net *net, struct hlist_head *head,
                                             const struct in6_addr *laddr,
                                             const struct in6_addr *faddr,
                                             struct rds_transport *trans,
                                             u8 tos, int dev_if) {
    return NULL;
}

static struct rds_transport *rds_trans_get_preferred(struct net *net,
                                                    const struct in6_addr *addr,
                                                    int dev_if) {
    return NULL;
}

static void rds_trans_put(struct rds_transport *trans) {}

static void __rds_conn_path_init(struct rds_connection *conn,
                                struct rds_conn_path *cp, int is_outgoing) {}

static int rds_destroy_pending(struct rds_connection *conn) {
    return 0;
}

static void rds_conn_net_set(struct rds_connection *conn, struct net *net) {}

static int rds_cong_get_maps(struct rds_connection *conn) {
    return 0;
}

static void rds_cong_add_conn(struct rds_connection *conn) {}

#define rdsdebug(fmt, ...) do { } while (0)