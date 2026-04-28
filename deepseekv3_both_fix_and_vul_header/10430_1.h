#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef unsigned char MagickBooleanType;
typedef size_t MagickSizeType;
typedef ssize_t MagickOffsetType;
typedef unsigned long MagickStatusType;

#define MagickFalse 0
#define MagickTrue 1
#define MagickCoreSignature 0xabacadabUL

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef unsigned long Quantum;

#define OpaqueAlpha 1
#define BlendPixelTrait 1
#define LoadImageTag 1
#define LoadImagesTag 2
#define TraceEvent 1
#define CorruptImageError 1
#define ResourceLimitError 1
#define ReadBinaryBlobMode 1

struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    Image *previous;
    Image *next;
    char *filename;
    unsigned alpha_trait;
    unsigned scene;
    Quantum *pixels;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    unsigned number_scenes;
    unsigned scene;
};

struct _ExceptionInfo {
    unsigned long signature;
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned long ReadBlobLSBLong(Image *);
MagickBooleanType EOFBlob(Image *);
void ThrowReaderException(int, const char *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
Quantum ScaleCharToQuantum(unsigned char);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
Quantum GetPixelAlpha(Image *, Quantum *);
size_t GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
void *RelinquishMagickMemory(void *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
Image *GetNextImageInList(Image *);
Image *AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *SyncNextImageInList(Image *);
MagickOffsetType TellBlob(Image *);
MagickSizeType GetBlobSize(Image *);
void CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(int, const char *, const char *, const char *);
const char *GetMagickModule(void);