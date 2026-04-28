#include <stdint.h>
#include <stddef.h>

struct sk_buff {
    void *sk;
};

struct nlmsghdr {
    uint32_t nlmsg_seq;
};

struct nlattr {};

struct net {
    void *crypto_nlsk;
};

struct crypto_user_alg {
    char *cru_name;
    char *cru_driver_name;
};

struct crypto_alg {};

struct crypto_dump_info {
    struct sk_buff *in_skb;
    struct sk_buff *out_skb;
    uint32_t nlmsg_seq;
    uint32_t nlmsg_flags;
};

struct NETLINK_CB {
    uint32_t portid;
};

#define EINVAL 22
#define ENOENT 2
#define ENOMEM 12
#define GFP_KERNEL 0
#define NLMSG_DEFAULT_SIZE 1024

static inline int null_terminated(const char *str) { return 1; }
static inline struct net *sock_net(void *sk) { return (struct net *)0; }
static inline struct crypto_user_alg *nlmsg_data(struct nlmsghdr *nlh) { return (struct crypto_user_alg *)0; }
static inline struct crypto_alg *crypto_alg_match(struct crypto_user_alg *p, int exact) { return (struct crypto_alg *)0; }
static inline struct sk_buff *nlmsg_new(size_t size, int flags) { return (struct sk_buff *)0; }
static inline int crypto_report_alg(struct crypto_alg *alg, struct crypto_dump_info *info) { return 0; }
static inline void crypto_mod_put(struct crypto_alg *alg) {}
static inline int nlmsg_unicast(void *sk, struct sk_buff *skb, uint32_t portid) { return 0; }
static inline struct NETLINK_CB NETLINK_CB(struct sk_buff *skb) { struct NETLINK_CB cb = {0}; return cb; }