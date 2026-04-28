#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>
#include <netinet/ip6.h>

typedef uint8_t u8;
typedef uint8_t __u8;

struct ipv6hdr {
    __u8 nexthdr;
};

struct icmp6hdr {
    __u8 icmp6_type;
};

struct sk_buff {
    u8 *data;
    int len;
    struct {
        struct ipv6hdr *ipv6h;
    } nh;
};

#define ICMPV6_INFOMSG_MASK 0x80

int ipv6_skip_exthdr(const struct sk_buff *skb, int start, __u8 *nexthdrp, ...);
void *skb_header_pointer(const struct sk_buff *skb, int offset, int len, void *buffer);