#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

typedef unsigned char Quantum;
typedef unsigned int MagickStatusType;
typedef unsigned long long MagickSizeType;
typedef long long MagickOffsetType;
typedef ptrdiff_t ssize_t;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { UndefinedPixelTrait, BlendPixelTrait } PixelTrait;
typedef enum { DirectClass } ClassType;
typedef enum { LoadImageTag, LoadImagesTag } ProgressMonitorTag;
typedef enum { CorruptImageError, ResourceLimitError } ErrorType;
typedef enum { TraceEvent } LogEventType;
typedef enum { ReadBinaryBlobMode } BlobMode;

#define MagickCoreSignature 0xabacadabUL
#define MagickMax(a,b) ((a) > (b) ? (a) : (b))

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _MemoryInfo MemoryInfo;
typedef struct _PixelInfo PixelInfo;
typedef double MagickRealType;

struct _Image {
    Image *previous;
    Image *next;
    size_t columns;
    size_t rows;
    size_t colors;
    size_t scene;
    PixelTrait alpha_trait;
    ClassType storage_class;
    PixelInfo *colormap;
    char *filename;
    struct {
        int x;
        int y;
    } page;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    MagickBooleanType ping;
    char *filename;
    size_t number_scenes;
    size_t scene;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _MemoryInfo {
    void *blob;
};

struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
Image *DestroyImageList(Image *);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
short ReadBlobLSBShort(Image *);
int ReadBlobLSBSignedShort(Image *);
unsigned char ReadBlobByte(Image *);
MagickBooleanType EOFBlob(Image *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
unsigned char *GetVirtualMemoryBlob(MemoryInfo *);
void ResetMagickMemory(void *, int, size_t);
void ThrowReaderException(ErrorType, const char *);
void ThrowFileException(ExceptionInfo *, ErrorType, const char *, const char *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ProgressMonitorTag, MagickOffsetType, size_t);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
MagickOffsetType TellBlob(Image *);
MagickSizeType GetBlobSize(Image *);
MagickBooleanType CloseBlob(Image *);
void ValidateColormapValue(Image *, size_t, Quantum *, ExceptionInfo *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
void SetPixelIndex(Image *, Quantum, Quantum *);
size_t GetPixelChannels(Image *);
unsigned char ScaleQuantumToChar(Quantum);
Quantum ScaleCharToQuantum(unsigned char);
Quantum ScaleShortToQuantum(short);
Quantum ClampToQuantum(MagickRealType);
void LogMagickEvent(LogEventType, const char *, const char *, ...);
void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
char *DestroyString(char *);
const char *GetMagickModule(void);