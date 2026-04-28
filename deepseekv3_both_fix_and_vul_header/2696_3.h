#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    const u_char *ndo_snapend;
} netdissect_options;

struct pkt_prep {
    uint32_t pp_n;
};

struct pgstate {
    uint32_t slot;
    struct {
        uint32_t p_sid;
        uint32_t p_uid;
    } page;
    uint32_t nid;
};

struct id_off {
    uint32_t id;
    uint32_t off;
};

#define ND_TTEST(ptr) (1)
#define ND_PRINT(args) 
#define EXTRACT_32BITS(p) (*(const uint32_t *)(p))

const char *ipaddr_string(netdissect_options *ndo, const uint32_t *addr);