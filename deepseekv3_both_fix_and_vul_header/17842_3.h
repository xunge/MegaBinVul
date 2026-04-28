#include <string.h>
#include <stdint.h>
#include <stddef.h>

typedef uint8_t UINT8;
typedef ptrdiff_t Py_ssize_t;

#define IMAGING_CODEC_OVERRUN 1

typedef struct ImagingCodecState {
    int xsize;
    int ysize;
    int bits;
    int bytes;
    int x;
    int y;
    int xoff;
    int yoff;
    int errcode;
    UINT8* buffer;
    void (*shuffle)(UINT8*, UINT8*, int);
} *ImagingCodecState;

typedef struct Imaging {
    char* mode;
    UINT8** image;
    int pixelsize;
} *Imaging;