#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef uint16_t bgp_size_t;
typedef uint16_t iana_afi_t;
typedef uint8_t iana_safi_t;
typedef uint16_t afi_t;
typedef uint8_t safi_t;

#define BGP_ATTR_NHLEN_IPV4 4
#define BGP_ATTR_NHLEN_VPNV4 12
#define BGP_ATTR_NHLEN_IPV6_GLOBAL 16
#define BGP_ATTR_NHLEN_VPNV6_GLOBAL 24
#define BGP_ATTR_NHLEN_IPV6_GLOBAL_AND_LL 32
#define BGP_ATTR_NHLEN_VPNV6_GLOBAL_AND_LL 40

#define IPV4_MAX_BYTELEN 4
#define IPV6_MAX_BYTELEN 16

#define SAFI_FLOWSPEC 133

#define BGP_ATTR_PARSE_ERROR -1
#define BGP_ATTR_PARSE_ERROR_NOTIFYPLS -2
#define BGP_ATTR_PARSE_WITHDRAW -3
#define BGP_ATTR_PARSE_PROCEED 0
#define BGP_ATTR_PARSE_EOR 1

#define BGP_NOTIFY_UPDATE_MAL_ATTR 3

#define ATTR_FLAG_BIT(x) (1 << (x))
#define BGP_ATTR_MP_REACH_NLRI 14

#define EC_BGP_DEFUNCT_SNPA_LEN 0

struct stream {
    size_t getp;
    uint8_t *data;
};
#define stream_get_getp(s) ((s)->getp)
#define stream_getw(s) (ntohs(*(uint16_t *)((s)->data + (s)->getp)), (s)->getp += 2)
#define stream_getc(s) (*(uint8_t *)((s)->data + (s)->getp), (s)->getp += 1)
#define stream_getl(s) (ntohl(*(uint32_t *)((s)->data + (s)->getp)), (s)->getp += 4)
#define stream_get(p, s, len) (memcpy((p), (s)->data + (s)->getp, (len)), (s)->getp += (len))
#define stream_pnt(s) ((s)->data + (s)->getp)
#define stream_forward_getp(s, len) ((s)->getp += (len))
#define STREAM_READABLE(s) (0)

struct peer {
    char *host;
    struct {
        struct {
            int ifindex;
        } *ifp;
    } nexthop;
};

struct attr {
    uint8_t mp_nexthop_len;
    struct in_addr mp_nexthop_global_in;
    struct in6_addr mp_nexthop_global;
    struct in6_addr mp_nexthop_local;
    struct in_addr nexthop;
    int nh_ifindex;
    int nh_lla_ifindex;
    uint8_t flag;
};

struct bgp_attr_parser_args {
    struct peer *peer;
    struct attr *attr;
    bgp_size_t length;
};

struct bgp_nlri {
    afi_t afi;
    safi_t safi;
    uint8_t *nlri;
    bgp_size_t length;
};

#define BGP_INPUT(peer) ((struct stream *)NULL)

#define fallthrough

int bgp_map_afi_safi_iana2int(iana_afi_t pkt_afi, iana_safi_t pkt_safi, afi_t *afi, safi_t *safi);
const char *iana_afi2str(iana_afi_t afi);
const char *iana_safi2str(iana_safi_t safi);
int bgp_debug_update(struct peer *peer, void *a, void *b, int c);
int bgp_attr_malformed(struct bgp_attr_parser_args *args, int code, int subcode);
void zlog_info(const char *format, ...);
void zlog_debug(const char *format, ...);
void zlog_warn(const char *format, ...);
void flog_warn(int ec, const char *format, ...);