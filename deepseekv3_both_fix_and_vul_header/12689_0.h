#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    uint32_t *chars;
    uint32_t *attrs;
} caca_canvas_t;

#define CACA_BOLD 0x01
#define CACA_ITALICS 0x02

uint8_t caca_attr_to_ansi_fg(uint32_t attr);
uint8_t caca_attr_to_ansi_bg(uint32_t attr);
size_t caca_utf32_to_utf8(char *out, uint32_t ch);
void debug(const char *format, ...);