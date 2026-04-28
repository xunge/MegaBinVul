#include <stdint.h>
#include <stdio.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
    int ndo_suppress_default_print;
} netdissect_options;

#define ND_PRINT(args) printf args
#define ND_TCHECK(ptr)
#define ND_TCHECK2(ptr, len)
#define ND_DEFAULTPRINT(ptr, len)
#define EXTRACT_32BITS(ptr) (*(uint32_t*)(ptr))

enum mpls_packet_type {
    PT_UNKNOWN,
    PT_IPV4,
    PT_IPV6,
    PT_OSI
};

#define MPLS_LABEL(label) ((label) >> 12)
#define MPLS_EXP(label) (((label) >> 9) & 0x7)
#define MPLS_STACK(label) ((label) & 0x100)
#define MPLS_TTL(label) ((label) & 0xFF)

static const char *mpls_labelname[] = {
    "IPv4 explicit NULL",
    "Router Alert",
    "IPv6 explicit NULL",
    "IPv4 implicit NULL"
};