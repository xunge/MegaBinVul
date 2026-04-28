#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

#define ND_TCHECK2(p, l)
#define BGP_VPN_RD_LEN 8
#define BGP_MULTICAST_VPN_ROUTE_TYPE_INTRA_AS_I_PMSI 1
#define BGP_MULTICAST_VPN_ROUTE_TYPE_INTER_AS_I_PMSI 2
#define BGP_MULTICAST_VPN_ROUTE_TYPE_S_PMSI 3
#define BGP_MULTICAST_VPN_ROUTE_TYPE_SOURCE_ACTIVE 4
#define BGP_MULTICAST_VPN_ROUTE_TYPE_SHARED_TREE_JOIN 5
#define BGP_MULTICAST_VPN_ROUTE_TYPE_SOURCE_TREE_JOIN 6
#define BGP_MULTICAST_VPN_ROUTE_TYPE_INTRA_AS_SEG_LEAF 7
#define EXTRACT_32BITS(p) (*((uint32_t *)(p)))

typedef struct netdissect_options netdissect_options;

extern const char *bgp_multicast_vpn_route_type_values[];
extern const char *tok2str(const char *[], const char *, unsigned int);
extern const char *bgp_vpn_rd_print(netdissect_options *, const u_char *);
extern const char *bgp_vpn_ip_print(netdissect_options *, const u_char *, u_int);
extern u_int bgp_vpn_sg_print(netdissect_options *, const u_char *, char *, u_int);
extern const char *as_printf(netdissect_options *, char *, size_t, uint32_t);

static char astostr[32];