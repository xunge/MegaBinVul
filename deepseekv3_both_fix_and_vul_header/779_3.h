#include <stddef.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/icmp6.h>

typedef struct netdissect_options {
    const u_char *ndo_snapend;
    int ndo_vflag;
} netdissect_options;

struct nd_opt_route_info {
    uint8_t  nd_opt_rti_type;
    uint8_t  nd_opt_rti_len;
    uint8_t  nd_opt_rti_prefixlen;
    uint8_t  nd_opt_rti_flags;
    uint32_t nd_opt_rti_lifetime;
};

#define ND_OPT_SOURCE_LINKADDR    1
#define ND_OPT_TARGET_LINKADDR    2
#define ND_OPT_PREFIX_INFORMATION 3
#define ND_OPT_REDIRECTED_HEADER  4
#define ND_OPT_MTU                5
#define ND_OPT_RDNSS              25
#define ND_OPT_DNSSL              31
#define ND_OPT_ADVINTERVAL        7
#define ND_OPT_HOMEAGENT_INFO     8
#define ND_OPT_ROUTE_INFO         24

#define ND_TCHECK(p) 
#define ND_TCHECK2(p, l)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) 
#define EXTRACT_32BITS(p) 

static const char *tok2str(const char *strings, const char *default_str, int val);
static const char *bittok2str(const char *strings, const char *default_str, int val);
static const char *get_lifetime(uint32_t val);
static const char *get_rtpref(uint8_t val);
static const char *ip6addr_string(netdissect_options *ndo, const struct in6_addr *addr);
static void print_lladdr(netdissect_options *ndo, const u_char *cp, size_t len);
static void print_unknown_data(netdissect_options *ndo, const u_char *cp, const char *prefix, size_t len);
static const char *ns_nprint(netdissect_options *ndo, const u_char *cp, const u_char *bp);