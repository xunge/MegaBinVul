#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

typedef struct netdissect_options netdissect_options;
typedef unsigned char u_char;
typedef unsigned int u_int;

static const char hex[] = "0123456789abcdef";

struct netdissect_options {
    void (*ndo_error)(netdissect_options *, const char *);
};

struct bsnamemem {
    char *bs_name;
};

struct enamemem {
    char *e_name;
};

struct bsnamemem *lookup_bytestring(netdissect_options *, const u_char *, unsigned int);