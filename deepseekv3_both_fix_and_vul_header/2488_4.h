#include <stdlib.h>
#include <string.h>

#define HASHNAMESIZE 256

typedef struct netdissect_options {
    void (*ndo_error)(struct netdissect_options *, const char *);
} netdissect_options;

struct bsnamemem {
    struct bsnamemem *bs_nxt;
    u_int bs_addr0;
    u_int bs_addr1;
    u_int bs_addr2;
    u_char *bs_bytes;
    unsigned int bs_nbytes;
};

struct enamemem {
    struct enamemem *e_nxt;
    u_int e_addr0;
    u_int e_addr1;
    u_int e_addr2;
    u_char *e_bs;
};

extern struct bsnamemem bytestringtable[HASHNAMESIZE];