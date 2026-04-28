#include <stdlib.h>
#include <string.h>

struct ssh {
    int compat;
};

#define SSH_BUG_RSASIGMD5 0x0001

extern void debug2_f(const char *fmt, ...);
extern void fatal(const char *fmt, ...);
extern char *match_filter_denylist(char *proposal, const char *denylist);