#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Guchar;

struct GfxState;
struct Object;

struct Stream {
    void close();
};

struct GfxColorSpace {
    int getMode();
};

struct GfxICCBasedColorSpace {
    GfxColorSpace* getAlt();
};

struct GfxImageColorMap {
    int getNumPixelComps();
    int getBits();
    void getGrayLine(Guchar* pix, unsigned char* dest, int width);
    void getRGBLine(Guchar* pix, unsigned int* dest, int width);
    GfxColorSpace* getColorSpace();
};

struct ImageStream {
    ImageStream(Stream *str, int width, int numComps, int bits);
    ~ImageStream();
    void reset();
    Guchar* getLine();
};

struct cairo_matrix_t {
    double xx; double yx;
    double xy; double yy;
    double x0; double y0;
};

struct cairo_surface_t;
struct cairo_pattern_t;
struct cairo_t;

struct CairoOutputDev {
    void drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str,
                            int width, int height,
                            GfxImageColorMap *colorMap,
                            Stream *maskStr,
                            int maskWidth, int maskHeight,
                            GfxImageColorMap *maskColorMap);
};

enum {
    csDeviceRGB,
    csICCBased,
    CAIRO_FORMAT_A8,
    CAIRO_FORMAT_RGB24,
    CAIRO_FILTER_BILINEAR
};

#define LOG(x) (x)

extern cairo_t *cairo;
extern cairo_t *cairo_shape;

void* gmalloc(size_t size);
void* gmallocn(size_t n, size_t size);
void* gmallocn3(size_t x, size_t y, size_t z);

cairo_surface_t* cairo_image_surface_create_for_data(void* data, int format, int width, int height, int stride);
cairo_pattern_t* cairo_pattern_create_for_surface(cairo_surface_t* surface);
void cairo_matrix_init_translate(cairo_matrix_t* matrix, double tx, double ty);
void cairo_matrix_scale(cairo_matrix_t* matrix, double sx, double sy);
void cairo_pattern_set_matrix(cairo_pattern_t* pattern, cairo_matrix_t* matrix);
void cairo_pattern_set_filter(cairo_pattern_t* pattern, int filter);
void cairo_set_source(cairo_t* cr, cairo_pattern_t* source);
void cairo_mask(cairo_t* cr, cairo_pattern_t* pattern);
void cairo_save(cairo_t* cr);
void cairo_restore(cairo_t* cr);
void cairo_pattern_destroy(cairo_pattern_t* pattern);
void cairo_surface_destroy(cairo_surface_t* surface);