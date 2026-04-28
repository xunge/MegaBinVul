#include <assert.h>
#include <string.h>

typedef unsigned int MagickBooleanType;

#define MagickCoreSignature 0x12345678
#define MagickPathExtent 4096
#define MagickFalse 0
#define MagickTrue 1
#define WriteBinaryBlobMode 1

enum {
    TraceEvent,
    CorruptImageError,
    ResourceLimitError
};

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _MagickInfo MagickInfo;

struct _ImageInfo {
    unsigned int signature;
    char *magick;
    char *filename;
};

struct _Image {
    unsigned int signature;
    MagickBooleanType debug;
    char *filename;
    char *magick;
};

struct _ExceptionInfo {
    int severity;
    char *reason;
};

struct _MagickInfo {
    char *name;
    char *mime_type;
};

static void *RelinquishMagickMemory(void *);
static char *DestroyString(char *);
static ImageInfo *DestroyImageInfo(ImageInfo *);
static Image *DestroyImage(Image *);
static void ThrowWriterException(int, const char *);
static int LocaleCompare(const char *, const char *);
static void *ImageToBlob(const ImageInfo *, Image *, size_t *, ExceptionInfo *);
static char *Base64Encode(const unsigned char *, size_t, size_t *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static void WriteBlobString(Image *, const char *);
static int FormatLocaleString(char *, size_t, const char *, ...);
static const char *GetMagickMimeType(const MagickInfo *);
static const MagickInfo *GetMagickInfo(const char *, ExceptionInfo *);
static ImageInfo *CloneImageInfo(const ImageInfo *);
static int SetImageInfo(ImageInfo *, int, ExceptionInfo *);
static Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
static void LogMagickEvent(int, const char *, const char *, ...);
static const char *GetMagickModule(void);
static char *CopyMagickString(char *, const char *, size_t);