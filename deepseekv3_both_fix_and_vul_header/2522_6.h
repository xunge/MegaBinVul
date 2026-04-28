#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

struct netdissect_options {
    int ndo_vflag;
};

struct isakmp_gen {
    uint8_t critical;
    uint16_t len;
};

struct ikev2_auth {
    struct isakmp_gen h;
    uint8_t auth_method;
};

#define ND_TCHECK(p)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define STR_OR_ID(id, strarray) ((id) < sizeof(strarray)/sizeof(strarray[0]) ? strarray[id] : "?")
#define NPSTR(p) ""
#define _U_

int rawprint(struct netdissect_options *, const uint8_t *, unsigned int);
int ike_show_somedata(struct netdissect_options *, const u_char *, const u_char *);
void ikev2_pay_print(struct netdissect_options *, const char *, uint8_t);

typedef struct netdissect_options netdissect_options;