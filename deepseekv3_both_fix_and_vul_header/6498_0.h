#include <stdlib.h>

#define XCURSOR_IMAGE_MAX_SIZE 0x7fff
#define XCURSOR_IMAGE_VERSION 1

typedef unsigned int XcursorPixel;

typedef struct {
    int version;
    XcursorPixel *pixels;
    int size;
    int width;
    int height;
    int delay;
} XcursorImage;