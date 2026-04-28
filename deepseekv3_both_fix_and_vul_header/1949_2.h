#include <stdint.h>
#include <sys/time.h>
#include <time.h>

typedef uint8_t u8;

struct timeval64 {
    int64_t tv64;
};

struct sk_buff {
    u8 *data;
    unsigned int len;
    int pkt_type;
    int ip_summed;
    u8 *mac_header;
    u8 *network_header;
    unsigned short protocol;
    struct timeval64 tstamp;
    unsigned int truesize;
    int skb_shared;
};

struct net_device {
    int type;
    int ifindex;
    void *header_ops;
};

struct packet_type {
    void *af_packet_priv;
};

struct sock {
    int sk_type;
    unsigned int sk_rcvbuf;
    struct {
        void *lock;
    } sk_receive_queue;
    void (*sk_data_ready)(struct sock *sk, int len);
    int sk_rmem_alloc;
};

struct packet_sock {
    unsigned int tp_hdrlen;
    unsigned int tp_reserve;
    struct {
        unsigned int frame_size;
    } rx_ring;
    unsigned int copy_thresh;
    unsigned int tp_version;
    unsigned int tp_tstamp;
    int origdev;
    struct {
        unsigned int tp_packets;
        unsigned int tp_drops;
    } stats;
};

struct sockaddr_ll {
    unsigned short sll_family;
    unsigned short sll_hatype;
    unsigned short sll_halen;
    unsigned short sll_protocol;
    unsigned short sll_pkttype;
    int sll_ifindex;
    u8 sll_addr[8];
};

struct tpacket_hdr {
    unsigned int tp_len;
    unsigned int tp_snaplen;
    unsigned int tp_mac;
    unsigned int tp_net;
    unsigned int tp_sec;
    unsigned int tp_usec;
};

struct tpacket2_hdr {
    unsigned int tp_len;
    unsigned int tp_snaplen;
    unsigned int tp_mac;
    unsigned int tp_net;
    unsigned int tp_sec;
    unsigned int tp_nsec;
    unsigned short tp_vlan_tci;
    unsigned short tp_padding;
};

struct skb_shared_hwtstamps {
    struct timeval64 syststamp;
    struct timeval64 hwtstamp;
};

#define TP_STATUS_LOSING 0x1
#define TP_STATUS_USER 0x2
#define TP_STATUS_CSUMNOTREADY 0x4
#define TP_STATUS_KERNEL 0x0
#define TP_STATUS_COPY 0x8
#define TP_STATUS_VLAN_VALID 0x10
#define PACKET_LOOPBACK 0
#define PACKET_OUTGOING 1
#define SOCK_DGRAM 1
#define CHECKSUM_PARTIAL 1
#define TPACKET_V1 0
#define TPACKET_V2 1
#define SOF_TIMESTAMPING_SYS_HARDWARE 1
#define SOF_TIMESTAMPING_RAW_HARDWARE 2
#define AF_PACKET 17
#define ARCH_IMPLEMENTS_FLUSH_DCACHE_PAGE 0
#define GFP_ATOMIC 0

#define TPACKET_ALIGN(x) (((x)+3)&~3)
#define PAGE_ALIGN(x) (((x)+4095)&~4095)

static inline int skb_shared(const struct sk_buff *skb) { return 0; }
static inline struct sk_buff *skb_clone(struct sk_buff *skb, int flags) { return 0; }
static inline struct sk_buff *skb_get(struct sk_buff *skb) { return 0; }
static inline void skb_set_owner_r(struct sk_buff *skb, struct sock *sk) {}
static inline u8 *skb_mac_header(const struct sk_buff *skb) { return 0; }
static inline unsigned int skb_network_offset(const struct sk_buff *skb) { return 0; }
static inline void skb_push(struct sk_buff *skb, unsigned int len) {}
static inline void skb_pull(struct sk_buff *skb, unsigned int len) {}
static inline int net_eq(void *a, void *b) { return 0; }
static inline void *dev_net(struct net_device *dev) { return 0; }
static inline void *sock_net(struct sock *sk) { return 0; }
static inline struct packet_sock *pkt_sk(struct sock *sk) { return 0; }
static inline struct skb_shared_hwtstamps *skb_hwtstamps(struct sk_buff *skb) { return 0; }
static inline int run_filter(struct sk_buff *skb, struct sock *sk, unsigned int len) { return 0; }
static inline int atomic_read(int *v) { return 0; }
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void *packet_current_frame(struct packet_sock *po, void *ring, int status) { return 0; }
static inline void packet_increment_head(void *ring) {}
static inline void __skb_queue_tail(void *list, struct sk_buff *skb) {}
static inline struct timeval ktime_to_timeval(struct timeval64 t) { struct timeval tv = {0}; return tv; }
static inline struct timespec ktime_to_timespec(struct timeval64 t) { struct timespec ts = {0}; return ts; }
static inline void do_gettimeofday(struct timeval *tv) {}
static inline void getnstimeofday(struct timespec *ts) {}
static inline int vlan_tx_tag_present(struct sk_buff *skb) { return 0; }
static inline unsigned short vlan_tx_tag_get(struct sk_buff *skb) { return 0; }
static inline unsigned short dev_parse_header(struct sk_buff *skb, u8 *addr) { return 0; }
static inline int unlikely(int x) { return x; }
static inline void __packet_set_status(struct packet_sock *po, void *h, unsigned long status) {}
static inline void smp_mb() {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void BUG() {}
static inline void skb_copy_bits(struct sk_buff *skb, int offset, void *to, int len) {}
static inline void flush_dcache_page(void *page) {}
static inline void *pgv_to_page(void *addr) { return NULL; }