#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MagickExport
#define MagickTrue 1
#define MagickEpsilon 1.0E-10

typedef struct _Image {
    struct _ExceptionInfo *exception;
} Image;

typedef struct _ImageInfo ImageInfo;

typedef struct _StopInfo {
    double offset;
    char *color;
} StopInfo;

typedef struct _GradientInfo {
    size_t number_stops;
    StopInfo *stops;
} GradientInfo;

typedef struct _DrawInfo {
    char *id;
    char *primitive;
    char *geometry;
    int compliance;
    char *viewbox;
    char *affine;
    int gravity;
    char *fill;
    char *stroke;
    double stroke_width;
    Image *fill_pattern;
    Image *tile;
    Image *stroke_pattern;
    int stroke_antialias;
    int text_antialias;
    int fill_rule;
    int linecap;
    int linejoin;
    double miterlimit;
    double dash_offset;
    int decorate;
    int compose;
    char *text;
    char *font;
    char *metrics;
    char *family;
    int style;
    int stretch;
    int weight;
    char *encoding;
    double pointsize;
    double kerning;
    double interline_spacing;
    double interword_spacing;
    int direction;
    char *density;
    int align;
    char *undercolor;
    char *border_color;
    char *server_name;
    double *dash_pattern;
    GradientInfo gradient;
    char *bounds;
    double fill_opacity;
    double stroke_opacity;
    char *element_reference;
    char *clip_path;
    int clip_units;
    char *clip_mask;
    Image *clipping_mask;
    Image *composite_mask;
    int render;
    ImageInfo *image_info;
    int debug;
} DrawInfo;

enum {
    ResourceLimitFatalError
};

extern void *AcquireCriticalMemory(size_t);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void GetDrawInfo(const ImageInfo *, DrawInfo *);
extern int CloneString(char **, const char *);
extern Image *CloneImage(const Image *, size_t, size_t, int, void *);
extern Image *NewImageList(void);
extern void ThrowFatalException(int, const char *);
extern ImageInfo *CloneImageInfo(const ImageInfo *);