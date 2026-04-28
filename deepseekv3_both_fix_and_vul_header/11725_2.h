#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define ANSILOVE_INVALID_PARAM 1
#define ANSILOVE_MEMORY_ERROR 2
#define ANSILOVE_GD_ERROR 3
#define ANSI_SEQUENCE_MAX_LENGTH 32
#define LF 10
#define CR 13
#define TAB 9
#define SUB 26
#define ESC 27

struct ansilove_ctx {
    uint8_t *buffer;
    size_t length;
    int error;
};

struct ansilove_options {
    int columns;
    int font;
    int mode;
    bool icecolors;
    bool diz;
    bool truecolor;
    int bits;
};

struct fontStruct {
    uint8_t *font_data;
    int height;
    bool isAmigaFont;
};

struct ansiChar {
    uint32_t background;
    uint32_t foreground;
    uint8_t character;
    int32_t column;
    int32_t row;
};

enum {
    ANSILOVE_MODE_CED,
    ANSILOVE_MODE_TRANSPARENT,
    ANSILOVE_MODE_WORKBENCH
};

typedef struct {
    int dummy;
} *gdImagePtr;

extern uint8_t workbench_palette[];
extern uint8_t ansi_palette[];
extern void alSelectFont(struct fontStruct *fontData, int font);
extern void drawchar(gdImagePtr im, uint8_t *font_data, int bits, int height, int x, int y, int bg, int fg, uint8_t c);
extern int output(struct ansilove_ctx *ctx, struct ansilove_options *options, gdImagePtr canvas);
extern gdImagePtr gdImageCreate(int sx, int sy);
extern gdImagePtr gdImageCreateTrueColor(int sx, int sy);
extern int gdImageColorAllocate(gdImagePtr im, int r, int g, int b);
extern void gdImageFill(gdImagePtr im, int x, int y, int color);
extern void gdImageColorTransparent(gdImagePtr im, int color);
extern long strtonum(const char *nptr, long minval, long maxval, const char **errstr);