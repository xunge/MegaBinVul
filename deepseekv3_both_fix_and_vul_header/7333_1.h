#include <string.h>
#include <stdarg.h>

#define SUBTLV_PAD1 0
#define SUBTLV_PADN 1
#define SUBTLV_DIVERSITY 2
#define DIVERSITY_HOPS 64
#define EC_BABEL_PACKET 0
#define BABEL_DEBUG_COMMON 0

void flog_err(int code, const char *msg, ...);
void debugf(int level, const char *fmt, ...);