#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <assert.h>

typedef uint32_t bgp_size_t;
typedef uint32_t as_t;

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_ERROR,
    BGP_ATTR_PARSE_WITHDRAW,
    BGP_ATTR_PARSE_ERROR_NOTIFYPLS,
    BGP_ATTR_PARSE_EOR
};

enum bgp_attr_type {
    BGP_ATTR_ORIGIN = 1,
    BGP_ATTR_AS_PATH,
    BGP_ATTR_NEXT_HOP,
    BGP_ATTR_MULTI_EXIT_DISC,
    BGP_ATTR_LOCAL_PREF,
    BGP_ATTR_ATOMIC_AGGREGATE,
    BGP_ATTR_AGGREGATOR,
    BGP_ATTR_COMMUNITIES = 8,
    BGP_ATTR_ORIGINATOR_ID = 9,
    BGP_ATTR_CLUSTER_LIST = 10,
    BGP_ATTR_MP_REACH_NLRI = 14,
    BGP_ATTR_MP_UNREACH_NLRI = 15,
    BGP_ATTR_EXT_COMMUNITIES = 16,
    BGP_ATTR_AS4_PATH = 17,
    BGP_ATTR_AS4_AGGREGATOR = 18,
    BGP_ATTR_PMSI_TUNNEL = 22,
    BGP_ATTR_ENCAP = 23,
    BGP_ATTR_PREFIX_SID = 40,
    BGP_ATTR_LARGE_COMMUNITIES = 32,
    BGP_ATTR_OTC = 35,
    BGP_ATTR_AIGP = 26,
    BGP_ATTR_IPV6_EXT_COMMUNITIES = 25
};

enum bgp_notify_update_err {
    BGP_NOTIFY_UPDATE_ERR = 3,
    BGP_NOTIFY_UPDATE_ATTR_LENG_ERR = 1,
    BGP_NOTIFY_UPDATE_MAL_ATTR = 4,
    BGP_NOTIFY_UPDATE_ATTR_FLAG_ERR = 5
};

enum bgp_error_codes {
    EC_BGP_ATTRIBUTE_TOO_SMALL,
    EC_BGP_EXT_ATTRIBUTE_TOO_SMALL,
    EC_BGP_ATTRIBUTE_TOO_LARGE,
    EC_BGP_ATTRIBUTE_PARSE_WITHDRAW,
    EC_BGP_ATTRIBUTE_REPEATED,
    EC_BGP_ATTRIBUTE_PARSE_ERROR,
    EC_BGP_ATTRIBUTE_FETCH_ERROR,
    EC_BGP_ATTRIBUTES_MISMATCH
};

#define BGP_ATTR_BITMAP_SIZE 32
#define BGP_ATTR_MIN_LEN 3
#define BGP_ATTR_FLAG_EXTLEN (1 << 4)
#define BGP_PEER_EBGP 0
#define SAFI_LABELED_UNICAST 4
#define BGP_INVALID_LABEL_INDEX 0xFFFFFFFF
#define ENCAP_SUBTLV_TYPE 1
#define VNC_SUBTLV_TYPE 2

#define CHECK_FLAG(flag, bit) ((flag) & (bit))
#define CHECK_BITMAP(bitmap, type) ((bitmap)[(type)/8] & (1 << ((type)%8)))
#define SET_BITMAP(bitmap, type) ((bitmap)[(type)/8] |= (1 << ((type)%8)))
#define ATTR_FLAG_BIT(type) (1 << (type))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct peer {
    char *host;
    int sort;
    void *connection;
    size_t max_packet_size;
    void *input_stream;
};

struct attr {
    uint32_t flag;
    uint32_t mp_nexthop_len;
    uint32_t label_index;
    struct bgp_attr_encap *encap_subtlvs;
};

struct bgp_nlri {
    int safi;
};

struct aspath;
struct transit {
    int refcnt;
};

struct bgp_attr_encap {
    int refcnt;
};

struct bgp_attr_encap_subtlv {
    int refcnt;
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

extern const char attr_str[][32];

/* Stream functions */
#define BGP_INPUT(peer) ((peer)->input_stream)
#define BGP_INPUT_PNT(peer) ((uint8_t*)stream_pnt(BGP_INPUT(peer)))
#define STREAM_DATA(stream) ((uint8_t*)(stream))
#define STREAM_READABLE(stream) (stream_length(stream) - stream_get_getp(stream))

/* Function declarations */
void flog_warn(int ec, const char *fmt, ...);
void bgp_notify_send(void *connection, int major, int minor);
void bgp_notify_send_with_data(void *connection, int major, int minor, void *data, size_t len);
const char *lookup_msg(const char *str, int type, const char *def);

uint8_t *stream_pnt(void *stream);
size_t stream_length(void *stream);
size_t stream_get_getp(void *stream);
uint8_t stream_getc(void *stream);
uint16_t stream_getw(void *stream);
void stream_get(void *dest, void *stream, size_t len);
void stream_rewind_getp(void *stream, size_t len);
void stream_set_getp(void *stream, size_t pos);
void stream_forward_getp(void *stream, size_t len);

/* BGP attribute functions */
int bgp_attr_flag_invalid(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_malformed(struct bgp_attr_parser_args *args, int code, size_t len);
enum bgp_attr_parse_ret bgp_attr_origin(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_aspath(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_as4_path(struct bgp_attr_parser_args *args, struct aspath **as4_path);
enum bgp_attr_parse_ret bgp_attr_nexthop(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_med(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_local_pref(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_atomic(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_aggregator(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_as4_aggregator(struct bgp_attr_parser_args *args, as_t *as4_aggregator, struct in_addr *as4_aggregator_addr);
enum bgp_attr_parse_ret bgp_attr_community(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_large_community(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_originator_id(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_cluster_list(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_mp_reach_parse(struct bgp_attr_parser_args *args, struct bgp_nlri *mp_update);
enum bgp_attr_parse_ret bgp_mp_unreach_parse(struct bgp_attr_parser_args *args, struct bgp_nlri *mp_withdraw);
enum bgp_attr_parse_ret bgp_attr_ext_communities(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_encap(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_prefix_sid(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_pmsi_tunnel(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_ipv6_ext_communities(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_otc(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_aigp(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_unknown(struct bgp_attr_parser_args *args);
int bgp_attr_nexthop_valid(struct peer *peer, struct attr *attr);
int bgp_attr_check(struct peer *peer, struct attr *attr);
int bgp_attr_munge_as4_attrs(struct peer *peer, struct attr *attr, struct aspath *as4_path, as_t as4_aggregator, struct in_addr *as4_aggregator_addr);
enum bgp_attr_parse_ret bgp_attr_aspath_check(struct peer *peer, struct attr *attr);

/* Memory management functions */
void aspath_unintern(struct aspath **path);
struct transit *bgp_attr_get_transit(struct attr *attr);
void bgp_attr_set_transit(struct attr *attr, struct transit *transit);
struct transit *transit_intern(struct transit *transit);
void transit_free(struct transit *transit);
struct bgp_attr_encap *encap_intern(struct bgp_attr_encap *encap, int type);
void bgp_attr_flush_encap(struct attr *attr);
struct bgp_attr_encap_subtlv *bgp_attr_get_vnc_subtlvs(struct attr *attr);
void bgp_attr_set_vnc_subtlvs(struct attr *attr, struct bgp_attr_encap_subtlv *subtlvs);