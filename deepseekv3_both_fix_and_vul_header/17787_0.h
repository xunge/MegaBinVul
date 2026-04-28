#include <string.h>

typedef struct {
    int bitsPerPixel;
    int paddedWidthInBytes;
    int width;
    int height;
    unsigned char *frameBuffer;
    struct {
        int trueColour;
        unsigned int redShift;
        unsigned int greenShift;
        unsigned int blueShift;
        unsigned long redMax;
        unsigned long greenMax;
        unsigned long blueMax;
    } serverFormat;
} *rfbScreenInfoPtr;

int ScaleX(rfbScreenInfoPtr src, rfbScreenInfoPtr dst, int x);
int ScaleY(rfbScreenInfoPtr src, rfbScreenInfoPtr dst, int y);
void rfbScaledCorrection(rfbScreenInfoPtr src, rfbScreenInfoPtr dst, int *x, int *y, int *w, int *h, const char *name);