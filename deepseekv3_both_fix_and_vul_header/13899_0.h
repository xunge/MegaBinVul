#include <stdint.h>

typedef uint8_t byte;
typedef struct xps_font_s xps_font_t;

struct xps_font_s {
    byte *data;
    int cmapsubtable;
    int length;
};

#define gs_error_invalidfont (-1)
#define return_error(x) return (x)

static inline uint16_t u16(const byte *p) {
    return (p[0] << 8) | p[1];
}

static inline int16_t s16(const byte *p) {
    return (p[0] << 8) | p[1];
}

static inline uint32_t u32(const byte *p) {
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

#define gs_warn1(fmt, arg) /* no-op */