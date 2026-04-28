#include <assert.h>
#include <string.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    TraceEvent,
    CoderEvent
} LogEventType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ExceptionType;

#define MagickSignature 0x12345678
#define MaxTextExtent 2048

typedef struct _Image {
    unsigned long columns;
    unsigned long rows;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    char *filename;
    char *magick;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _MngInfo {
    Image *image;
} MngInfo;

extern void *AcquireMagickMemory(size_t);
extern void ResetMagickMemory(void *, int, size_t);
extern size_t ReadBlob(Image *, size_t, unsigned char *);
extern int LocaleCompare(const char *, const char *);
extern MagickBooleanType LogMagickEvent(LogEventType, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern Image *AcquireImage(const ImageInfo *);
extern MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
extern void ThrowReaderException(ExceptionType, const char *);
extern Image *ReadOneJNGImage(MngInfo *, const ImageInfo *, ExceptionInfo *);
extern MngInfo *MngInfoFreeStruct(MngInfo *);
extern void CloseBlob(Image *);