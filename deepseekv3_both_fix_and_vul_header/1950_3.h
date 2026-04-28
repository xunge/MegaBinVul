#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>

struct kiocb;
struct socket {
    struct sock *sk;
    int type;
};
struct sock;
struct sk_buff {
    unsigned int len;
    unsigned char *head;
    unsigned char *data;
    unsigned char *tail;
    unsigned char *end;
    unsigned int ip_summed;
    unsigned int csum_offset;
    unsigned int network_offset;
    unsigned char cb[48];
};
struct sockaddr_ll {
    unsigned short sll_halen;
    unsigned char sll_addr[8];
};
struct sockaddr_pkt {
    unsigned short spkt_family;
    unsigned char spkt_device[14];
    unsigned short spkt_protocol;
};
struct virtio_net_hdr {
    unsigned char flags;
    unsigned char gso_type;
    unsigned short hdr_len;
    unsigned short gso_size;
    unsigned short csum_start;
    unsigned short csum_offset;
};
struct skb_shared_info {
    unsigned short gso_size;
    unsigned short gso_type;
};
struct tpacket_auxdata {
    unsigned int tp_status;
    unsigned int tp_len;
    unsigned int tp_snaplen;
    unsigned int tp_mac;
    unsigned int tp_net;
    unsigned short tp_vlan_tci;
    unsigned short tp_padding;
};

#define EINVAL 22
#define ENODEV 19
#define ENETDOWN 100
#define CHECKSUM_PARTIAL 1
#define SOL_PACKET 263
#define PACKET_AUXDATA 8
#define TP_STATUS_USER 1
#define TP_STATUS_CSUMNOTREADY 2
#define TP_STATUS_VLAN_VALID 4
#define SKB_GSO_TCPV4 1
#define SKB_GSO_TCPV6 2
#define SKB_GSO_UDP 4
#define SKB_GSO_FCOE 8
#define SKB_GSO_TCP_ECN 16
#define VIRTIO_NET_HDR_GSO_TCPV4 1
#define VIRTIO_NET_HDR_GSO_TCPV6 2
#define VIRTIO_NET_HDR_GSO_UDP 3
#define VIRTIO_NET_HDR_GSO_ECN 0x80
#define VIRTIO_NET_HDR_GSO_NONE 0
#define VIRTIO_NET_HDR_F_NEEDS_CSUM 1
#define MSG_CMSG_COMPAT 0x80000000

struct pkt_sk {
    int ifindex;
    int has_vnet_hdr;
    int auxdata;
};

#define pkt_sk(sk) ((struct pkt_sk *)(sk))

#define PACKET_SKB_CB(skb) ((struct packet_skb_cb *)((skb)->cb))

struct packet_skb_cb {
    struct {
        struct sockaddr_ll ll;
    } sa;
    unsigned int origlen;
};

static inline unsigned int skb_headlen(const struct sk_buff *skb) {
    return skb->len - (skb->data - skb->head);
}

static inline unsigned int skb_checksum_start_offset(const struct sk_buff *skb) {
    return skb->csum_offset;
}

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return (struct skb_shared_info *)(skb->end);
}

static inline unsigned int skb_network_offset(const struct sk_buff *skb) {
    return skb->network_offset;
}

static inline int vlan_tx_tag_present(const struct sk_buff *skb) {
    return 0;
}

static inline unsigned short vlan_tx_tag_get(const struct sk_buff *skb) {
    return 0;
}

static inline void BUG() {}

static inline int memcpy_toiovec(struct iovec *iov, const void *from, size_t len) {
    return 0;
}

static inline int skb_copy_datagram_iovec(const struct sk_buff *skb, int offset,
                                        struct iovec *to, int len) {
    return 0;
}

static inline void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk,
                                        struct sk_buff *skb) {}

static inline void put_cmsg(struct msghdr *msg, int level, int type, int len, void *data) {}

static inline void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {}

static inline int packet_recv_error(struct sock *sk, struct msghdr *msg, size_t len) {
    return 0;
}

static inline int skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err) {
    return 0;
}

static inline int skb_is_gso(const struct sk_buff *skb) {
    return 0;
}