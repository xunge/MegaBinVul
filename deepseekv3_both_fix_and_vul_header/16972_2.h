#include <stdint.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

typedef uint16_t bgp_size_t;
typedef uint16_t iana_afi_t;
typedef uint8_t iana_safi_t;
typedef uint16_t afi_t;
typedef uint8_t safi_t;

#define BGP_MSG_ROUTE_REFRESH_MIN_SIZE 23
#define BGP_HEADER_SIZE 19
#define BGP_Stop 0
#define BGP_PACKET_NOOP 1
#define CMD_SUCCESS 0
#define PEER_CAP_REFRESH_ADV (1 << 0)
#define PEER_CAP_RESTART_RCV (1 << 1)
#define PEER_CAP_ENHANCED_RR_RCV (1 << 2)
#define ORF_TYPE_PREFIX 64
#define ORF_COMMON_PART_REMOVE_ALL (1 << 0)
#define ORF_COMMON_PART_REMOVE (1 << 1)
#define ORF_COMMON_PART_DENY (1 << 2)
#define REFRESH_DEFER 0
#define REFRESH_IMMEDIATE 1
#define BGP_ROUTE_REFRESH_BORR 1
#define BGP_ROUTE_REFRESH_EORR 2
#define INET6_BUFSIZ 46

#define PEER_STATUS_ORF_WAIT_REFRESH (1 << 0)
#define PEER_STATUS_EOR_RECEIVED (1 << 1)
#define PEER_STATUS_BORR_RECEIVED (1 << 2)
#define PEER_STATUS_EORR_RECEIVED (1 << 3)
#define PEER_STATUS_ENHANCED_REFRESH (1 << 4)
#define PEER_STATUS_EOR_SEND (1 << 5)
#define PEER_STATUS_REFRESH_PENDING (1 << 6)
#define PEER_STATUS_BORR_SEND (1 << 7)
#define PEER_STATUS_EORR_SEND (1 << 8)
#define SUBGRP_STATUS_DEFAULT_ORIGINATE (1 << 0)

#define CHECK_FLAG(flags, flag) ((flags) & (flag))
#define SET_FLAG(flags, flag) ((flags) |= (flag))
#define UNSET_FLAG(flags, flag) ((flags) &= ~(flag))

enum bgp_notify_error_code {
    BGP_NOTIFY_HEADER_ERR,
    BGP_NOTIFY_FSM_ERR,
    BGP_NOTIFY_ROUTE_REFRESH_ERR,
    BGP_NOTIFY_CEASE
};

enum bgp_notify_subcode {
    BGP_NOTIFY_HEADER_BAD_MESTYPE,
    BGP_NOTIFY_ROUTE_REFRESH_INVALID_MSG_LEN,
    BGP_NOTIFY_SUBCODE_UNSPECIFIC
};

enum bgp_fsm_status {
    BGP_STATUS_ESTABLISHED
};

enum bgp_error_subcode {
    EC_BGP_NO_CAP,
    EC_BGP_INVALID_STATUS
};

struct stream {
    uint8_t *curr;
    uint8_t *(*pnt)(struct stream *);
    void (*forward_getp)(struct stream *, uint16_t);
    uint16_t (*getw)(struct stream *);
    uint8_t (*getc)(struct stream *);
};

struct peer {
    uint32_t cap;
    char *host;
    struct stream *curr;
    uint8_t status;
    uint8_t af_sflags[2][2];
    uint8_t subtype;
    void *orf_plist[2][2];
    bool nsf[2][2];
    void *t_refresh_stalepath;
    struct bgp *bgp;
    uint32_t stalepath_time;
};

struct peer_af {
    struct subgroup *subgroup;
    uint32_t sflags;
};

struct subgroup {
    uint32_t sflags;
};

struct update_group {
    struct peer *peer;
};

struct bgp {
    uint32_t stalepath_time;
};

struct orf_prefix {
    uint32_t seq;
    uint8_t ge;
    uint8_t le;
    struct {
        uint8_t family;
        uint8_t prefixlen;
        union {
            uint8_t prefix[16];
        } u;
    } p;
};

#define PAF_UPDGRP(paf) ((struct update_group *)(paf))
#define UPDGRP_PEER(updgrp) ((struct peer *)(updgrp)->peer)
#define PSIZE(plen) ((plen + 7) / 8)

static struct {
    void *master;
} *bm;

static const char *bgp_status_msg[] = {
    "Idle", "Connect", "Active", "OpenSent", "OpenConfirm", "Established"
};

static void flog_err(enum bgp_error_subcode code, const char *fmt, ...) {}
static void bgp_notify_send(struct peer *peer, enum bgp_notify_error_code code, enum bgp_notify_subcode subcode) {}
static bool peer_established(struct peer *peer) { return peer->status == BGP_STATUS_ESTABLISHED; }
static const char *lookup_msg(const char *msg[], uint8_t status, void *null) { return msg[status]; }
static uint8_t bgp_fsm_error_subcode(uint8_t status) { return status; }
static int bgp_map_afi_safi_iana2int(iana_afi_t pkt_afi, iana_safi_t pkt_safi, afi_t *afi, safi_t *safi) { return 0; }
static void zlog_info(const char *fmt, ...) {}
static const char *iana_afi2str(iana_afi_t afi) { return "AFI"; }
static const char *iana_safi2str(iana_safi_t safi) { return "SAFI"; }
static void zlog_err(const char *fmt, ...) {}
static void zlog_debug(const char *fmt, ...) {}
static bool bgp_debug_neighbor_events(struct peer *peer) { return true; }
static void prefix_bgp_orf_remove_all(afi_t afi, const char *name) {}
static uint8_t afi2family(afi_t afi) { return 0; }
static uint16_t prefix_blen(struct orf_prefix *p) { return 0; }
static int prefix_bgp_orf_set(const char *name, afi_t afi, struct orf_prefix *orfp, int permit, int add) { return CMD_SUCCESS; }
static void *prefix_bgp_orf_lookup(afi_t afi, const char *name) { return NULL; }
static struct peer_af *peer_af_find(struct peer *peer, afi_t afi, safi_t safi) { return NULL; }
static const char *afi2str(afi_t afi) { return "AFI"; }
static const char *safi2str(safi_t safi) { return "SAFI"; }
static bool peer_active_nego(struct peer *peer) { return true; }
static void bgp_set_stale_route(struct peer *peer, afi_t afi, safi_t safi) {}
static void event_add_timer(void *master, void (*func)(void *), void *arg, uint32_t time, void **timer) {}
static void bgp_refresh_stalepath_timer_expire(void *arg) {}
static void EVENT_OFF(void *timer) {}
static void bgp_clear_stale_route(struct peer *peer, afi_t afi, safi_t safi) {}
static void bgp_route_refresh_send(struct peer *peer, afi_t afi, safi_t safi, uint8_t orf, uint8_t when, uint16_t orf_len, uint8_t subtype) {}
static void bgp_announce_route(struct peer *peer, afi_t afi, safi_t safi, bool force) {}

static uint16_t stream_getw(struct stream *s) { return s->getw(s); }
static uint8_t stream_getc(struct stream *s) { return s->getc(s); }
static uint8_t *stream_pnt(struct stream *s) { return s->pnt(s); }
static void stream_forward_getp(struct stream *s, uint16_t len) { s->forward_getp(s, len); }