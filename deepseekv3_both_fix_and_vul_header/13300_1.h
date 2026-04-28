#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>

typedef struct gnrc_netif_hdr {
    uint8_t src_l2addr_len;
    uint8_t dst_l2addr_len;
} gnrc_netif_hdr_t;

typedef struct gnrc_pktsnip {
    void *data;
    size_t size;
    unsigned users;
} gnrc_pktsnip_t;

typedef struct gnrc_sixlowpan_frag_rb_base {
    uint16_t current_size;
    uint16_t datagram_size;
} gnrc_sixlowpan_frag_rb_base_t;

typedef struct gnrc_sixlowpan_frag_rb {
    gnrc_sixlowpan_frag_rb_base_t base;
    gnrc_pktsnip_t *pkt;
    int offset_diff;
} gnrc_sixlowpan_frag_rb_t;

typedef struct gnrc_sixlowpan_frag_vrb {
    gnrc_sixlowpan_frag_rb_base_t base;
} gnrc_sixlowpan_frag_vrb_t;

typedef struct sixlowpan_sfr_rfrag {
    struct {
        uint16_t tag;
    } base;
} sixlowpan_sfr_rfrag_t;

typedef struct sixlowpan_frag_n {
    uint8_t dummy;
} sixlowpan_frag_n_t;

#define MODULE_GNRC_SIXLOWPAN_FRAG 1
#define MODULE_GNRC_SIXLOWPAN_FRAG_SFR 1
#define MODULE_GNRC_SIXLOWPAN_FRAG_MINFWD 1
#define MODULE_GNRC_SIXLOWPAN_IPHC 1
#define IS_USED(x) (x)

#define RBUF_ADD_ERROR (-1)
#define RBUF_ADD_FORWARDED (1)
#define RBUF_ADD_REPEAT (2)
#define RBUF_ADD_DUPLICATE (3)

#define SIXLOWPAN_UNCOMP (0x41)

#define DEBUG(x)

static gnrc_sixlowpan_frag_rb_t rbuf[1];