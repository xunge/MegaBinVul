#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define BUILD_BUG_ON(condition) ((void)0)
#define TPACKET_ALIGNMENT 16
#define TPACKET_ALIGN(x) (((x)+TPACKET_ALIGNMENT-1)&~(TPACKET_ALIGNMENT-1))
#define TP_STATUS_USER (1 << 0)
#define TP_STATUS_CSUMNOTREADY (1 << 1)
#define TP_STATUS_CSUM_VALID (1 << 2)
#define TP_STATUS_LOSING (1 << 3)
#define TP_STATUS_COPY (1 << 4)
#define TP_STATUS_VLAN_VALID (1 << 5)
#define TP_STATUS_VLAN_TPID_VALID (1 << 6)
#define TP_STATUS_KERNEL (0)
#define TPACKET_V1 0
#define TPACKET_V2 1
#define TPACKET_V3 2
#define ROOM_NONE 0
#define SOCK_DGRAM 2
#define PACKET_LOOPBACK 5
#define PACKET_OUTGOING 6
#define CHECKSUM_PARTIAL 1
#define CHECKSUM_COMPLETE 2
#define AF_PACKET 17
#define NSEC_PER_USEC 1000UL
#define ARCH_IMPLEMENTS_FLUSH_DCACHE_PAGE 1
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_ALIGN(addr) (((addr)+PAGE_SIZE-1)&PAGE_MASK)
#define GFP_ATOMIC 0
#define unlikely(x) (x)
#define BUG() do { while(1); } while(0)

typedef uint8_t u8;
typedef uint32_t __u32;
typedef uint16_t u16;
typedef int32_t atomic_t;
typedef uint32_t u32;

struct spinlock {
    int lock;
};

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned char pkt_type;
    unsigned char ip_summed;
    unsigned short vlan_proto;
    unsigned short vlan_tci;
    bool shared;
    unsigned short protocol;
};

struct net_device {
    unsigned short type;
    int ifindex;
    void *header_ops;
};

struct packet_type {
    void *af_packet_priv;
};

struct sock {
    int sk_type;
    unsigned int sk_rcvbuf;
    atomic_t sk_rmem_alloc;
    struct {
        struct spinlock lock;
    } sk_receive_queue;
    void (*sk_data_ready)(struct sock *);
};

struct tpacket_block_desc {
    unsigned int max_frame_len;
};

struct packet_ring_buffer {
    unsigned int frame_size;
    unsigned long *rx_owner_map;
    unsigned int head;
    struct tpacket_block_desc *pd;
};

struct packet_stats {
    struct {
        unsigned int tp_packets;
    } stats1;
};

struct packet_sock {
    struct sock sk;
    unsigned int tp_version;
    unsigned int tp_hdrlen;
    unsigned int tp_reserve;
    unsigned int tp_tstamp;
    unsigned int copy_thresh;
    atomic_t tp_drops;
    struct packet_ring_buffer rx_ring;
    bool has_vnet_hdr;
    bool origdev;
    struct packet_stats stats;
};

struct sockaddr_ll {
    unsigned short sll_family;
    unsigned short sll_protocol;
    int sll_ifindex;
    unsigned short sll_hatype;
    unsigned char sll_halen;
    unsigned char sll_addr[8];
    unsigned char sll_pkttype;
};

struct timespec64 {
    long tv_sec;
    long tv_nsec;
};

struct tpacket_hdr {
    unsigned long tp_status;
    unsigned int tp_len;
    unsigned int tp_snaplen;
    unsigned int tp_mac;
    unsigned int tp_net;
    unsigned int tp_sec;
    unsigned int tp_usec;
};

struct tpacket2_hdr {
    unsigned long tp_status;
    unsigned int tp_len;
    unsigned int tp_snaplen;
    unsigned int tp_mac;
    unsigned int tp_net;
    unsigned int tp_sec;
    unsigned int tp_nsec;
    unsigned short tp_vlan_tci;
    unsigned short tp_vlan_tpid;
    unsigned char tp_padding[12];
};

struct tpacket3_hdr {
    unsigned long tp_status;
    unsigned int tp_len;
    unsigned int tp_snaplen;
    unsigned int tp_mac;
    unsigned int tp_net;
    unsigned int tp_sec;
    unsigned int tp_nsec;
    unsigned int tp_nxt_offset;
    unsigned char tp_padding[8];
};

