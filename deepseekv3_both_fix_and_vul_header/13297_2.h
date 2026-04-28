#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct gnrc_pktsnip gnrc_pktsnip_t;
typedef struct gnrc_netif gnrc_netif_t;
typedef struct ipv6_hdr ipv6_hdr_t;
typedef struct gnrc_sixlowpan_frag gnrc_sixlowpan_frag_t;
typedef struct gnrc_sixlowpan_frag_rb gnrc_sixlowpan_frag_rb_t;
typedef struct gnrc_sixlowpan_frag_vrb gnrc_sixlowpan_frag_vrb_t;

#define GNRC_NETTYPE_IPV6 0x0800
#define GNRC_NETTYPE_NETIF 0x0801

#define IPHC1_IDX 0
#define SIXLOWPAN_IPHC1_NH 0x01
#define NHC_ID_MASK 0xE0
#define NHC_IPV6_EXT_ID 0xE0
#define NHC_IPV6_EXT_ID_ALT 0x00
#define NHC_UDP_ID 0xF0

struct gnrc_pktsnip {
    gnrc_pktsnip_t *next;
    void *data;
    size_t size;
    uint16_t type;
};

struct gnrc_netif {
    struct {
        uint16_t max_frag_size;
    } sixlo;
};

struct ipv6_hdr {
    uint8_t vtc;
    uint8_t tcfl;
    uint16_t len;
    uint8_t nh;
    uint8_t hl;
    uint8_t src[16];
    uint8_t dst[16];
};

struct gnrc_sixlowpan_frag {
    uint16_t datagram_size;
    uint16_t current_size;
    void *ints;
};

struct gnrc_sixlowpan_frag_rb {
    gnrc_sixlowpan_frag_t super;
    gnrc_pktsnip_t *pkt;
    int offset_diff;
};

struct gnrc_sixlowpan_frag_vrb {
    gnrc_sixlowpan_frag_t super;
    gnrc_netif_t *in_netif;
    int offset_diff;
};

#define DEBUG(fmt, ...) ((void)0)

static inline uint16_t byteorder_htons(uint16_t x) {
    return ((x & 0xff) << 8) | ((x >> 8) & 0xff);
}

static inline char *ipv6_addr_to_str(char *out, const uint8_t *addr, size_t len) {
    return out;
}

size_t _iphc_ipv6_decode(uint8_t *iphc_hdr, void *netif_data, gnrc_netif_t *iface, void *ipv6_data);
void _recv_error_release(gnrc_pktsnip_t *sixlo, gnrc_pktsnip_t *ipv6, gnrc_sixlowpan_frag_rb_t *rbuf);
size_t _iphc_nhc_ipv6_decode(gnrc_pktsnip_t *sixlo, size_t payload_offset, void *rbuf, size_t *prev_nh_offset, gnrc_pktsnip_t *ipv6, size_t *uncomp_hdr_len);
size_t _iphc_nhc_udp_decode(gnrc_pktsnip_t *sixlo, size_t payload_offset, void *rbuf, size_t prev_nh_offset, gnrc_pktsnip_t *ipv6, size_t *uncomp_hdr_len);
bool _is_rfrag(gnrc_pktsnip_t *sixlo);
gnrc_pktsnip_t *gnrc_pktbuf_add(gnrc_pktsnip_t *next, void *data, size_t size, uint16_t type);
void gnrc_pktbuf_release(gnrc_pktsnip_t *pkt);
gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *pkt, uint16_t type);
gnrc_netif_t *gnrc_netif_hdr_get_netif(void *data);
gnrc_pktsnip_t *gnrc_pkt_delete(gnrc_pktsnip_t *pkt, gnrc_pktsnip_t *snip);
gnrc_pktsnip_t *gnrc_pkt_append(gnrc_pktsnip_t *pkt, gnrc_pktsnip_t *snip);
int gnrc_pktbuf_realloc_data(gnrc_pktsnip_t *pkt, size_t size);
gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_from_route(gnrc_sixlowpan_frag_t *frag, gnrc_netif_t *iface, gnrc_pktsnip_t *ipv6);
void gnrc_sixlowpan_frag_vrb_rm(gnrc_sixlowpan_frag_vrb_t *vrbe);
size_t gnrc_pkt_len(gnrc_pktsnip_t *pkt);
gnrc_pktsnip_t *_encode_frag_for_forwarding(gnrc_pktsnip_t *ipv6, gnrc_sixlowpan_frag_vrb_t *vrbe);
int _forward_frag(gnrc_pktsnip_t *ipv6, gnrc_pktsnip_t *next, gnrc_sixlowpan_frag_vrb_t *vrbe, unsigned page);
void gnrc_sixlowpan_frag_rb_remove(gnrc_sixlowpan_frag_rb_t *rbuf);
void gnrc_sixlowpan_dispatch_recv(gnrc_pktsnip_t *ipv6, void *ctx, unsigned page);