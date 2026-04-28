#include <stdint.h>

typedef struct gdImageStruct *gdImagePtr;
typedef int32_t gdFixed;

struct gdImageStruct {
    int **tpixels;
};

static inline gdFixed gd_itofx(int i);
static inline double gd_fxtof(gdFixed f);
static inline gdFixed gd_mulfx(gdFixed x, gdFixed y);
static inline int _color_blend(int bg, int fg);