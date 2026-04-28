#include <string.h>

typedef unsigned char UINT8;
typedef long Py_ssize_t;

typedef struct Imaging *Imaging;
typedef struct ImagingCodecState *ImagingCodecState;

struct Imaging {
    char *mode;
    void **image;
    int pixelsize;
};

struct ImagingCodecState {
    int xsize;
    int bytes;
    int errcode;
    UINT8 *buffer;
    int x;
    int y;
    int yoff;
    int xoff;
    int ysize;
    void (*shuffle)(UINT8*, UINT8*, int);
};

#define IMAGING_CODEC_OVERRUN 1