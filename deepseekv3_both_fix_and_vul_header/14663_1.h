#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define ReadBinaryBlobMode 0
#define FileOpenError 0
#define TraceEvent 0

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;

typedef enum {
    MagickTrue = 1
} MagickBooleanType;

struct _Image {
    size_t columns;
    size_t rows;
    struct {
        double x;
    } resolution;
    char filename[MagickPathExtent];
    char magick_filename[MagickPathExtent];
    char magick[MagickPathExtent];
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char filename[MagickPathExtent];
    int orientation;
    double x;
};

struct _ExceptionInfo {
    unsigned long signature;
};

static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception);
static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception);
static Image *DestroyImageList(Image *image);
static void LogMagickEvent(int event, const char *module, const char *format, ...);
static const char *GetMagickModule(void);
static void ThrowImageException(int error, const char *reason);
static int AcquireUniqueFileResource(char *filename);
static size_t WriteLSBLong(FILE *file, size_t value);
static int ReadBlobByte(Image *image);
static MagickBooleanType CloseBlob(Image *image);
static Image *DestroyImage(Image *image);
static ImageInfo *CloneImageInfo(ImageInfo *image_info);
static void FormatLocaleString(char *str, size_t size, const char *format, ...);
static Image *ReadTIFFImage(ImageInfo *image_info, ExceptionInfo *exception);
static ImageInfo *DestroyImageInfo(ImageInfo *image_info);
static void CopyMagickString(char *dst, const char *src, size_t size);
static void RelinquishUniqueFileResource(const char *filename);