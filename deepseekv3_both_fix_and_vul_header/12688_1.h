#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct caca_canvas {
    int width;
    int height;
    uint32_t *attrs;
    uint32_t *chars;
};

typedef struct caca_canvas caca_canvas_t;

#define CACA_MAGIC_FULLWIDTH 0x0000ffff
#define CACA_DEFAULT 0
#define CACA_BOLD (1 << 0)
#define CACA_ITALICS (1 << 1)
#define CACA_UNDERLINE (1 << 2)
#define CACA_BLINK (1 << 3)

int caca_utf32_is_fullwidth(uint32_t c);
int caca_attr_to_ansi_bg(uint32_t attr);
int caca_attr_to_ansi_fg(uint32_t attr);
unsigned long _caca_attr_to_rgb24bg(uint32_t attr);
unsigned long _caca_attr_to_rgb24fg(uint32_t attr);