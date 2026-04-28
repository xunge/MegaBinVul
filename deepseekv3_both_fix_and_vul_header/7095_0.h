#include <stdlib.h>
#include <string.h>

struct ssh {
    int compat;
};

#define SSH_BUG_BIGENDIANAES 0x00000001

void debug2_f(const char *fmt, ...);
void fatal(const char *fmt, ...);
char *match_filter_denylist(char *proposal, const char *filter);