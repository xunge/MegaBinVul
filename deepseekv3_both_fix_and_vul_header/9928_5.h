#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t canid_t;

struct list_head {
    struct list_head *next, *prev;
};

struct notifier_block {
    int (*notifier_call)(struct notifier_block *, unsigned long, void *);
    struct notifier_block *next;
    int priority;
};

struct socket {
    struct sock *sk;
};

struct sock {
    // basic sock fields
};

struct bcm_sock {
    struct list_head tx_ops;
    struct list_head rx_ops;
    int bound;
    int ifindex;
    char *procname;
    int bcm_proc_read;
    struct notifier_block notifier;
};

struct bcm_op {
    struct list_head list;
    struct bcm_op *next;
    int ifindex;
    int rx_reg_dev;
    canid_t can_id;
};

struct net_device {
    // basic net_device fields
};

struct sk_buff {
    // basic sk_buff fields
};

struct net {
    // basic net fields
};

struct proc_dir_entry;
extern struct net init_net;
extern struct proc_dir_entry *proc_dir;

static inline struct bcm_sock *bcm_sk(const struct sock *sk) { return (struct bcm_sock *)sk; }
static void bcm_remove_op(struct bcm_op *op) {}
static void bcm_rx_unreg(struct net_device *dev, struct bcm_op *op) {}
static void can_rx_unregister(struct net_device *dev, canid_t can_id, canid_t mask,
                             void (*func)(struct sk_buff *, void *), void *data) {}
static void bcm_rx_handler(struct sk_buff *skb, void *op) {}

#define REGMASK(id) ((id) & 0x1FFFFFFFU)

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

void unregister_netdevice_notifier(struct notifier_block *nb);
void lock_sock(struct sock *sk);
void release_sock(struct sock *sk);
void sock_orphan(struct sock *sk);
void sock_put(struct sock *sk);
struct net_device *dev_get_by_index(struct net *net, int ifindex);
void dev_put(struct net_device *dev);
void remove_proc_entry(const char *name, struct proc_dir_entry *parent);