#include <stdbool.h>
#include <stddef.h>

#define DST_XFRM_TUNNEL 0x1000

struct net_device {
    unsigned int mtu;
};

struct dst_entry {
    unsigned int flags;
    unsigned int header_len;
    struct net_device *dev;
    struct dst_entry *path;
};

struct rt6_info {
    struct dst_entry dst;
};

struct sk_buff;

struct frag_hdr {
    unsigned char dummy[8];  // Minimal size for IPv6 fragment header
};

static inline unsigned int dst_mtu(const struct dst_entry *dst) {
    return dst->dev ? dst->dev->mtu : 0;
}

#define min(a, b) ((a) < (b) ? (a) : (b))