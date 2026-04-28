#include <assert.h>
#include <string.h>

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef long ssize_t;

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
} PixelPacket;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t colors;
    unsigned depth;
    int storage_class;
    PixelPacket *colormap;
    struct _Image *next;
} Image;

#define MagickCoreSignature 0x1234
#define MagickFalse 0
#define MagickTrue 1
#define MagickPathExtent 4096
#define ReadBinaryBlobMode 0
#define PseudoClass 0
#define TraceEvent 0
#define ResourceLimitError 1
#define CorruptImageError 2

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void *AcquireQuantumMemory(size_t, size_t);
char *ReadBlobString(Image *, char *);
void *ResizeQuantumMemory(void *, size_t, size_t);
void *RelinquishMagickMemory(void *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
MagickBooleanType sixel_decode(Image *, unsigned char *, unsigned char **, size_t *, size_t *, unsigned char **, size_t *, ExceptionInfo *);
void ThrowReaderException(int, const char *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
Quantum ScaleCharToQuantum(unsigned char);
void SetPixelIndex(Image *, ssize_t, Quantum *);
size_t GetPixelChannels(Image *);