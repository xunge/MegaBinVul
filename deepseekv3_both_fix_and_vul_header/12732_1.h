#include <stdint.h>
#include <string.h>

typedef struct ImagingCodecState {
    int errcode;
    int ysize;
    int xsize;
} *ImagingCodecState;

typedef struct Imaging {
    uint8_t **image;
} *Imaging;

#define I32(ptr) (*(int32_t*)(ptr))
#define I16(ptr) (*(int16_t*)(ptr))
#define ERR_IF_DATA_OOB(n) if (bytes < (n)) { state->errcode = IMAGING_CODEC_OVERRUN; return -1; }

#define IMAGING_CODEC_OVERRUN 1
#define IMAGING_CODEC_UNKNOWN 2
#define IMAGING_CODEC_BROKEN 3

typedef uint8_t UINT8;
typedef int32_t Py_ssize_t;