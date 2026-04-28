#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

typedef unsigned char u_char;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK2(p, l)
#define ND_PRINT(args) printf args

#define CCPOPT_BSDCOMP 0
#define CCPOPT_MVRCA 1
#define CCPOPT_DEFLATE 2

extern const char *ccpconfopts_values[];
extern const char *tok2str(const char *[], const char *, int);
extern void print_unknown_data(netdissect_options *, const u_char *, const char *, int);