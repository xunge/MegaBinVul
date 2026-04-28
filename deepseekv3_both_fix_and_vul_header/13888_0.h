#include <string.h>
#include <ctype.h>

typedef unsigned char byte;

typedef struct xps_font_s {
    byte *data;
    int length;
} xps_font_t;

int xps_find_sfnt_table(xps_font_t *font, const char *name, int *length);
void gs_warn(const char *msg);

static inline unsigned short u16(const unsigned char *p) {
    return (p[0] << 8) | p[1];
}

static inline unsigned int u32(const unsigned char *p) {
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}