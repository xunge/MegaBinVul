#include <stdint.h>

typedef uint8_t u_char;
typedef unsigned int u_int;

#define IPOPT_TS_TSONLY 0
#define IPOPT_TS_TSANDADDR 1
#define IPOPT_TS_PRESPEC 3

#define ND_PRINT(args)
#define EXTRACT_32BITS(p) (*(const uint32_t *)(p))

typedef struct netdissect_options {
    /* dummy structure */
} netdissect_options;

const char *ipaddr_string(netdissect_options *ndo, const u_char *cp);