#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef size_t ssize_t;

#define MagickFalse 0
#define MagickTrue 1
#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define WriteBinaryBlobMode 1
#define MSBEndian 1
#define TraceEvent 1
#define SaveImagesTag "SaveImages"
#define CorruptImageError 1
#define CacheError 1

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _ChromaticityInfo {
    PointInfo red_primary;
    PointInfo green_primary;
    PointInfo blue_primary;
    PointInfo white_point;
} ChromaticityInfo;

typedef struct _RectangleInfo {
    double width;
    double height;
    double x;
    double y;
} RectangleInfo;

typedef struct _OffsetInfo {
    long x;
    long y;
} OffsetInfo;

typedef struct _ResolutionInfo {
    double x;
    double y;
} ResolutionInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    int debug;
    int adjoin;
} ImageInfo;

typedef struct _StringInfo {
    size_t length;
    unsigned char *datum;
} StringInfo;

typedef struct _Image {
    unsigned long signature;
    int debug;
    char *filename;
    int storage_class;
    size_t colors;
    size_t depth;
    size_t number_channels;
    size_t number_meta_channels;
    size_t columns;
    size_t rows;
    int type;
    int colorspace;
    int intensity;
    int endian;
    int compression;
    double quality;
    int units;
    ResolutionInfo resolution;
    RectangleInfo page;
    OffsetInfo tile_offset;
    size_t scene;
    double iterations;
    double delay;
    int ticks_per_second;
    int gravity;
    int dispose;
    int rendering_intent;
    double gamma;
    ChromaticityInfo chromaticity;
    int orientation;
    void *profiles;
    char *montage;
    char *directory;
    int alpha_trait;
    int (*progress_monitor)(const char*, MagickOffsetType, size_t, void*);
    void *client_data;
    struct _Image *next;
    struct _Image *previous;
    struct {
        double red;
        double green;
        double blue;
    } *colormap;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef int (*MagickProgressMonitor)(const char*, MagickOffsetType, size_t, void*);

enum {
    UndefinedType,
    UndefinedPixelIntensityMethod,
    UndefinedEndian,
    UndefinedCompression,
    UndefinedResolution,
    UndefinedTicksPerSecond,
    UndefinedGravity,
    UndefinedDispose,
    UndefinedIntent,
    UndefinedOrientation,
    PseudoClass,
    DirectClass
};

enum {
    MagickClassOptions,
    MagickPixelTraitOptions,
    MagickTypeOptions,
    MagickColorspaceOptions,
    MagickPixelIntensityOptions,
    MagickEndianOptions,
    MagickCompressOptions,
    MagickResolutionOptions,
    MagickGravityOptions,
    MagickDisposeOptions,
    MagickIntentOptions,
    MagickOrientationOptions
};