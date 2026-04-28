#include <stdint.h>
#include <arpa/inet.h>

#define SUBTLV_PAD1 0
#define SUBTLV_PADN 1
#define SUBTLV_TIMESTAMP 2

#define EC_BABEL_PACKET 0
#define BABEL_DEBUG_COMMON 0

#define DO_NTOHL(dest, src) do { \
    memcpy(&(dest), (src), sizeof(dest)); \
    (dest) = ntohl(dest); \
} while (0)

extern void flog_err(int ec, const char *msg);
extern void debugf(int level, const char *fmt, ...);