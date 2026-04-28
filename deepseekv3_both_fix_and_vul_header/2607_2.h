#include <stdint.h>
#include <string.h>
#include <netinet/in.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint8_t critical;
    uint8_t reserved;
    uint16_t len;
    uint8_t h[4];
};

struct ikev2_auth {
    struct isakmp_gen h;
    uint8_t auth_method;
    uint8_t reserved[3];
};

#define _U_
#define ND_TCHECK(x)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define NPSTR(x) ""
#define STR_OR_ID(id, str) ((id) < sizeof(str)/sizeof(str[0]) ? str[id] : "?")

int rawprint(netdissect_options *ndo, const uint8_t *data, u_int len);
int ike_show_somedata(netdissect_options *ndo, const u_char *data, const u_char *ep);
void ikev2_pay_print(netdissect_options *ndo, const char *pstr, uint8_t critical);