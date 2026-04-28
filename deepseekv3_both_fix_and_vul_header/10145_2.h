#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    NoCompression,
    RLECompression
} CompressionType;

typedef enum {
    PseudoClass,
    DirectClass
} ClassType;

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} AlphaChannelType;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ErrorType;

typedef enum {
    ReadBinaryBlobMode
} AccessMode;

typedef enum {
    LoadImageTag,
    LoadImagesTag
} ProgressMonitorTag;

typedef size_t MagickSizeType;
typedef unsigned char Quantum;
typedef long MagickOffsetType;

#define MagickCoreSignature 0xabacadabUL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define OpaqueAlpha 1

typedef struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    size_t scene;
    CompressionType compression;
    ClassType storage_class;
    AlphaChannelType alpha_trait;
    struct _Image *previous;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _MemoryInfo MemoryInfo;

typedef struct _SGIInfo {
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
} SGIInfo;

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, AccessMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned short ReadBlobMSBShort(Image *);
unsigned char ReadBlobByte(Image *);
unsigned long ReadBlobMSBLong(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
void ThrowReaderException(ErrorType, const char *);
void LogMagickEvent(LogEventType, const char *, const char *, ...);
const char *GetMagickModule(void);
MagickBooleanType SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
size_t MagickMin(size_t, size_t);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
unsigned char *GetVirtualMemoryBlob(MemoryInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
MagickBooleanType EOFBlob(Image *);
ssize_t TellBlob(Image *);
ssize_t SeekBlob(Image *, MagickOffsetType, int);
ssize_t ReadBlobMSBSignedLong(Image *);
MagickBooleanType SGIDecode(size_t, ssize_t, unsigned char *, ssize_t, unsigned char *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
Quantum ScaleShortToQuantum(unsigned short);
Quantum ScaleCharToQuantum(unsigned char);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
size_t GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ProgressMonitorTag, MagickOffsetType, size_t);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
void SetPixelIndex(Image *, Quantum, Quantum *);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
void ThrowFileException(ExceptionInfo *, ErrorType, const char *, const char *);
Image *AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickOffsetType GetBlobSize(Image *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);