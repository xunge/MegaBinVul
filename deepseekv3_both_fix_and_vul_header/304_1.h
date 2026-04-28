#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int MagickStatusType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    CMYKColorspace
} ColorspaceType;

typedef enum {
    FileOpenError,
    DelegateError
} ExceptionType;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    SigmaValue
} GeometryFlags;

#define DefaultResolution 72.0
#define MagickCoreSignature 0x12345678
#define MagickPathExtent 4096
#define PSDensityGeometry "72x72"
#define PSPageGeometry "612x792"

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

typedef struct _Image {
    unsigned long signature;
    ColorspaceType colorspace;
    struct {
        double x;
        double y;
    } resolution;
    char *filename;
    char *magick;
    RectangleInfo page;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    char *filename;
    MagickBooleanType debug;
    char *page;
    MagickBooleanType monochrome;
    char *magick;
    unsigned long number_scenes;
    unsigned long scene;
    char *scenes;
    MagickBooleanType antialias;
    MagickBooleanType verbose;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
    ExceptionType type;
    char *reason;
    char *description;
} ExceptionInfo;

typedef struct _DelegateInfo {
    const char *commands;
} DelegateInfo;