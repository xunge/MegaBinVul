#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

typedef unsigned char Quantum;
typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef unsigned int uInt;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef struct _PointInfo {
    float x;
    float y;
} PointInfo;

typedef struct _ChromaticityInfo {
    PointInfo red_primary;
    PointInfo green_primary;
    PointInfo blue_primary;
    PointInfo white_point;
} ChromaticityInfo;

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} PixelTrait;

typedef enum {
    NoInterlace,
    PNGInterlace
} InterlaceType;

typedef enum {
    PixelsPerCentimeterResolution
} ResolutionType;

typedef struct _Image {
    size_t rows;
    size_t columns;
    Quantum *pixels;
    char filename[4096];
    struct {
        ssize_t x;
        ssize_t y;
        size_t width;
        size_t height;
    } page;
    struct {
        double x;
        double y;
    } resolution;
    struct {
        float red;
        float green;
        float blue;
    } background_color;
    ChromaticityInfo chromaticity;
    float gamma;
    int rendering_intent;
    InterlaceType interlace;
    ResolutionType units;
    PixelTrait alpha_trait;
    struct _Image *next;
} Image;

typedef struct _ImageInfo {
    char filename[4096];
    MagickBooleanType ping;
} ImageInfo;

typedef struct _MngInfo {
    Image *image;
    png_uint_32 mng_width;
    png_uint_32 mng_height;
    int mng_type;
    ssize_t x_off[1];
    ssize_t y_off[1];
    int object_id;
    int image_found;
} MngInfo;

typedef struct _ExceptionInfo {
    int code;
} ExceptionInfo;

typedef enum {
    CoderEvent
} LogEventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ErrorType;

typedef enum {
    LoadImagesTag
} ProgressMonitorType;

typedef enum {
    WriteBinaryBlobMode
} AccessMode;

typedef enum {
    OpaqueAlpha
} AlphaType;

typedef enum {
    PNG_RESOLUTION_METER
} PNGResolutionType;

#define MagickPathExtent 4096
#define PNG_UINT_31_MAX 0x7fffffffL

static const char mng_JHDR[] = "JHDR";
static const char mng_JDAT[] = "JDAT";
static const char mng_JdAA[] = "JdAA";
static const char mng_IDAT[] = "IDAT";
static const char mng_JDAA[] = "JDAA";
static const char mng_JSEP[] = "JSEP";
static const char mng_bKGD[] = "bKGD";
static const char mng_gAMA[] = "gAMA";
static const char mng_cHRM[] = "cHRM";
static const char mng_sRGB[] = "sRGB";
static const char mng_oFFs[] = "oFFs";
static const char mng_pHYs[] = "pHYs";
static const char mng_IEND[] = "IEND";
static const char mng_IHDR[] = "IHDR";

static Quantum *GetAuthenticPixelQueue(Image *);
static size_t GetPixelChannels(Image *);