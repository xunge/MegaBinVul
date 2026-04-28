#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define SYSCONFDIR "/etc"

struct hesiod_p {
    char *lhs;
    char *rhs;
};

extern int read_config_file(struct hesiod_p *ctx, const char *configname);