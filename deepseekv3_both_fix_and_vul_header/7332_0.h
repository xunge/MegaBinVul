#include <stdint.h>

#define SUBTLV_PAD1 0
#define SUBTLV_PADN 1
#define SUBTLV_TIMESTAMP 2

#define EC_BABEL_PACKET 0
#define BABEL_DEBUG_COMMON 0

#define DO_NTOHL(dest, src) \
    do { \
        const unsigned char *p = (src); \
        (dest) = ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | \
                 ((uint32_t)p[2] << 8) | (uint32_t)p[3]; \
    } while (0)

void flog_err(int code, const char *msg);
void debugf(int level, const char *fmt, ...);