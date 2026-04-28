#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

#define NF_ACCEPT 1
#define NF_INET_PRE_ROUTING 0
#define DCCP_PKT_INVALID 7

struct net {
    struct {
        int sysctl_checksum;
    } ct;
};

struct nf_conn;
struct sk_buff {
    unsigned int len;
};

enum ip_conntrack_info;

struct dccp_hdr {
    uint8_t dccph_doff;
    uint8_t dccph_cscov;
    uint8_t dccph_type;
};

static inline void *skb_header_pointer(const struct sk_buff *skb, int offset, int len, void *buffer) {
    return buffer;
}

static inline int nf_checksum_partial(const struct sk_buff *skb, unsigned int hooknum,
                                     unsigned int dataoff, unsigned int len,
                                     uint8_t protocol, uint8_t pf) {
    return 0;
}

static inline int LOG_INVALID(struct net *net, int proto) {
    return 0;
}

static inline void nf_log_packet(struct net *net, uint8_t pf, unsigned int hooknum,
                                const struct sk_buff *skb, const void *in,
                                const void *out, const char *fmt, ...) {}