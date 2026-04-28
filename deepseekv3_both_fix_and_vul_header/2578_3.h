#include <stdint.h>
#include <arpa/inet.h>

typedef uint8_t u_char;
typedef unsigned int u_int;

typedef struct netdissect_options netdissect_options;

#define ND_TCHECK(a)
#define ND_TCHECK2(a, b) 
#define ND_PRINT(ndo, ...)

#define IPOPT_EOL 0
#define IPOPT_NOP 1
#define IPOPT_RR 7
#define IPOPT_SSRR 137
#define IPOPT_LSRR 131
#define IPOPT_TS 68
#define IPOPT_RA 148
#define IPOPT_SECURITY 130

#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))

extern const char *tstr;
extern const char *ip_option_values[];
extern const char *tok2str(const char *, const char *, unsigned int);
extern int ip_printts(netdissect_options *, const u_char *, u_int);
extern int ip_printroute(netdissect_options *, const u_char *, u_int);