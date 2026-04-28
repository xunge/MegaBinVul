#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef unsigned int MagickBooleanType;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef enum { MagickFalse, MagickTrue } MagickBooleanEnum;
typedef enum { UndefinedPixelTrait, BlendPixelTrait } PixelTrait;
typedef enum { PseudoClass, DirectClass } ClassType;
typedef enum { LSBEndian, MSBEndian } EndianType;
typedef enum { TraceEvent } LogEventType;
typedef enum { CorruptImageError, ResourceLimitError, CoderError } ErrorType;
typedef enum { ReadBinaryBlobMode } BlobMode;

#define MagickCoreSignature 0xabacadabUL
#define QuantumRange 65535
#define MAGICKCORE_QUANTUM_DEPTH 16
#define OpaqueAlpha QuantumRange
#define LoadImageTag "LoadImage"
#define LoadImagesTag "LoadImages"

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum alpha;
} PixelPacket;

struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    ClassType storage_class;
    PixelTrait alpha_trait;
    EndianType endian;
    struct _Image *previous;
    struct _Image *next;
    unsigned long scene;
    char *filename;
    PixelPacket *colormap;
};

typedef struct _Image Image;

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    MagickBooleanType ping;
    char *filename;
    unsigned long scene;
    unsigned long number_scenes;
};

struct _ExceptionInfo {
    unsigned long signature;
};

static void MSBOrderShort(unsigned char *p, size_t length);
static void MSBOrderLong(unsigned char *p, size_t length);
static ssize_t ReadBlob(Image *image, size_t length, void *data);
static int ReadBlobByte(Image *image);
static unsigned int ReadBlobLong(Image *image);
static int ReadBlobSignedLong(Image *image);
static MagickBooleanType EOFBlob(const Image *image);
static void ThrowReaderException(ErrorType error, const char *reason);
static void ThrowFileException(ExceptionInfo *exception, ErrorType error,
    const char *reason, const char *description);
static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception);
static Image *DestroyImageList(Image *image);
static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image,
    BlobMode mode, ExceptionInfo *exception);
static void LogMagickEvent(LogEventType event, const char *module,
    const char *format, ...);
static const char *GetMagickModule(void);
static MagickBooleanType AcquireImageColormap(Image *image,
    size_t colors, ExceptionInfo *exception);
static unsigned char *AcquireQuantumMemory(size_t count, size_t quantum);
static void *RelinquishMagickMemory(void *memory);
static MagickBooleanType SetImageExtent(Image *image, size_t columns,
    size_t rows, ExceptionInfo *exception);
static Quantum *QueueAuthenticPixels(Image *image, ssize_t x,
    ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
static MagickBooleanType SyncAuthenticPixels(Image *image,
    ExceptionInfo *exception);
static MagickBooleanType SetImageProgress(Image *image, const char *tag,
    MagickOffsetType offset, MagickOffsetType span);
static void SetPixelRed(const Image *image, Quantum quantum, Quantum *pixel);
static void SetPixelGreen(const Image *image, Quantum quantum, Quantum *pixel);
static void SetPixelBlue(const Image *image, Quantum quantum, Quantum *pixel);
static void SetPixelAlpha(const Image *image, Quantum quantum, Quantum *pixel);
static void SetPixelIndex(const Image *image, Quantum index, Quantum *pixel);
static Quantum GetPixelRed(const Image *image, const Quantum *pixel);
static Quantum GetPixelGreen(const Image *image, const Quantum *pixel);
static Quantum GetPixelBlue(const Image *image, const Quantum *pixel);
static size_t GetPixelChannels(const Image *image);
static MagickBooleanType SyncImage(Image *image, ExceptionInfo *exception);
static MagickOffsetType TellBlob(const Image *image);
static MagickSizeType GetBlobSize(const Image *image);
static MagickBooleanType CloseBlob(Image *image);
static Image *GetFirstImageInList(const Image *image);
static Image *GetNextImageInList(const Image *image);
static Image *SyncNextImageInList(Image *image);
static MagickBooleanType AcquireNextImage(const ImageInfo *image_info,
    Image *image, ExceptionInfo *exception);
static unsigned char ScaleCharToQuantum(unsigned char value);
static size_t ConstrainColormapIndex(Image *image, ssize_t index,
    ExceptionInfo *exception);
static MagickBooleanType CheckMemoryOverflow(size_t count, size_t quantum);
static void SetImageProperty(Image *image, const char *property,
    const char *value, ExceptionInfo *exception);
static size_t MagickMax(size_t x, size_t y);