#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BUFSIZ 1024
#define AFI_IP 1
#define AFI_MAX 2
#define SAFI_UNICAST 1
#define SAFI_MAX 2

typedef unsigned int bgp_size_t;
typedef unsigned int afi_t;
typedef unsigned int safi_t;

struct peer_connection {
    int status;
    struct peer *peer;
};

struct peer {
    char *host;
    struct peer_connection *connection;
    char rcvd_attr_str[BUFSIZ];
    int rcvd_attr_printed;
    struct stream *curr;
    int stat_upd_7606;
    bool afc[AFI_MAX][SAFI_MAX];
    bool nsf[AFI_MAX][SAFI_MAX];
    unsigned int af_sflags[AFI_MAX][SAFI_MAX];
    struct bgp *bgp;
    bool advmap_table_change;
    time_t update_time;
};

struct stream {
    uint8_t *data;
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

struct bgp {
    int vrf_id;
    struct graceful_restart_info *gr_info[AFI_MAX][SAFI_MAX];
};

struct graceful_restart_info {
    int eor_required;
    int eor_received;
    void *t_select_deferral;
};

struct vrf {
    char *name;
};

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_WITHDRAW,
    BGP_ATTR_PARSE_ERROR,
    BGP_ATTR_PARSE_EOR
};

enum NLRI_PARSE_RET {
    BGP_NLRI_PARSE_OK,
    BGP_NLRI_PARSE_ERROR,
    BGP_NLRI_PARSE_ERROR_PREFIX_OVERFLOW
};

#define BGP_INVALID_LABEL_INDEX 0
#define MPLS_INVALID_LABEL 0
#define BGP_Stop 0
#define Receive_UPDATE_message 0
#define EC_BGP_INVALID_STATUS 0
#define EC_BGP_UPDATE_RCV 0
#define EC_BGP_UPDATE_PACKET_SHORT 0
#define EC_BGP_UPDATE_PACKET_LONG 0
#define BGP_NOTIFY_FSM_ERR 0
#define BGP_NOTIFY_UPDATE_ERR 0
#define BGP_NOTIFY_UPDATE_MAL_ATTR 0
#define BGP_NOTIFY_UPDATE_INVAL_NETWORK 0
#define BGP_NOTIFY_UPDATE_OPT_ATTR_ERR 0
#define ATTR_FLAG_BIT(x) (1 << (x))
#define BGP_ATTR_MP_REACH_NLRI 0
#define BGP_ATTR_MP_UNREACH_NLRI 0
#define PEER_STATUS_EOR_RECEIVED (1 << 0)
#define VRF_DEFAULT_NAME "default"
#define MTYPE_TMP 0
#define XFREE(type, ptr) free(ptr)

static const char *bgp_status_msg = "";

static inline uint8_t *stream_pnt(struct stream *s) { return s->pnt; }
static inline bgp_size_t stream_getw(struct stream *s) { return 0; }
static inline void stream_forward_getp(struct stream *s, bgp_size_t len) { s->pnt += len; }

static inline int peer_established(struct peer_connection *connection) { return 1; }
static inline const char *lookup_msg(const char *msg, int status, void *null) { return ""; }
static inline void bgp_notify_send(struct peer_connection *connection, int err, int subcode) {}
static inline int bgp_fsm_error_subcode(int status) { return 0; }
static inline void flog_err(int ec, const char *fmt, ...) {}
static inline void flog_warn(int ec, const char *fmt, ...) {}
static inline void zlog_debug(const char *fmt, ...) {}
static inline void zlog_info(const char *fmt, ...) {}
static inline int bgp_attr_parse(struct peer *peer, struct attr *attr, bgp_size_t len, struct bgp_nlri *update, struct bgp_nlri *withdraw) { return 0; }
static inline void bgp_attr_unintern_sub(struct attr *attr) {}
static inline int bgp_dump_attr(struct attr *attr, char *buf, size_t size) { return 0; }
static inline int bgp_attr_nexthop_valid(struct peer *peer, struct attr *attr) { return 0; }
static inline int bgp_nlri_parse(struct peer *peer, struct attr *attr, struct bgp_nlri *nlri, int withdraw) { return 0; }
static inline struct vrf *vrf_lookup_by_id(int id) { return NULL; }
static inline void bgp_update_explicit_eors(struct peer *peer) {}
static inline void bgp_best_path_select_defer(void *bgp, afi_t afi, safi_t safi) {}
static inline void bgp_clear_stale_route(struct peer *peer, afi_t afi, safi_t safi) {}
static inline const char *get_afi_safi_str(afi_t afi, safi_t safi, bool debug) { return ""; }
static inline time_t monotime(void *arg) { return time(NULL); }
static inline int bgp_debug_neighbor_events(struct peer *peer) { return 0; }
static inline int bgp_debug_update(struct peer *peer, void *a, void *b, int c) { return 0; }

#define BGP_PEER_GRACEFUL_RESTART_CAPABLE(peer) (0)
#define BGP_PEER_RESTARTING_MODE(peer) (0)
#define BGP_DEBUG(update, type) (0)
#define CHECK_FLAG(flags, bit) ((flags) & (bit))
#define SET_FLAG(flags, bit) ((flags) |= (bit))
#define EVENT_OFF(event) (void)0
#define EVENT_ARG(event) NULL