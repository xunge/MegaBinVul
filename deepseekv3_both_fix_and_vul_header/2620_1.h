#include <netinet/in.h>
#include <netinet/ip6.h>

typedef struct netdissect_options {
    const u_char *ndo_snapend;
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK(p)
#define ND_PRINT(args)
#define EXTRACT_32BITS(p) (*(uint32_t*)(p))
#define IPV6_RTHDR_TYPE_0 0
#define IPV6_RTHDR_TYPE_2 2
#define _U_

const char *ip6addr_string(netdissect_options *ndo, const struct in6_addr *addr);