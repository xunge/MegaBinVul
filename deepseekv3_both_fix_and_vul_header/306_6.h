#include <assert.h>
#include <string.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    char *page;
    struct {
        double x;
        double y;
    } resolution;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
    char *message;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    struct {
        double x;
        double y;
    } resolution;
    struct _Image *previous;
} Image;

typedef enum {
    RightToLeftDirection,
    LeftToRightDirection
} DirectionType;

typedef enum {
    ForgetGravity,
    NorthWestGravity,
    NorthGravity,
    NorthEastGravity,
    WestGravity,
    CenterGravity,
    EastGravity,
    SouthWestGravity,
    SouthGravity,
    SouthEastGravity
} GravityType;

typedef enum {
    UndefinedAlign,
    LeftAlign,
    CenterAlign,
    RightAlign
} AlignType;

typedef struct _DrawInfo {
    char *font;
    double pointsize;
    AlignType align;
    GravityType gravity;
    DirectionType direction;
    struct {
        double red;
        double green;
        double blue;
        double alpha;
    } fill;
} DrawInfo;

typedef struct _MemoryInfo {
    void *blob;
} MemoryInfo;

typedef struct _PixelInfo {
    double red;
    double green;
    double blue;
    double alpha;
} PixelInfo;

typedef struct _RectangleInfo {
    double x;
    double y;
} RectangleInfo;

typedef struct _PangoRectangle {
    int x;
    int y;
    int width;
    int height;
} PangoRectangle;

typedef struct _GError {
    char *message;
} GError;

#define MagickCoreSignature 0xabacadabUL
#define DefaultSVGDensity 90.0
#define PANGO_SCALE 1024

typedef enum {
    PANGO_ALIGN_LEFT,
    PANGO_ALIGN_CENTER,
    PANGO_ALIGN_RIGHT
} PangoAlignment;

typedef enum {
    PANGO_GRAVITY_SOUTH,
    PANGO_GRAVITY_EAST,
    PANGO_GRAVITY_NORTH,
    PANGO_GRAVITY_WEST,
    PANGO_GRAVITY_AUTO
} PangoGravity;

typedef enum {
    PANGO_DIRECTION_LTR,
    PANGO_DIRECTION_RTL
} PangoDirection;

typedef enum {
    PANGO_GRAVITY_HINT_NATURAL,
    PANGO_GRAVITY_HINT_STRONG,
    PANGO_GRAVITY_HINT_LINE
} PangoGravityHint;

typedef enum {
    PANGO_ELLIPSIZE_NONE,
    PANGO_ELLIPSIZE_START,
    PANGO_ELLIPSIZE_MIDDLE,
    PANGO_ELLIPSIZE_END
} PangoEllipsizeMode;

typedef enum {
    PANGO_WRAP_WORD,
    PANGO_WRAP_CHAR,
    PANGO_WRAP_WORD_CHAR
} PangoWrapMode;

typedef enum {
    CAIRO_HINT_STYLE_DEFAULT,
    CAIRO_HINT_STYLE_NONE,
    CAIRO_HINT_STYLE_SLIGHT,
    CAIRO_HINT_STYLE_MEDIUM,
    CAIRO_HINT_STYLE_FULL
} cairo_hint_style_t;

typedef enum {
    CAIRO_OPERATOR_CLEAR,
    CAIRO_OPERATOR_OVER
} cairo_operator_t;

typedef enum {
    CAIRO_FORMAT_ARGB32
} cairo_format_t;

typedef struct _PangoContext PangoContext;
typedef struct _PangoFontDescription PangoFontDescription;
typedef struct _PangoFontMap PangoFontMap;
typedef struct _PangoLayout PangoLayout;
typedef struct _cairo_font_options_t cairo_font_options_t;
typedef struct _cairo_surface_t cairo_surface_t;
typedef struct _cairo_t cairo_t;

#define GetPixelChannels(image) 4
#define GetPixelAlpha(image,q) (*(q+3))
#define QuantumScale (1.0/QuantumRange)
#define QuantumRange ((double) ((1UL << 16) - 1))
#define ScaleCharToQuantum(x) ((Quantum) (x))
#define TraceEvent 0
#define CoderError 0
#define ResourceLimitError 0
#define LoadImageTag 0

typedef unsigned short Quantum;
typedef long ssize_t;
typedef unsigned long size_t;
typedef long MagickOffsetType;

