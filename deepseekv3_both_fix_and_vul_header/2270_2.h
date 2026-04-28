#include <assert.h>
#include <string.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

typedef enum {
    UndefinedInterlace,
    NoInterlace,
    PlaneInterlace,
    PartitionInterlace
} InterlaceType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    TraceEvent,
    OptionError,
    CorruptImageError,
    ResourceLimitError
} ExceptionType;

typedef enum {
    YCbCrColorspace
} ColorspaceType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    LoadImageTag,
    LoadImagesTag
} ProgressTag;

typedef enum {
    TriangleFilter
} FilterType;

typedef enum {
    SigmaValue = 0x01
} GeometryFlags;

typedef unsigned long MagickSizeType;
typedef unsigned long MagickOffsetType;
typedef unsigned long size_t;
typedef long ssize_t;
typedef unsigned char Quantum;
typedef unsigned int MagickStatusType;

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    InterlaceType interlace;
    char *sampling_factor;
    MagickBooleanType ping;
    unsigned long number_scenes;
    unsigned long scene;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t depth;
    unsigned long offset;
    char filename[4096];
    struct _Image *previous;
    unsigned long scene;
    struct _Image *next;
};

typedef struct {
    double rho;
    double sigma;
} GeometryInfo;

#define MagickCoreSignature 0x12345678
#define MagickPathExtent 4096

static Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static void ThrowReaderException(ExceptionType, const char *);
static void LogMagickEvent(ExceptionType, const char *, const char *, ...);
static const char *GetMagickModule(void);
static void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
static MagickBooleanType DiscardBlobBytes(Image *, MagickSizeType);
static void *AcquireQuantumMemory(size_t, size_t);
static Image *CloneImage(Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
static Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static void SetPixelRed(Image *, Quantum, Quantum *);
static void SetPixelGreen(Image *, Quantum, Quantum *);
static void SetPixelBlue(Image *, Quantum, Quantum *);
static Quantum ScaleCharToQuantum(unsigned char);
static Quantum ScaleShortToQuantum(unsigned short);
static size_t GetPixelChannels(Image *);
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
static Image *GetPreviousImageInList(Image *);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static MagickBooleanType SetImageProgress(Image *, ProgressTag, MagickOffsetType, size_t);
static void CloseBlob(Image *);
static void AppendImageFormat(const char *, char *);
static Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static const Quantum *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static Quantum GetPixelGreen(Image *, const Quantum *);
static Quantum GetPixelBlue(Image *, const Quantum *);
static Image *ResizeImage(Image *, size_t, size_t, FilterType, ExceptionInfo *);
static Image *DestroyImage(Image *);
static MagickBooleanType SetImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
static void CopyMagickString(char *, const char *, size_t);
static MagickBooleanType EOFBlob(Image *);
static Image *AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
static Image *GetNextImageInList(Image *);
static Image *SyncNextImageInList(Image *);
static MagickOffsetType TellBlob(Image *);
static MagickSizeType GetBlobSize(Image *);
static void *RelinquishMagickMemory(void *);
static Image *GetFirstImageInList(Image *);
static MagickStatusType ParseGeometry(const char *, GeometryInfo *);