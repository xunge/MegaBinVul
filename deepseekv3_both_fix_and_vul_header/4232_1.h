#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>

typedef struct Imaging {
    int xsize;
    int ysize;
    int mode;
    int type;
    int bands;
    uint8_t **image8;
    uint8_t **image;
} *Imaging;

typedef struct ImagingSectionCookie *ImagingSectionCookie;

struct filter {
    float (*filter)(float);
    float support;
};

extern struct filter LANCZOS;
extern struct filter BILINEAR;
extern struct filter BICUBIC;

#define IMAGING_TRANSFORM_LANCZOS 0
#define IMAGING_TRANSFORM_BILINEAR 1
#define IMAGING_TRANSFORM_BICUBIC 2

#define IMAGING_TYPE_UINT8 0
#define IMAGING_TYPE_INT32 1
#define IMAGING_TYPE_FLOAT32 2

typedef uint8_t UINT8;

extern Imaging ImagingError_ValueError(const char *message);
extern Imaging ImagingError_MemoryError();
extern Imaging ImagingNew(int mode, int xsize, int ysize);
extern void ImagingSectionEnter(ImagingSectionCookie *cookie);
extern void ImagingSectionLeave(ImagingSectionCookie *cookie);

static inline float i2f(int v) { return (float)v; }
static inline uint8_t clip8(float v) { return (uint8_t)(v < 0 ? 0 : v > 255 ? 255 : v + 0.5); }

#define IMAGING_PIXEL_I(im, x, y) (*((int*) &(im)->image[(y)][(x)*4]))
#define IMAGING_PIXEL_F(im, x, y) (*((float*) &(im)->image[(y)][(x)*4]))