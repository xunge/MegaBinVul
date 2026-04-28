#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define GFP_KERNEL 0
#define ENOBUFS 105
#define NLMSG_GOODSIZE 1024
#define AF_UNSPEC 0
#define TCA_ACT_TAB 1
#define RTMGRP_TC 1
#define NLM_F_ECHO 0x02

struct tc_action;
struct netlink_skb_parms {
    u32 dst_groups;
};
struct sk_buff {
    unsigned char *tail;
    unsigned char *data;
    struct netlink_skb_parms cb;
};
struct nlmsghdr {
    u32 nlmsg_len;
};
struct tcamsg {
    unsigned char tca_family;
    unsigned char tca__pad1;
    unsigned short tca__pad2;
};
struct rtattr {
    unsigned short rta_len;
    unsigned short rta_type;
};
#define NETLINK_CB(skb) ((skb)->cb)

static inline struct sk_buff *alloc_skb(unsigned int size, int flags) { return NULL; }
static inline void skb_trim(struct sk_buff *skb, unsigned int len) {}
static inline int rtnetlink_send(struct sk_buff *skb, u32 pid, u32 group, int flags) { return 0; }
static inline int tcf_action_dump(struct sk_buff *skb, struct tc_action *a, int start, int end) { return 0; }

#define NLMSG_NEW(skb, pid, seq, type, len, flags) \
    ({ struct nlmsghdr *__nlh = (struct nlmsghdr*)(skb)->tail; __nlh; })
#define NLMSG_DATA(nlh) ((void*)((char*)(nlh) + sizeof(struct nlmsghdr)))
#define RTA_PUT(skb, attrtype, attrlen, data) \
    ({ struct rtattr *__rta = (struct rtattr*)(skb)->tail; __rta; })