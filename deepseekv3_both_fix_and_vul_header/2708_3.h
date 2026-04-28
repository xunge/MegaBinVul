#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <string.h>

struct sock {
    unsigned int sk_flags;
};

struct net_device {
    struct {
        unsigned long tx_dropped;
    } stats;
};

struct macvtap_queue {
    unsigned int flags;
    unsigned int vnet_hdr_sz;
    struct sock sk;
    struct macvlan_dev *vlan;
};

struct macvlan_dev {
    struct net_device *dev;
};

struct msghdr {
    void *msg_control;
};

struct virtio_net_hdr {
    unsigned char flags;
    unsigned char gso_type;
    unsigned short hdr_len;
    unsigned short gso_size;
    unsigned short csum_start;
    unsigned short csum_offset;
};

struct ethhdr {
    unsigned short h_proto;
};

struct sk_buff {
    unsigned char *head;
    unsigned char *data;
    unsigned char *tail;
    unsigned char *end;
    unsigned int len;
    unsigned short protocol;
    void (*destructor)(struct sk_buff *skb);
};

struct skb_shared_info {
    void *destructor_arg;
    unsigned int tx_flags;
};

#define IFF_VNET_HDR 0x1
#define SOCK_ZEROCOPY 0x1
#define ETH_HLEN 14
#define MAX_SKB_FRAGS 16
#define GOODCOPY_LEN 256
#define NET_IP_ALIGN 2
#define VIRTIO_NET_HDR_F_NEEDS_CSUM 1
#define SKBTX_DEV_ZEROCOPY 0x1

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return (struct skb_shared_info *)(skb->end);
}

static inline struct ethhdr *eth_hdr(struct sk_buff *skb) {
    return (struct ethhdr *)skb->data;
}

static inline void skb_set_network_header(struct sk_buff *skb, int offset) {
    skb->data += offset;
    skb->len -= offset;
}

static inline void skb_reset_mac_header(struct sk_buff *skb) {
    skb->data = skb->head;
}

static inline int sock_flag(struct sock *sk, int flag) {
    return sk->sk_flags & flag;
}

static inline int unlikely(int cond) {
    return cond;
}

static inline int memcpy_fromiovecend(void *dst, const struct iovec *iov, int offset, int len) {
    return -1;
}

static inline int iov_length(const struct iovec *iov, int count) {
    return -1;
}

static inline struct sk_buff *macvtap_alloc_skb(struct sock *sk, int align, int len, int hdr_len, int noblock, int *err) {
    return NULL;
}

static inline int zerocopy_sg_from_iovec(struct sk_buff *skb, const struct iovec *iov, int hdr_len, int count) {
    return -1;
}

static inline int skb_copy_datagram_from_iovec(struct sk_buff *skb, int offset, const struct iovec *iov, int hdr_len, int len) {
    return -1;
}

static inline int macvtap_skb_from_vnet_hdr(struct sk_buff *skb, struct virtio_net_hdr *hdr) {
    return -1;
}

static inline void rcu_read_lock_bh(void) {}
static inline void rcu_read_unlock_bh(void) {}
static inline void *rcu_dereference_bh(void *p) { return p; }

static inline int macvlan_start_xmit(struct sk_buff *skb, struct net_device *dev) {
    return -1;
}

static inline void kfree_skb(struct sk_buff *skb) {}