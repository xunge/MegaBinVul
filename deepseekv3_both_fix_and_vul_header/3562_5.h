#include <stdint.h>
#include <stddef.h>

#define CRYPTOCFGA_MAX 0
#define CRYPTO_MSG_MAX 0
#define CRYPTO_MSG_BASE 0
#define CRYPTO_MSG_GETALG 0
#define CRYPTO_REPORT_MAXSIZE 0
#define NLM_F_DUMP 0
#define EINVAL 0
#define EPERM 0
#define CAP_NET_ADMIN 0

typedef uint16_t u16;

struct sk_buff;
struct nlmsghdr {
    int nlmsg_type;
    unsigned int nlmsg_flags;
};
struct nlattr;
struct nla_policy {
    unsigned int type;
    unsigned int len;
};
struct sock;

struct list_head {
    struct list_head *next, *prev;
};

struct crypto_alg {
    struct list_head cra_list;
};

struct crypto_link {
    int (*dump)(struct sk_buff*, struct nlmsghdr*);
    int (*done)(struct nlmsghdr*);
    int (*doit)(struct sk_buff*, struct nlmsghdr*, struct nlattr**);
};

struct netlink_dump_control {
    int (*dump)(struct sk_buff*, struct nlmsghdr*);
    int (*done)(struct nlmsghdr*);
    int min_dump_alloc;
};

extern struct list_head crypto_alg_list;
extern struct sock *crypto_nlsk;
extern const struct crypto_link crypto_dispatch[];
extern const struct nla_policy crypto_policy[];
extern const int crypto_msg_min[];

int capable(int cap);
int nlmsg_parse(const struct nlmsghdr *nlh, int hdrlen, struct nlattr *tb[], 
               int maxtype, const struct nla_policy *policy);
int netlink_dump_start(struct sock *ssk, struct sk_buff *skb, 
                      const struct nlmsghdr *nlh, 
                      struct netlink_dump_control *control);

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((char*)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(pos))((char*)pos->member.next - offsetof(typeof(*pos), member)))