#include <assert.h>
#include <string.h>

typedef int MagickBooleanType;
typedef unsigned char Quantum;
typedef long ssize_t;

#define MagickCoreSignature 0
#define MagickFalse 0
#define MagickPathExtent 4096
#define ReadBinaryBlobMode 0
#define ResourceLimitError 0
#define CorruptImageError 0
#define PseudoClass 0
#define TraceEvent 0

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
};

struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t colors;
    unsigned depth;
    unsigned storage_class;
    struct _PixelPacket *colormap;
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void *AcquireQuantumMemory(size_t, size_t);
char *ReadBlobString(Image *, char *);
void *ResizeQuantumMemory(void *, size_t, size_t);
void ThrowReaderException(int, const char *);
MagickBooleanType sixel_decode(unsigned char *, unsigned char **, size_t *, size_t *, unsigned char **, size_t *);
void *RelinquishMagickMemory(void *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelIndex(Image *, ssize_t, Quantum *);
size_t GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
void CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
Quantum ScaleCharToQuantum(unsigned char);
void LogMagickEvent(int, const char *, const char *, const char *);
const char *GetMagickModule(void);