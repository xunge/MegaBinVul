#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <assert.h>

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_ERROR,
    BGP_ATTR_PARSE_WITHDRAW,
    BGP_ATTR_PARSE_ERROR_NOTIFYPLS
};

#define BGP_ATTR_BITMAP_SIZE 32
#define BGP_ATTR_MIN_LEN 3
#define BGP_ATTR_FLAG_EXTLEN 0x10
#define BGP_PEER_EBGP 0
#define SAFI_LABELED_UNICAST 4
#define BGP_INVALID_LABEL_INDEX 0xFFFFFFFF
#define ENCAP_SUBTLV_TYPE 1

#define BGP_ATTR_ORIGIN 1
#define BGP_ATTR_AS_PATH 2
#define BGP_ATTR_AS4_PATH 3
#define BGP_ATTR_NEXT_HOP 4
#define BGP_ATTR_MULTI_EXIT_DISC 5
#define BGP_ATTR_LOCAL_PREF 6
#define BGP_ATTR_ATOMIC_AGGREGATE 7
#define BGP_ATTR_AGGREGATOR 8
#define BGP_ATTR_AS4_AGGREGATOR 9
#define BGP_ATTR_COMMUNITIES 10
#define BGP_ATTR_LARGE_COMMUNITIES 11
#define BGP_ATTR_ORIGINATOR_ID 12
#define BGP_ATTR_CLUSTER_LIST 13
#define BGP_ATTR_MP_REACH_NLRI 14
#define BGP_ATTR_MP_UNREACH_NLRI 15
#define BGP_ATTR_EXT_COMMUNITIES 16
#define BGP_ATTR_ENCAP 17
#define BGP_ATTR_PREFIX_SID 18
#define BGP_ATTR_PMSI_TUNNEL 19
#define BGP_ATTR_IPV6_EXT_COMMUNITIES 20
#define BGP_ATTR_OTC 21
#define BGP_ATTR_AIGP 22

struct peer {
    char *host;
    int sort;
    void *connection;
    size_t max_packet_size;
};

struct attr {
    uint32_t flag;
    uint8_t mp_nexthop_len;
    uint32_t label_index;
    struct encap_subtlvs *encap_subtlvs;
};

struct bgp_nlri {
    uint8_t safi;
};

struct aspath;
struct transit {
    int refcnt;
};

struct encap_subtlvs {
    int refcnt;
};

static const char *attr_str[] = {
    [1] = "ORIGIN",
    [2] = "AS_PATH",
    [3] = "AS4_PATH",
    [4] = "NEXT_HOP",
    [5] = "MULTI_EXIT_DISC",
    [6] = "LOCAL_PREF",
    [7] = "ATOMIC_AGGREGATE",
    [8] = "AGGREGATOR",
    [9] = "AS4_AGGREGATOR",
    [10] = "COMMUNITIES",
    [11] = "LARGE_COMMUNITIES",
    [12] = "ORIGINATOR_ID",
    [13] = "CLUSTER_LIST",
    [14] = "MP_REACH_NLRI",
    [15] = "MP_UNREACH_NLRI",
    [16] = "EXT_COMMUNITIES",
    [17] = "ENCAP",
    [18] = "PREFIX_SID",
    [19] = "PMSI_TUNNEL",
    [20] = "IPV6_EXT_COMMUNITIES",
    [21] = "OTC",
    [22] = "AIGP"
};

typedef uint32_t bgp_size_t;
typedef uint32_t as_t;

#define BGP_INPUT(peer) ((void *)0)
#define BGP_INPUT_PNT(peer) ((uint8_t *)0)
#define STREAM_READABLE(stream) 0
#define STREAM_DATA(stream) ((uint8_t *)0)
#define stream_pnt(stream) ((uint8_t *)0)
#define stream_getc(stream) 0
#define stream_getw(stream) 0
#define stream_get(buf, stream, len)
#define stream_rewind_getp(stream, len)
#define stream_set_getp(stream, pos)
#define stream_forward_getp(stream, len)
#define CHECK_FLAG(flags, bit) ((flags) & (bit))
#define CHECK_BITMAP(bitmap, bit) 0
#define SET_BITMAP(bitmap, bit)
#define ATTR_FLAG_BIT(attr) (1 << (attr))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define EC_BGP_ATTRIBUTE_TOO_SMALL 0
#define EC_BGP_EXT_ATTRIBUTE_TOO_SMALL 0
#define EC_BGP_ATTRIBUTE_TOO_LARGE 0
#define EC_BGP_ATTRIBUTE_PARSE_WITHDRAW 0
#define EC_BGP_ATTRIBUTE_REPEATED 0
#define EC_BGP_ATTRIBUTE_PARSE_ERROR 0
#define EC_BGP_ATTRIBUTE_FETCH_ERROR 0
#define EC_BGP_ATTRIBUTES_MISMATCH 0

#define BGP_NOTIFY_UPDATE_ERR 0
#define BGP_NOTIFY_UPDATE_ATTR_LENG_ERR 0
#define BGP_NOTIFY_UPDATE_MAL_ATTR 0
#define BGP_NOTIFY_UPDATE_ATTR_FLAG_ERR 0

void flog_warn(int code, const char *format, ...);
void bgp_notify_send(void *connection, int major, int minor);
void bgp_notify_send_with_data(void *connection, int major, int minor, void *data, size_t len);
const char *lookup_msg(const char * const *table, int code, const char *default_msg);

struct bgp_attr_parser_args {
    struct peer *peer;
    bgp_size_t length;
    struct attr *attr;
    uint8_t type;
    uint8_t flags;
    uint8_t *startp;
    size_t total;
};

int bgp_attr_flag_invalid(struct bgp_attr_parser_args *args);
enum bgp_attr_parse_ret bgp_attr_malformed(struct bgp_attr_parser_args *args, int subcode, size_t len);
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
int bgp_attr_check(struct peer *peer, struct attr *attr, bgp_size_t length);
int bgp_attr_munge_as4_attrs(struct peer *peer, struct attr *attr, struct aspath *as4_path, as_t as4_aggregator, struct in_addr *as4_aggregator_addr);
enum bgp_attr_parse_ret bgp_attr_aspath_check(struct peer *peer, struct attr *attr);
void aspath_unintern(struct aspath **path);
struct transit *bgp_attr_get_transit(struct attr *attr);
void bgp_attr_set_transit(struct attr *attr, struct transit *transit);
struct transit *transit_intern(struct transit *transit);
void transit_free(struct transit *transit);
struct encap_subtlvs *encap_intern(struct encap_subtlvs *subtlvs, int type);
void bgp_attr_flush_encap(struct attr *attr);