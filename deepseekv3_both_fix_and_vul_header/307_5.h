#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _BlobInfo BlobInfo;
typedef struct _RectangleInfo RectangleInfo;
typedef struct _GeometryInfo GeometryInfo;
typedef struct _TimerInfo TimerInfo;
typedef struct _PixelCache PixelCache;
typedef struct _PixelChannelMap PixelChannelMap;
typedef struct _SemaphoreInfo SemaphoreInfo;
typedef struct _ColorInfo ColorInfo;

typedef enum {
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    sRGBColorspace,
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
    HSLColorspace,
    HWBColorspace,
    LABColorspace,
    CineonLogColorspace,
    Rec601LumaColorspace,
    Rec709LumaColorspace,
    LogColorspace,
    CMYColorspace
} ColorspaceType;

typedef enum {
    PerceptualIntent,
    RelativeIntent,
    SaturationIntent,
    AbsoluteIntent
} RenderingIntent;

typedef enum {
    NoInterlace,
    LineInterlace,
    PlaneInterlace,
    PartitionInterlace
} InterlaceType;

typedef enum {
    OverCompositeOp,
    InCompositeOp,
    OutCompositeOp,
    AtopCompositeOp,
    XorCompositeOp,
    PlusCompositeOp,
    MinusCompositeOp,
    AddCompositeOp,
    SubtractCompositeOp,
    DifferenceCompositeOp,
    MultiplyCompositeOp,
    BumpmapCompositeOp,
    CopyCompositeOp,
    CopyRedCompositeOp,
    CopyGreenCompositeOp,
    CopyBlueCompositeOp,
    CopyOpacityCompositeOp,
    ClearCompositeOp,
    DissolveCompositeOp,
    DisplaceCompositeOp,
    ModulateCompositeOp,
    ThresholdCompositeOp,
    NoCompositeOp,
    DarkenCompositeOp,
    LightenCompositeOp,
    HueCompositeOp,
    SaturateCompositeOp,
    ColorizeCompositeOp,
    LuminizeCompositeOp,
    ScreenCompositeOp,
    OverlayCompositeOp,
    CopyCyanCompositeOp,
    CopyMagentaCompositeOp,
    CopyYellowCompositeOp,
    CopyBlackCompositeOp,
    DivideCompositeOp,
    HardLightCompositeOp,
    SoftLightCompositeOp,
    ExclusionCompositeOp,
    ColorDodgeCompositeOp,
    ColorBurnCompositeOp,
    LinearBurnCompositeOp,
    LinearDodgeCompositeOp,
    LinearLightCompositeOp,
    VividLightCompositeOp,
    PinLightCompositeOp,
    HardMixCompositeOp,
    UndefinedCompositeOp
} CompositeOperator;

typedef enum {
    UndefinedDispose,
    NoneDispose,
    BackgroundDispose,
    PreviousDispose
} DisposeType;

typedef enum {
    UndefinedTicksPerSecond = 100
} TicksPerSecondType;

typedef enum {
    UndefinedCompression,
    NoCompression,
    B44ACompression,
    B44Compression,
    BZipCompression,
    DXT1Compression,
    DXT3Compression,
    DXT5Compression,
    FaxCompression,
    Group4Compression,
    JPEGCompression,
    JPEG2000Compression,
    LosslessJPEGCompression,
    LZWCompression,
    RLECompression,
    ZipCompression,
    ZipSCompression,
    PizCompression,
    Pxr24Compression,
    WaveletCompression
} CompressionType;

typedef enum {
    UndefinedEndian,
    LSBEndian,
    MSBEndian
} EndianType;

typedef enum {
    UndefinedUnits,
    PixelsPerInch,
    PixelsPerCentimeter
} ResolutionType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    DefaultChannels,
    ReadChannels,
    WriteChannels,
    AllChannels
} ChannelType;

typedef enum {
    AllCompliance,
    CSSCompliance,
    SVGCompliance,
    X11Compliance,
    XPMCompliance
} ComplianceType;

typedef enum {
    UndefinedQuantum,
    AlphaQuantum,
    BlackQuantum,
    BlueQuantum,
    CMYKQuantum,
    CyanQuantum,
    GrayQuantum,
    GreenQuantum,
    IndexQuantum,
    MagentaQuantum,
    OpacityQuantum,
    RedQuantum,
    RGBQuantum,
    YellowQuantum,
    AllQuantum
} QuantumType;

typedef enum {
    TraceEvent,
    DebugEvent,
    InformEvent,
    WarningEvent,
    ErrorEvent,
    FatalErrorEvent,
    ExceptionEvent,
    ResourceEvent,
    CacheEvent,
    BlobEvent,
    TransformEvent,
    LocaleEvent,
    CoderEvent,
    ModuleEvent,
    WandEvent,
    X11Event,
    ConfigureEvent
} LogEventType;

