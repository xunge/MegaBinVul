#include <stddef.h>
#include <stdint.h>
#include <arpa/inet.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK2(a, b)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))

enum {
    IPCPOPT_2ADDR,
    IPCPOPT_IPCOMP,
    IPCPOPT_ADDR,
    IPCPOPT_MOBILE4,
    IPCPOPT_PRIDNS,
    IPCPOPT_PRINBNS,
    IPCPOPT_SECDNS,
    IPCPOPT_SECNBNS,
    IPCPOPT_IPCOMP_HDRCOMP
};

#define PPP_VJC 0x002d
#define IPCPOPT_IPCOMP_MINLEN 14

static const char *tok2str(const char *strings, const char *unknown, int val);
static const char *ipaddr_string(netdissect_options *ndo, const u_char *p);
static void print_unknown_data(netdissect_options *ndo, const u_char *cp, const char *s, int len);