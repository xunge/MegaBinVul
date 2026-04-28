#include <assert.h>
#include <stddef.h>

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef size_t ssize_t;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    int storage_class;
} Image;

typedef struct _RGBTRIPLE {
    unsigned char rgbtBlue;
    unsigned char rgbtGreen;
    unsigned char rgbtRed;
} RGBTRIPLE;

#define MagickCoreSignature 0x1234
#define MagickFalse 0
#define DirectClass 1
#define OpaqueAlpha 255
#define TraceEvent 1
#define CoderError 1

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
void AppendImageToList(Image **, Image *);
Image *DestroyImageList(Image *);
const char *GetImageOption(const ImageInfo *, const char *);
const char *GetMagickModule(void);
int IsStringTrue(const char *);
void *LogMagickEvent(int, const char *, const char *, ...);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void *ResetMagickMemory(void *, int, size_t);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
int GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
Quantum ScaleCharToQuantum(unsigned char);
void ThrowReaderException(int, const char *);