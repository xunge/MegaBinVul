#include <stddef.h>
#include <stdint.h>
#include <arpa/inet.h>

typedef unsigned char u_char;

typedef struct netdissect_options {
    /* dummy structure since we can't include actual definition */
    int dummy;
} netdissect_options;

#define ND_TCHECK(p)
#define ND_TCHECK_16BITS(p)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))

#define IP6MOPT_PAD1            0
#define IP6MOPT_PADN            1
#define IP6MOPT_REFRESH         2
#define IP6MOPT_ALTCOA          3
#define IP6MOPT_NONCEID         4
#define IP6MOPT_AUTH            5

#define IP6MOPT_MINLEN          2
#define IP6MOPT_REFRESH_MINLEN  4
#define IP6MOPT_ALTCOA_MINLEN   18
#define IP6MOPT_NONCEID_MINLEN  6
#define IP6MOPT_AUTH_MINLEN     4