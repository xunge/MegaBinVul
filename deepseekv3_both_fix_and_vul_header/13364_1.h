#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_ERROR
};

#define BGP_PREFIX_SID_LABEL_INDEX 1
#define BGP_PREFIX_SID_IPV6 2
#define BGP_PREFIX_SID_ORIGINATOR_SRGB 3
#define BGP_PREFIX_SID_VPN_SID 4
#define BGP_PREFIX_SID_SRV6_L3_SERVICE 5

#define BGP_PREFIX_SID_LABEL_INDEX_LENGTH 8
#define BGP_PREFIX_SID_IPV6_LENGTH 20
#define BGP_PREFIX_SID_ORIGINATOR_SRGB_LENGTH 6
#define BGP_PREFIX_SID_VPN_SID_LENGTH 20

#define BGP_INVALID_LABEL_INDEX 0xFFFFFFFF
#define BGP_NOTIFY_UPDATE_ATTR_LENG_ERR 1
#define BGP_NOTIFY_UPDATE_OPT_ATTR_ERR 2
#define BGP_NOTIFY_UPDATE_MAL_ATTR 3

#define EC_BGP_ATTR_LEN 1
#define EC_BGP_ATTRIBUTE_REPEATED 2

#define STREAM_READABLE(stream) 0
#define stream_getc(stream) 0
#define stream_getw(stream) 0
#define stream_getl(stream) 0
#define stream_get(ptr, stream, len) 
#define stream_forward_getp(stream, len)

#define flog_err(code, fmt, ...)
#define zlog_debug(fmt, ...)
#define BGP_DEBUG(type, level) 0
#define bgp_debug_update(peer, p1, p2, level) 0

struct peer {
    void *curr;
    const char *host;
};

struct attr {
    uint32_t label_index;
    struct bgp_attr_srv6_vpn *srv6_vpn;
};

struct bgp_attr_parser_args {
    struct peer *peer;
    struct attr *attr;
    uint32_t total;
};

struct bgp_attr_srv6_vpn {
    uint8_t sid_flags;
    struct in6_addr sid;
};

#define XCALLOC(type, size) malloc(size)
#define MTYPE_BGP_SRV6_VPN 1

static struct bgp_attr_srv6_vpn *srv6_vpn_intern(struct bgp_attr_srv6_vpn *vpn) { return vpn; }
static void sid_copy(struct in6_addr *dst, struct in6_addr *src) { *dst = *src; }
static enum bgp_attr_parse_ret bgp_attr_malformed(struct bgp_attr_parser_args *args, int code, uint32_t total) { return BGP_ATTR_PARSE_ERROR; }
static enum bgp_attr_parse_ret bgp_attr_srv6_service(struct bgp_attr_parser_args *args) { return BGP_ATTR_PARSE_PROCEED; }