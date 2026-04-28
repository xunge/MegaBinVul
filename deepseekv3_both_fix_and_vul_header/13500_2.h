#include <stddef.h>
#include <stdint.h>

struct ipv6_addr {
    uint8_t addr[16];
};

struct ipv6_hdr {
    struct ipv6_addr dst;
};

struct gnrc_pktsnip {
    void *data;
    struct gnrc_pktsnip *next;
};

struct gnrc_netif_hdr;
struct gnrc_netif;

struct gnrc_sixlowpan_frag_fb {
    struct gnrc_pktsnip *pkt;
};

typedef struct gnrc_pktsnip gnrc_pktsnip_t;
typedef struct gnrc_netif_hdr gnrc_netif_hdr_t;
typedef struct gnrc_netif gnrc_netif_t;
typedef struct ipv6_hdr ipv6_hdr_t;
typedef struct ipv6_addr ipv6_addr_t;
typedef struct gnrc_sixlowpan_frag_fb gnrc_sixlowpan_frag_fb_t;

#define IS_USED(x) (0)
#define MODULE_GNRC_SIXLOWPAN_FRAG_MINFWD 0
#define DEBUG(x)

size_t gnrc_pkt_len(gnrc_pktsnip_t *pkt);
gnrc_netif_t *gnrc_netif_hdr_get_netif(gnrc_netif_hdr_t *netif_hdr);
gnrc_pktsnip_t *_iphc_encode(gnrc_pktsnip_t *pkt, void *data, gnrc_netif_t *netif);
int gnrc_sixlowpan_frag_minfwd_frag_iphc(gnrc_pktsnip_t *tmp, size_t orig_datagram_size, ipv6_addr_t *dst, void *ctx);
void gnrc_sixlowpan_multiplex_by_size(gnrc_pktsnip_t *tmp, size_t orig_datagram_size, gnrc_netif_t *netif, unsigned page);
void gnrc_pktbuf_release(gnrc_pktsnip_t *pkt);