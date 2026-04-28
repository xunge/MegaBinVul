#include <stdbool.h>
#include <stddef.h>

struct sk_buff;
struct device;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct mctp_sk_key {
    struct sk_buff *reasm_head;
    bool manual_alloc;
    bool reasm_dead;
    bool valid;
    struct device *dev;
    int lock;
    struct hlist_node hlist;
    struct hlist_node sklist;
};

struct net {
    struct {
        int keys_lock;
    } mctp;
};

#define __releases(x)
#define trace_mctp_key_release(key, reason) 
#define mctp_dev_release_key(dev, key) 
#define spin_unlock_irqrestore(lock, flags) 
#define spin_lock_irqsave(lock, flags) 
#define hlist_del(node) 
#define mctp_key_unref(key) 
#define kfree_skb(skb)