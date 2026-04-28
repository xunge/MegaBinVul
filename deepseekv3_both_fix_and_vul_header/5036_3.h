#include <stdint.h>
#include <string.h>
#include <netinet/in.h>

typedef uint32_t as_t;
typedef uint32_t bgp_size_t;

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_ERROR,
    BGP_ATTR_PARSE_WITHDRAW,
    BGP_ATTR_PARSE_ERROR_NOTIFYPLS,
    BGP_ATTR_PARSE_EOR
};
typedef enum bgp_attr_parse_ret bgp_attr_parse_ret_t;

enum bgp_notify_update_err {
    BGP_NOTIFY_UPDATE_ERR,
    BGP_NOTIFY_UPDATE_ATTR_LENG_ERR,
    BGP_NOTIFY_UPDATE_MAL_ATTR,
    BGP_NOTIFY_UPDATE_ATTR_FLAG_ERR
};

enum bgp_attr_type {
    BGP_ATTR_ORIGIN,
    BGP_ATTR_AS_PATH,
    BGP_ATTR_AS4_PATH,
    BGP_ATTR_NEXT_HOP,
    BGP_ATTR_MULTI_EXIT_DISC,
    BGP_ATTR_LOCAL_PREF,
    BGP_ATTR_ATOMIC_AGGREGATE,
    BGP_ATTR_AGGREGATOR,
    BGP_ATTR_AS4_AGGREGATOR,
    BGP_ATTR_COMMUNITIES,
    BGP_ATTR_LARGE_COMMUNITIES,
    BGP_ATTR_ORIGINATOR_ID,
    BGP_ATTR_CLUSTER_LIST,
    BGP_ATTR_MP_REACH_NLRI,
    BGP_ATTR_MP_UNREACH_NLRI,
    BGP_ATTR_EXT_COMMUNITIES,
    BGP_ATTR_VNC,
    BGP_ATTR_ENCAP,
    BGP_ATTR_PREFIX_SID,
    BGP_ATTR_PMSI_TUNNEL
};

enum bgp_error_codes {
    EC_BGP_ATTRIBUTE_TOO_SMALL,
    EC_BGP_EXT_ATTRIBUTE_TOO_SMALL,
    EC_BGP_ATTRIBUTE_REPEATED,
    EC_BGP_ATTRIBUTE_TOO_LARGE,
    EC_BGP_ATTRIBUTE_PARSE_ERROR,
    EC_BGP_ATTRIBUTE_PARSE_WITHDRAW,
    EC_BGP_ATTRIBUTE_FETCH_ERROR,
    EC_BGP_ATTRIBUTES_MISMATCH
};

#define BGP_ATTR_BITMAP_SIZE 32
#define BGP_ATTR_MIN_LEN 3
#define BGP_ATTR_FLAG_EXTLEN 0x10
#define BGP_MAX_PACKET_SIZE 4096
#define ENCAP_SUBTLV_TYPE 1
#define VNC_SUBTLV_TYPE 2
#define ENABLE_BGP_VNC 0

#define CHECK_FLAG(flags, flag) ((flags) & (flag))
#define CHECK_BITMAP(bitmap, type) ((bitmap)[(type)/8] & (1 << ((type)%8)))
#define SET_BITMAP(bitmap, type) ((bitmap)[(type)/8] |= (1 << ((type)%8)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ATTR_FLAG_BIT(type) (1 << (type))

struct peer {
    char *host;
    void *input;
};

struct attr {
    uint32_t flag;
    void *transit;
    void *encap_subtlvs;
    void *vnc_subtlvs;
};

struct bgp_nlri {
    // Placeholder for NLRI structure
};

struct aspath {
    // Placeholder for AS path structure
};

struct bgp_attr_parser_args {
    struct peer *peer;
    bgp_size_t length;
    struct attr *attr;
    uint8_t type;
    uint8_t flags;
    uint8_t *startp;
    size_t total;
};

extern const char *attr_str[];

#define BGP_INPUT(peer) ((peer)->input)
#define BGP_INPUT_PNT(peer) ((uint8_t *)stream_pnt(BGP_INPUT(peer)))

// Placeholder functions
uint8_t *stream_pnt(void *stream);
uint8_t stream_getc(void *stream);
uint16_t stream_getw(void *stream);
void stream_get(void *dst, void *src, size_t len);
void stream_forward_getp(void *stream, int offset);
size_t STREAM_READABLE(void *stream);
void flog_warn(int code, const char *fmt, ...);
void bgp_notify_send(struct peer *peer, int err, int subcode);
void bgp_notify_send_with_data(struct peer *peer, int err, int subcode, void *data, size_t len);
const char *lookup_msg(const char *table[], int type, const char *default_msg);
int bgp_attr_flag_invalid(struct bgp_attr_parser_args *args);
int bgp_attr_malformed(struct bgp_attr_parser_args *args, int err, size_t total);
int bgp_attr_origin(struct bgp_attr_parser_args *args);
int bgp_attr_aspath(struct bgp_attr_parser_args *args);
int bgp_attr_as4_path(struct bgp_attr_parser_args *args, struct aspath **as4_path);
int bgp_attr_nexthop(struct bgp_attr_parser_args *args);
int bgp_attr_med(struct bgp_attr_parser_args *args);
int bgp_attr_local_pref(struct bgp_attr_parser_args *args);
int bgp_attr_atomic(struct bgp_attr_parser_args *args);
int bgp_attr_aggregator(struct bgp_attr_parser_args *args);
int bgp_attr_as4_aggregator(struct bgp_attr_parser_args *args, as_t *as4_aggregator, struct in_addr *as4_aggregator_addr);
int bgp_attr_community(struct bgp_attr_parser_args *args);
int bgp_attr_large_community(struct bgp_attr_parser_args *args);
int bgp_attr_originator_id(struct bgp_attr_parser_args *args);
int bgp_attr_cluster_list(struct bgp_attr_parser_args *args);
int bgp_mp_reach_parse(struct bgp_attr_parser_args *args, struct bgp_nlri *mp_update);
int bgp_mp_unreach_parse(struct bgp_attr_parser_args *args, struct bgp_nlri *mp_withdraw);
int bgp_attr_ext_communities(struct bgp_attr_parser_args *args);
int bgp_attr_encap(uint8_t type, struct peer *peer, bgp_size_t length, struct attr *attr, uint8_t flag, uint8_t *startp);
int bgp_attr_prefix_sid(bgp_size_t length, struct bgp_attr_parser_args *args, struct bgp_nlri *mp_update);
int bgp_attr_pmsi_tunnel(struct bgp_attr_parser_args *args);
int bgp_attr_unknown(struct bgp_attr_parser_args *args);
int bgp_attr_check(struct peer *peer, struct attr *attr);
int bgp_attr_munge_as4_attrs(struct peer *peer, struct attr *attr, struct aspath *as4_path, as_t as4_aggregator, struct in_addr *as4_aggregator_addr);
int bgp_attr_aspath_check(struct peer *peer, struct attr *attr);
void aspath_unintern(struct aspath **aspath);
void *transit_intern(void *transit);
void *encap_intern(void *encap, int type);