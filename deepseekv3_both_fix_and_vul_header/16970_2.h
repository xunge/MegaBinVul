#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int bgp_size_t;
typedef unsigned int afi_t;
typedef unsigned int safi_t;

#define AFI_IP 1
#define SAFI_UNICAST 1
#define BGP_ATTR_MP_REACH_NLRI 14
#define BGP_ATTR_MP_UNREACH_NLRI 15
#define BGP_NOTIFY_UPDATE_ERR 3
#define BGP_NOTIFY_UPDATE_MAL_ATTR 1
#define BGP_NOTIFY_UPDATE_INVAL_NETWORK 3
#define BGP_NOTIFY_UPDATE_OPT_ATTR_ERR 4
#define BGP_NOTIFY_FSM_ERR 1
#define BGP_Stop 0
#define Receive_UPDATE_message 1
#define MPLS_INVALID_LABEL 0xFFFFFFFF
#define BGP_INVALID_LABEL_INDEX 0xFFFFFFFF
#define BUFSIZ 8192
#define MTYPE_TMP 0
#define VRF_DEFAULT_NAME "default"

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_WITHDRAW,
    BGP_ATTR_PARSE_ERROR,
    BGP_ATTR_PARSE_EOR
};

enum bgp_nlri_parse_ret {
    BGP_NLRI_PARSE_OK,
    BGP_NLRI_PARSE_ERROR,
    BGP_NLRI_PARSE_ERROR_PREFIX_OVERFLOW
};

enum bgp_debug_flags {
    UPDATE_IN,
    UPDATE_PREFIX
};

struct graceful_restart_info {
    int eor_required;
    int eor_received;
    void *t_select_deferral;
};

struct peer {
    char *host;
    struct bgp *bgp;
    struct stream *curr;
    uint8_t *rcvd_attr_str;
    int rcvd_attr_printed;
    int stat_upd_7606;
    time_t update_time;
    bool advmap_table_change;
    bool afc[2][2];
    bool nsf[2][2];
    unsigned int af_sflags[2][2];
    struct connection *connection;
};

struct bgp {
    int vrf_id;
    struct graceful_restart_info gr_info[2][2];
};

struct connection {
    int status;
};

struct stream {
    uint8_t *pnt;
};

struct attr {
    unsigned int flag;
    unsigned int label_index;
    unsigned int label;
};

struct bgp_nlri {
    afi_t afi;
    safi_t safi;
    uint8_t *nlri;
    bgp_size_t length;
};

struct vrf {
    char *name;
};

enum {
    EC_BGP_INVALID_STATUS,
    EC_BGP_UPDATE_RCV,
    EC_BGP_UPDATE_PACKET_SHORT,
    EC_BGP_UPDATE_PACKET_LONG
};

#define ATTR_FLAG_BIT(x) (1 << (x))
#define CHECK_FLAG(x, y) ((x) & (y))
#define SET_FLAG(x, y) ((x) |= (y))
#define PEER_STATUS_EOR_RECEIVED (1 << 0)
#define BGP_PEER_GRACEFUL_RESTART_CAPABLE(x) (0)
#define BGP_PEER_RESTARTING_MODE(x) (0)
#define EVENT_OFF(x) (void)(x)
#define EVENT_ARG(x) (x)
#define XFREE(type, ptr) free(ptr)
#define BGP_DEBUG(type, flag) (0)

static const char *bgp_status_msg[] = {NULL};

static inline uint8_t *stream_pnt(struct stream *s) { return s->pnt; }
static inline void stream_forward_getp(struct stream *s, bgp_size_t len) { s->pnt += len; }
static inline bgp_size_t stream_getw(struct stream *s) { bgp_size_t val = *(bgp_size_t *)s->pnt; s->pnt += sizeof(bgp_size_t); return val; }

static inline bool peer_established(struct peer *peer) { return false; }
static inline const char *lookup_msg(const char *msg[], int status, void *arg) { return NULL; }
static inline void bgp_notify_send(struct peer *peer, int code, int subcode) {}
static inline int bgp_fsm_error_subcode(int status) { return 0; }
static inline int bgp_attr_parse(struct peer *peer, struct attr *attr, bgp_size_t len, struct bgp_nlri *mp_update, struct bgp_nlri *mp_withdraw) { return 0; }
static inline void bgp_attr_unintern_sub(struct attr *attr) {}
static inline int bgp_dump_attr(struct attr *attr, char *buf, int len) { return 0; }
static inline bool bgp_debug_update(struct peer *peer, void *arg1, void *arg2, int arg3) { return false; }
static inline int bgp_attr_nexthop_valid(struct peer *peer, struct attr *attr) { return 0; }
static inline int bgp_nlri_parse(struct peer *peer, struct attr *attr, struct bgp_nlri *nlri, int withdraw) { return 0; }
static inline void bgp_update_explicit_eors(struct peer *peer) {}
static inline struct vrf *vrf_lookup_by_id(int id) { return NULL; }
static inline const char *get_afi_safi_str(afi_t afi, safi_t safi, bool debug) { return NULL; }
static inline void bgp_clear_stale_route(struct peer *peer, afi_t afi, safi_t safi) {}
static inline void bgp_best_path_select_defer(struct bgp *bgp, afi_t afi, safi_t safi) {}
static inline bool bgp_debug_neighbor_events(struct peer *peer) { return false; }
static inline time_t monotime(void *arg) { return time(NULL); }
static inline void flog_err(int code, const char *fmt, ...) {}
static inline void flog_warn(int code, const char *fmt, ...) {}
static inline void zlog_debug(const char *fmt, ...) {}
static inline void zlog_info(const char *fmt, ...) {}