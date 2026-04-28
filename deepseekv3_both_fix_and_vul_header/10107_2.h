#include <stdint.h>
#include <time.h>

typedef uint8_t u8;
typedef uint16_t __be16;
typedef uint32_t __be32;
typedef uint32_t __u32;
typedef unsigned long jiffies_t;
extern jiffies_t jiffies;

struct sk_buff {
    unsigned char *data;
    void *dev;
};
struct inet6_skb_parm;
struct net_device {
    unsigned int mtu;
};
struct ip6_tnl {
    jiffies_t err_time;
    int err_count;
    struct {
        char *name;
    } parms;
    struct net_device *dev;
};
struct gre_base_hdr {
    __be16 flags;
    __be16 protocol;
};
struct ipv6hdr {
    __be32 daddr;
    __be32 saddr;
};
struct ipv6_tlv_tnl_enc_lim {
    u8 encap_limit;
};

#define IP6TUNNEL_ERR_TIMEO (10*HZ)
#define IPV6_MIN_MTU 1280
#define GRE_VERSION 0x8000
#define GRE_ROUTING 0x4000
#define GRE_CSUM 0x2000
#define GRE_KEY 0x1000
#define GRE_SEQ 0x0800
#define ICMPV6_DEST_UNREACH 1
#define ICMPV6_TIME_EXCEED 3
#define ICMPV6_EXC_HOPLIMIT 0
#define ICMPV6_PARAMPROB 4
#define ICMPV6_HDR_FIELD 0
#define ICMPV6_PKT_TOOBIG 2
#define HZ 100

static inline int pskb_may_pull(struct sk_buff *skb, unsigned int len) { return 1; }
static inline __be32 be32_to_cpu(__be32 val) { return val; }
static inline struct ip6_tnl *ip6gre_tunnel_lookup(void *dev, const __be32 *daddr, const __be32 *saddr, __be32 key, __be16 protocol) { return NULL; }
static inline __u32 ip6_tnl_parse_tlv_enc_lim(struct sk_buff *skb, unsigned char *data) { return 0; }
static inline int time_before(jiffies_t a, jiffies_t b) { return a < b; }
#define net_dbg_ratelimited(fmt, ...) 