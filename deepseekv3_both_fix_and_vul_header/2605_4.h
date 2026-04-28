#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef unsigned int u_int;
typedef unsigned char u_char;

typedef struct netdissect_options {
    int dummy;
} netdissect_options;

struct isakmp_gen {
    u_char np;
    uint16_t len;
    u_char critical;
};

struct ikev2_p {
    struct isakmp_gen h;
    u_char p_no;
    u_char prot_id;
    u_char spi_size;
    u_char num_t;
};

#define ND_TCHECK(expr)
#define ND_TCHECK2(expr, len)
#define ND_PRINT(args)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define NPSTR(x) ""
#define PROTOIDSTR(x) ""
#define ISAKMP_NPTYPE_P 0
#define ISAKMP_NPTYPE_T 0
#define _U_

static int rawprint(netdissect_options *ndo, const uint8_t *data, size_t len) { return 1; }
static const u_char *ikev2_pay_print(netdissect_options *ndo, const char *str, int crit) { return NULL; }
static const u_char *ikev2_t_print(netdissect_options *ndo, int tcount, const struct isakmp_gen *ext, u_int len, const u_char *ep) { return NULL; }