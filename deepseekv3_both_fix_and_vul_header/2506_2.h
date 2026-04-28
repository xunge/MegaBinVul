#include <sys/types.h>
#include <stdint.h>
#include <netinet/in.h>

#define CHDLC_HDRLEN 4
#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_IPV6 0x86DD
#define CHDLC_TYPE_SLARP 0x8035
#define ETHERTYPE_MPLS 0x8847
#define ETHERTYPE_MPLS_MULTI 0x8848
#define ETHERTYPE_ISO 0x8000

typedef unsigned int u_int;
typedef unsigned char u_char;

struct tok {
    int v;
    const char *s;
};

typedef struct netdissect_options {
    int ndo_eflag;
    const u_char *ndo_snapend;
} netdissect_options;

extern const struct tok chdlc_cast_values[];
extern const struct tok ethertype_values[];

#define ND_TCHECK2(p, l)
#define ND_TCHECK_16BITS(p)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ((u_int16_t)ntohs(*(const u_int16_t *)(p)))