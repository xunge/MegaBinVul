#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define GNRC_NETIF_L2ADDR_MAXLEN 8
#define US_PER_MS 1000
#define MODULE_GNRC_SIXLOWPAN_FRAG_SFR_STATS 1
#define CONFIG_GNRC_SIXLOWPAN_FRAG_RBUF_DEL_TIMER 0
#define CONFIG_GNRC_SIXLOWPAN_FRAG_VRB_TIMEOUT_US 0
#define IS_USED(x) (x)

typedef struct {
    void *data;
} gnrc_pktsnip_t;

typedef struct {
    uint8_t src_l2addr_len;
    uint8_t *src_addr;
    uint16_t netif;
} gnrc_netif_hdr_t;

typedef struct {
    struct {
        uint8_t tag;
        uint8_t disp_ecn;
    } base;
    uint8_t bitmap[4];
} sixlowpan_sfr_ack_t;

typedef struct {
    uint8_t disp_ecn;
    uint8_t tag;
} sixlowpan_sfr_t;

typedef struct {
    struct {
        uint8_t *src;
        uint8_t src_len;
        uint8_t tag;
        uint32_t arrival;
    } super;
    uint16_t in_netif;
} gnrc_sixlowpan_frag_vrb_t;

typedef struct {
    void *event;
    struct {
        void *ptr;
    } content;
} msg_t;

typedef struct {
    msg_t msg;
    void *event;
} arq_timeout_event_t;

typedef struct {
    arq_timeout_event_t arq_timeout_event;
} sfr_t;

typedef struct {
    sfr_t sfr;
} gnrc_sixlowpan_frag_fb_t;

typedef struct {
    uint32_t u32;
} unaligned_u32_t;

extern unaligned_u32_t _full_bitmap;
extern unaligned_u32_t _null_bitmap;
extern char addr_str[GNRC_NETIF_L2ADDR_MAXLEN * 3];

struct evtimer;
typedef struct evtimer evtimer_t;
extern evtimer_t _arq_timer;

struct {
    struct {
        int forwarded;
    } acks;
} _stats;

static inline uint32_t xtimer_now_usec(void) { return 0; }
static inline char* gnrc_netif_addr_to_str(void *addr, uint8_t len, char *out) { return out; }
static inline void* gnrc_netif_hdr_get_src_addr(gnrc_netif_hdr_t *hdr) { return NULL; }
static inline uint16_t gnrc_netif_hdr_get_netif(gnrc_netif_hdr_t *hdr) { return 0; }
static inline gnrc_sixlowpan_frag_vrb_t* gnrc_sixlowpan_frag_vrb_reverse(uint16_t netif, void *src, uint8_t src_len, uint8_t tag) { return NULL; }
static inline void _send_ack(uint16_t netif, void *src, uint8_t src_len, sixlowpan_sfr_t *base, uint8_t *bitmap) {}
static inline uint32_t unaligned_get_u32(const uint8_t *ptr) { return 0; }
static inline void gnrc_sixlowpan_frag_vrb_rm(gnrc_sixlowpan_frag_vrb_t *vrbe) {}
static inline gnrc_sixlowpan_frag_fb_t* gnrc_sixlowpan_frag_fb_get_by_tag(uint8_t tag) { return NULL; }
static inline void evtimer_del(evtimer_t *timer, void *event) {}
static inline void _retry_datagram(gnrc_sixlowpan_frag_fb_t *fbuf) {}
static inline void _check_failed_frags(sixlowpan_sfr_ack_t *hdr, gnrc_sixlowpan_frag_fb_t *fbuf, uint32_t time) {}
static inline void gnrc_pktbuf_release(gnrc_pktsnip_t *pkt) {}
#define DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)