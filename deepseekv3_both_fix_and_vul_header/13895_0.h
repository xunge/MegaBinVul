#include <stdint.h>

typedef unsigned char byte;

typedef struct {
    byte *data;
    int cmapsubcount;
    int cmaptable;
    int cmapsubtable;
    int length;
    int usepua;
} xps_font_t;

static inline uint16_t u16(const byte *p) {
    return (p[0] << 8) | p[1];
}

static inline uint32_t u32(const byte *p) {
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}