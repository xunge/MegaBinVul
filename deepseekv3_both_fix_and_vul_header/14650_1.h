#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned char MagickBooleanType;
typedef size_t MagickSizeType;
typedef int64_t MagickOffsetType;
typedef uint32_t Quantum;
typedef double MagickRealType;
typedef unsigned char IndexPacket;
typedef struct _PixelPacket PixelPacket;
typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define QuantumRange ((Quantum) ~0UL)
#define MAGICKCORE_QUANTUM_DEPTH 16
#define LSBEndian 0
#define MSBEndian 1
#define PseudoClass 1
#define DirectClass 2
#define OpaqueOpacity QuantumRange
#define ReadBinaryBlobMode 0

enum {
    TraceEvent,
    CorruptImageError,
    ResourceLimitError,
    CoderError,
    LoadImageTag,
    LoadImagesTag
};

struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum opacity;
};

struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    MagickBooleanType matte;
    size_t colors;
    unsigned long endian;
    unsigned long storage_class;
    unsigned long scene;
    char *filename;
    PixelPacket *colormap;
    void *exception;
    Image *previous;
    Image *next;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    unsigned long number_scenes;
    unsigned long scene;
};

struct _ExceptionInfo {
    unsigned long signature;
};

static void ThrowReaderException(int, const char *);
static void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
static void InheritException(ExceptionInfo *, void *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static ssize_t ReadBlob(Image *, size_t, void *);
static int ReadBlobByte(Image *);
static unsigned long ReadBlobLong(Image *);
static long ReadBlobSignedLong(Image *);
static Image *AcquireImage(const ImageInfo *);
static Image *DestroyImageList(Image *);
static Image *GetFirstImageInList(Image *);
static Image *GetNextImageInList(Image *);
static Image *SyncNextImageInList(Image *);
static void AcquireNextImage(const ImageInfo *, Image *);
static MagickBooleanType AcquireImageColormap(Image *, unsigned long);
static MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long);
static MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, unsigned long);
static void *AcquireQuantumMemory(size_t, size_t);
static void *RelinquishMagickMemory(void *);
static void LogMagickEvent(int, const char *, const char *, ...);
static const char *GetMagickModule(void);
static void MSBOrderShort(void *, size_t);
static void MSBOrderLong(void *, size_t);
static MagickBooleanType CheckMemoryOverflow(size_t, size_t);
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
static MagickBooleanType EOFBlob(Image *);
static MagickOffsetType TellBlob(Image *);
static MagickSizeType GetBlobSize(Image *);
static void CloseBlob(Image *);
static PixelPacket *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static IndexPacket *GetAuthenticIndexQueue(Image *);
static void SetPixelRed(PixelPacket *, Quantum);
static void SetPixelGreen(PixelPacket *, Quantum);
static void SetPixelBlue(PixelPacket *, Quantum);
static void SetPixelOpacity(PixelPacket *, Quantum);
static void SetPixelIndex(IndexPacket *, size_t);
static Quantum GetPixelRed(PixelPacket *);
static Quantum GetPixelGreen(PixelPacket *);
static Quantum ScaleCharToQuantum(unsigned char);
static size_t ConstrainColormapIndex(Image *, ssize_t);
static void SyncImage(Image *);
static char *SetImageProperty(Image *, const char *, const char *);

static size_t MagickMax(size_t a, size_t b) {
    return (a > b) ? a : b;
}