#include <netinet/in.h>
#include <netinet/icmp6.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct in6_addr;

#define ND_PRINT(args)
#define ND_TCHECK(expr) 
#define ND_TCHECK2(ptr, len)
#define EXTRACT_16BITS(p) ((u_int16_t)ntohs(*(const u_int16_t *)(p)))

static const char *ip6addr_string(netdissect_options *ndo, const u_char *addr) { return ""; }
static const char *tok2str(const char **strings, const char *fmt, int val) { return ""; }

static const char *mldv2report2str[] = { NULL };