#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BGP_ADDPATH_ID_LEN 4
#define MPLS_INVALID_LABEL 0xFFFFFFFF
#define IPV4_MAX_BITLEN 32
#define IPV6_MAX_BITLEN 128
#define PSIZE(prefixlen) (((prefixlen) + 7) / 8)
#define BSIZE(len) ((len) * 8)

typedef uint16_t afi_t;
typedef uint8_t safi_t;
typedef uint32_t mpls_label_t;

struct peer {
    const char *host;
};

struct attr {
};

struct bgp_nlri {
    uint8_t *nlri;
    uint32_t length;
    afi_t afi;
    safi_t safi;
};

struct prefix {
    uint16_t family;
    uint8_t prefixlen;
    union {
        struct in_addr prefix4;
        struct in6_addr prefix6;
        uint8_t prefix;
    } u;
};

enum {
    AFI_IP = 1,
    AFI_IP6 = 2,
    SAFI_UNICAST = 1,
    SAFI_LABELED_UNICAST = 4
};

enum bgp_nlri_parse_error {
    BGP_NLRI_PARSE_OK,
    BGP_NLRI_PARSE_ERROR_PACKET_OVERFLOW,
    BGP_NLRI_PARSE_ERROR_LABEL_LENGTH,
    BGP_NLRI_PARSE_ERROR_PREFIX_LENGTH,
    BGP_NLRI_PARSE_ERROR_PACKET_LENGTH
};

enum bgp_notify_update_err {
    BGP_NOTIFY_UPDATE_ERR,
    BGP_NOTIFY_UPDATE_INVAL_NETWORK
};

enum zebra_route_type {
    ZEBRA_ROUTE_BGP
};

enum bgp_route_status {
    BGP_ROUTE_NORMAL
};

enum log_errors {
    EC_BGP_UPDATE_RCV
};

uint16_t afi2family(afi_t afi);
bool bgp_addpath_encode_rx(struct peer *peer, afi_t afi, safi_t safi);
uint8_t bgp_nlri_get_labels(struct peer *peer, uint8_t *pnt, int psize, mpls_label_t *label);
void bgp_update(struct peer *peer, struct prefix *p, uint32_t addpath_id, struct attr *attr, afi_t afi, safi_t safi, enum zebra_route_type type, enum bgp_route_status status, void *arg, mpls_label_t *label, int label_count, int withdraw, void *tag);
void bgp_withdraw(struct peer *peer, struct prefix *p, uint32_t addpath_id, afi_t afi, safi_t safi, enum zebra_route_type type, enum bgp_route_status status, void *arg, mpls_label_t *label, int label_count, void *tag);
void bgp_notify_send(struct peer *peer, enum bgp_notify_update_err err, enum bgp_notify_update_err subcode);
void flog_err(enum log_errors error, const char *format, ...);