#include <stddef.h>
#include <stdint.h>

struct sk_buff {
    void *sk;
};
struct nlmsghdr {
    uint32_t nlmsg_seq;
};
struct nlattr;
struct net {
    void *crypto_nlsk;
};
struct crypto_user_alg {
    char *cru_name;
    char *cru_driver_name;
};
struct crypto_alg;

struct crypto_dump_info {
    struct sk_buff *in_skb;
    struct sk_buff *out_skb;
    uint32_t nlmsg_seq;
    uint16_t nlmsg_flags;
};

#define EINVAL 22
#define ENOENT 2
#define ENOMEM 12
#define GFP_ATOMIC 0
#define NLMSG_DEFAULT_SIZE 1024

struct net *sock_net(void *sk);
void *nlmsg_data(struct nlmsghdr *nlh);
int null_terminated(char *s);
struct crypto_alg *crypto_alg_match(struct crypto_user_alg *p, int exact);
struct sk_buff *nlmsg_new(size_t size, int flags);
int crypto_reportstat_alg(struct crypto_alg *alg, struct crypto_dump_info *info);
void crypto_mod_put(struct crypto_alg *alg);
int nlmsg_unicast(void *sk, struct sk_buff *skb, uint32_t portid);
struct { uint32_t portid; } NETLINK_CB(struct sk_buff *skb);