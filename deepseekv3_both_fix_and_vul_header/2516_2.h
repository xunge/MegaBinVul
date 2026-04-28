#include <stddef.h>

typedef struct netdissect_options netdissect_options;

struct netdissect_options {
    const unsigned char *ndo_snapend;
};