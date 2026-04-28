#include <stdbool.h>
#include <stddef.h>

struct net;
struct socket;

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    unsigned long data;
};

typedef struct {
    int lock;
} spinlock_t;

struct rds_tcp_connection;
struct rds_tcp_net;
struct rds_connection;
struct rds_path;

struct rds_tcp_connection {
    struct list_head t_tcp_node;
    bool t_tcp_node_detached;
    struct socket *t_sock;
    struct rds_path *t_cpath;
};

struct rds_path {
    struct rds_connection *cp_conn;
};

struct rds_connection {
    struct net *c_net;
};

struct rds_tcp_net {
    struct socket *rds_tcp_listen_sock;
    struct work_struct rds_tcp_accept_w;
};

extern spinlock_t rds_tcp_conn_lock;
extern struct list_head rds_tcp_conn_list;
extern unsigned int rds_tcp_netid;

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)
#define spin_lock_irq(lock) do { (void)(lock); } while (0)
#define spin_unlock_irq(lock) do { (void)(lock); } while (0)
#define list_for_each_entry_safe(pos, n, head, member) for (pos = NULL, n = NULL; pos != NULL; pos = NULL)
#define list_move_tail(list, head) do { (void)(list); (void)(head); } while (0)
#define list_del(entry) do { (void)(entry); } while (0)

static inline bool list_has_conn(struct list_head *head, struct rds_connection *conn) { return false; }
static inline void rds_tcp_listen_stop(struct socket *sock, struct work_struct *work) {}
static inline void rds_conn_destroy(struct rds_connection *conn) {}
static inline struct rds_tcp_net *net_generic(struct net *net, unsigned int id) { return NULL; }
static inline struct net *read_pnet(struct net **pnet) { return *pnet; }