#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef int MagickBooleanType;
typedef unsigned int MagickSizeType;
typedef long ssize_t;

#define MagickCoreSignature 0xABACADABUL
#define MagickFalse 0
#define MagickTrue 1
#define ResourceLimitError 0
#define CorruptImageError 0
#define FileOpenError 0
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define MagickPathExtent 4096

struct _Image {
    char filename[MagickPathExtent];
    char magick[MagickPathExtent];
    unsigned int signature;
    void *blob;
    size_t blob_size;
};

struct _ImageInfo {
    char filename[MagickPathExtent];
    unsigned int signature;
    MagickBooleanType debug;
    void *blob;
    size_t blob_size;
};

struct _ExceptionInfo {
    unsigned int signature;
};

static Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static size_t GetBlobSize(Image *);
static void *AcquireQuantumMemory(size_t, size_t);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static int CloseBlob(Image *);
static int LocaleNCompare(const char *, const char *, size_t);
static unsigned char *SFWScan(unsigned char *, unsigned char *, const unsigned char *, size_t);
static void TranslateSFWMarker(unsigned char *);
static void *CopyMagickMemory(void *, const void *, size_t);
static void *RelinquishMagickMemory(void *);
static ImageInfo *CloneImageInfo(const ImageInfo *);
static void SetImageInfoBlob(ImageInfo *, void *, size_t);
static int AcquireUniqueFileResource(char *);
static FILE *fopen_utf8(const char *, const char *);
static void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
static char *GetExceptionMessage(int);
static void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
static char *DestroyString(char *);
static Image *ReadImage(ImageInfo *, ExceptionInfo *);
static void RelinquishUniqueFileResource(const char *);
static ImageInfo *DestroyImageInfo(ImageInfo *);
static void DuplicateBlob(Image *, Image *);
static Image *FlipImage(Image *, ExceptionInfo *);
static Image *GetFirstImageInList(Image *);
static void ThrowReaderException(int, const char *);
static void LogMagickEvent(int, const char *, const char *, ...);
static const char *GetMagickModule(void);
static void CopyMagickString(char *, const char *, size_t);
static Image *DestroyImage(Image *);