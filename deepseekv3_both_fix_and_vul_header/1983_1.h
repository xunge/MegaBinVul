#include <stdint.h>

struct sk_buff;
struct ipv6hdr {
    uint8_t saddr[16];
};

typedef struct {
    uint8_t a6[16];
} xfrm_address_t;

typedef uint32_t __be32;

extern __be32 xfrm6_tunnel_spi_lookup(xfrm_address_t *addr);
extern int xfrm6_rcv_spi(struct sk_buff *skb, __be32 spi);