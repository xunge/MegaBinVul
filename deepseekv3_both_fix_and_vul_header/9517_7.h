#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

typedef unsigned char u_char;

#define PPP_IP      0x21
#define PPP_IPV6    0x57
#define PPP_ADDRESS 0xff
#define PPP_CONTROL 0x03

#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))

typedef struct netdissect_options {
    const void *ndo_snapend;
} netdissect_options;

void ip_print(netdissect_options *, const u_char *, int);
void ip6_print(netdissect_options *, const u_char *, int);
void handle_ppp(netdissect_options *, int, const u_char *, int);
#define ND_PRINT(args) ((void)0)