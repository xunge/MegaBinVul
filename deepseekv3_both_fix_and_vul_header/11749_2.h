#include <errno.h>
#include <stddef.h>

struct net {
    struct user_namespace *user_ns;
};

struct sk_buff {
    void *sk;
};

struct user_namespace;

#define ERR_PTR(err) ((void *)((long)(err)))
#define EINVAL 22
#define EACCES 13
#define CAP_NET_ADMIN 12

struct net *get_net_ns_by_id(struct net *net, int id);
struct net *sock_net(void *sk);
void put_net(struct net *net);
int netlink_ns_capable(struct sk_buff *skb, struct user_namespace *ns, int cap);