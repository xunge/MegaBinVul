#include <stdint.h>

typedef unsigned char byte;
typedef struct {
    byte *data;
    int length;
    int cmapsubtable;
} xps_font_t;

#define gs_error_invalidfont (-1)

static inline uint16_t u16(const byte *p) {
    return (p[0] << 8) | p[1];
}

static inline int16_t s16(const byte *p) {
    return (p[0] << 8) | p[1];
}

static inline uint32_t u32(const byte *p) {
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

void gs_warn1(const char *fmt, int arg);