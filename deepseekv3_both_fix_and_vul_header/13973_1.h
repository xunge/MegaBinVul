#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

#define MagickCoreSignature 0x1234
#define MagickPathExtent 4096

enum {
    TopRightOrientation,
    BottomRightOrientation,
    BottomLeftOrientation,
    LeftTopOrientation,
    RightTopOrientation,
    RightBottomOrientation,
    LeftBottomOrientation
};

typedef enum {
    TraceEvent
} LogEventType;

#define WriteBinaryBlobMode 0

typedef struct _ImageInfo {
    unsigned long signature;
    char *density;
    char filename[MagickPathExtent];
    char magick[MagickPathExtent];
    int debug;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    int debug;
    char filename[MagickPathExtent];
    unsigned long columns;
    unsigned long rows;
    int orientation;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _GeometryInfo {
    double rho;
} GeometryInfo;

ssize_t WriteCALSRecord(Image *, const char *);
void *RelinquishMagickMemory(void *);
void *ResetMagickMemory(void *, int, size_t);
void *CopyMagickString(char *, const char *, size_t);
void *ParseGeometry(const char *, GeometryInfo *);
ImageInfo *CloneImageInfo(const ImageInfo *);
Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
unsigned char *ImageToBlob(const ImageInfo *, Image *, size_t *, ExceptionInfo *);
Image *DestroyImage(Image *);
ImageInfo *DestroyImageInfo(ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
ssize_t WriteBlob(Image *, size_t, const unsigned char *);
MagickBooleanType CloseBlob(Image *);
void LogMagickEvent(LogEventType, const char *, const char *, ...);
char *GetMagickModule(void);
int FormatLocaleString(char *, size_t, const char *, ...);