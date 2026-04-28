#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct gnrc_pktsnip gnrc_pktsnip_t;
typedef struct gnrc_netif gnrc_netif_t;
typedef struct ipv6_hdr ipv6_hdr_t;
typedef struct gnrc_sixlowpan_frag_rb gnrc_sixlowpan_frag_rb_t;
typedef struct gnrc_sixlowpan_frag_vrb gnrc_sixlowpan_frag_vrb_t;

struct gnrc_pktsnip {
    void *data;
    size_t size;
    gnrc_pktsnip_t *next;
};

struct gnrc_netif {
    struct {
        uint16_t max_frag_size;
    } sixlo;
};

struct ipv6_hdr {
    uint8_t nh;
    uint8_t hl;
    uint16_t len;
    uint8_t dst[16];
};

struct gnrc_sixlowpan_frag_rb {
    struct {
        uint16_t datagram_size;
        uint16_t current_size;
        void *ints;
    } super;
    gnrc_pktsnip_t *pkt;
    int offset_diff;
};

struct gnrc_sixlowpan_frag_vrb {
    struct {
        uint16_t current_size;
    } super;
    gnrc_netif_t *in_netif;
    int offset_diff;
};

#define MODULE_GNRC_SIXLOWPAN_FRAG_VRB
#define MODULE_GNRC_SIXLOWPAN_IPHC_NHC
#define MODULE_GNRC_SIXLOWPAN_FRAG_SFR

#define GNRC_NETTYPE_IPV6 0
#define GNRC_NETTYPE_NETIF 0

#define IPHC1_IDX 0
#define SIXLOWPAN_IPHC1_NH 0
#define NHC_ID_MASK 0
#define NHC_IPV6_EXT_ID 0
#define NHC_IPV6_EXT_ID_ALT 1
#define NHC_UDP_ID 2

#define DEBUG(fmt, ...)

static void _recv_error_release(gnrc_pktsnip_t *a, gnrc_pktsnip_t *b, gnrc_sixlowpan_frag_rb_t *c) {}
static size_t _iphc_ipv6_decode(uint8_t *a, void *b, gnrc_netif_t *c, void *d) { return 0; }
static size_t _iphc_nhc_ipv6_decode(gnrc_pktsnip_t *a, size_t b, gnrc_sixlowpan_frag_rb_t *c, size_t *d, gnrc_pktsnip_t *e, size_t *f) { return 0; }
static size_t _iphc_nhc_udp_decode(gnrc_pktsnip_t *a, size_t b, gnrc_sixlowpan_frag_rb_t *c, size_t d, gnrc_pktsnip_t *e, size_t *f) { return 0; }
static bool _is_rfrag(gnrc_pktsnip_t *a) { return false; }
static gnrc_pktsnip_t *gnrc_pktbuf_add(void *a, void *b, size_t c, int d) { return NULL; }
static void gnrc_pktbuf_release(gnrc_pktsnip_t *a) {}
static int gnrc_pktbuf_realloc_data(gnrc_pktsnip_t *a, size_t b) { return 0; }
static gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *a, int b) { return NULL; }
static gnrc_netif_t *gnrc_netif_hdr_get_netif(void *a) { return NULL; }
static gnrc_pktsnip_t *gnrc_pkt_delete(gnrc_pktsnip_t *a, gnrc_pktsnip_t *b) { return NULL; }
static gnrc_pktsnip_t *gnrc_pkt_append(gnrc_pktsnip_t *a, gnrc_pktsnip_t *b) { return NULL; }
static gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_from_route(void *a, gnrc_netif_t *b, gnrc_pktsnip_t *c) { return NULL; }
static void gnrc_sixlowpan_frag_vrb_rm(gnrc_sixlowpan_frag_vrb_t *a) {}
static void gnrc_sixlowpan_frag_rb_remove(gnrc_sixlowpan_frag_rb_t *a) {}
static size_t gnrc_pkt_len(gnrc_pktsnip_t *a) { return 0; }
static gnrc_pktsnip_t *_encode_frag_for_forwarding(gnrc_pktsnip_t *a, gnrc_sixlowpan_frag_vrb_t *b) { return NULL; }
static int _forward_frag(gnrc_pktsnip_t *a, gnrc_pktsnip_t *b, gnrc_sixlowpan_frag_vrb_t *c, unsigned d) { return 0; }
static void gnrc_sixlowpan_dispatch_recv(gnrc_pktsnip_t *a, void *b, unsigned c) {}
static char *ipv6_addr_to_str(char *a, void *b, size_t c) { return NULL; }

static inline uint16_t byteorder_htons(uint16_t x) {
    return ((x & 0xff) << 8) | ((x >> 8) & 0xff);
}