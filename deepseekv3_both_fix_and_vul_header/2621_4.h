#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define TPACKET_ALIGNMENT 16
#define TPACKET_ALIGN(x) (((x)+TPACKET_ALIGNMENT-1)&~(TPACKET_ALIGNMENT-1))
#define TP_STATUS_USER 0
#define TP_STATUS_KERNEL 0
#define TP_STATUS_CSUMNOTREADY (1 << 0)
#define TP_STATUS_CSUM_VALID (1 << 1)
#define TP_STATUS_LOSING (1 << 2)
#define TP_STATUS_COPY (1 << 3)
#define TP_STATUS_VLAN_VALID (1 << 4)
#define TP_STATUS_VLAN_TPID_VALID (1 << 5)
#define PACKET_LOOPBACK 5
#define PACKET_OUTGOING 6
#define SOCK_DGRAM 2
#define AF_PACKET 17
#define CHECKSUM_PARTIAL 1
#define CHECKSUM_COMPLETE 2
#define TPACKET_V1 0
#define TPACKET_V2 1
#define TPACKET_V3 2
#define NSEC_PER_USEC 1000
#define ARCH_IMPLEMENTS_FLUSH_DCACHE_PAGE 1
#define PAGE_ALIGN(addr) (((addr)+PAGE_SIZE-1)&~(PAGE_SIZE-1))
#define PAGE_SIZE 4096
#define GFP_ATOMIC 0

typedef uint8_t u8;
typedef uint32_t __u32;
typedef uint32_t u32;

struct sk_buff {
    void *data;
    unsigned int len;
    unsigned char pkt_type;
    unsigned short protocol;
    unsigned short vlan_proto;
    unsigned int ip_summed;
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
    unsigned short sk_type;
    struct {
        struct {
            int lock;
        } sk_receive_queue;
        int sk_rmem_alloc;
        int sk_rcvbuf;
        void (*sk_data_ready)(struct sock *sk);
    };
};

struct tpacket_bdqc {
    unsigned int max_frame_len;
};

struct packet_sock {
    unsigned int tp_version;
    unsigned int tp_hdrlen;
    unsigned int tp_reserve;
    bool has_vnet_hdr;
    bool origdev;
    struct {
        unsigned int frame_size;
        struct tpacket_bdqc *pbdqc;
    } rx_ring;
    unsigned int copy_thresh;
    struct {
        struct {
            unsigned int tp_packets;
            unsigned int tp_drops;
        } stats1;
    } stats;
    unsigned int tp_tstamp;
};

struct sockaddr_ll {
    unsigned short sll_halen;
    unsigned char sll_addr[8];
    unsigned short sll_family;
    unsigned short sll_hatype;
    unsigned short sll_protocol;
    unsigned char sll_pkttype;
    int sll_ifindex;
};

struct virtio_net_hdr {
    // Minimal definition for compilation
};

union tpacket_uhdr {
    struct tpacket_hdr_v1 *h1;
    struct tpacket_hdr_v2 *h2;
    struct tpacket_hdr_v3 *h3;
    void *raw;
};

struct tpacket_hdr_v1 {
    unsigned int tp_len;
    unsigned int tp_snaplen;
    unsigned int tp_mac;
    unsigned int tp_net;
    unsigned int tp_sec;
    unsigned int tp_usec;
};

struct tpacket_hdr_v2 {
    unsigned int tp_len;
    unsigned int tp_snaplen;
    unsigned int tp_mac;
    unsigned int tp_net;
    unsigned int tp_sec;
    unsigned int tp_nsec;
    unsigned short tp_vlan_tci;
    unsigned short tp_vlan_tpid;
    unsigned char tp_padding[4];
};

struct tpacket_hdr_v3 {
    unsigned int tp_status;
    unsigned int tp_len;
    unsigned int tp_snaplen;
    unsigned int tp_mac;
    unsigned int tp_net;
    unsigned int tp_sec;
    unsigned int tp_nsec;
    unsigned char tp_padding[16];
};

static inline struct packet_sock *pkt_sk(struct sock *sk) { return (struct packet_sock *)sk; }
static inline int net_eq(void *a, void *b) { return a == b; }
static inline void *dev_net(struct net_device *dev) { return (void *)dev; }
static inline void *sock_net(struct sock *sk) { return (void *)sk; }
static inline void skb_push(struct sk_buff *skb, int len) {}
static inline void *skb_mac_header(struct sk_buff *skb) { return skb->data; }
static inline void skb_pull(struct sk_buff *skb, int len) {}
static inline int skb_network_offset(struct sk_buff *skb) { return 0; }
static inline int run_filter(struct sk_buff *skb, struct sock *sk, int len) { return len; }
static inline int skb_csum_unnecessary(struct sk_buff *skb) { return 0; }
static inline int atomic_read(int *v) { return *v; }
static inline int skb_shared(struct sk_buff *skb) { return 0; }
static inline struct sk_buff *skb_clone(struct sk_buff *skb, int flags) { return skb; }
static inline struct sk_buff *skb_get(struct sk_buff *skb) { return skb; }
static inline void skb_set_owner_r(struct sk_buff *skb, struct sock *sk) {}
static inline int unlikely(int expr) { return expr; }
static inline struct tpacket_bdqc *GET_PBDQC_FROM_RB(void *rb) { return ((struct packet_sock *)rb)->rx_ring.pbdqc; }
static inline void pr_err_once(const char *fmt, ...) {}
static inline void spin_lock(int *lock) {}
static inline void *packet_current_rx_frame(struct packet_sock *po, struct sk_buff *skb, int status, int len) { return NULL; }
static inline void packet_increment_rx_head(struct packet_sock *po, void *ring) {}
static inline void __skb_queue_tail(void *queue, struct sk_buff *skb) {}
static inline void spin_unlock(int *lock) {}
static inline int virtio_net_hdr_from_skb(struct sk_buff *skb, void *hdr, int vio_le, int validate) { return 0; }
static inline int vio_le() { return 0; }
static inline void skb_copy_bits(struct sk_buff *skb, int offset, void *to, int len) {}
static inline int tpacket_get_timestamp(struct sk_buff *skb, struct timespec *ts, int tstamp) { return 0; }
static inline void getnstimeofday(struct timespec *ts) {}
static inline int skb_vlan_tag_present(struct sk_buff *skb) { return 0; }
static inline unsigned short skb_vlan_tag_get(struct sk_buff *skb) { return 0; }
static inline unsigned short ntohs(unsigned short val) { return val; }
static inline void BUG() {}
static inline int dev_parse_header(struct sk_buff *skb, unsigned char *haddr) { return 0; }
static inline void smp_mb() {}
static inline void flush_dcache_page(void *page) {}
static inline void *pgv_to_page(void *addr) { return addr; }
static inline void smp_wmb() {}
static inline void __packet_set_status(struct packet_sock *po, void *hdr, int status) {}
static inline void prb_clear_blk_fill_status(void *ring) {}
static inline void consume_skb(struct sk_buff *skb) {}
static inline void kfree_skb(struct sk_buff *skb) {}