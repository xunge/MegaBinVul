#include <stdint.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

struct isakmp_gen {
    uint32_t critical;
    uint16_t len;
};

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK(a)
#define ND_TCHECK2(a, b)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define ND_ISPRINT(c) isprint(c)
#define NPSTR(tpay) ""

#define _U_ __attribute__((unused))

static int rawprint(netdissect_options *ndo, const uint8_t *data, int len) { return 1; }
static void ikev2_pay_print(netdissect_options *ndo, const char *str, uint32_t critical) {}