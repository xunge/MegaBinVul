#include <stdint.h>
#include <string.h>
#include <stddef.h>

typedef struct {
    int errcode;
    int ysize;
    int xsize;
} *ImagingCodecState;

typedef struct {
    uint8_t** image;
} *Imaging;

#define I32(ptr) (*(int32_t*)(ptr))
#define I16(ptr) (*(int16_t*)(ptr))

#define IMAGING_CODEC_UNKNOWN 1
#define IMAGING_CODEC_OVERRUN 2

typedef uint8_t UINT8;
typedef ptrdiff_t Py_ssize_t;