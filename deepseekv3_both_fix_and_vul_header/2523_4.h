#include <stddef.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;
typedef uint32_t uint32_t;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint8_t np;
    uint8_t reserved;
    uint16_t len;
};

struct ikev1_pl_n {
    uint32_t doi;
    uint8_t prot_id;
    uint8_t spi_size;
    uint16_t type;
};

struct attrmap {
    uint16_t type;
    const char *name;
};

const struct attrmap oakley_t_map[] = {
    {0, NULL}
};

#define _U_
#define ND_PRINT(x)
#define ND_TCHECK(x)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define NPSTR(x) ""
#define STR_OR_ID(x, str) ""
#define numstr(x) ""
#define rawprint(ndo, data, len) 0
#define PROTOIDSTR(x) ""
#define EXTRACT_32BITS(p) 0
#define ike_show_somedata(ndo, cp, ep) 0
#define ikev1_attrmap_print(ndo, cp, ep, map, nmap) NULL
#define ikev1_sub_print(ndo, type, gen, ep, phase, doi, proto, depth) NULL
#define isakmp_print(ndo, cp, len, dummy) NULL

#define ISAKMP_NPTYPE_N 0
#define IPSECDOI_NTYPE_RESPONDER_LIFETIME 1
#define IPSECDOI_NTYPE_REPLAY_STATUS 2
#define ISAKMP_NTYPE_NO_PROPOSAL_CHOSEN 3
#define ISAKMP_NPTYPE_SA 4