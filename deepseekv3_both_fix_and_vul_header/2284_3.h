#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef intptr_t ssize_t;
typedef uint64_t MagickSizeType;
typedef int64_t MagickOffsetType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

#define MagickCoreSignature 0x12345678
#define MAGICKCORE_QUANTUM_DEPTH 16

enum CompressionType {
    NoCompression,
    RLECompression
};

enum PixelTrait {
    UndefinedPixelTrait,
    BlendPixelTrait
};

enum StorageClass {
    DirectClass,
    PseudoClass
};

enum {
    TraceEvent,
    LoadImageTag,
    LoadImagesTag
};

enum ErrorType {
    CorruptImageError,
    ResourceLimitError
};

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _MemoryInfo MemoryInfo;
typedef struct _SGIInfo SGIInfo;

struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    size_t scene;
    enum PixelTrait alpha_trait;
    enum StorageClass storage_class;
    enum CompressionType compression;
    Image *previous;
    char *filename;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
    char *filename;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _MemoryInfo {
    void *dummy;
};

struct _SGIInfo {
    unsigned short magic;
    unsigned char storage;
    unsigned char bytes_per_pixel;
    unsigned short dimension;
    unsigned short columns;
    unsigned short rows;
    unsigned short depth;
    unsigned long minimum_value;
    unsigned long maximum_value;
    unsigned long sans;
    char name[80];
    unsigned long pixel_format;
    unsigned char filler[404];
};

typedef unsigned char Quantum;

#define OpaqueAlpha 0
#define ScaleShortToQuantum(x) ((Quantum)(x))
#define ScaleCharToQuantum(x) ((Quantum)(x))
#define GetPixelChannels(image) 4
#define ReadBinaryBlobMode 0
#define SEEK_SET 0

static inline size_t MagickMin(size_t a, size_t b) {
    return (a < b) ? a : b;
}

/* Function prototypes */
Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned short ReadBlobMSBShort(Image *);
void ThrowReaderException(int, const char *);
unsigned char ReadBlobByte(Image *);
unsigned long ReadBlobMSBLong(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
MagickBooleanType SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
unsigned char *GetVirtualMemoryBlob(MemoryInfo *);
unsigned char *AcquireQuantumMemory(size_t, size_t);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
void *RelinquishMagickMemory(void *);
MagickBooleanType EOFBlob(Image *);
ssize_t ReadBlobMSBSignedLong(Image *);
MagickOffsetType TellBlob(Image *);
ssize_t SeekBlob(Image *, MagickOffsetType, int);
MagickBooleanType SGIDecode(size_t, ssize_t, unsigned char *, ssize_t, unsigned char *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
void SetPixelIndex(Image *, Quantum, Quantum *);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
size_t GetBlobSize(Image *);
void CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
const char *GetMagickModule(void);
void LogMagickEvent(int, const char *, const char *, ...);