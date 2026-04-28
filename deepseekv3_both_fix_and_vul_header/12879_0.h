#include <stddef.h>

typedef unsigned char uchar;

typedef struct {
    int width;
    int height;
    int maskscale;
    int maskwidth;
    uchar *mask;
} image_t;

extern int PSLevel;