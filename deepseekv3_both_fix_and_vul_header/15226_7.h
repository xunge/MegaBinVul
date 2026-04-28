#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Guchar;
typedef int GBool;

class GfxState;
class Object;

class Stream {
public:
    virtual void close() = 0;
    virtual ~Stream() {}
};

enum GfxColorSpaceMode {
    csDeviceRGB,
    csICCBased
};

class GfxColorSpace {
public:
    virtual GfxColorSpaceMode getMode() = 0;
    virtual ~GfxColorSpace() {}
};

class GfxICCBasedColorSpace : public GfxColorSpace {
public:
    virtual GfxColorSpace* getAlt() = 0;
};

class GfxImageColorMap {
public:
    virtual int getNumPixelComps() = 0;
    virtual int getBits() = 0;
    virtual GfxColorSpace* getColorSpace() = 0;
    virtual void getRGBLine(Guchar *in, unsigned int *out, int width) = 0;
    virtual ~GfxImageColorMap() {}
};

class ImageStream {
public:
    ImageStream(Stream *str, int width, int nComps, int nBits);
    virtual ~ImageStream();
    virtual void reset();
    virtual Guchar* getLine();
};

struct cairo_surface_t;
struct cairo_pattern_t;
struct cairo_matrix_t {
    double xx; double yx;
    double xy; double yy;
    double x0; double y0;
};

class CairoOutputDev {
public:
    void drawMaskedImage(GfxState *state, Object *ref,
                        Stream *str, int width, int height,
                        GfxImageColorMap *colorMap,
                        Stream *maskStr, int maskWidth,
                        int maskHeight, GBool maskInvert);
protected:
    void *cairo;
    void *cairo_shape;
};

void *gmalloc(size_t size);
void *gmallocn(int n, int size);
void *gmallocn3(int width, int height, int size);
void gfree(void *p);

#define CAIRO_FORMAT_A8 0
#define CAIRO_FORMAT_RGB24 1
#define CAIRO_FILTER_BILINEAR 2

cairo_surface_t* cairo_image_surface_create_for_data(unsigned char *data, int format, int width, int height, int stride);
cairo_pattern_t* cairo_pattern_create_for_surface(cairo_surface_t *surface);
void cairo_matrix_init_translate(cairo_matrix_t *matrix, double tx, double ty);
void cairo_matrix_scale(cairo_matrix_t *matrix, double sx, double sy);
void cairo_pattern_set_matrix(cairo_pattern_t *pattern, const cairo_matrix_t *matrix);
void cairo_pattern_set_filter(cairo_pattern_t *pattern, int filter);
void cairo_set_source(void *cr, cairo_pattern_t *source);
void cairo_mask(void *cr, cairo_pattern_t *pattern);
void cairo_save(void *cr);
void cairo_restore(void *cr);
void cairo_pattern_destroy(cairo_pattern_t *pattern);
void cairo_surface_destroy(cairo_surface_t *surface);

#define LOG(x) (void)0