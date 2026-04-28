#include <stddef.h>
#include <stdint.h>

typedef unsigned char u_char;

struct attrmap {
    const char *type;
    const char **value;
    size_t nvalue;
};

typedef struct netdissect_options netdissect_options;

#define ND_TCHECK(p)
#define ND_TCHECK_16BITS(p)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ((uint16_t)0)

int rawprint(netdissect_options *, const uint8_t *, size_t);