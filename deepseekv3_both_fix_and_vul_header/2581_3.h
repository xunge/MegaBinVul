#include <stdint.h>
#include <stdio.h>

typedef unsigned char u_char;

typedef struct netdissect_options netdissect_options;

#define ND_TCHECK(p)
#define ND_TCHECK_16BITS(p)
#define EXTRACT_16BITS(p) ((p)[0] << 8 | (p)[1])
#define ND_PRINT(args) printf args

int rawprint(netdissect_options *ndo, const uint8_t *data, int len);