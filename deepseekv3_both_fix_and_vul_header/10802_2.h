#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef double MagickRealType;

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _MemoryInfo MemoryInfo;
typedef struct _PixelInfo PixelInfo;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef unsigned long MagickSizeType;
typedef unsigned int MagickStatusType;
typedef long MagickOffsetType;

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} PixelTrait;

typedef enum {
    UndefinedException,
    CorruptImageError,
    ResourceLimitError
} ExceptionType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    LoadImageTag,
    LoadImagesTag
} ImageTag;

typedef enum {
    TraceEvent
} LogEventType;

typedef unsigned char Quantum;

#define MagickCoreSignature 0xabacadabUL
#define MagickMax(a,b) ((a) > (b) ? (a) : (b))
#define EOF (-1)

typedef struct {
    ssize_t x;
    ssize_t y;
} PointInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    PointInfo page;
    PixelTrait alpha_trait;
    size_t scene;
    size_t colors;
    ClassType storage_class;
    PixelInfo *colormap;
    Image *previous;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    size_t scene;
    size_t number_scenes;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} PixelInfo;

void *AcquireQuantumMemory(size_t, size_t);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
unsigned char *GetVirtualMemoryBlob(MemoryInfo *);
void *RelinquishMagickMemory(void *);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
void *ResetMagickMemory(void *, int, size_t);
char *DestroyString(char *);
void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
Image *GetFirstImageInList(Image *);
Image *DestroyImageList(Image *);
Image *AcquireNextImage(ImageInfo *, Image *, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
void LogMagickEvent(LogEventType, const char *, const char *, ...);

MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ImageTag, MagickOffsetType, size_t);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
MagickBooleanType EOFBlob(Image *);

ssize_t ReadBlob(Image *, size_t, unsigned char *);
short ReadBlobLSBShort(Image *);
short ReadBlobLSBSignedShort(Image *);
int ReadBlobByte(Image *);
ssize_t TellBlob(Image *);
ssize_t GetBlobSize(Image *);

Quantum ScaleCharToQuantum(unsigned char);
Quantum ScaleShortToQuantum(short);
Quantum ClampToQuantum(MagickRealType);

void ThrowReaderException(ExceptionType, const char *);
void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
void SetPixelIndex(Image *, Quantum, Quantum *);
void ValidateColormapValue(Image *, ssize_t, Quantum *, ExceptionInfo *);

const char *GetMagickModule(void);
Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
unsigned char ScaleQuantumToChar(Quantum);
size_t GetPixelChannels(Image *);