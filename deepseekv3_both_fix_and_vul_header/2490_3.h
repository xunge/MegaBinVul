#include <stdlib.h>

typedef struct netdissect_options {
    void (*ndo_error)(struct netdissect_options *, const char *);
} netdissect_options;

struct bsnamemem {
    char *bs_name;
};

struct enamemem {
    char *e_name;
};

typedef union {
    struct bsnamemem bs;
    struct enamemem en;
} bytestring_mem;

#define LINKADDR_ETHER 1
#define LINKADDR_FRELAY 2
#define ETHER_ADDR_LEN 6

extern const char hex[];
extern const char *etheraddr_string(netdissect_options *, const u_char *);
extern const char *q922_string(netdissect_options *, const u_char *, unsigned int);
extern bytestring_mem *lookup_bytestring(netdissect_options *, const u_char *, unsigned int);