#include <stdint.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint8_t data[1]; 
};

struct ikev1_pl_cert {
    uint32_t encode;
};

#define _U_
#define ND_TCHECK(x)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define NPSTR(x) ""
#define STR_OR_ID(id, str) ((id) < sizeof(str)/sizeof(str[0]) ? str[id] : "?")
#define ISAKMP_NPTYPE_CERT 0

static int rawprint(netdissect_options *ndo, const uint8_t *data, u_int len) {
    return 0;
}