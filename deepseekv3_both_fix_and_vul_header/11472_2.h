#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1

typedef unsigned int MagickBooleanType;
typedef long ssize_t;

typedef enum {
    UndefinedOrientation,
    TopLeftOrientation,
    TopRightOrientation,
    BottomRightOrientation,
    BottomLeftOrientation,
    LeftTopOrientation,
    RightTopOrientation,
    RightBottomOrientation,
    LeftBottomOrientation
} OrientationType;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char filename[MagickPathExtent];
    char *size;
    char *density;
    OrientationType orientation;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    char filename[MagickPathExtent];
    char magick_filename[MagickPathExtent];
    char magick[MagickPathExtent];
} Image;

#define ReadBinaryBlobMode 0
#define FileOpenError 0
#define TraceEvent 0

static const char* GetMagickModule() { return ""; }
static void LogMagickEvent(int, const char*, const char*, ...) {}

#define LocaleNCompare strncmp
#define OpenBlob(a,b,c,d) MagickFalse
#define CloseBlob(a) (void)0
#define DestroyImageList(a) NULL
#define DestroyImage(a) NULL
#define AcquireImage(a,b) NULL
#define ReadBlob(a,b,c) 0
#define ReadBlobByte(a) EOF
#define ThrowImageException(a,b) (void)0
#define CloneImageInfo(a) NULL
#define SetImageInfoBlob(a,b,c) (void)0
#define FormatLocaleString snprintf
#define CloneString(a,b) 0
#define ReadImage(a,b) NULL
#define CopyMagickString strncpy
#define DestroyImageInfo(a) NULL
#define RelinquishUniqueFileResource(a) unlink(a)
#define AcquireUniqueFileResource(a) (-1)