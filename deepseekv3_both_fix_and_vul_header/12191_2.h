#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef uint16_t bgp_size_t;
typedef uint16_t afi_t;
typedef uint8_t safi_t;

#define AFI_IP 1
#define SAFI_UNICAST 1
#define BGP_INVALID_LABEL_INDEX 0xFFFFFFFF
#define MPLS_INVALID_LABEL 0xFFFFFFFF
#define BUFSIZ 8192
#define BGP_Stop 0
#define Receive_UPDATE_message 1
#define BGP_NOTIFY_FSM_ERR 0
#define BGP_NOTIFY_UPDATE_ERR 0
#define BGP_NOTIFY_UPDATE_MAL_ATTR 0
#define BGP_NOTIFY_UPDATE_INVAL_NETWORK 0
#define BGP_NOTIFY_UPDATE_OPT_ATTR_ERR 0
#define EC_BGP_INVALID_STATUS 0
#define EC_BGP_UPDATE_RCV 0
#define EC_BGP_UPDATE_PACKET_SHORT 0
#define EC_BGP_UPDATE_PACKET_LONG 0
#define VRF_DEFAULT_NAME "default"
#define PEER_STATUS_EOR_RECEIVED (1 << 0)
#define BGP_ATTR_MP_REACH_NLRI 14
#define BGP_ATTR_MP_UNREACH_NLRI 15

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_WITHDRAW,
    BGP_ATTR_PARSE_ERROR,
    BGP_ATTR_PARSE_MISSING_MANDATORY
};

enum BGP_NLRI_PARSE_RET {
    BGP_NLRI_PARSE_OK,
    BGP_NLRI_PARSE_ERROR,
    BGP_NLRI_PARSE_ERROR_PREFIX_OVERFLOW
};

struct peer_connection {
    int status;
};

struct stream {
    uint8_t *pnt;
};

struct attr {
    uint8_t flag;
    uint32_t label_index;
    uint32_t label;
};

struct bgp_nlri {
    afi_t afi;
    safi_t safi;
    uint8_t *nlri;
    bgp_size_t length;
};

struct graceful_restart_info {
    int eor_required;
    int eor_received;
    void *t_select_deferral;
};

struct peer {
    char *host;
    struct stream *curr;
    struct peer_connection *connection;
    struct bgp *bgp;
    uint8_t rcvd_attr_str[BUFSIZ];
    int rcvd_attr_printed;
    bool afc[2][2];
    uint8_t af_sflags[2][2];
    bool nsf[2][2];
    time_t update_time;
    bool advmap_table_change;
    int stat_upd_7606;
};

struct bgp {
    int vrf_id;
    struct graceful_restart_info gr_info[2][2];
};

struct vrf {
    char *name;
};

static const char *bgp_status_msg[] = {NULL};

#define BGP_DEBUG(type, subtype) 0
#define BGP_PEER_GRACEFUL_RESTART_CAPABLE(peer) 0
#define BGP_PEER_RESTARTING_MODE(peer) 0
#define CHECK_FLAG(flags, bit) ((flags) & (bit))
#define SET_FLAG(flags, bit) ((flags) |= (bit))
#define EVENT_OFF(event) 
#define XFREE(type, ptr) 
#define MTYPE_TMP 0
#define EVENT_ARG(event) NULL
#define ATTR_FLAG_BIT(attr) (1 << (attr))

static inline uint8_t *stream_pnt(struct stream *s) { return s->pnt; }
static inline void stream_forward_getp(struct stream *s, bgp_size_t len) { s->pnt += len; }
static inline bgp_size_t stream_getw(struct stream *s) { bgp_size_t val = *(bgp_size_t *)s->pnt; s->pnt += 2; return val; }

static bool peer_established(struct peer_connection *connection) { return false; }
static const char *lookup_msg(const char *msg[], int status, const char *def) { return def; }
static int bgp_fsm_error_subcode(int status) { return 0; }
static void bgp_notify_send(struct peer_connection *connection, int major, int minor) {}
static int bgp_attr_parse(struct peer *peer, struct attr *attr, bgp_size_t len, struct bgp_nlri *mp_update, struct bgp_nlri *mp_withdraw) { return 0; }
static void bgp_attr_unintern_sub(struct attr *attr) {}
static int bgp_dump_attr(struct attr *attr, char *buf, size_t size) { return 0; }
static bool bgp_debug_update(struct peer *peer, void *arg1, void *arg2, int arg3) { return false; }
static int bgp_attr_nexthop_valid(struct peer *peer, struct attr *attr) { return 0; }
static int bgp_nlri_parse(struct peer *peer, struct attr *attr, struct bgp_nlri *nlri, int withdraw) { return 0; }
static void bgp_update_explicit_eors(struct peer *peer) {}
static struct vrf *vrf_lookup_by_id(int vrf_id) { return NULL; }
static const char *get_afi_safi_str(afi_t afi, safi_t safi, bool debug) { return ""; }
static void bgp_clear_stale_route(struct peer *peer, afi_t afi, safi_t safi) {}
static bool bgp_debug_neighbor_events(struct peer *peer) { return false; }
static void bgp_best_path_select_defer(struct bgp *bgp, afi_t afi, safi_t safi) {}
static time_t monotime(void *arg) { return time(NULL); }
static void flog_err(int ec, const char *fmt, ...) {}
static void flog_warn(int ec, const char *fmt, ...) {}
static void zlog_debug(const char *fmt, ...) {}
static void zlog_info(const char *fmt, ...) {}