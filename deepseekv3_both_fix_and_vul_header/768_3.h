#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint8_t type;
    uint8_t reserved;
    uint16_t length;
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
#define ND_TCHECK(x)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define NPSTR(x) ""
#define STR_OR_ID(x, y) ((x) < sizeof(y)/sizeof(y[0]) && y[x] ? y[x] : "?")
#define PROTOIDSTR(x) ""
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))
#define IPSECDOI_NTYPE_RESPONDER_LIFETIME 24576
#define IPSECDOI_NTYPE_REPLAY_STATUS 24577
#define ISAKMP_NPTYPE_N 0

extern int rawprint(netdissect_options *, const uint8_t *, u_int);
extern const u_char *ikev1_attrmap_print(netdissect_options *, const u_char *, const u_char *, const struct attrmap *, size_t);
extern int ike_show_somedata(netdissect_options *, const u_char *, const u_char *);
extern const char *numstr(u_int);