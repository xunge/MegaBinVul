#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

struct sk_buff;
struct ipv6_opt_hdr {
    uint8_t nexthdr;
    uint8_t hdrlen;
};

struct frag_hdr {
    uint8_t nexthdr;
    uint8_t reserved;
    uint16_t frag_off;
    uint32_t identification;
};

#define NEXTHDR_HOP 0
#define NEXTHDR_ROUTING 43
#define NEXTHDR_FRAGMENT 44
#define NEXTHDR_AUTH 51
#define NEXTHDR_DEST 60
#define NEXTHDR_NONE 59

typedef uint8_t u8;

static inline int ipv6_ext_hdr(u8 nexthdr)
{
    return (nexthdr == NEXTHDR_HOP) ||
           (nexthdr == NEXTHDR_ROUTING) ||
           (nexthdr == NEXTHDR_FRAGMENT) ||
           (nexthdr == NEXTHDR_AUTH) ||
           (nexthdr == NEXTHDR_DEST);
}

static inline int ipv6_optlen(struct ipv6_opt_hdr *hdr)
{
    return (hdr->hdrlen + 1) << 3;
}

#define BUG() do { *(volatile int *)0 = 0; } while (0)

static inline void *skb_header_pointer(const struct sk_buff *skb, int offset, int len, void *buffer)
{
    return buffer;
}