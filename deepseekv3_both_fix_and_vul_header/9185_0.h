#include <stdint.h>

#define SIG_FSQ_OFF 4
#define SIG_FID_OFF 1

typedef uint8_t guint8;
typedef uint32_t guint32;

static inline guint32 pletoh24(const guint8 *p) {
    return (p[0] << 16) | (p[1] << 8) | p[2];
}