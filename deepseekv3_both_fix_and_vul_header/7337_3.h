#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct socket {
    struct sock *sk;
};

struct sock {
    int dummy;
};

struct net {
    struct {
        struct {
            void *bcmproc_dir;
        } can;
    };
};

struct bcm_sock {
    struct list_head notifier;
    struct list_head tx_ops;
    struct list_head rx_ops;
    int bound;
    int ifindex;
    int bcm_proc_read;
    char *procname;
};

struct bcm_op {
    struct list_head list;
    int ifindex;
    int rx_reg_dev;
    int can_id;
};

struct net_device {
    int dummy;
};

int bcm_notifier_lock;
struct bcm_sock *bcm_busy_notifier;

static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline struct bcm_sock *bcm_sk(const struct sock *sk) { return NULL; }
static void bcm_rx_unreg(struct net_device *dev, struct bcm_op *op) {}
static void bcm_remove_op(struct bcm_op *op) {}
static void can_rx_unregister(struct net *net, struct net_device *dev, int can_id, int mask, void (*func)(void *, void *), void *data) {}
static void bcm_rx_handler(void *skb, void *op) {}

#define spin_lock(lock) 
#define spin_unlock(lock) 
#define schedule_timeout_uninterruptible(timeout) 
#define list_del(entry) 
#define list_for_each_entry_safe(pos, n, head, member) 
#define synchronize_rcu() 
#define lock_sock(sk) 
#define release_sock(sk) 
#define sock_orphan(sk) 
#define sock_put(sk) 
#define dev_get_by_index(net, ifindex) NULL
#define dev_put(dev) 
#define remove_proc_entry(name, parent) 
#define IS_ENABLED(x) 0
#define CONFIG_PROC_FS 0
#define REGMASK(x) 0