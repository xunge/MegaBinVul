#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef uint8_t __u8;
typedef uint32_t u32;

#define NULL ((void *)0)
#define CHECKSUM_NONE 0
#define CHECKSUM_PARTIAL 1
#define IPPROTO_UDP 17
#define IPPROTO_RAW 255
#define SOCK_DGRAM 2
#define SOCK_RAW 3
#define MSG_MORE 0x8000
#define MSG_DONTWAIT 0x40
#define MSG_CONFIRM 0x800
#define EMSGSIZE 90
#define EFAULT 14
#define EINVAL 22
#define ENOMEM 12
#define ENOBUFS 105
#define ETH_P_IPV6 0x86DD
#define IPV6_MAXPLEN 65535
#define MAX_SKB_FRAGS 18
#define NETIF_F_IPV6_CSUM (1 << 8)
#define NETIF_F_HW_CSUM (1 << 9)
#define NETIF_F_UFO (1 << 10)
#define NETIF_F_SG (1 << 11)
#define SOF_TIMESTAMPING_OPT_ID (1 << 0)
#define SKBTX_ANY_SW_TSTAMP (1 << 0)
#define IPCORK_ALLFRAG 0x01
#define IPSTATS_MIB_OUTDISCARDS 0

struct sock {
    int sk_protocol;
    int sk_type;
    unsigned int sk_tsflags;
    u32 sk_tskey;
    unsigned int sk_wmem_alloc;
    unsigned int sk_sndbuf;
    int sk_allocation;
};

struct flowi6;
struct sk_buff_head;
struct skb_frag {
    unsigned int size;
};

struct skb_shared_info {
    __u8 tx_flags;
    u32 tskey;
    int nr_frags;
    struct skb_frag frags[MAX_SKB_FRAGS];
};

struct sk_buff {
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
    __u8 ip_summed;
    __u8 protocol;
    unsigned short transport_header;
    unsigned short network_header;
    u32 csum;
    void *dst;
    void *dev;
    struct skb_shared_info *shinfo;
};

struct inet_cork {
    unsigned int flags;
    unsigned int fragsize;
    unsigned int length;
    void *dst;
};

struct inet6_cork {
    struct ipv6_txoptions *opt;
};

struct page_frag {
    void *page;
    unsigned int offset;
    unsigned int size;
};

struct ipcm6_cookie {
    int dontfrag;
};

struct sockcm_cookie {
    unsigned int tsflags;
};

struct rt6_info {
    struct {
        unsigned int header_len;
        unsigned int trailer_len;
        struct {
            unsigned int features;
        } *dev;
    } dst;
    unsigned int rt6i_nfheader_len;
    void *rt6i_idev;
};

struct ipv6_txoptions {
    unsigned int opt_flen;
    unsigned int opt_nflen;
};

struct ipv6hdr {};
struct frag_hdr {};

static inline unsigned short htons(unsigned short x) { return x; }
static inline struct sk_buff *skb_peek_tail(struct sk_buff_head *queue) { return NULL; }
static inline unsigned int LL_RESERVED_SPACE(void *dev) { return 0; }
static inline int dst_allfrag(void *dst) { return 0; }
static inline int ip6_sk_ignore_df(struct sock *sk) { return 0; }
static inline void ipv6_local_rxpmtu(struct sock *sk, struct flowi6 *fl6, unsigned int mtu) {}
static inline void ipv6_local_error(struct sock *sk, int err, struct flowi6 *fl6, unsigned int mtu) {}
static inline void sock_tx_timestamp(struct sock *sk, unsigned int tsflags, __u8 *tx_flags) {}
static inline int skb_is_gso(struct sk_buff *skb) { return 0; }
static inline int dst_xfrm(void *dst) { return 0; }
static inline int udp_get_no_check6_tx(struct sock *sk) { return 0; }
static inline int ip6_ufo_append_data(struct sock *sk, struct sk_buff_head *queue, 
                                    int (*getfrag)(void *, char *, int, int, int, struct sk_buff *),
                                    void *from, int length, int hh_len, int fragheaderlen,
                                    int exthdrlen, int transhdrlen, unsigned int mtu,
                                    unsigned int flags, struct flowi6 *fl6) { return 0; }
static inline void ip6_append_data_mtu(unsigned int *mtu, unsigned int *maxfraglen,
                                     int fragheaderlen, struct sk_buff *skb,
                                     struct rt6_info *rt, unsigned int orig_mtu) {}
static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, unsigned int size,
                                                int flags, int *err) { return NULL; }
static inline unsigned int atomic_read(unsigned int *v) { return *v; }
static inline struct sk_buff *sock_wmalloc(struct sock *sk, unsigned int size,
                                         int priority, int allocation) { return NULL; }
static inline int unlikely(int x) { return x; }
static inline void skb_reserve(struct sk_buff *skb, unsigned int len) {}
static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return skb->shinfo; }
static inline char *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline void skb_set_network_header(struct sk_buff *skb, int offset) {}
static inline u32 skb_copy_and_csum_bits(struct sk_buff *skb, unsigned int offset,
                                       char *to, unsigned int len, u32 csum) { return 0; }
static inline u32 csum_sub(u32 csum, u32 addend) { return 0; }
static inline void pskb_trim_unique(struct sk_buff *skb, unsigned int len) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void skb_set_dst_pending_confirm(struct sk_buff *skb, int flag) {}
static inline void __skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk) {}
static inline void __skb_trim(struct sk_buff *skb, unsigned int len) {}
static inline int sk_page_frag_refill(struct sock *sk, struct page_frag *pfrag) { return 0; }
static inline int skb_can_coalesce(struct sk_buff *skb, int i, void *page, unsigned int offset) { return 0; }
static inline void __skb_fill_page_desc(struct sk_buff *skb, int i, void *page,
                                      unsigned int offset, unsigned int size) {}
static inline void get_page(void *page) {}
static inline void *page_address(void *page) { return NULL; }
static inline void skb_frag_size_add(struct skb_frag *frag, unsigned int size) { frag->size += size; }
static inline void atomic_add(unsigned int i, unsigned int *v) { *v += i; }
static inline void IP6_INC_STATS(void *net, void *idev, int stat) {}
static inline void *sock_net(struct sock *sk) { return NULL; }

#define min_t(type, x, y) ((type)(x) < (type)(y) ? (type)(x) : (type)(y))