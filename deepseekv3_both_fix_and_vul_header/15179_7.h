#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef uint16_t __u16;

#define KERN_DEBUG ""
#define printk printf

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

struct sk_buff {
    unsigned int len;
    unsigned char *head;
    unsigned char *data;
    unsigned char *tail;
    unsigned char *end;
    unsigned int pkt_type;
    unsigned int headroom;
};

struct net_device {
    unsigned short type;
    unsigned int hard_header_len;
};

struct ddpehdr {
    __u16 deh_dnet;
    uint8_t deh_dnode;
    __u16 deh_len_hops;
};

struct ddp_dl {
    unsigned int header_length;
} *ddp_dl;

struct atalk_addr {
    __u16 s_net;
    uint8_t s_node;
};

struct atalk_route {
    unsigned int flags;
    struct atalk_addr gateway;
    struct net_device *dev;
};

#define PACKET_HOST 0
#define ARPHRD_PPP 512
#define RTF_GATEWAY 0x0002
#define NET_XMIT_DROP 1
#define NET_RX_DROP 1
#define NET_XMIT_SUCCESS 0
#define GFP_ATOMIC 0

static inline __u16 htons(__u16 x) {
    return ((x & 0xff) << 8) | ((x & 0xff00) >> 8);
}

static void kfree_skb(struct sk_buff *skb) {}
static struct sk_buff *skb_realloc_headroom(struct sk_buff *skb, int size) { return skb; }
static struct sk_buff *skb_unshare(struct sk_buff *skb, int flags) { return skb; }
static void skb_trim(struct sk_buff *skb, unsigned int len) {}
static unsigned int skb_headroom(struct sk_buff *skb) { return 0; }
static struct atalk_route *atrtr_find(struct atalk_addr *ta) { return NULL; }
static int aarp_send_ddp(struct net_device *dev, struct sk_buff *skb, struct atalk_addr *ta, void *null) { return 0; }