union tpacket_uhdr {
    struct tpacket_hdr *h1;
    struct tpacket2_hdr *h2;
    struct tpacket3_hdr *h3;
    void *raw;
};

struct virtio_net_hdr {
    uint8_t flags;
    uint8_t gso_type;
    uint16_t hdr_len;
    uint16_t gso_size;
    uint16_t csum_start;
    uint16_t csum_offset;
};

static inline void atomic_inc(atomic_t *v) { (*v)++; }
static inline int atomic_read(const atomic_t *v) { return *v; }

static inline struct packet_sock *pkt_sk(struct sock *sk) {
    return (struct packet_sock *)sk;
}

static inline bool net_eq(void *a, void *b) { return a == b; }
static inline void *dev_net(struct net_device *dev) { return (void *)dev; }
static inline void *sock_net(struct sock *sk) { return (void *)sk; }

static inline unsigned char *skb_mac_header(const struct sk_buff *skb) {
    return skb->data;
}

static inline unsigned int skb_network_offset(const struct sk_buff *skb) {
    return 0;
}

static inline void skb_push(struct sk_buff *skb, unsigned int len) {
    skb->data -= len;
    skb->len += len;
}

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
    skb->len -= len;
}

static inline bool skb_shared(const struct sk_buff *skb) {
    return skb->shared;
}

static inline struct sk_buff *skb_clone(struct sk_buff *skb, int flags) {
    return skb;
}

static inline struct sk_buff *skb_get(struct sk_buff *skb) {
    return skb;
}

static inline void skb_set_owner_r(struct sk_buff *skb, struct sock *sk) {}

static inline int run_filter(struct sk_buff *skb, struct sock *sk, unsigned int len) {
    return 1;
}

static inline int __packet_rcv_has_room(struct packet_sock *po, struct sk_buff *skb) {
    return 1;
}

static inline bool skb_csum_unnecessary(const struct sk_buff *skb) {
    return true;
}

static inline bool skb_vlan_tag_present(const struct sk_buff *skb) {
    return false;
}

static inline unsigned short skb_vlan_tag_get(const struct sk_buff *skb) {
    return 0;
}

static inline unsigned short ntohs(unsigned short val) {
    return val;
}

static inline struct tpacket_block_desc *GET_PBDQC_FROM_RB(struct packet_ring_buffer *rb) {
    return rb->pd;
}

static inline void *packet_current_rx_frame(struct packet_sock *po, 
                                          struct sk_buff *skb,
                                          unsigned int status,
                                          unsigned int len) {
    return NULL;
}

static inline void packet_increment_rx_head(struct packet_sock *po,
                                          struct packet_ring_buffer *rb) {}

static inline void __skb_queue_tail(void *queue, struct sk_buff *skb) {}

static inline void skb_copy_bits(const struct sk_buff *skb, int offset,
                               void *to, int len) {}

static inline int tpacket_get_timestamp(struct sk_buff *skb,
                                      struct timespec64 *ts,
                                      unsigned int tstamp) {
    return 0;
}

static inline void ktime_get_real_ts64(struct timespec64 *ts) {}

static inline void prb_clear_blk_fill_status(struct packet_ring_buffer *rb) {}

static inline void __packet_set_status(struct packet_sock *po,
                                     void *hdr, unsigned int status) {}

static inline void __set_bit(int nr, volatile unsigned long *addr) {}

static inline void __clear_bit(int nr, volatile unsigned long *addr) {}

static inline int test_bit(int nr, const volatile unsigned long *addr) {
    return 0;
}

static inline void spin_lock(struct spinlock *lock) {}

static inline void spin_unlock(struct spinlock *lock) {}

static inline void smp_mb(void) {}

static inline void smp_wmb(void) {}

static inline void flush_dcache_page(void *page) {}

static inline void *pgv_to_page(void *addr) { return addr; }

static inline void consume_skb(struct sk_buff *skb) {}

static inline void kfree_skb(struct sk_buff *skb) {}

static inline bool virtio_net_hdr_from_skb(struct sk_buff *skb, void *hdr,
                                         bool vio_le, bool validate, int vlan_depth) {
    return false;
}

static inline bool vio_le(void) { return false; }

static inline int dev_parse_header(struct sk_buff *skb, unsigned char *haddr) {
    return 0;
}

#define pr_err_once(fmt, ...) 