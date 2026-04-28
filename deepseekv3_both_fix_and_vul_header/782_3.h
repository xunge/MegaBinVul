#include <stdint.h>
#include <netinet/in.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

typedef unsigned char u_char;
typedef unsigned int u_int;

struct nd_rpl_daoack {
    uint8_t rpl_flags;
    uint8_t rpl_daoseq;
    uint8_t rpl_instanceid;
    uint8_t rpl_status;
    uint8_t rpl_dagid[16];
};

struct rpl_dio_genoption {
    uint8_t opt_type;
    uint8_t opt_len;
};

#define ND_TCHECK2(p, l)
#define ND_PRINT(args)
#define DAGID_LEN 16
#define ND_RPL_DAOACK_MIN_LEN 4
#define RPL_DAOACK_D(flags) ((flags) & 0x80)

const char *ip6addr_string(netdissect_options *ndo, const uint8_t *addr);
void rpl_dio_printopt(netdissect_options *ndo, const struct rpl_dio_genoption *opt, u_int length);