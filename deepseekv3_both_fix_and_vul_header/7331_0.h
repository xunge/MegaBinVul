#include <stdint.h>

#define DO_NTOHS(var, ptr) \
    (var) = ((uint16_t)((ptr)[0]) << 8) | (ptr)[1]

#define BABEL_DEBUG_COMMON 0
#define MESSAGE_PAD1 0
#define MESSAGE_MAX 255

static const unsigned char tlv_min_length[256];

static void debugf(int level, const char *fmt, ...);