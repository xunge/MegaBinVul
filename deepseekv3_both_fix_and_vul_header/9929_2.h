#include <stdlib.h>

struct socket {
    struct sock *sk;
};

struct sock;
struct net_device;
struct net;
struct notifier_block {
    int dummy;
};

extern struct net init_net;

struct raw_sock {
    struct notifier_block notifier;
    int bound;
    int ifindex;
    int count;
    void *filter;
};

static inline struct raw_sock *raw_sk(const struct sock *sk) { return (struct raw_sock *)sk; }
static void unregister_netdevice_notifier(struct notifier_block *nb) {}
static void lock_sock(struct sock *sk) {}
static void release_sock(struct sock *sk) {}
static void sock_orphan(struct sock *sk) {}
static void sock_put(struct sock *sk) {}
static void dev_put(struct net_device *dev) {}
static void raw_disable_allfilters(struct net_device *dev, struct sock *sk) {}
static struct net_device *dev_get_by_index(struct net *net, int ifindex) { return NULL; }
#define kfree free