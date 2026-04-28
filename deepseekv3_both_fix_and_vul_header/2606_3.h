#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint8_t np;
    uint8_t critical;
    uint16_t len;
};

struct ikev2_id {
    struct isakmp_gen h;
    uint8_t type;
};

#define ID_IPV4_ADDR     1
#define ID_FQDN          2
#define ID_RFC822_ADDR   3
#define ID_IPV6_ADDR     5
#define ID_DER_ASN1_DN   9
#define ID_DER_ASN1_GN   10
#define ID_KEY_ID        11

#define _U_ 
#define ND_TCHECK(a)
#define ND_TCHECK2(a, b)
#define ND_PRINT(a) printf a
#define ND_ISPRINT(c) isprint((unsigned char)(c))
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define NPSTR(tpay) ""

int rawprint(netdissect_options *ndo, const uint8_t *data, int len);
void ikev2_pay_print(netdissect_options *ndo, const char *str, uint8_t critical);