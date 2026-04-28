#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef unsigned char MagickBooleanType;
typedef size_t MagickSizeType;
typedef long long MagickOffsetType;
typedef double MagickRealType;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
} ImageInfo;

typedef struct _PixelPacket {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} PixelPacket;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    PixelPacket *colormap;
    MagickBooleanType alpha_trait;
    MagickBooleanType storage_class;
    struct _Image *previous;
    struct _Image *next;
    size_t scene;
    const char *filename;
} Image;

#define MagickCoreSignature 0xABACADABUL
#define MagickFalse 0
#define MagickTrue 1
#define UndefinedPixelTrait 0
#define BlendPixelTrait 1
#define PseudoClass 1
#define LoadImageTag 1
#define LoadImagesTag 2
#define TraceEvent 1
#define GetMagickModule() ""
#define CorruptImageError 1
#define ResourceLimitError 2
#define CoderError 3
#define MAGICKCORE_QUANTUM_DEPTH 8
#define ReadBinaryBlobMode 0

#define ScaleCharToQuantum(x) ((Quantum)(x))
#define ClampToQuantum(x) ((Quantum)(x))
#define ConstrainColormapIndex(image,index,exception) (index)
#define GetPixelChannels(image) 1
#define GetPixelRed(image,q) (*(q))
#define GetPixelGreen(image,q) (*(q))
#define GetPixelBlue(image,q) (*(q))
#define SetPixelIndex(image,index,q) (*(q) = (index))
#define SetPixelRed(image,value,q) (*(q) = (value))
#define SetPixelGreen(image,value,q) (*(q) = (value))
#define SetPixelBlue(image,value,q) (*(q) = (value))
#define SetPixelAlpha(image,value,q) (*(q) = (value))

static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception) {
    return (Image *)malloc(sizeof(Image));
}
static Image *DestroyImageList(Image *image) { free(image); return NULL; }
static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception) { return MagickTrue; }
static void CloseBlob(Image *image) {}
static ssize_t ReadBlob(Image *image, size_t count, void *data) { return count; }
static unsigned int ReadBlobMSBLong(Image *image) { return 0; }
static Image *GetFirstImageInList(Image *image) { return image; }
static MagickBooleanType AcquireImageColormap(Image *image, size_t colors, ExceptionInfo *exception) { return MagickTrue; }
static Quantum *QueueAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception) { return (Quantum *)malloc(1); }
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception) { return MagickTrue; }
static MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows, ExceptionInfo *exception) { return MagickTrue; }
static void *AcquireQuantumMemory(size_t count, size_t size) { return malloc(count * size); }
static void *RelinquishMagickMemory(void *memory) { free(memory); return NULL; }
static MagickBooleanType HeapOverflowSanityCheck(size_t width, size_t depth) { return MagickFalse; }
static MagickBooleanType DecodeImage(const unsigned char *source, size_t length, unsigned char *destination, size_t extent) { return MagickTrue; }
static void SyncImage(Image *image, ExceptionInfo *exception) {}
static MagickBooleanType EOFBlob(Image *image) { return MagickFalse; }
static void AcquireNextImage(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) {}
static Image *GetNextImageInList(Image *image) { return NULL; }
static Image *SyncNextImageInList(Image *image) { return image; }
static MagickBooleanType SetImageProgress(Image *image, int tag, MagickOffsetType offset, size_t span) { return MagickTrue; }
static MagickOffsetType TellBlob(Image *image) { return 0; }
static MagickSizeType GetBlobSize(Image *image) { return 0; }
static void LogMagickEvent(int event, const char *module, const char *format, ...) {}
static void ThrowReaderException(int code, const char *reason) {}
static void ThrowFileException(ExceptionInfo *exception, int code, const char *reason, const char *file) {}
#define ResetMagickMemory(dest,val,len) memset(dest,val,len)
#define CopyMagickMemory(dest,src,len) memcpy(dest,src,len)