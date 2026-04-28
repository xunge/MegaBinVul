#include <stdint.h>

typedef uint32_t u32;

struct net;

struct sk_buff {
    unsigned char cb[48];
    unsigned int len;
};

struct nlmsghdr {
    u32 nlmsg_seq;
    u32 nlmsg_flags;
};

struct Qdisc {
    u32 handle;
};

struct netlink_callback {
    u32 pid;
};

#define NETLINK_CB(skb) (*((struct netlink_callback *)&(skb)->cb[0]))

#define NLMSG_GOODSIZE 32768
#define GFP_KERNEL 0
#define NLM_F_REPLACE 0x100
#define NLM_F_ECHO 0x8
#define RTM_DELQDISC 0
#define RTM_NEWQDISC 0
#define RTNLGRP_TC 0
#define ENOBUFS 105
#define EINVAL 22

struct sk_buff *alloc_skb(unsigned int size, int flags);
void kfree_skb(struct sk_buff *skb);
int tc_fill_qdisc(struct sk_buff *skb, struct Qdisc *q, u32 clid, u32 pid, int seq, int flags, int cmd);
int rtnetlink_send(struct sk_buff *skb, struct net *net, u32 pid, unsigned int group, int echo);