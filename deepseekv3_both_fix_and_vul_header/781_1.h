#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct nd_rpl_dio {
    u_char rpl_dagid[16];
    u_int8_t rpl_dtsn;
    u_int8_t rpl_instanceid;
    u_int16_t rpl_dagrank;
    u_int8_t rpl_mopprf;
};

struct rpl_dio_genoption;

extern const char *ip6addr_string(struct netdissect_options *, const u_char *);
extern void rpl_dio_printopt(struct netdissect_options *, const struct rpl_dio_genoption *, u_int);
extern const char *tok2str(const char *, const char *, int);
extern const char *rpl_tstr;
extern const char *rpl_mop_values[];

#define ND_TCHECK(p) 
#define ND_PRINT(args) 
#define EXTRACT_16BITS(p) ntohs(*(const u_int16_t *)(p))
#define RPL_DIO_GROUNDED(x) ((x) & 0x80)
#define RPL_DIO_MOP(x) (((x) >> 3) & 0x07)
#define RPL_DIO_PRF(x) ((x) & 0x07)