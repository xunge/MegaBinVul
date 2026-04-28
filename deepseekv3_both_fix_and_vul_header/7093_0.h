#include <stdlib.h>
#include <string.h>

#define SSH_BUG_CURVE25519PAD 0x01
#define SSH_OLD_DHGEX 0x02

struct ssh {
    int compat;
};

extern void debug2_f(const char *fmt, ...);
extern void fatal(const char *fmt, ...);
extern char *match_filter_denylist(char *proposal, const char *denylist);