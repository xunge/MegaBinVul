#include <stdint.h>
#include <string.h>

typedef struct ImagingCodecState {
    int errcode;
    int ysize;
    int xsize;
} *ImagingCodecState;

typedef struct Imaging {
    uint8_t** image;
} *Imaging;

#define I32(ptr) (*(int32_t*)(ptr))
#define I16(ptr) (*(int16_t*)(ptr))

#define IMAGING_CODEC_UNKNOWN 1
#define IMAGING_CODEC_OVERRUN 2

typedef uint8_t UINT8;