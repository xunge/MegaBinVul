#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

#define CHDLC_HDRLEN 4
#define CHDLC_TYPE_SLARP 0x8035
#define CHDLC_TYPE_CDP 0x2000
#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_IPV6 0x86DD
#define ETHERTYPE_MPLS 0x8847
#define ETHERTYPE_MPLS_MULTI 0x8848
#define ETHERTYPE_ISO 0x8000

typedef struct netdissect_options {
    int ndo_eflag;
    const uint8_t *ndo_snapend;
} netdissect_options;

#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))
#define ND_PRINT(args) printf args

typedef unsigned int u_int;
typedef uint8_t u_char;

struct tok {
    const char *s;
    unsigned int v;
};

extern const struct tok chdlc_cast_values[];
extern const struct tok ethertype_values[];
extern const char *tok2str(const struct tok *, const char *, unsigned int);

extern void ip_print(netdissect_options *, const u_char *, u_int);
extern void ip6_print(netdissect_options *, const u_char *, u_int);
extern void chdlc_slarp_print(netdissect_options *, const u_char *, u_int);
extern void mpls_print(netdissect_options *, const u_char *, u_int);
extern void isoclns_print(netdissect_options *, const u_char *, u_int, int);