typedef enum {
    XValue = 0x001,
    XiValue = 0x001,
    YValue = 0x002,
    PsiValue = 0x002,
    WidthValue = 0x004,
    RhoValue = 0x004,
    HeightValue = 0x008,
    SigmaValue = 0x008,
    ChiValue = 0x010,
    XiNegative = 0x020,
    ChiNegative = 0x040,
    PsiNegative = 0x080,
    PercentValue = 0x100,
    AspectValue = 0x200,
    NormalizeValue = 0x200,
    LessValue = 0x400,
    GreaterValue = 0x800,
    MinimumValue = 0x1000,
    AreaValue = 0x2000,
    DecimalValue = 0x4000,
    SeparatorValue = 0x8000,
    AllValues = 0xFFFF
} GeometryFlags;

typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned int MagickStatusType;

#define MagickPathExtent 4096
#define MAGICKCORE_QUANTUM_DEPTH 16
#define MagickCoreSignature 0xabacadabUL

struct _PointInfo {
    double x, y, z;
};

struct _PrimaryInfo {
    double x, y, z;
};

struct _ChromaticityInfo {
    struct _PrimaryInfo red_primary;
    struct _PrimaryInfo green_primary;
    struct _PrimaryInfo blue_primary;
    struct _PrimaryInfo white_point;
};

struct _RectangleInfo {
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
};

struct _GeometryInfo {
    double rho;
    double sigma;
    double xi;
    double psi;
    double chi;
};

struct _ColorInfo {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
};

struct _TimerInfo {
    /* Timer info fields */
};

struct _ImageInfo {
    FILE *file;
    char *filename;
    char *magick;
    char *size;
    char *extract;
    CompressionType compression;
    size_t quality;
    EndianType endian;
    InterlaceType interlace;
    ResolutionType units;
    char *density;
    char *page;
    size_t depth;
    MagickBooleanType dither;
    struct _ColorInfo matte_color;
    struct _ColorInfo background_color;
    struct _ColorInfo border_color;
    struct _ColorInfo transparent_color;
    MagickBooleanType ping;
    void (*progress_monitor)(const char *, const MagickOffsetType, const MagickSizeType, void *);
    void *client_data;
    void *cache;
};

struct _Image {
    char filename[MagickPathExtent];
    char magick_filename[MagickPathExtent];
    char magick[MagickPathExtent];
    size_t columns;
    size_t rows;
    size_t depth;
    ClassType storage_class;
    ColorspaceType colorspace;
    RenderingIntent rendering_intent;
    float gamma;
    struct _ChromaticityInfo chromaticity;
    InterlaceType interlace;
    size_t delay;
    ssize_t ticks_per_second;
    CompositeOperator compose;
    struct _ColorInfo matte_color;
    struct _ColorInfo background_color;
    struct _ColorInfo border_color;
    struct _ColorInfo transparent_color;
    struct _TimerInfo timer;
    PixelCache *cache;
    ChannelType channel_mask;
    PixelChannelMap *channel_map;
    BlobInfo *blob;
    time_t timestamp;
    MagickBooleanType debug;
    size_t reference_count;
    SemaphoreInfo *semaphore;
    unsigned long signature;
    struct _RectangleInfo extract_info;
    struct _RectangleInfo page;
    CompressionType compression;
    size_t quality;
    EndianType endian;
    ResolutionType units;
    struct _PointInfo resolution;
    MagickBooleanType dither;
    MagickBooleanType ping;
    void (*progress_monitor)(const char *, const MagickOffsetType, const MagickSizeType, void *);
    void *client_data;
    size_t offset;
    DisposeType dispose;
};

#define MatteColor "MatteColor"
#define BackgroundColor "BackgroundColor"
#define BorderColor "BorderColor"
#define TransparentColor "TransparentColor"
#define MagickDisposeOptions "Undefined;None;Background;Previous"

#define MagickExport

extern const char *GetMagickModule(void);
extern void *AcquireCriticalMemory(size_t);
extern void LogMagickEvent(LogEventType, const char *, const char *, ...);
extern void CopyMagickString(char *, const char *, const size_t);
extern void QueryColorCompliance(const char *, ComplianceType, ColorInfo *, ExceptionInfo *);
extern void GetTimerInfo(TimerInfo *);
extern PixelCache *AcquirePixelCache(size_t);
extern PixelChannelMap *AcquirePixelChannelMap(void);
extern BlobInfo *CloneBlobInfo(BlobInfo *);
extern MagickBooleanType IsEventLogging(void);
extern SemaphoreInfo *AcquireSemaphoreInfo(void);
extern void SetBlobExempt(Image *, MagickBooleanType);
extern MagickStatusType ParseAbsoluteGeometry(const char *, RectangleInfo *);
extern void Swap(size_t *, size_t *);
extern MagickStatusType ParseGeometry(const char *, GeometryInfo *);
extern char *GetPageGeometry(const char *);
extern char *DestroyString(char *);
extern void ClonePixelCacheMethods(PixelCache *, void *);
extern void SyncImageSettings(const ImageInfo *, Image *, ExceptionInfo *);
extern const char *GetImageOption(const ImageInfo *, const char *);
extern long ParseCommandOption(const char *, MagickBooleanType, const char *);