#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <stdint.h>

typedef long ssize_t;

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _MngInfo MngInfo;
typedef struct _PixelPacket PixelPacket;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    CoderEvent
} LogEventType;

typedef enum {
    LoadImagesTag
} ProgressMonitorTag;

typedef enum {
    PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
    NoInterlace,
    PNGInterlace
} InterlaceType;

typedef enum {
    WriteBinaryBlobMode
} OpenBlobMode;

typedef enum {
    PNG_RESOLUTION_METER
} PNGResolutionType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ErrorType;

typedef unsigned char png_byte;
typedef uint32_t png_uint_32;
typedef unsigned int uInt;

typedef struct {
    float x, y;
} PointInfo;

typedef struct {
    PointInfo red_primary;
    PointInfo green_primary;
    PointInfo blue_primary;
    PointInfo white_point;
} ChromaticityInfo;

typedef struct {
    ssize_t x, y;
    size_t width, height;
} RectangleInfo;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
} ColorPacket;

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
    char *description;
} ExceptionInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    RectangleInfo page;
    ChromaticityInfo chromaticity;
    ColorPacket background_color;
    float gamma;
    float x_resolution;
    float y_resolution;
    ResolutionType units;
    int rendering_intent;
    InterlaceType interlace;
    MagickBooleanType matte;
    char filename[4096];
    ExceptionInfo exception;
    void *blob;
} Image;

typedef struct _ImageInfo {
    char filename[4096];
    MagickBooleanType ping;
} ImageInfo;

typedef struct _MngInfo {
    Image *image;
    size_t mng_width;
    size_t mng_height;
    int mng_type;
    ssize_t x_off[1];
    ssize_t y_off[1];
    int object_id;
    int image_found;
} MngInfo;

typedef struct _PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
} PixelPacket;

#define MaxTextExtent 4096
#define PNG_UINT_31_MAX 0x7fffffffL
#define OpaqueOpacity 0
#define QuantumRange 255
#define SEEK_SET 0

static const char mng_JHDR[4] = {'J','H','D','R'};
static const char mng_JDAT[4] = {'J','D','A','T'};
static const char mng_JdAA[4] = {'J','d','A','A'};
static const char mng_IDAT[4] = {'I','D','A','T'};
static const char mng_JDAA[4] = {'J','D','A','A'};
static const char mng_JSEP[4] = {'J','S','E','P'};
static const char mng_bKGD[4] = {'b','K','G','D'};
static const char mng_gAMA[4] = {'g','A','M','A'};
static const char mng_cHRM[4] = {'c','H','R','M'};
static const char mng_sRGB[4] = {'s','R','G','B'};
static const char mng_oFFs[4] = {'o','F','F','s'};
static const char mng_pHYs[4] = {'p','H','Y','s'};
static const char mng_IEND[4] = {'I','E','N','D'};
static const char mng_IHDR[4] = {'I','H','D','R'};

unsigned long crc32(unsigned long, const unsigned char *, unsigned int);
unsigned char ScaleCharToQuantum(unsigned char);
unsigned char GetPixelRed(const PixelPacket *);
unsigned char GetPixelOpacity(const PixelPacket *);
void SetPixelOpacity(PixelPacket *, unsigned char);
void SetPixelAlpha(PixelPacket *, unsigned char);
int Magick_RenderingIntent_from_PNG_RenderingIntent(int);
long mng_get_long(const unsigned char *);