#include <stdint.h>
#include <stddef.h>

typedef struct netdissect_options {
    int ndo_eflag;
} netdissect_options;

#define ND_PRINT(args)
#define NLPID_CLNP 0x81
#define NLPID_ESIS 0x82
#define NLPID_ISIS 0x83
#define NLPID_NULLNS 0x00
#define NLPID_Q933 0x08
#define NLPID_IP 0xCC
#define NLPID_IP6 0x8E
#define NLPID_PPP 0xCF

typedef unsigned int u_int;

const char *tok2str(const char **, const char *, int);
int clnp_print(netdissect_options *, const uint8_t *, u_int);
void esis_print(netdissect_options *, const uint8_t *, u_int);
int isis_print(netdissect_options *, const uint8_t *, u_int);
void q933_print(netdissect_options *, const uint8_t *, u_int);
void ip_print(netdissect_options *, const uint8_t *, u_int);
void ip6_print(netdissect_options *, const uint8_t *, u_int);
void ppp_print(netdissect_options *, const uint8_t *, u_int);
void print_unknown_data(netdissect_options *, const uint8_t *, const char *, u_int);

static const char *nlpid_values[] = {
    NULL
};