#include <stdio.h>
#include <stddef.h>
#include <math.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    UndefinedPixelTrait,
    AlphaPixelTrait
} PixelTrait;

typedef enum {
    UndefinedColorspace,
    GRAYColorspace
} ColorspaceType;

typedef enum {
    UndefinedClass,
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    UndefinedCompression,
    NoCompression
} CompressionType;

typedef enum {
    UndefinedDispose,
    NoneDispose
} DisposeType;

typedef enum {
    UndefinedResolution,
    PixelsPerInchResolution
} ResolutionType;

typedef struct _ExceptionInfo {
    int severity;
} ExceptionInfo;

typedef struct _ImageInfo {
    char *filename;
    char *unique;
    MagickBooleanType debug;
    unsigned long scene;
    unsigned long number_scenes;
} ImageInfo;

typedef struct _Image {
    char *filename;
    char *magick;
    char *magick_filename;
    MagickBooleanType debug;
    size_t extent;
    unsigned long columns;
    unsigned long rows;
    unsigned long magick_columns;
    unsigned long magick_rows;
    unsigned long depth;
    unsigned long delay;
    unsigned long scene;
    ClassType storage_class;
    ColorspaceType colorspace;
    PixelTrait alpha_trait;
    CompressionType compression;
    DisposeType dispose;
    unsigned long quality;
    ResolutionType units;
    struct {
        double x;
        double y;
    } resolution;
    struct {
        double width;
        double height;
        double x;
        double y;
    } page;
} Image;

typedef struct {
    double width;
    double height;
    double x;
    double y;
} RectangleInfo;

#define MagickPathExtent 4096
#define MAGICKCORE_QUANTUM_DEPTH 16
#define MagickEpsilon 1.0E-10

enum {
    TraceEvent,
    OptionWarning
};

enum {
    HeadPath,
    ExtensionPath,
    TailPath,
    BasePath
};

typedef long ssize_t;

extern const void *MagickClassOptions;
extern const void *MagickColorspaceOptions;
extern const void *MagickPixelTraitOptions;
extern const void *MagickCompressOptions;
extern const void *MagickDisposeOptions;
extern const void *MagickResolutionOptions;

const char *GetMagickModule(void);
void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, char);
void LogMagickEvent(int, const char *, const char *, ...);
void FormatMagickSize(size_t, MagickBooleanType, const char *, size_t, char *);
size_t GetBlobSize(Image *);
const char *GetImageProperty(Image *, const char *, ExceptionInfo *);
void GetPathComponent(const char *, int, char *);
void FormatLocaleString(char *, size_t, const char *, ...);
size_t GetNumberColors(Image *, FILE *, ExceptionInfo *);
size_t GetImageListLength(Image *);
size_t GetImageIndexInList(Image *);
const char *CommandOptionToMnemonic(const void *, ssize_t);
MagickBooleanType SetImageGray(Image *, ExceptionInfo *);
RectangleInfo GetImageBoundingBox(Image *, ExceptionInfo *);
MagickBooleanType SignatureImage(Image *, ExceptionInfo *);
void SetImageArtifact(Image *, const char *, const char *);
const char *GetImageArtifact(Image *, const char *);
void SetImageOption(ImageInfo *, const char *, const char *);
const char *GetImageOption(ImageInfo *, const char *);