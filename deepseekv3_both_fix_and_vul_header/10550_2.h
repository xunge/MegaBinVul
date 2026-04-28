#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef unsigned int MagickStatusType;
typedef unsigned long long MagickSizeType;
typedef long long MagickOffsetType;
typedef long ssize_t;
typedef unsigned long size_t;
typedef double MagickRealType;

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} PixelTrait;

typedef enum {
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    TraceEvent
} EventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ErrorType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    LoadImageTag,
    LoadImagesTag
} ImageTag;

typedef unsigned char Quantum;

typedef struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} PixelInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    struct {
        ssize_t x;
        ssize_t y;
    } page;
    PixelTrait alpha_trait;
    size_t scene;
    size_t colors;
    ClassType storage_class;
    PixelInfo *colormap;
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

typedef struct _MemoryInfo {
    void *blob;
} MemoryInfo;

#define MagickCoreSignature 0xABACADABUL
#define MagickMax(a,b) ((a) > (b) ? (a) : (b))
#define EOF (-1)

static Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static void ThrowReaderException(ErrorType, const char *);
static short ReadBlobLSBShort(Image *);
static unsigned char ReadBlobByte(Image *);
static short ReadBlobLSBSignedShort(Image *);
static MagickBooleanType EOFBlob(Image *);
static void ThrowFileException(ExceptionInfo *, ErrorType, const char *, const char *);
static void *AcquireQuantumMemory(size_t, size_t);
static unsigned short ScaleShortToQuantum(short);
static char *DestroyString(char *);
static MagickBooleanType SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
static MemoryInfo *AcquireVirtualMemory(size_t, size_t);
static void *GetVirtualMemoryBlob(MemoryInfo *);
static void *RelinquishMagickMemory(void *);
static MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
static Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
static MagickBooleanType SetImageProgress(Image *, ImageTag, MagickOffsetType, size_t);
static MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
static Quantum ScaleCharToQuantum(unsigned char);
static void SetPixelRed(Image *, Quantum, Quantum *);
static void SetPixelGreen(Image *, Quantum, Quantum *);
static void SetPixelBlue(Image *, Quantum, Quantum *);
static void SetPixelAlpha(Image *, Quantum, Quantum *);
static size_t GetPixelChannels(Image *);
static void SetPixelIndex(Image *, Quantum, Quantum *);
static MagickBooleanType SyncImage(Image *, ExceptionInfo *);
static Quantum ClampToQuantum(MagickRealType);
static void ValidateColormapValue(Image *, size_t, Quantum *, ExceptionInfo *);
static Image *GetFirstImageInList(Image *);
static Image *GetNextImageInList(Image *);
static Image *SyncNextImageInList(Image *);
static void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
static MagickOffsetType TellBlob(Image *);
static MagickOffsetType GetBlobSize(Image *);
static MagickBooleanType CloseBlob(Image *);
static void LogMagickEvent(EventType, const char *, const char *, ...);
static const char *GetMagickModule(void);