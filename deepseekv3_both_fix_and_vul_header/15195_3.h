#include <stdint.h>
#include <string.h>
#include <errno.h>

typedef uint32_t u32;
typedef uint8_t u8;

#define TCA_ACT_MAX 10
#define TCA_ACT_KIND 1
#define TCA_ACT_TAB 2
#define NLMSG_GOODSIZE 4096
#define GFP_KERNEL 0
#define AF_UNSPEC 0
#define RTM_DELACTION 0
#define RTMGRP_TC 0
#define NLM_F_ROOT 0x100
#define NLM_F_ECHO 0x08
#define EINVAL 22
#define ENOBUFS 105

struct rtattr {
    unsigned short rta_len;
    unsigned short rta_type;
};

struct nlmsghdr {
    uint32_t nlmsg_len;
    uint16_t nlmsg_type;
    uint16_t nlmsg_flags;
    uint32_t nlmsg_seq;
    uint32_t nlmsg_pid;
};

struct tcamsg {
    unsigned char tca_family;
    unsigned char tca__pad1;
    unsigned short tca__pad2;
};

struct netlink_callback {
    // dummy structure
};

struct sk_buff {
    unsigned char *tail;
};

struct tc_action;

struct tc_action_ops {
    int (*walk)(struct sk_buff *, struct netlink_callback *, int, struct tc_action *);
    void *owner;
};

struct tc_action {
    struct tc_action_ops *ops;
};

static inline void *NLMSG_DATA(struct nlmsghdr *nlh) { return (void*)(nlh + 1); }
static inline struct nlmsghdr *NLMSG_PUT(struct sk_buff *skb, uint32_t pid, uint32_t seq, int type, int len) { return NULL; }
static inline void RTA_PUT(struct sk_buff *skb, int type, int len, void *data) {}
static inline int rtattr_parse_nested(struct rtattr **tb, int max, struct rtattr *rta) { return 0; }
static inline struct sk_buff *alloc_skb(unsigned int size, int flags) { return NULL; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void kfree(void *obj) {}
static inline void module_put(void *module) {}
static inline int rtnetlink_send(struct sk_buff *skb, uint32_t pid, int group, int flags) { return 0; }
static inline void printk(const char *fmt, ...) {}

static struct tc_action *create_a(int dummy) { return NULL; }
static struct tc_action_ops *tc_lookup_action(struct rtattr *kind) { return NULL; }