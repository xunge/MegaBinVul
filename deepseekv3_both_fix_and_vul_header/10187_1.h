#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _MemoryInfo MemoryInfo;
typedef struct _PixelInfo PixelInfo;

typedef unsigned char Quantum;
typedef size_t MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned int MagickStatusType;
typedef int MagickBooleanType;
typedef double MagickRealType;

#define MagickFalse 0
#define MagickTrue 1
#define MagickCoreSignature 0x1234

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} PixelTrait;

typedef enum {
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    LoadImageTag,
    LoadImagesTag
} ProgressMonitorTag;

typedef enum {
    TraceEvent
} EventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ErrorType;

typedef enum {
    ReadBinaryBlobMode
} AccessMode;

struct _Image {
    size_t columns;
    size_t rows;
    size_t scene;
    size_t colors;
    PixelTrait alpha_trait;
    ClassType storage_class;
    char *filename;
    Image *previous;
    Image *next;
    struct {
        ssize_t x;
        ssize_t y;
    } page;
    PixelInfo *colormap;
};

struct _ImageInfo {
    char *filename;
    MagickBooleanType debug;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
    unsigned int signature;
};

struct _ExceptionInfo {
    unsigned int signature;
};

struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
};

struct _MemoryInfo {
    void *blob;
};

ssize_t ReadBlob(Image *, size_t, unsigned char *);
short ReadBlobLSBShort(Image *);
short ReadBlobLSBSignedShort(Image *);
unsigned char ReadBlobByte(Image *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, AccessMode, ExceptionInfo *);
Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
Image *DestroyImageList(Image *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
void *GetVirtualMemoryBlob(MemoryInfo *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
void LogMagickEvent(EventType, const char *, const char *, ...);
const char *GetMagickModule(void);
void ThrowReaderException(ErrorType, const char *);
void ThrowFileException(ExceptionInfo *, ErrorType, const char *, const char *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ProgressMonitorTag, MagickOffsetType, size_t);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
Image *GetFirstImageInList(Image *);
Image *SyncNextImageInList(Image *);
Image *GetNextImageInList(Image *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
MagickOffsetType TellBlob(Image *);
MagickSizeType GetBlobSize(Image *);
MagickBooleanType EOFBlob(Image *);
char *DestroyString(char *);
MagickBooleanType SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
unsigned char ScaleShortToQuantum(short);
unsigned char ScaleCharToQuantum(unsigned char);
Quantum ClampToQuantum(MagickRealType);
void ValidateColormapValue(Image *, size_t, Quantum *, ExceptionInfo *);
size_t GetPixelChannels(Image *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
void SetPixelIndex(Image *, Quantum, Quantum *);
size_t MagickMax(size_t, size_t);