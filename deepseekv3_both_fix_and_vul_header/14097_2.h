#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MagickFalse 0
#define MagickTrue 1
#define MagickCoreSignature 0xabacadabUL
#define QuantumRange 255UL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define OpaqueAlpha QuantumRange

typedef unsigned int MagickBooleanType;
typedef size_t MagickSizeType;
typedef long long MagickOffsetType;
typedef unsigned char Quantum;

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum alpha;
} PixelPacket;

typedef struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    unsigned int storage_class;
    unsigned int alpha_trait;
    unsigned int endian;
    PixelPacket *colormap;
    char *filename;
    struct _Image *previous;
    struct _Image *next;
    unsigned long scene;
    MagickBooleanType debug;
    unsigned long signature;
} Image;

typedef struct _ImageInfo {
    char *filename;
    MagickBooleanType debug;
    MagickBooleanType ping;
    unsigned long number_scenes;
    unsigned long scene;
    unsigned long signature;
} ImageInfo;

typedef struct _ExceptionInfo {
    char *reason;
    char *description;
    unsigned long signature;
} ExceptionInfo;

enum {
    UndefinedPixelTrait,
    BlendPixelTrait
};

enum {
    PseudoClass,
    DirectClass
};

enum {
    LSBEndian,
    MSBEndian
};

enum {
    TraceEvent
};

enum {
    CorruptImageError,
    ResourceLimitError,
    CoderError
};

enum {
    ReadBinaryBlobMode
};

enum {
    LoadImageTag,
    LoadImagesTag
};

static void *AcquireQuantumMemory(size_t count, size_t quantum);
static void *RelinquishMagickMemory(void *memory);
static MagickBooleanType HeapOverflowSanityCheck(size_t count, size_t quantum);
static void MSBOrderShort(unsigned char *p, size_t length);
static void MSBOrderLong(unsigned char *p, size_t length);
static ssize_t ReadBlob(Image *image, size_t length, void *data);
static int ReadBlobByte(Image *image);
static unsigned int ReadBlobLong(Image *image);
static int ReadBlobSignedLong(Image *image);
static MagickBooleanType EOFBlob(Image *image);
static void ThrowReaderException(int error, const char *reason);
static void ThrowFileException(ExceptionInfo *exception, int error, const char *reason, const char *description);
static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception);
static Image *DestroyImageList(Image *image);
static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception);
static void LogMagickEvent(int event, const char *module, const char *format, ...);
static const char *GetMagickModule(void);
static MagickBooleanType AcquireImageColormap(Image *image, size_t colors, ExceptionInfo *exception);
static Quantum *QueueAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception);
static MagickBooleanType SetImageProgress(Image *image, int tag, MagickOffsetType offset, size_t span);
static MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows, ExceptionInfo *exception);
static Image *SyncNextImageInList(Image *image);
static Image *GetNextImageInList(Image *image);
static Image *GetFirstImageInList(Image *image);
static MagickBooleanType AcquireNextImage(const ImageInfo *image_info, Image *image, ExceptionInfo *exception);
static MagickOffsetType TellBlob(Image *image);
static MagickSizeType GetBlobSize(Image *image);
static MagickBooleanType CloseBlob(Image *image);
static Quantum ScaleCharToQuantum(unsigned char value);
static ssize_t ConstrainColormapIndex(Image *image, ssize_t index, ExceptionInfo *exception);
static MagickBooleanType SyncImage(Image *image, ExceptionInfo *exception);
static void SetPixelRed(Image *image, Quantum red, Quantum *pixel);
static void SetPixelGreen(Image *image, Quantum green, Quantum *pixel);
static void SetPixelBlue(Image *image, Quantum blue, Quantum *pixel);
static void SetPixelAlpha(Image *image, Quantum alpha, Quantum *pixel);
static void SetPixelIndex(Image *image, Quantum index, Quantum *pixel);
static Quantum GetPixelRed(Image *image, Quantum *pixel);
static Quantum GetPixelGreen(Image *image, Quantum *pixel);
static Quantum GetPixelBlue(Image *image, Quantum *pixel);
static size_t GetPixelChannels(Image *image);
static void SetImageProperty(Image *image, const char *property, const char *value, ExceptionInfo *exception);

#define MagickMax(a,b) ((a) > (b) ? (a) : (b))