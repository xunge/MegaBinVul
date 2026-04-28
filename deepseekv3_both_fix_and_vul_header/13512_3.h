#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    CMYKColorspace
} ColorspaceType;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    FileOpenError,
    DelegateError
} ExceptionType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    RhoValue,
    SigmaValue
} GeometryFlags;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
} RectangleInfo;

typedef struct _SegmentInfo {
    double x1;
    double y1;
    double x2;
    double y2;
} SegmentInfo;

typedef struct _GeometryInfo {
    double rho;
    double sigma;
} GeometryInfo;

typedef struct _ResolutionInfo {
    double x;
    double y;
} ResolutionInfo;

typedef struct _Image {
    ResolutionInfo resolution;
    ColorspaceType colorspace;
    char *filename;
    char *magick;
    size_t magick_columns;
    size_t magick_rows;
    size_t columns;
    size_t rows;
    RectangleInfo page;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    char *filename;
    char *page;
    MagickBooleanType monochrome;
    MagickBooleanType ping;
    unsigned long number_scenes;
    unsigned long scene;
    char *scenes;
    char magick[1];
    MagickBooleanType antialias;
    int verbose;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _DelegateInfo {
    const char *commands;
} DelegateInfo;

typedef unsigned int MagickStatusType;

#define MagickCoreSignature 0x12345678
#define MagickPathExtent 4096
#define DefaultResolution 72.0
#define PSDensityGeometry "72x72"
#define PSPageGeometry "612x792"