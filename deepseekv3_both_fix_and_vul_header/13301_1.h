#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef struct gnrc_pktsnip {
    struct gnrc_pktsnip *next;
    void *data;
    size_t size;
    uint16_t type;
} gnrc_pktsnip_t;

typedef struct {
    uint8_t nh;
} ipv6_hdr_t;

typedef struct {
    // Define necessary fields for gnrc_netif_hdr_t
} gnrc_netif_hdr_t;

typedef struct {
    // Define necessary fields for gnrc_netif_t
} gnrc_netif_t;

typedef struct {
    // Define necessary fields for udp_hdr_t
} udp_hdr_t;

#define GNRC_NETTYPE_UNDEF 0
#define GNRC_NETTYPE_SIXLOWPAN 1
#define PROTNUM_UDP 17
#define PROTNUM_IPV6 41
#define PROTNUM_IPV6_EXT_HOPOPT 0
#define PROTNUM_IPV6_EXT_RH 43
#define PROTNUM_IPV6_EXT_FRAG 44
#define PROTNUM_IPV6_EXT_DST 60
#define PROTNUM_IPV6_EXT_MOB 135
#define PROTNUM_RESERVED 255

static int _compressible(gnrc_pktsnip_t *ptr);
static uint16_t _iphc_ipv6_encode(gnrc_pktsnip_t *pkt, const gnrc_netif_hdr_t *netif_hdr, gnrc_netif_t *iface, uint8_t *iphc_hdr);
static int _compressible_nh(uint8_t nh);
static ssize_t _nhc_udp_encode_snip(gnrc_pktsnip_t *pkt, uint8_t *data);
static ssize_t _nhc_ipv6_encode_snip(gnrc_pktsnip_t *pkt, const gnrc_netif_hdr_t *netif_hdr, gnrc_netif_t *iface, uint8_t *data, uint8_t *nh);
static ssize_t _nhc_ipv6_ext_encode_snip(gnrc_pktsnip_t *pkt, uint8_t *data, uint8_t *nh);

gnrc_pktsnip_t *gnrc_pktbuf_add(void *data, void *next, size_t size, uint16_t type);
gnrc_pktsnip_t *gnrc_pktbuf_start_write(gnrc_pktsnip_t *pkt);
void gnrc_pktbuf_release(gnrc_pktsnip_t *pkt);
void gnrc_pktbuf_realloc_data(gnrc_pktsnip_t *pkt, size_t size);
gnrc_pktsnip_t *gnrc_pktbuf_remove_snip(gnrc_pktsnip_t *pkt, gnrc_pktsnip_t *snip);

#define DEBUG(x)
#define MODULE_GNRC_SIXLOWPAN_IPHC_NHC