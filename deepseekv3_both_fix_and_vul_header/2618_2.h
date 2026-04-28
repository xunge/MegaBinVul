#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef unsigned char u_char;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint8_t critical;
    uint8_t reserved;
    uint16_t len;
};

#define ND_TCHECK(x)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define NPSTR(x) ""

int ikev2_pay_print(netdissect_options *, const char *, uint8_t);
int rawprint(netdissect_options *, const uint8_t *, int);