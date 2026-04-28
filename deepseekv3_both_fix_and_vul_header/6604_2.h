#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define TCPOLEN_MSS 4
#define TCPOPT_MSS 2
#define XT_TCPMSS_CLAMP_PMTU 1
#define NFPROTO_IPV4 2
#define GFP_ATOMIC 0

typedef uint16_t __be16;
typedef uint32_t __be32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef uint16_t u_int16_t;
typedef uint8_t u_int8_t;
typedef uint16_t __u16;

struct xt_tcpmss_info {
    u_int16_t mss;
};

struct tcphdr {
    __be16 source;
    __be16 dest;
    __be32 seq;
    __be32 ack_seq;
    __u16 res1:4,
        doff:4,
        fin:1,
        syn:1,
        rst:1,
        psh:1,
        ack:1,
        urg:1,
        ece:1,
        cwr:1;
    __be16 window;
    __be16 check;
    __be16 urg_ptr;
};

struct sk_buff {
    unsigned int len;
    unsigned char *data;
    unsigned char *network_header;
    unsigned int tailroom;
    void* dst;
};

struct xt_action_param {
    const void *targinfo;
    unsigned int fragoff;
    unsigned int family;
};

struct net;

static inline unsigned int optlen(const u8 *opt, unsigned int offset) {
    return opt[offset + 1];
}

static inline __be16 htons(uint16_t hostshort) {
    return (hostshort << 8) | (hostshort >> 8);
}

static inline int skb_make_writable(struct sk_buff *skb, unsigned int len) {
    return 1;
}

static inline unsigned char *skb_network_header(const struct sk_buff *skb) {
    return skb->network_header;
}

static inline struct net *xt_net(const struct xt_action_param *par) {
    return NULL;
}

static inline unsigned int tcpmss_reverse_mtu(struct net *net, struct sk_buff *skb, unsigned int family) {
    return 0;
}

static inline unsigned int dst_mtu(void *dst) {
    return 0;
}

static inline void *skb_dst(const struct sk_buff *skb) {
    return skb->dst;
}

static inline void net_err_ratelimited(const char *fmt, ...) {}

static inline void inet_proto_csum_replace2(__be16 *check, struct sk_buff *skb,
                                          __be16 from, __be16 to, bool pseudohdr) {}

static inline unsigned int skb_tailroom(const struct sk_buff *skb) {
    return skb->tailroom;
}

static inline int pskb_expand_head(struct sk_buff *skb, int nhead, int ntail, int gfp_mask) {
    return 0;
}

static inline void skb_put(struct sk_buff *skb, unsigned int len) {}

static inline unsigned int xt_family(const struct xt_action_param *par) {
    return par->family;
}

static inline void inet_proto_csum_replace4(__be16 *check, struct sk_buff *skb,
                                          __be32 from, __be32 to, bool pseudohdr) {}

static inline unsigned int min(unsigned int a, unsigned int b) {
    return a < b ? a : b;
}