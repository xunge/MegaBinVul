#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _MngInfo MngInfo;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    TraceEvent,
    CoderEvent
} MagickEventType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    FileOpenError,
    CorruptImageError,
    ResourceLimitError
} ExceptionType;

typedef enum {
    RGBColorspace
} ColorspaceType;

#define MagickSignature 0x12345678
#define MaxTextExtent 256

struct _Image {
    unsigned long columns;
    unsigned long rows;
    ColorspaceType colorspace;
    double gamma;
    struct {
        struct {
            float x;
            float y;
        } red_primary;
        struct {
            float x;
            float y;
        } green_primary;
        struct {
            float x;
            float y;
        } blue_primary;
        struct {
            float x;
            float y;
        } white_point;
    } chromaticity;
    struct {
        double width;
        double height;
        double x;
        double y;
    } page;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _MngInfo {
    Image *image;
};

extern void *AcquireMagickMemory(size_t);
extern void ResetMagickMemory(void *, int, size_t);
extern Image *AcquireImage(const ImageInfo *);
extern MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
extern ssize_t ReadBlob(Image *, size_t, unsigned char *);
extern void ThrowReaderException(ExceptionType, const char *);
extern MagickBooleanType LogMagickEvent(MagickEventType, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern Image *ReadOnePNGImage(MngInfo *, const ImageInfo *, ExceptionInfo *);
extern MngInfo *MngInfoFreeStruct(MngInfo *);
extern MagickBooleanType CloseBlob(Image *);
extern MagickBooleanType IssRGBColorspace(ColorspaceType);
extern void SetImageColorspace(Image *, ColorspaceType);