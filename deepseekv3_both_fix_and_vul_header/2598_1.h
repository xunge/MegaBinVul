#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>

typedef struct netdissect_options netdissect_options;
typedef unsigned char u_char;
typedef unsigned int u_int;

#define ND_TCHECK(a)
#define ND_TCHECK2(a, b)
#define EXTRACT_32BITS(p) (*(uint32_t*)(p))
char astostr[64];

static const char *as_printf(netdissect_options *ndo, char *buf, size_t buflen, uint32_t as);
static const char *bgp_vpn_rd_print(netdissect_options *ndo, const u_char *rd);