#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

typedef enum _MagickBooleanType { MagickFalse, MagickTrue } MagickBooleanType;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    double x_resolution;
    double y_resolution;
    char *filename;
    ExceptionInfo exception;
    unsigned char *blob;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
} ImageInfo;

typedef struct _DrawInfo {
    struct {
        double sx;
        double sy;
    } affine;
    char *primitive;
} DrawInfo;

typedef struct _SegmentInfo {
    double x1;
    double y1;
    double x2;
    double y2;
} SegmentInfo;

#define MagickSignature 0xabacadabUL
#define MaxTextExtent 4096
#define TraceEvent 0
#define OptionError 0
#define ResourceLimitError 0
#define ReadBinaryBlobMode 0