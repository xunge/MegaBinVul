#include <assert.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>

#define MagickExport

typedef unsigned int MagickBooleanType;
typedef unsigned int MagickStatusType;
typedef unsigned int ColorspaceType;
typedef unsigned int CompositeOperator;
typedef unsigned int CompressionType;
typedef unsigned int DisposeType;
typedef unsigned int GravityType;
typedef unsigned int PixelIntensityMethod;
typedef unsigned int RenderingIntent;
typedef unsigned int PixelInterpolateMethod;
typedef unsigned int ResolutionType;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    void *properties;
    size_t delay;
    ssize_t ticks_per_second;
    struct {
        double x;
        double y;
    } resolution;
    unsigned long depth;
    DisposeType dispose;
    double gamma;
    GravityType gravity;
    PixelIntensityMethod intensity;
    RenderingIntent rendering_intent;
    PixelInterpolateMethod interpolate;
    unsigned long iterations;
    ResolutionType units;
    CompositeOperator compose;
    CompressionType compression;
    struct {
        double rho;
        double sigma;
    } page;
    struct {
        double rho;
        double sigma;
    } tile_offset;
} Image;

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _SplayTreeInfo SplayTreeInfo;
typedef struct _StringInfo StringInfo;
typedef struct _ImageInfo ImageInfo;

typedef struct _GeometryInfo {
    double rho;
    double sigma;
} GeometryInfo;

#define MagickCoreSignature 0
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define AllCompliance 0
#define OptionError 0
#define MagickPathExtent 4096
#define GreaterValue 0x01
#define LessValue 0x02
#define SigmaValue 0x04

#define CompareSplayTreeString NULL
#define RelinquishMagickMemory NULL
#define NewSplayTree(a,b,c) NULL
#define DeleteImageProperty(a,b) 0
#define LogMagickEvent(a,b,c,d) 0
#define GetMagickModule() NULL
#define ThrowMagickException(a,b,c,d,e,f) 0
#define LocaleNCompare(a,b,c) 0
#define LocaleCompare(a,b) 0
#define QueryColorCompliance(a,b,c,d) 0
#define ParseCommandOption(a,b,c) 0
#define SetImageColorspace(a,b,c) 0
#define ParseGeometry(a,b) 0
#define StringToUnsignedLong(a) 0
#define StringToDouble(a,b) 0.0
#define GetPageGeometry(a) NULL
#define ParseAbsoluteGeometry(a,b) 0
#define DestroyString(a) NULL
#define AcquireImageInfo() NULL
#define CopyMagickString(a,b,c) 0
#define SetImageInfo(a,b,c) 0
#define FileToStringInfo(a,b,c) NULL
#define SetImageProfile(a,b,c,d) 0
#define DestroyImageInfo(a) NULL
#define AddValueToSplayTree(a,b,c) 0
#define ConstantString(a) NULL