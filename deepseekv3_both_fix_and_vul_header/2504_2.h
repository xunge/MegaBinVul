#include <stdint.h>
#include <stdio.h>

typedef struct netdissect_options netdissect_options;
typedef unsigned int u_int;
typedef unsigned char u_char;

#define PPP_LCP      0xc021
#define PPP_IPCP     0x8021
#define PPP_OSICP    0x8223
#define PPP_MPLSCP   0x8281
#define PPP_IPV6CP   0x8057
#define PPP_CCP      0x80fd
#define PPP_BACP     0x8029
#define PPP_ML       0x003d
#define PPP_CHAP     0xc223
#define PPP_PAP      0xc023
#define PPP_BAP      0x802d
#define PPP_VJNC     0x002d
#define PPP_IP       0x0021
#define PPP_IPV6     0x0057
#define PPP_IPX      0x002b
#define PPP_OSI      0x0023
#define PPP_MPLS_UCAST 0x0281
#define PPP_MPLS_MCAST 0x0283
#define PPP_COMP     0x00fd

#define ETHERTYPE_IP    0x0800
#define ETHERTYPE_IPV6  0x86dd
#define ETHERTYPE_IPX   0x8137

struct tok {
    int v;
    const char *s;
};
extern const struct tok ppptype2str[];

#define ND_PRINT(args) printf args