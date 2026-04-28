#include <assert.h>
#include <string.h>

typedef int MagickBooleanType;
typedef long MagickOffsetType;
typedef unsigned char Quantum;
typedef unsigned long size_t;
typedef long ssize_t;

#define QuantumRange 65535

typedef struct _ImageInfo {
    unsigned long signature;
    char *magick;
    MagickBooleanType adjoin;
    int compression;
    int debug;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    char *filename;
    unsigned long columns;
    unsigned long rows;
    int storage_class;
    int colors;
    int units;
    struct {
        double x;
        double y;
    } resolution;
    int alpha_trait;
    struct _Image *previous;
    struct _Image *next;
    int debug;
    struct {
        Quantum red;
        Quantum green;
        Quantum blue;
    } *colormap;
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
#define UndefinedPixelTrait 0
#define PseudoClass 1
#define DirectClass 2
#define NoCompression 0
#define WriteBinaryBlobMode 0
#define ImageError 0
#define ResourceLimitError 0
#define CorruptImageError 0
#define FileOpenError 0
#define TraceEvent 0
#define SaveImageTag 0
#define SaveImagesTag 0
#define sRGBColorspace 0

#define GetMagickModule() ""
#define LogMagickEvent(a,b,c,d) 0
#define OpenBlob(a,b,c,d) 0
#define ThrowWriterException(a,b) return(MagickFalse)
#define TransformImageColorspace(a,b,c) 0
#define LocaleCompare(a,b) 0
#define GetNextImageInList(a) NULL
#define AcquireQuantumMemory(a,b) NULL
#define WriteBlobLSBLong(a,b) 0
#define TellBlob(a) 0
#define WriteBlobByte(a,b) 0
#define WriteBlobLSBShort(a,b) 0
#define ScaleQuantumToChar(a) 0
#define WriteBlob(a,b,c) 0
#define AcquireVirtualMemory(a,b) NULL
#define RelinquishMagickMemory(a) NULL
#define RelinquishVirtualMemory(a) NULL
#define GetVirtualMemoryBlob(a) NULL
#define GetVirtualPixels(a,b,c,d,e,f) NULL
#define GetPixelRed(a,b) 0
#define GetPixelChannels(a) 0
#define GetPixelGreen(a,b) 0
#define GetPixelBlue(a,b) 0
#define GetPixelAlpha(a,b) 0
#define PCXWritePixels(a,b,c) MagickFalse
#define SetImageProgress(a,b,c,d) MagickFalse
#define GetPixelIndex(a,b) 0
#define GetPixelLuma(a,b) 0
#define SeekBlob(a,b,c) 0
#define GetExceptionMessage(a) NULL
#define ThrowMagickException(a,b,c,d,e,f,g) 0
#define DestroyString(a) NULL
#define CloseBlob(a) 0
#define SyncNextImageInList(a) NULL
#define GetImageListLength(a) 0
#define SetImageMonochrome(a,b) MagickFalse