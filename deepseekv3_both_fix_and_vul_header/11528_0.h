#include <stdarg.h>
#include <stdio.h>

typedef struct {
    struct {
        int (*puts)(void);
    } *font;
} Bitmap;

int bm_puts(Bitmap *b, int x, int y, const char *buffer);