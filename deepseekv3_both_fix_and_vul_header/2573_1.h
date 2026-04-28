#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

struct netdissect_options {
    int ndo_vflag;
};

typedef struct netdissect_options netdissect_options;

struct ip6_frag {
    uint32_t ip6f_ident;
    uint16_t ip6f_offlg;
};

struct ip6_hdr {
    uint16_t ip6_plen;
};

#define ND_TCHECK(p)
#define ND_PRINT(args) printf args
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))
#define IP6F_OFF_MASK 0xfff8

uint16_t ntohs(uint16_t netshort);
uint32_t ntohl(uint32_t netlong);