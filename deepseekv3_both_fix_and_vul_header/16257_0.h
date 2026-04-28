#include <stdlib.h>

#define PPP_IP      0x21
#define PPP_IPV6    0x57
#define PPP_ADDRESS 0xff
#define PPP_CONTROL 0x03

#define EXTRACT_16BITS(p) ((u_int16_t)ntohs(*(const u_int16_t *)(p)))

typedef struct netdissect_options {
    const u_char *ndo_snapend;
} netdissect_options;

#define ND_TTEST(p) ((p) < ndo->ndo_snapend)

#define ND_PRINT(args)

void ip_print(netdissect_options *, const u_char *, u_int);
void ip6_print(netdissect_options *, const u_char *, u_int);
void handle_ppp(netdissect_options *, int, const u_char *, int);