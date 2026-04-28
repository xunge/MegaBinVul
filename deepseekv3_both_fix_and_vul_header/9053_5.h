#include <stdatomic.h>
#include <pthread.h>

#define PF_UNIX 1
#define GFP_KERNEL 0

struct path {
    void *dentry;
    void *mnt;
};

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct wait_queue_head {
    pthread_mutex_t lock;
};

struct wait_queue_entry {
    unsigned int flags;
    void *private;
    void *func;
    struct list_head entry;
};

struct net {
    struct {
        int sysctl_max_dgram_qlen;
    } unx;
};

struct socket;

struct sock {
    void (*sk_write_space)(struct sock *sk);
    int sk_max_ack_backlog;
    void (*sk_destruct)(struct sock *sk);
    struct {
        pthread_mutex_t lock;
    } sk_receive_queue;
    struct proto *sk_prot;
};

struct unix_sock {
    struct path path;
    pthread_mutex_t lock;
    atomic_long inflight;
    struct list_head link;
    pthread_mutex_t readlock;
    struct wait_queue_head peer_wait;
    struct wait_queue_entry peer_wake;
};

struct proto {
    // proto structure members
};

struct proto unix_proto;

static atomic_long unix_nr_socks;
static pthread_mutex_t af_unix_sk_receive_queue_lock_key;

static inline int get_max_files() { return 1024; }
static inline struct sock *sk_alloc(struct net *net, int family, int priority, struct proto *prot, int kern) { return NULL; }
static inline void sock_init_data(struct socket *sock, struct sock *sk) {}
static inline void lockdep_set_class(pthread_mutex_t *lock, pthread_mutex_t *key) {}
static inline struct unix_sock *unix_sk(struct sock *sk) { return NULL; }
static inline void unix_insert_socket(void *list, struct sock *sk) {}
static inline void *unix_sockets_unbound(struct sock *sk) { return NULL; }
static inline void local_bh_disable() {}
static inline void sock_prot_inuse_add(struct net *net, struct proto *prot, int val) {}
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline void local_bh_enable() {}

void unix_write_space(struct sock *sk);
void unix_sock_destructor(struct sock *sk);
void unix_dgram_peer_wake_relay(struct wait_queue_entry *wq_entry, unsigned int mode, int sync, void *key);

static inline void atomic_long_inc(atomic_long *v) { (*v)++; }
static inline long atomic_long_read(atomic_long *v) { return *v; }
static inline void atomic_long_set(atomic_long *v, long i) { *v = i; }
static inline void atomic_long_dec(atomic_long *v) { (*v)--; }

static inline void spin_lock_init(pthread_mutex_t *lock) {
    pthread_mutex_init(lock, NULL);
}
static inline void mutex_init(pthread_mutex_t *lock) {
    pthread_mutex_init(lock, NULL);
}
static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list->prev = list;
}
static inline void init_waitqueue_head(struct wait_queue_head *wq_head) {
    pthread_mutex_init(&wq_head->lock, NULL);
}
static inline void init_waitqueue_func_entry(struct wait_queue_entry *wq_entry, void *func) {
    wq_entry->func = func;
}