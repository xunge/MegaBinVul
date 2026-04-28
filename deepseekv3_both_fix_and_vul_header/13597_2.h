#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef int64_t MagickOffsetType;
typedef float Quantum;

typedef enum {
    CSM1,
    CSM2
} CSM;

typedef enum {
    RGBA16,
    RGB24,
    RGBA32
} PixelFormat;

typedef enum {
    ResourceLimitError,
    CorruptImageError
} ExceptionType;

typedef enum {
    LoadImageTag
} ProgressTag;

typedef struct _PixelInfo {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum alpha;
} PixelInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    size_t colors;
    struct _Image *previous;
    PixelInfo *colormap;
} Image;

typedef struct _ImageInfo {
    const char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
    int dummy;
} ExceptionInfo;

typedef struct _TIM2ImageHeader {
    size_t header_size;
    size_t clut_color_count;
    size_t clut_size;
    unsigned char clut_type;
} TIM2ImageHeader;

MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType DiscardBlobBytes(Image *, size_t);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
void ThrowBinaryException(ExceptionType, const char *, const char *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
ssize_t ReadBlob(Image *, size_t, void *);
void SetPixelIndex(Image *, unsigned char, Quantum *);
size_t GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ProgressTag, MagickOffsetType, size_t);
void SyncImage(Image *, ExceptionInfo *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
Quantum GetChannelValue(unsigned int, int, PixelFormat);
Quantum GetAlpha(unsigned int, PixelFormat);
void deshufflePalette(Image *, PixelInfo *);