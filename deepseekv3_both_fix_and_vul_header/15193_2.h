#include <string.h>
#include <stdio.h>

struct sk_buff {
    unsigned char *tail;
    unsigned char *data;
    int len;
};

struct netlink_callback {
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
};

struct nlmsghdr {
    unsigned int nlmsg_seq;
    unsigned short nlmsg_type;
    unsigned int nlmsg_len;
    unsigned int nlmsg_flags;
};

struct rtattr {
    unsigned short rta_len;
    unsigned short rta_type;
};

struct tc_action {
    struct tc_action_ops *ops;
};

struct tc_action_ops {
    int (*walk)(struct sk_buff *, struct netlink_callback *, int, struct tc_action *);
    void *owner;
};

struct tcamsg {
    unsigned char tca_family;
    unsigned char tca__pad1;
    unsigned short tca__pad2;
};

#define NETLINK_CB(skb) (*(struct { int pid; } *)(skb))
#define NLMSG_PUT(skb, pid, seq, type, len) ({ \
    struct nlmsghdr *__nlh = (struct nlmsghdr *)skb->tail; \
    __nlh->nlmsg_type = (type); \
    __nlh->nlmsg_seq = (seq); \
    __nlh->nlmsg_flags = 0; \
    __nlh; \
})
#define NLMSG_DATA(nlh) ((void *)((char *)(nlh) + sizeof(struct nlmsghdr)))
#define RTA_PUT(skb, type, len, data) ({ \
    struct rtattr *__rta = (struct rtattr *)skb->tail; \
    __rta->rta_type = (type); \
    __rta->rta_len = (len); \
    __rta; \
})

#define AF_UNSPEC 0
#define TCA_ACT_TAB 1
#define RTM_GETACTION 2
#define NLM_F_MULTI 0x2

typedef unsigned char u8;

char *find_dump_kind(struct nlmsghdr *nlh);
struct tc_action_ops *tc_lookup_action_n(char *kind);
void module_put(void *owner);
void skb_trim(struct sk_buff *skb, unsigned char *pos);
void printk(const char *fmt, ...);