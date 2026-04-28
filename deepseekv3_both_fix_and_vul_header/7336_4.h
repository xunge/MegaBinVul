#include <stddef.h>

#define CAN_FD_FRAME 0x00000004
#define REGMASK(id) ((id) & 0x1FFFFFFF)

typedef unsigned int canid_t;

struct list_head {
    struct list_head *next, *prev;
};

struct sk_buff {
    // dummy definition
};

struct net_device;
struct sock;
struct net;

struct bcm_op {
    struct list_head list;
    canid_t can_id;
    int ifindex;
    unsigned int flags;
    struct sock *sk;
    struct net_device *rx_reg_dev;
};

struct bcm_msg_head {
    canid_t can_id;
    unsigned int flags;
};

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_del(entry) \
    do { \
        struct list_head *prev = (entry)->prev; \
        struct list_head *next = (entry)->next; \
        next->prev = prev; \
        prev->next = next; \
    } while (0)

static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline struct net_device *dev_get_by_index(struct net *net, int ifindex) { return NULL; }
static inline void dev_put(struct net_device *dev) {}
static inline void bcm_rx_unreg(struct net_device *dev, struct bcm_op *op) {}
static inline void can_rx_unregister(struct net *net, struct net_device *dev,
                                   canid_t can_id, canid_t mask,
                                   void (*func)(struct sk_buff *, void *),
                                   void *data) {}
static inline void bcm_rx_handler(struct sk_buff *skb, void *data) {}
static inline void bcm_remove_op(struct bcm_op *op) {}