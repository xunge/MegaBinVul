#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef uint16_t u16;
typedef uint8_t u8;
typedef uint32_t __wsum;

#define SOCK_DEAD 1
#define PPPOX_CONNECTED 2
#define UDP_CSUM_NOXMIT 1
#define CHECKSUM_NONE 0
#define CHECKSUM_COMPLETE 1
#define CHECKSUM_PARTIAL 2
#define NETIF_F_V4_CSUM 0x0001
#define CSUM_MANGLED_0 0xFFFF
#define KERN_DEBUG "<7>"
#define NET_SKB_PAD 32
#define IPSKB_XFRM_TUNNEL_SIZE (1 << 0)
#define IPSKB_XFRM_TRANSFORMED (1 << 1)
#define IPSKB_REROUTED (1 << 2)

struct ppp_channel {
    void *private;
};

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned int truesize;
    unsigned char *head;
    unsigned char *transport_header;
    int ip_summed;
    unsigned int csum_start;
    unsigned int csum_offset;
    void *dst;
    unsigned char cb[48];
};

struct sock {
    unsigned short sk_state;
    int sk_no_check;
    void *sk_dst_cache;
};

struct inet_sock {
    uint16_t inet_sport;
    uint16_t inet_dport;
    uint32_t inet_saddr;
    uint32_t inet_daddr;
};

struct ip_options {
    unsigned char opt[40];
    unsigned char flags;
};

struct ipcm_cookie {
    struct ip_options *opt;
    unsigned int flags;
};

#define IPCB(skb) ((struct ipcm_cookie *)((skb)->cb))

struct net_device {
    unsigned int features;
};

struct dst_entry {
    struct net_device *dev;
};

struct pppol2tp_session;
struct pppol2tp_tunnel;

struct pppol2tp_stats {
    unsigned long tx_packets;
    unsigned long tx_bytes;
    unsigned long tx_errors;
};

struct pppol2tp_session {
    struct sock *tunnel_sock;
    char *name;
    unsigned int debug;
    int send_seq;
    u16 ns;
    struct pppol2tp_stats stats;
};

struct pppol2tp_tunnel {
    struct pppol2tp_stats stats;
};

#define PPPOL2TP_MSG_DATA 0x0001
#define PRINTK(debug, type, level, fmt, args...) \
    do { if (debug & type) printk(level fmt, ##args); } while (0)

static inline int sock_flag(const struct sock *sk, int flag) { return 0; }
static inline struct pppol2tp_session *pppol2tp_sock_to_session(struct sock *sk) { return NULL; }
static inline struct pppol2tp_tunnel *pppol2tp_sock_to_tunnel(struct sock *sk) { return NULL; }
static inline int pppol2tp_l2tp_header_len(struct pppol2tp_session *session) { return 0; }
static inline unsigned int skb_headroom(const struct sk_buff *skb) { return 0; }
static inline int skb_cow_head(struct sk_buff *skb, unsigned int headroom) { return 0; }
static inline void skb_orphan(struct sk_buff *skb) {}
static inline unsigned char *__skb_push(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline void pppol2tp_build_l2tp_header(struct pppol2tp_session *session, void *ptr) {}
static inline struct inet_sock *inet_sk(const struct sock *sk) { return NULL; }
static inline void skb_reset_transport_header(struct sk_buff *skb) {}
static inline struct udphdr *udp_hdr(const struct sk_buff *skb) { return NULL; }
static inline void sock_put(struct sock *sk) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void nf_reset(struct sk_buff *skb) {}
static inline void skb_dst_drop(struct sk_buff *skb) {}
static inline void skb_dst_set(struct sk_buff *skb, void *dst) {}
static inline void *dst_clone(void *dst) { return NULL; }
static inline void *__sk_dst_get(const struct sock *sk) { return NULL; }
static inline void pppol2tp_skb_set_owner_w(struct sk_buff *skb, struct sock *sk) {}
static inline int ip_queue_xmit(struct sk_buff *skb, int flag) { return 0; }
static inline __wsum skb_checksum(struct sk_buff *skb, int offset, int len, __wsum sum) { return 0; }
static inline uint16_t csum_tcpudp_magic(uint32_t saddr, uint32_t daddr, uint16_t len, uint8_t proto, __wsum sum) { return 0; }
static inline int printk(const char *fmt, ...) { return 0; }
static inline struct dst_entry *skb_dst(const struct sk_buff *skb) { return NULL; }
static inline unsigned char *skb_transport_header(const struct sk_buff *skb) { return NULL; }