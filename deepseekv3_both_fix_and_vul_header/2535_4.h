#include <sys/types.h>
#include <stdarg.h>
#include <stddef.h>

#define INDIR_MASK    0xc0
#define EDNS0_MASK    0x40
#define EDNS0_ELT_BITLABEL 1

typedef unsigned char u_char;
typedef unsigned int u_int;

struct netdissect_options {
    const u_char *ndo_snapend;
};

typedef struct netdissect_options netdissect_options;

int labellen(netdissect_options *, const u_char *);
int ND_TTEST2(const u_char, int);
void ND_PRINT(netdissect_options *, const char *, ...);
const u_char *blabel_print(netdissect_options *, const u_char *);
int fn_printn(netdissect_options *, const u_char *, u_int, const u_char *);

/* Macro to fix ND_PRINT calls */
#define ND_PRINT(args) ND_PRINT args