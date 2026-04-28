#include <stdint.h>
#include <netinet/in.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

#define ND_TCHECK(p)
#define ND_TCHECK2(p, l)
#define ND_PRINT(args)

#define DAGID_LEN 16
#define ND_RPL_DAO_MIN_LEN 4

#define RPL_DAO_D(flags) ((flags) & 0x80)
#define RPL_DAO_K(flags) ((flags) & 0x40)

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct nd_rpl_dao {
    uint8_t rpl_instanceid;
    uint8_t rpl_flags;
    uint8_t rpl_daoseq;
    uint8_t rpl_dagid[DAGID_LEN];
};

struct rpl_dio_genoption {
    uint8_t opt_type;
    uint8_t opt_len;
};

const char *ip6addr_string(netdissect_options *ndo, const uint8_t *addr);
void rpl_dio_printopt(netdissect_options *ndo, const struct rpl_dio_genoption *opt, u_int length);