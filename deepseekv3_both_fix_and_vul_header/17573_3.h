#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CURSOR_SIZE 256
#define sz_rfbXCursorColors 6

typedef bool rfbBool;
#define TRUE true
#define FALSE false

typedef struct rfbClient rfbClient;
typedef struct rfbPixelFormat {
    int bitsPerPixel;
} rfbPixelFormat;

struct rfbClient {
    rfbPixelFormat format;
    uint8_t* rcSource;
    uint8_t* rcMask;
    void (*GotCursorShape)(rfbClient*, int, int, int, int, int);
};

typedef struct {
    uint8_t foreRed;
    uint8_t foreGreen;
    uint8_t foreBlue;
    uint8_t backRed;
    uint8_t backGreen;
    uint8_t backBlue;
} rfbXCursorColors;

#define rfbEncodingXCursor 0

#define RGB24_TO_PIXEL(bpp, r, g, b) (((r) << 16) | ((g) << 8) | (b))

rfbBool ReadFromRFBServer(rfbClient* client, char* buf, size_t len);