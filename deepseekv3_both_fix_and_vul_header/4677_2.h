#include <stdint.h>

#define TIPC_NLA_SOCK_MAX 1
#define TIPC_NLA_SOCK_REF 0
#define TIPC_NLA_SOCK 1
#define EINVAL 22

typedef uint32_t u32;

struct sk_buff {
    void *sk;
    int len;
};

struct netlink_callback {
    uint32_t args[3];
    void *nlh;
};

struct net;
struct tipc_sock {
    struct {
        int dummy;
    } sk;
};

struct nlattr {
    uint32_t dummy;
};

struct nla_policy {
    int dummy;
};

extern struct nla_policy tipc_nl_sock_policy[];
extern int tipc_nlmsg_parse(void *nlh, struct nlattr ***attrs);
extern int nla_parse_nested(struct nlattr *tb[], int maxtype, struct nlattr *nla, const struct nla_policy *policy);
extern uint32_t nla_get_u32(const struct nlattr *nla);
extern struct net *sock_net(void *sk);
extern struct tipc_sock *tipc_sk_lookup(struct net *net, u32 portid);
extern void lock_sock(void *sk);
extern int __tipc_nl_list_sk_publ(struct sk_buff *skb, struct netlink_callback *cb, struct tipc_sock *tsk, u32 *last_publ);
extern void release_sock(void *sk);
extern void sock_put(void *sk);