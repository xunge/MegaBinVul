#include <netinet/in.h>
#include <netinet/icmp6.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_PRINT(args)
#define ND_TCHECK(expr) 
#define ND_TCHECK2(expr, len)
#define EXTRACT_16BITS(p) ((u_int16_t)ntohs(*(const u_int16_t *)(p)))

const char *ip6addr_string(struct netdissect_options *ndo, const u_char *addr);