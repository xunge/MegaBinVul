#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef long ssize_t;
typedef unsigned char MagickBooleanType;
typedef unsigned long MagickOffsetType;
typedef unsigned short Quantum;

typedef struct _ImageInfo {
    unsigned long signature;
    int compression;
    char magick[2048];
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    unsigned long debug;
    char filename[2048];
    unsigned long columns;
    unsigned long rows;
    unsigned long colors;
    unsigned long storage_class;
    unsigned long matte;
    double x_resolution;
    double y_resolution;
    void *exception;
    void *previous;
    void *colormap;
} Image;

typedef struct _StringInfo {
    size_t length;
    void *datum;
} StringInfo;

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum alpha;
} PixelPacket;

typedef struct _IndexPacket {
    unsigned char index;
} IndexPacket;

typedef struct _PICTRectangle {
    short top;
    short left;
    short bottom;
    short right;
} PICTRectangle;

typedef struct _PICTPixmap {
    unsigned short version;
    unsigned short pack_type;
    unsigned long pack_size;
    unsigned short pixel_type;
    unsigned short bits_per_pixel;
    unsigned short component_count;
    unsigned short component_size;
    unsigned long plane_bytes;
    unsigned long table;
    unsigned long reserved;
} PICTPixmap;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define DefaultResolution 72.0
#define MaxTextExtent 2048
#define JPEGCompression 1
#define DirectClass 1
#define PseudoClass 2
#define sRGBColorspace 1
#define ResourceLimitError 1
#define ImageError 1
#define SaveImageTag 1
#define TraceEvent 1
#define WriteBinaryBlobMode 1

#define ThrowWriterException(code,reason) return(MagickFalse)
#define LogMagickEvent(event,module,...) (0)
#define GetMagickModule() ("module")
#define OpenBlob(a,b,c,d) (MagickTrue)
#define CloseBlob(a) (0)
#define WriteBlob(a,b,c) (0)
#define WriteBlobByte(a,b) (0)
#define WriteBlobMSBShort(a,b) (0)
#define WriteBlobMSBLong(a,b) (0)
#define WriteBlobString(a,b) (0)
#define GetImageProfile(a,b) (NULL)
#define GetStringInfoLength(a) (0)
#define GetStringInfoDatum(a) (NULL)
#define CloneImage(a,b,c,d,e) (NULL)
#define CloneImageInfo(a) (NULL)
#define DestroyImageInfo(a) (NULL)
#define DestroyImage(a) (NULL)
#define ImageToBlob(a,b,c,d) (NULL)
#define GetVirtualPixels(a,b,c,d,e,f) (NULL)
#define GetVirtualIndexQueue(a) (NULL)
#define SetImageProgress(a,b,c,d) (MagickTrue)
#define TellBlob(a) (0)
#define SeekBlob(a,b,c) (0)
#define AcquireQuantumMemory(a,b) malloc((a)*(b))
#define RelinquishMagickMemory(a) (free(a), NULL)
#define ResetMagickMemory(a,b,c) memset(a,b,c)
#define CopyMagickString(a,b,c) strncpy(a,b,c)
#define TransformImageColorspace(a,b) (0)
#define ScaleQuantumToShort(a) (0)
#define ScaleQuantumToChar(a) (0)
#define GetPixelRed(a) (0)
#define GetPixelGreen(a) (0)
#define GetPixelBlue(a) (0)
#define GetPixelAlpha(a) (0)
#define GetPixelIndex(a) (0)
#define EncodeImage(a,b,c,d) (0)
#define IssRGBCompatibleColorspace(a) (0)