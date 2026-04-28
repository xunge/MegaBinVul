#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef size_t MagickOffsetType;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    unsigned long number_scenes;
    unsigned long scene;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    unsigned depth;
    unsigned long scene;
    struct _Image *previous;
    char *filename;
    unsigned alpha_trait;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _MemoryInfo {
    void *blob;
} MemoryInfo;

#define MagickCoreSignature 0x1234
#define MagickFalse 0
#define MagickTrue 1
#define OpaqueAlpha 1
#define BlendPixelTrait 1

enum {
    TraceEvent,
    CorruptImageError,
    ResourceLimitError,
    LoadImageTag,
    LoadImagesTag
};

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned long ReadBlobMSBLong(Image *);
MagickBooleanType EOFBlob(Image *);
void ThrowReaderException(int, const char *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
unsigned char *GetVirtualMemoryBlob(MemoryInfo *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
Quantum GetPixelAlpha(Image *, Quantum *);
size_t GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickOffsetType TellBlob(Image *);
MagickOffsetType GetBlobSize(Image *);
void CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(int, const char *, const char *, const char *);
const char *GetMagickModule(void);

#define ScaleCharToQuantum(x) ((Quantum)(x))