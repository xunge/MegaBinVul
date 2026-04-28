#include <stdint.h>

typedef uint8_t UINT8;

typedef struct ImagingCodecState {
    int xsize;
    int ysize;
    int y;
    UINT8* buffer;
    void (*shuffle)(UINT8*, UINT8*, int);
} *ImagingCodecState;

typedef struct Imaging {
    UINT8** image;
} *Imaging;

int ImagingPcdDecode(Imaging im, ImagingCodecState state, UINT8* buf, int bytes);