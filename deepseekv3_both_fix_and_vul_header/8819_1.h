#include <stdint.h>
#include <stddef.h>

typedef struct {
    int bitsPerPixel;
} rfbPixelFormat;

typedef struct {
    uint8_t* frameBuffer;
    int width;
    rfbPixelFormat format;
} rfbClient;

void rfbClientLog(const char* format, ...);