#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int bpp;
    int flags;
} JsGraphicsData;

typedef struct {
    void* backendData;
    JsGraphicsData data;
} JsGraphics;

#define JSGRAPHICSFLAGS_ARRAYBUFFER_VERTICAL_BYTE 1
#define JSGRAPHICSFLAGS_ARRAYBUFFER_MSB 2

unsigned int lcdGetPixelIndex_ArrayBuffer(JsGraphics* gfx, short x, short y, short pixelCount);