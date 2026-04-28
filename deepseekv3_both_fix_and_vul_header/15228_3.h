#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Guchar;
typedef int GBool;

class GfxState;
class Object;
class Stream;
class GfxImageColorMap;
class ImageStream;
class GfxICCBasedColorSpace;

enum GfxColorSpaceMode {
    csDeviceRGB,
    csICCBased
};

class GfxColorSpace {
public:
    virtual GfxColorSpaceMode getMode() = 0;
};

class GfxICCBasedColorSpace : public GfxColorSpace {
public:
    virtual GfxColorSpace* getAlt() = 0;
    virtual GfxColorSpaceMode getMode() { return csICCBased; }
};

class GfxImageColorMap {
public:
    virtual int getNumPixelComps() = 0;
    virtual int getBits() = 0;
    virtual GfxColorSpace* getColorSpace() = 0;
    virtual void getRGBLine(Guchar *pix, unsigned int *dest, int width) = 0;
};

class ImageStream {
public:
    ImageStream(Stream *str, int width, int nComps, int bits) {}
    virtual ~ImageStream() {}
    virtual void reset() {}
    virtual Guchar* getLine() { return nullptr; }
};

class CairoOutputDev {
public:
    void drawImage(GfxState *state, Object *ref, Stream *str,
                  int width, int height,
                  GfxImageColorMap *colorMap,
                  int *maskColors, GBool inlineImg);
};

typedef struct _cairo cairo_t;
typedef struct _cairo_surface cairo_surface_t;
typedef struct _cairo_pattern cairo_pattern_t;
typedef struct {
    double xx; double yx;
    double xy; double yy;
    double x0; double y0;
} cairo_matrix_t;

#define CAIRO_FORMAT_ARGB32 0
#define CAIRO_FORMAT_RGB24 1
#define CAIRO_FILTER_BILINEAR 2

extern cairo_t *cairo;
extern cairo_t *cairo_shape;

static inline void* gmalloc(size_t size) { return malloc(size); }
static inline void* gmallocn3(int a, int b, int c) { return malloc(a * b * c); }

static inline cairo_surface_t* cairo_image_surface_create_for_data(void* data, int format, int width, int height, int stride) { return nullptr; }
static inline cairo_pattern_t* cairo_pattern_create_for_surface(cairo_surface_t* surface) { return nullptr; }
static inline void cairo_matrix_init_translate(cairo_matrix_t* matrix, double tx, double ty) {}
static inline void cairo_matrix_scale(cairo_matrix_t* matrix, double sx, double sy) {}
static inline void cairo_pattern_set_matrix(cairo_pattern_t* pattern, cairo_matrix_t* matrix) {}
static inline void cairo_pattern_set_filter(cairo_pattern_t* pattern, int filter) {}
static inline void cairo_set_source(cairo_t* cr, cairo_pattern_t* pattern) {}
static inline void cairo_paint(cairo_t* cr) {}
static inline void cairo_save(cairo_t* cr) {}
static inline void cairo_restore(cairo_t* cr) {}
static inline void cairo_pattern_destroy(cairo_pattern_t* pattern) {}
static inline void cairo_surface_destroy(cairo_surface_t* surface) {}

#define LOG(x) do {} while(0)