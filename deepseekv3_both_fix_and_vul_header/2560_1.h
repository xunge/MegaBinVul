#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

#define ND_TCHECK(a)
#define ND_TCHECK2(a, b)
#define ND_PRINT(a) printf
#define EXTRACT_16BITS(a) (*(uint16_t *)(a))

#define IPOPT_EOL 0
#define IPOPT_NOP 1
#define IPOPT_RR 7
#define IPOPT_TS 68
#define IPOPT_SECURITY 130
#define IPOPT_LSRR 131
#define IPOPT_SSRR 137
#define IPOPT_RA 148

typedef struct netdissect_options {
    int dummy;
} netdissect_options;

extern const char *tstr;
extern const char *ip_option_values[];