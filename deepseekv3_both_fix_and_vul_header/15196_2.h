#include <stdatomic.h>
#include <string.h>
#include <stdint.h>

struct sk_buff {
    struct {
        struct iphdr *iph;
    } nh;
    int dst_pid;
};

struct iphdr {
    uint8_t version;
};

struct nlmsghdr {
    uint32_t nlmsg_type;
    uint32_t nlmsg_len;
};

struct nlmsgerr {
    int error;
    struct nlmsghdr msg;
};

struct sk_buff_head {
    struct sk_buff *next;
};

struct mfc_cache {
    struct {
        struct {
            struct sk_buff_head unresolved;
        } unres;
    } mfc_un;
};

#define NLMSG_ERROR 0x2
#define NLMSG_LENGTH(len) ((len) + sizeof(struct nlmsghdr))
#define NLMSG_DATA(nlh) ((void*)((char*)(nlh) + sizeof(struct nlmsghdr)))
#define MSG_DONTWAIT 0
#define ETIMEDOUT 110

extern atomic_int cache_resolve_queue_len;
extern void* mrt_cachep;
extern void* rtnl;

struct sk_buff* skb_dequeue(struct sk_buff_head* head);
void* skb_pull(struct sk_buff* skb, unsigned int len);
void skb_trim(struct sk_buff* skb, unsigned int len);
void netlink_unicast(void* rtnl, struct sk_buff* skb, int pid, int flags);
void kfree_skb(struct sk_buff* skb);
void kmem_cache_free(void* cachep, void* obj);

#define NETLINK_CB(skb) (*(struct { int dst_pid; }*)&(skb)->dst_pid)