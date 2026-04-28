#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint16_t len;
    uint8_t critical;
};

struct ikev2_ke {
    struct isakmp_gen h;
    uint16_t ke_group;
};

#define _U_
#define ND_TCHECK(x)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define NPSTR(x) ""
#define STR_OR_ID(id, map) ""
#define dh_p_map NULL

static int rawprint(netdissect_options *ndo, const uint8_t *data, u_int len);
static void ikev2_pay_print(netdissect_options *ndo, const char *str, uint8_t critical);