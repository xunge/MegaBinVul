#include <assert.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef unsigned char Quantum;

#define WriteBinaryBlobMode 0
#define sRGBColorspace 0
#define QuantumRange 65535
#define SEEK_SET 0

typedef struct _ImageInfo {
    const char *signature;
    const char *magick;
    int compression;
    int adjoin;
    int debug;
    const char *filename;
} ImageInfo;

typedef struct _Image {
    const char *signature;
    int debug;
    const char *filename;
    int storage_class;
    int colors;
    int columns;
    int rows;
    struct _Image *previous;
    struct _Image *next;
    struct {
        double x;
        double y;
    } resolution;
    int units;
    int alpha_trait;
    struct {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    } *colormap;
} Image;

typedef struct _ExceptionInfo {
    const char *signature;
} ExceptionInfo;

typedef struct _MemoryInfo {
    void *blob;
} MemoryInfo;

typedef struct _PCXInfo {
    unsigned char identifier;
    unsigned char version;
    unsigned char encoding;
    unsigned char bits_per_pixel;
    unsigned short left;
    unsigned short top;
    unsigned short right;
    unsigned short bottom;
    unsigned short horizontal_resolution;
    unsigned short vertical_resolution;
    unsigned char reserved;
    unsigned char planes;
    unsigned short bytes_per_line;
    unsigned char palette_info;
    unsigned char colormap_signature;
} PCXInfo;

#define MagickCoreSignature "MAGICKCORE"
#define MagickFalse 0
#define MagickTrue 1
#define UndefinedResolution 0
#define PixelsPerInchResolution 1
#define PixelsPerCentimeterResolution 2
#define UndefinedPixelTrait 0
#define PseudoClass 0
#define DirectClass 1
#define NoCompression 0
#define SaveImageTag 0
#define SaveImagesTag 0
#define ResourceLimitError 0
#define CorruptImageError 0
#define FileOpenError 0
#define TraceEvent 0

static const char* GetMagickModule(void) { return ""; }
static int LogMagickEvent(int, const char*, const char*, const char*) { return 0; }
static int OpenBlob(const ImageInfo*, Image*, int, ExceptionInfo*) { return 0; }
static int TransformImageColorspace(Image*, int, ExceptionInfo*) { return 0; }
static int LocaleCompare(const char*, const char*) { return 0; }
static Image* GetNextImageInList(Image*) { return NULL; }
static void* AcquireQuantumMemory(size_t, size_t) { return NULL; }
static void ThrowWriterException(int, const char*) {}
static MagickOffsetType TellBlob(Image*) { return 0; }
static int SetImageMonochrome(Image*, ExceptionInfo*) { return 0; }
static int WriteBlobLSBLong(Image*, unsigned int) { return 0; }
static int WriteBlobByte(Image*, unsigned char) { return 0; }
static int WriteBlobLSBShort(Image*, unsigned short) { return 0; }
static void* AcquireVirtualMemory(size_t, size_t) { return NULL; }
static unsigned char* GetVirtualMemoryBlob(MemoryInfo*) { return NULL; }
static const Quantum* GetVirtualPixels(Image*, int, ssize_t, size_t, int, ExceptionInfo*) { return NULL; }
static unsigned char ScaleQuantumToChar(Quantum) { return 0; }
static unsigned char GetPixelRed(Image*, const Quantum*) { return 0; }
static int GetPixelChannels(Image*) { return 0; }
static unsigned char GetPixelGreen(Image*, const Quantum*) { return 0; }
static unsigned char GetPixelBlue(Image*, const Quantum*) { return 0; }
static unsigned char GetPixelAlpha(Image*, const Quantum*) { return 0; }
static int PCXWritePixels(PCXInfo*, unsigned char*, Image*) { return 0; }
static int SetImageProgress(Image*, int, MagickOffsetType, size_t) { return 0; }
static unsigned char GetPixelIndex(Image*, const Quantum*) { return 0; }
static Quantum GetPixelLuma(Image*, const Quantum*) { return 0; }
static Image* SyncNextImageInList(Image*) { return NULL; }
static size_t GetImageListLength(Image*) { return 0; }
static MagickOffsetType SeekBlob(Image*, long, int) { return 0; }
static void* RelinquishMagickMemory(void*) { return NULL; }
static void* RelinquishVirtualMemory(MemoryInfo*) { return NULL; }
static char* GetExceptionMessage(int) { return NULL; }
static int ThrowMagickException(ExceptionInfo*, const char*, int, const char*, const char*, const char*, char*) { return 0; }
static char* DestroyString(char*) { return NULL; }
static int CloseBlob(Image*) { return 0; }
static int WriteBlob(Image*, size_t, const unsigned char*) { return 0; }