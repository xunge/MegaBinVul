#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>

typedef unsigned int u_int;
typedef unsigned char u_char;

struct isakmp_gen {
    u_char np;
    u_char reserved;
    uint16_t len;
    u_char critical;
};

typedef struct netdissect_options netdissect_options;

#define _U_
#define ND_TCHECK(a)
#define ND_TCHECK2(a, b) 
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define ISAKMP_NPTYPE_P 0
#define NPSTR(np) ""

static const u_char *ikev2_p_print(netdissect_options *, u_char, int, const struct isakmp_gen *, u_int, const u_char *, int);
static void ikev2_pay_print(netdissect_options *, const char *, u_char);