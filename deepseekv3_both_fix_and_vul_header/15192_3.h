#include <stdint.h>
#include <sys/socket.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

struct sk_buff {
    unsigned char *tail;
    unsigned char *data;
    int len;
};

struct tc_action;

struct nlmsghdr {
    u32 nlmsg_len;
    u16 nlmsg_type;
    u16 nlmsg_flags;
    u32 nlmsg_seq;
    u32 nlmsg_pid;
};

struct rtattr {
    unsigned short rta_len;
    unsigned short rta_type;
};

struct tcamsg {
    unsigned char tca_family;
    unsigned char tca__pad1;
    unsigned short tca__pad2;
};

#define NLMSG_NEW(skb, pid, seq, type, len, flags) \
    ({ (struct nlmsghdr *)skb->tail; })
#define NLMSG_DATA(nlh) ((void*)((char*)(nlh) + sizeof(struct nlmsghdr)))
#define RTA_PUT(skb, attrtype, attrlen, data) \
    ({ if (0) goto rtattr_failure; })
#define TCA_ACT_TAB 1

static int tcf_action_dump(struct sk_buff *skb, struct tc_action *a, int bind, int ref) {
    return 0;
}

static void skb_trim(struct sk_buff *skb, int len) {
    skb->len = len;
}