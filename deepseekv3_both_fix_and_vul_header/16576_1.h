#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

struct import {
    uint32_t dfg;
    uint32_t dbg;
    uint32_t clearattr;
};

#define CACA_DEFAULT 0
#define CACA_TRANSPARENT 1
#define CACA_LIGHTGRAY 2
#define CACA_BLACK 3

typedef struct {
    int width;
    int height;
    struct {
        int x;
        int y;
    } frames[1];
    int frame;
    uint32_t *attrs;
    uint32_t *chars;
} caca_canvas_t;

uint32_t caca_get_attr(caca_canvas_t *cv, int x, int y);
void caca_set_attr(caca_canvas_t *cv, uint32_t attr);
void caca_set_color_ansi(caca_canvas_t *cv, uint32_t fg, uint32_t bg);
int caca_set_canvas_size(caca_canvas_t *cv, int width, int height);
void caca_draw_line(caca_canvas_t *cv, int x1, int y1, int x2, int y2, uint32_t ch);
void caca_fill_box(caca_canvas_t *cv, int x1, int y1, int x2, int y2, uint32_t ch);
void caca_put_char(caca_canvas_t *cv, int x, int y, uint32_t ch);
void caca_put_attr(caca_canvas_t *cv, int x, int y, uint32_t attr);
uint32_t caca_get_char(caca_canvas_t *cv, int x, int y);
int caca_get_frame_count(caca_canvas_t *cv);
void caca_create_frame(caca_canvas_t *cv, int f);
void caca_set_frame(caca_canvas_t *cv, int f);
uint32_t caca_utf8_to_utf32(const char *utf8, size_t *bytes);
int caca_utf32_is_fullwidth(uint32_t ch);
uint32_t caca_cp437_to_utf32(unsigned char ch);
void ansi_parse_grcm(caca_canvas_t *cv, struct import *im, unsigned int argc, unsigned int *argv);
void debug(const char *format, ...);