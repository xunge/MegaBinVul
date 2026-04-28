#include <stdint.h>
#include <string.h>
#include <assert.h>

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
    uint16_t datagram_size;
    uint16_t current_size;
} gnrc_sixlowpan_frag_rb_base_t;

typedef struct gnrc_sixlowpan_frag_rb {
    gnrc_sixlowpan_frag_rb_base_t base;
    gnrc_pktsnip_t *pkt;
    uint16_t offset_diff;
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
#define DEBUG(x)

#define RBUF_ADD_ERROR (-1)
#define RBUF_ADD_FORWARDED (0)
#define RBUF_ADD_REPEAT (1)
#define RBUF_ADD_DUPLICATE (2)

#define SIXLOWPAN_UNCOMP (0x41)

extern const uint8_t *gnrc_netif_hdr_get_src_addr(const gnrc_netif_hdr_t *hdr);
extern const uint8_t *gnrc_netif_hdr_get_dst_addr(const gnrc_netif_hdr_t *hdr);
extern int gnrc_netif_hdr_get_netif(const gnrc_netif_hdr_t *hdr);
extern void gnrc_pktbuf_release(gnrc_pktsnip_t *pkt);
extern uint8_t *_6lo_frag_payload(gnrc_pktsnip_t *pkt);
extern size_t _6lo_frag_size(gnrc_pktsnip_t *pkt, size_t offset, uint8_t *data);
extern uint16_t sixlowpan_frag_datagram_size(void *data);
extern uint16_t sixlowpan_frag_datagram_tag(void *data);
extern uint8_t *_6lo_sfr_payload(gnrc_pktsnip_t *pkt);
extern size_t _6lo_sfr_frag_size(gnrc_pktsnip_t *pkt);
extern uint16_t _6lo_sfr_datagram_size(gnrc_pktsnip_t *pkt, size_t offset);
extern void gnrc_sixlowpan_frag_rb_gc(void);
extern gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_get(const uint8_t *src, uint8_t src_len, uint16_t tag);
extern void gnrc_sixlowpan_frag_vrb_rm(gnrc_sixlowpan_frag_vrb_t *vrb);
extern int _rbuf_get(const uint8_t *src, uint8_t src_len, const uint8_t *dst, uint8_t dst_len, uint16_t datagram_size, uint16_t datagram_tag, unsigned page);
extern void gnrc_sixlowpan_frag_rb_remove(gnrc_sixlowpan_frag_rb_t *rbuf);
extern int _rbuf_update_ints(gnrc_sixlowpan_frag_rb_base_t *super, size_t offset, size_t frag_size);
extern int _forward_frag(gnrc_pktsnip_t *pkt, size_t hdr_size, gnrc_sixlowpan_frag_vrb_t *vrb, unsigned page);
extern gnrc_pktsnip_t *_mark_frag_hdr(gnrc_pktsnip_t *pkt);
extern void gnrc_sixlowpan_iphc_recv(gnrc_pktsnip_t *pkt, gnrc_sixlowpan_frag_rb_t *rbuf, int arg);
extern int gnrc_sixlowpan_frag_rb_entry_empty(gnrc_sixlowpan_frag_rb_t *rbuf);
extern int _check_hdr(gnrc_pktsnip_t *tmp, unsigned page);
extern gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_from_route(gnrc_sixlowpan_frag_rb_base_t *super, int netif, gnrc_pktsnip_t *tmp);
extern void _adapt_hdr(gnrc_pktsnip_t *tmp, unsigned page);
extern int _forward_uncomp(gnrc_pktsnip_t *pkt, gnrc_sixlowpan_frag_rb_t *rbuf, gnrc_sixlowpan_frag_vrb_t *vrbe, unsigned page);
extern int _rbuf_resize_for_reassembly(gnrc_sixlowpan_frag_rb_t *rbuf);
extern int _check_fragments(gnrc_sixlowpan_frag_rb_base_t *super, size_t frag_size, size_t offset);
extern int _valid_offset(gnrc_pktsnip_t *pkt, size_t offset);
extern int sixlowpan_frag_is(void *data);
extern int sixlowpan_sfr_rfrag_is(void *data);
extern int sixlowpan_frag_n_is(void *data);
extern int sixlowpan_iphc_is(void *data);
extern int sixlowpan_frag_1_is(void *data);

extern gnrc_sixlowpan_frag_rb_t rbuf[];