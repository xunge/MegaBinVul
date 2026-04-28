#include <string.h>
#include <ctype.h>

typedef unsigned char byte;

typedef struct {
    byte *data;
    int length;
} xps_font_t;

int xps_find_sfnt_table(xps_font_t *font, const char *name, int *length);
void gs_warn(const char *msg);
unsigned short u16(const unsigned char *p);
unsigned int u32(const unsigned char *p);