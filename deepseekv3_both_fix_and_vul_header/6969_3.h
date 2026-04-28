#include <stdbool.h>
#include <stddef.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct net_device;
struct sk_buff;

struct mctp_sk_key {
    struct hlist_node hlist;
    struct hlist_node sklist;
    int lock;
    struct sk_buff *reasm_head;
    bool reasm_dead;
    bool valid;
    struct net_device *dev;
};

struct net {
    struct {
        struct hlist_head *keys;
        int keys_lock;
    } mctp;
};

#define __releases(x)
#define __must_hold(x)

void trace_mctp_key_release(struct mctp_sk_key *key, unsigned long reason);
void mctp_dev_release_key(struct net_device *dev, struct mctp_sk_key *key);
void mctp_key_unref(struct mctp_sk_key *key);
void kfree_skb(struct sk_buff *skb);
void spin_unlock_irqrestore(int *lock, unsigned long flags);
void hlist_del(struct hlist_node *n);