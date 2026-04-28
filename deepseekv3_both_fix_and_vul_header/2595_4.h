#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

typedef struct netdissect_options netdissect_options;

struct rx_header {
    uint32_t size;
};

struct tok {
    int v;
    const char *s;
};

extern const struct tok ubik_req[];
extern const struct tok ubik_lock_types[];
const char *tok2str(const struct tok *, const char *, int);

#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))
#define ND_TCHECK2(p, l)
#define ND_PRINT(args) 
#define INTOUT()
#define UINTOUT()
#define DATEOUT() 
#define UBIK_VERSIONOUT()