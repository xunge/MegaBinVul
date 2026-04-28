#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <sys/types.h>

#define MagickExport
#define MagickCoreSignature 0x12345678
#define MagickFalse 0
#define MagickTrue 1
#define MagickPathExtent 4096

enum {
    TraceEvent,
    CorruptImageError,
    ResourceLimitError
};

typedef unsigned char MagickBooleanType;

typedef enum {
    UndefinedClass,
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    UndefinedColorspace,
    RGBColorspace,
    GRAYColorspace,
    TransparentColorspace,
    OHTAColorspace,
    XYZColorspace,
    YCbCrColorspace,
    YCCColorspace,
    YIQColorspace,
    YPbPrColorspace,
    YUVColorspace,
    CMYKColorspace,
    sRGBColorspace,
    HSBColorspace,
    HSLColorspace,
    HWBColorspace,
    LABColorspace,
    CineonLogRGBColorspace,
    Rec601YCbCrColorspace,
    Rec709YCbCrColorspace,
    LogColorspace,
    CMYColorspace,
    LuvColorspace,
    HCLColorspace,
    LCHColorspace,
    LMSColorspace,
    LCHabColorspace,
    LCHuvColorspace,
    scRGBColorspace,
    HSIColorspace,
    HSVColorspace,
    HCLpColorspace,
    YDbDrColorspace,
    xyYColorspace,
    LinearGRAYColorspace
} ColorspaceType;

typedef enum {
    UndefinedAlphaChannel,
    ActivateAlphaChannel,
    BackgroundAlphaChannel,
    CopyAlphaChannel,
    DeactivateAlphaChannel,
    ExtractAlphaChannel,
    OpaqueAlphaChannel,
    ResetAlphaChannel,
    SetAlphaChannel,
    ShapeAlphaChannel,
    TransparentAlphaChannel,
    FlattenAlphaChannel,
    RemoveAlphaChannel
} AlphaChannelType;

typedef enum {
    UndefinedType,
    BilevelType,
    GrayscaleType,
    GrayscaleAlphaType,
    PaletteType,
    PaletteAlphaType,
    TrueColorType,
    TrueColorAlphaType,
    ColorSeparationType,
    ColorSeparationAlphaType,
    OptimizeType,
    PaletteBilevelAlphaType
} ImageType;

typedef struct _PixelInfo {
    double red;
    double green;
    double blue;
    double alpha;
    double black;
    size_t count;
} PixelInfo;

typedef struct _ImageInfo {
    size_t signature;
    // Other ImageInfo members
} ImageInfo;

typedef struct _TimerInfo {
    size_t signature;
    // Other TimerInfo members
} TimerInfo;

typedef struct _PixelChannelMap {
    size_t signature;
    // Other PixelChannelMap members
} PixelChannelMap;

typedef struct _SemaphoreInfo {
    size_t signature;
    // Other SemaphoreInfo members
} SemaphoreInfo;

typedef struct _PixelCache {
    size_t signature;
    // Other PixelCache members
} PixelCache;

typedef struct _BlobInfo {
    size_t signature;
    // Other BlobInfo members
} BlobInfo;

typedef struct _ExceptionInfo {
    size_t signature;
} ExceptionInfo;

typedef struct _Image {
    size_t signature;
    MagickBooleanType debug;
    char filename[MagickPathExtent];
    size_t columns;
    size_t rows;
    ClassType storage_class;
    size_t number_channels;
    size_t number_meta_channels;
    size_t metacontent_extent;
    ColorspaceType colorspace;
    size_t read_mask;
    size_t write_mask;
    AlphaChannelType alpha_trait;
    MagickBooleanType dither;
    size_t colors;
    PixelInfo *colormap;
    ImageInfo *image_info;
    TimerInfo timer;
    void *ascii85;
    size_t magick_columns;
    size_t magick_rows;
    ImageType type;
    size_t channel_mask;
    PixelChannelMap *channel_map;
    char magick_filename[MagickPathExtent];
    char magick[MagickPathExtent];
    void (*progress_monitor)(void);
    void *client_data;
    size_t reference_count;
    struct _Image *next;
    struct _Image *previous;
    struct _Image *list;
    void *blob;
    MagickBooleanType ping;
    SemaphoreInfo *semaphore;
    char *montage;
    char *directory;
    PixelCache *cache;
    struct {
        size_t width;
        ssize_t x;
        size_t height;
        ssize_t y;
    } page;
    struct {
        ssize_t x;
        ssize_t y;
    } tile_offset;
} Image;

void *AcquireMagickMemory(size_t);
void *AcquireQuantumMemory(size_t,size_t);
void *ResetMagickMemory(void *,int,size_t);
void *CopyMagickMemory(void *,const void *,size_t);
void LogMagickEvent(int,const char *,const char *,...);
void ThrowMagickException(ExceptionInfo *,const char *,int,const char *,const char *,...);
void ThrowImageException(int,const char *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void CloneImageProfiles(Image *,const Image *);
void CloneImageProperties(Image *,const Image *);
void CloneImageArtifacts(Image *,const Image *);
void GetTimerInfo(TimerInfo *);
void Ascii85Initialize(Image *);
PixelChannelMap *ClonePixelChannelMap(const PixelChannelMap *);
char *CloneString(char **,const char *);
void *ReferenceBlob(void *);
void *CloneBlobInfo(BlobInfo *);
Image *NewImageList(void);
int IsEventLogging(void);
SemaphoreInfo *AcquireSemaphoreInfo(void);
PixelCache *ReferencePixelCache(PixelCache *);
PixelCache *ClonePixelCache(PixelCache *);
const char *GetMagickModule(void);
int CopyMagickString(char *,const char *,size_t);