extern int LocaleNCompare(const char *, const char *, size_t);
extern int LocaleCompare(const char *, const char *);
extern long StringToLong(const char *);
extern char *GetImageProperty(Image *, const char *, ExceptionInfo *);
extern char *ConstantString(const char *);
extern PangoFontMap *pango_cairo_font_map_new();
extern void pango_cairo_font_map_set_resolution(PangoFontMap *, double);
extern PangoFontMap *PANGO_CAIRO_FONT_MAP(PangoFontMap *);
extern cairo_font_options_t *cairo_font_options_create();
extern void cairo_font_options_set_hint_style(cairo_font_options_t *, cairo_hint_style_t);
extern void cairo_font_options_destroy(cairo_font_options_t *);
extern PangoContext *pango_font_map_create_context(PangoFontMap *);
extern void pango_cairo_context_set_font_options(PangoContext *, cairo_font_options_t *);
extern void pango_context_set_language(PangoContext *, void *);
extern void *pango_language_from_string(const char *);
extern void pango_context_set_base_dir(PangoContext *, PangoDirection);
extern void pango_context_set_base_gravity(PangoContext *, PangoGravity);
extern void pango_context_set_gravity_hint(PangoContext *, PangoGravityHint);
extern PangoLayout *pango_layout_new(PangoContext *);
extern void pango_layout_set_auto_dir(PangoLayout *, int);
extern void pango_layout_set_ellipsize(PangoLayout *, PangoEllipsizeMode);
extern void pango_layout_set_justify(PangoLayout *, int);
extern void pango_layout_set_single_paragraph_mode(PangoLayout *, int);
extern void pango_layout_set_wrap(PangoLayout *, PangoWrapMode);
extern void pango_layout_set_indent(PangoLayout *, int);
extern void pango_layout_set_alignment(PangoLayout *, PangoAlignment);
extern PangoFontDescription *pango_font_description_new();
extern PangoFontDescription *pango_font_description_from_string(const char *);
extern void pango_font_description_set_size(PangoFontDescription *, int);
extern void pango_layout_set_font_description(PangoLayout *, PangoFontDescription *);
extern void pango_font_description_free(PangoFontDescription *);
extern int pango_parse_markup(const char *, int, unsigned int, void *, void *, void *, GError **);
extern void pango_layout_set_text(PangoLayout *, const char *, int);
extern void pango_layout_set_markup(PangoLayout *, const char *, int);
extern void pango_layout_context_changed(PangoLayout *);
extern void pango_layout_get_extents(PangoLayout *, PangoRectangle *, PangoRectangle *);
extern void pango_layout_set_width(PangoLayout *, int);
extern void pango_layout_set_height(PangoLayout *, int);
extern void g_object_unref(void *);
extern cairo_surface_t *cairo_image_surface_create_for_data(unsigned char *, cairo_format_t, int, int, int);
extern cairo_t *cairo_create(cairo_surface_t *);
extern void cairo_set_operator(cairo_t *, cairo_operator_t);
extern void cairo_paint(cairo_t *);
extern void cairo_translate(cairo_t *, double, double);
extern void cairo_set_source_rgba(cairo_t *, double, double, double, double);
extern void pango_cairo_show_layout(cairo_t *, PangoLayout *);
extern void cairo_destroy(cairo_t *);
extern void cairo_surface_destroy(cairo_surface_t *);
extern size_t cairo_format_stride_for_width(cairo_format_t, int);

extern void *LogMagickEvent(int, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
extern void ResetImagePage(Image *, const char *);
extern const char *GetImageOption(const ImageInfo *, const char *);
extern char *InterpretImageProperties(ImageInfo *, Image *, const char *, ExceptionInfo *);
extern void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
extern char *DestroyString(char *);
extern void SetImageBackgroundColor(Image *, ExceptionInfo *);
extern DrawInfo *CloneDrawInfo(const ImageInfo *, DrawInfo *);
extern DrawInfo *DestroyDrawInfo(DrawInfo *);
extern MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
extern MemoryInfo *AcquireVirtualMemory(size_t, size_t);
extern void *GetVirtualMemoryBlob(MemoryInfo *);
extern MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
extern Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern int SyncAuthenticPixels(Image *, ExceptionInfo *);
extern void GetPixelInfo(Image *, PixelInfo *);
extern void CompositePixelOver(Image *, PixelInfo *, double, Quantum *, double, Quantum *);
extern double PerceptibleReciprocal(double);
extern int SetImageProgress(Image *, int, MagickOffsetType, size_t);
extern Image *GetFirstImageInList(Image *);
extern Image *DestroyImageList(Image *);
extern void ThrowReaderException(int, const char *);
extern void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
extern int IsStringTrue(const char *);
extern int ParseAbsoluteGeometry(const char *, RectangleInfo *);