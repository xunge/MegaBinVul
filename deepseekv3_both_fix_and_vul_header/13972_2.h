#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef unsigned char Quantum;
typedef ptrdiff_t ssize_t;

struct _Image;
struct _ImageInfo;
struct _ExceptionInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    char *magick;
    MagickBooleanType adjoin;
    int compression;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    int storage_class;
    unsigned long columns;
    unsigned long rows;
    struct {
        double x;
        double y;
    } resolution;
    int units;
    unsigned long colors;
    struct {
        Quantum red;
        Quantum green;
        Quantum blue;
    } *colormap;
    int alpha_trait;
    struct _Image *previous;
    int (*GetPixelChannels)(const struct _Image *);
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
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

#define MagickCoreSignature 0x12345678
#define MagickFalse 0
#define MagickTrue 1
#define UndefinedResolution 0
#define PixelsPerInchResolution 1
#define PixelsPerCentimeterResolution 2
#define NoCompression 0
#define PseudoClass 0
#define DirectClass 1
#define UndefinedPixelTrait 0
#define WriteBinaryBlobMode 0
#define TraceEvent 0
#define ResourceLimitError 0
#define CorruptImageError 0
#define FileOpenError 0
#define SaveImageTag 0
#define SaveImagesTag 0
#define sRGBColorspace 1
#define SEEK_SET 0
#define QuantumRange 65535
#define GetMagickModule() "PCX"

static int LocaleCompare(const char *, const char *);
static void *AcquireQuantumMemory(size_t, size_t);
static void *AcquireVirtualMemory(size_t, size_t);
static void *GetVirtualMemoryBlob(MemoryInfo *);
static void *RelinquishVirtualMemory(MemoryInfo *);
static void *RelinquishMagickMemory(void *);
static char *GetExceptionMessage(int);
static char *DestroyString(char *);
static Image *GetNextImageInList(const Image *);
static Image *SyncNextImageInList(Image *);
static size_t GetImageListLength(const Image *);
static const Quantum *GetVirtualPixels(const Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static Quantum GetPixelRed(const Image *, const Quantum *);
static Quantum GetPixelGreen(const Image *, const Quantum *);
static Quantum GetPixelBlue(const Image *, const Quantum *);
static Quantum GetPixelAlpha(const Image *, const Quantum *);
static Quantum GetPixelIndex(const Image *, const Quantum *);
static Quantum GetPixelLuma(const Image *, const Quantum *);
static unsigned char ScaleQuantumToChar(Quantum);
static int GetPixelChannels(const Image *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static MagickBooleanType SetImageMonochrome(Image *, ExceptionInfo *);
static MagickBooleanType PCXWritePixels(const PCXInfo *, const unsigned char *, Image *);
static MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
static MagickBooleanType TransformImageColorspace(Image *, int, ExceptionInfo *);
static void WriteBlob(Image *, size_t, const unsigned char *);
static void WriteBlobByte(Image *, unsigned char);
static void WriteBlobLSBShort(Image *, unsigned short);
static void WriteBlobLSBLong(Image *, long);
static void LogMagickEvent(int, const char *, const char *, ...);
static void ThrowWriterException(int, const char *);
static void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
static MagickOffsetType TellBlob(const Image *);
static MagickOffsetType SeekBlob(Image *, long, int);
static void CloseBlob(Image *);