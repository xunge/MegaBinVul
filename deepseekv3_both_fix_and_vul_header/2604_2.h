#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_nflag;
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint8_t data[1];
};

struct ikev1_pl_id {
    struct {
        uint32_t id_type;
        uint32_t doi_data;
    } d;
};

struct ipsecdoi_id {
    uint8_t type;
    uint8_t proto_id;
    uint16_t port;
};

#define _U_
#define ND_TCHECK(x)
#define ND_TCHECK2(x, y)
#define ND_PRINT(x) printf x
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define NPSTR(x) ""
#define STR_OR_ID(id, str) (id < sizeof(str)/sizeof(str[0]) ? (str[id] ? str[id] : "?") : "?")
#define ISAKMP_NPTYPE_ID 0

#define IPSECDOI_ID_IPV4_ADDR 1
#define IPSECDOI_ID_FQDN 2
#define IPSECDOI_ID_USER_FQDN 3
#define IPSECDOI_ID_IPV4_ADDR_SUBNET 4
#define IPSECDOI_ID_IPV6_ADDR 5
#define IPSECDOI_ID_IPV6_ADDR_SUBNET 6
#define IPSECDOI_ID_IPV4_ADDR_RANGE 7
#define IPSECDOI_ID_IPV6_ADDR_RANGE 8
#define IPSECDOI_ID_DER_ASN1_DN 9
#define IPSECDOI_ID_DER_ASN1_GN 10
#define IPSECDOI_ID_KEY_ID 11

const char *ipaddr_string(netdissect_options *, const u_char *);
const char *ip6addr_string(netdissect_options *, const u_char *);
const char *netdb_protoname(int);
int rawprint(netdissect_options *, const uint8_t *, int);
void safeputchar(netdissect_options *, u_char);