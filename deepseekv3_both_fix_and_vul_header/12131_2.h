#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <assert.h>

typedef uint16_t bgp_size_t;
typedef uint32_t as_t;

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_ERROR,
    BGP_ATTR_PARSE_WITHDRAW,
    BGP_ATTR_PARSE_ERROR_NOTIFYPLS
};

#define BGP_ATTR_BITMAP_SIZE 32
#define BGP_ATTR_MIN_LEN 3
#define BGP_ATTR_FLAG_EXTLEN (1 << 4)
#define CHECK_FLAG(flag, bit) ((flag) & (bit))
#define CHECK_BITMAP(bitmap, type) ((bitmap)[(type)/8] & (1 << ((type)%8)))
#define SET_BITMAP(bitmap, type) ((bitmap)[(type)/8] |= (1 << ((type)%8)))
#define ATTR_FLAG_BIT(type) (1 << (type))
#define BGP_INVALID_LABEL_INDEX 0xFFFFFFFF
#define BGP_PEER_EBGP 1
#define SAFI_LABELED_UNICAST 4
#define ENCAP_SUBTLV_TYPE 1

#define BGP_ATTR_ORIGIN 1
#define BGP_ATTR_AS_PATH 2
#define BGP_ATTR_NEXT_HOP 3
#define BGP_ATTR_MULTI_EXIT_DISC 4
#define BGP_ATTR_LOCAL_PREF 5
#define BGP_ATTR_ATOMIC_AGGREGATE 6
#define BGP_ATTR_AGGREGATOR 7
#define BGP_ATTR_COMMUNITIES 8
#define BGP_ATTR_ORIGINATOR_ID 9
#define BGP_ATTR_CLUSTER_LIST 10
#define BGP_ATTR_MP_REACH_NLRI 14
#define BGP_ATTR_MP_UNREACH_NLRI 15
#define BGP_ATTR_EXT_COMMUNITIES 16
#define BGP_ATTR_AS4_PATH 17
#define BGP_ATTR_AS4_AGGREGATOR 18
#define BGP_ATTR_ENCAP 23
#define BGP_ATTR_PREFIX_SID 40
#define BGP_ATTR_PMSI_TUNNEL 22
#define BGP_ATTR_IPV6_EXT_COMMUNITIES 25
#define BGP_ATTR_OTC 35
#define BGP_ATTR_AIGP 26
#define BGP_ATTR_LARGE_COMMUNITIES 32

#define BGP_NOTIFY_UPDATE_ERR 3
#define BGP_NOTIFY_UPDATE_ATTR_LENG_ERR 4
#define BGP_NOTIFY_UPDATE_MAL_ATTR 5
#define BGP_NOTIFY_UPDATE_ATTR_FLAG_ERR 6

#define EC_BGP_ATTRIBUTE_TOO_SMALL 1
#define EC_BGP_EXT_ATTRIBUTE_TOO_SMALL 2
#define EC_BGP_ATTRIBUTE_TOO_LARGE 3
#define EC_BGP_ATTRIBUTE_PARSE_WITHDRAW 4
#define EC_BGP_ATTRIBUTE_REPEATED 5
#define EC_BGP_ATTRIBUTE_PARSE_ERROR 6
#define EC_BGP_ATTRIBUTE_FETCH_ERROR 7
#define EC_BGP_ATTRIBUTES_MISMATCH 8

struct peer {
    char *host;
    int sort;
    void *connection;
    size_t max_packet_size;
    struct stream *input;
    uint8_t *input_pnt;
};

struct attr {
    uint32_t flag;
    uint8_t mp_nexthop_len;
    uint32_t label_index;
    struct encap_subtlv *encap_subtlvs;
    struct aspath *aspath;
    struct aggregator *aggregator;
};

struct bgp_nlri {
    uint8_t safi;
};

struct aspath {
    // implementation details
};

struct transit {
    int refcnt;
    // other fields
};

struct encap_subtlv {
    int refcnt;
    // other fields
};

struct aggregator {
    // implementation details
};

struct stream {
    uint8_t *endp;
    uint8_t *getp;
    uint8_t *data;
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

#define BGP_INPUT_PNT(peer) (peer->input_pnt)
#define BGP_INPUT(peer) (peer->input)
#define STREAM_READABLE(stream) (stream->endp - stream->getp)
#define STREAM_DATA(stream) (stream->data)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static const char *attr_str[] = {
    [1] = "ORIGIN",
    [2] = "AS_PATH",
    [3] = "NEXT_HOP",
    [4] = "MULTI_EXIT_DISC",
    [5] = "LOCAL_PREF",
    [6] = "ATOMIC_AGGREGATE",
    [7] = "AGGREGATOR",
    [8] = "COMMUNITIES",
    [9] = "ORIGINATOR_ID",
    [10] = "CLUSTER_LIST",
    [14] = "MP_REACH_NLRI",
    [15] = "MP_UNREACH_NLRI",
    [16] = "EXT_COMMUNITIES",
    [17] = "AS4_PATH",
    [18] = "AS4_AGGREGATOR",
    [23] = "ENCAP",
    [40] = "PREFIX_SID",
    [22] = "PMSI_TUNNEL",
    [25] = "IPV6_EXT_COMMUNITIES",
    [35] = "OTC",
    [26] = "AIGP",
    [32] = "LARGE_COMMUNITIES"
};