#include <stdint.h>
#include <string.h>

typedef uint8_t u8;

struct iphdr {
    uint8_t version;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct mfc_cache {
    struct {
        struct {
            struct sk_buff_head unresolved;
        } unres;
    } mfc_un;
};

struct sk_buff {
    union {
        struct iphdr *iph;
    } nh;
    u8 *tail;
    struct {
        uint32_t dst_pid;
    } cb;
};

struct nlmsghdr {
    uint32_t nlmsg_len;
    uint16_t nlmsg_type;
};

struct nlmsgerr {
    int error;
    struct nlmsghdr msg;
};

#define NLMSG_DATA(nlh) ((void*)(((char*)nlh) + NLMSG_LENGTH(0)))
#define NLMSG_LENGTH(len) ((len) + ((sizeof(struct nlmsghdr) + 3) & ~3))
#define NETLINK_CB(skb) (skb->cb)
#define MSG_DONTWAIT 0x40
#define EMSGSIZE 90
#define NLMSG_ERROR 0x2

extern int ipmr_fill_mroute(struct sk_buff *skb, struct mfc_cache *c, void *data);
extern int netlink_unicast(void *rtnl, struct sk_buff *skb, uint32_t pid, int flags);
extern void ip_mr_forward(struct sk_buff *skb, struct mfc_cache *c, int vif);
extern struct sk_buff *__skb_dequeue(struct sk_buff_head *list);
extern u8 *skb_pull(struct sk_buff *skb, unsigned int len);
extern void skb_trim(struct sk_buff *skb, unsigned int len);

static void *rtnl;