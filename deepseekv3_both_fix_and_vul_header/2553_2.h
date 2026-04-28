#include <stdint.h>
#include <netinet/in.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options netdissect_options;
typedef struct pkt_prep pkt_prep;
typedef struct pgstate pgstate;
typedef struct id_off id_off;

struct netdissect_options {
    const u_char *ndo_snapend;
};

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

#define ND_PRINT(args)
#define ND_TTEST(ptr) (1)
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))
const char *ipaddr_string(netdissect_options *ndo, const uint32_t *addr);