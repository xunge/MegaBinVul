#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;

#define MagickCoreSignature 0x1234
#define TraceEvent 0

typedef unsigned long Quantum;
typedef unsigned short MagickSizeType;
typedef unsigned char MagickStatusType;

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
};

struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
    size_t colors;
    struct _PixelPacket *colormap;
    size_t depth;
};

struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
};

struct _ExceptionInfo {
    unsigned long signature;
};

typedef enum {
    WriteBinaryBlobMode
} BlobMode;

typedef enum {
    PaletteType
} ImageType;

typedef enum {
    sRGBColorspace
} ColorspaceType;

typedef enum {
    ResourceLimitError
} ErrorType;

#define GetMagickModule() ""
#define LogMagickEvent(a,b,c,d) 0
#define OpenBlob(a,b,c,d) MagickFalse
#define TransformImageColorspace(a,b,c) 0
#define IsPaletteImage(a) MagickFalse
#define SetImageType(a,b,c) 0
#define GetImageQuantumDepth(a,b) 0
#define AcquireQuantumMemory(a,b) NULL
#define ThrowWriterException(a,b) return(MagickFalse)
#define ScaleQuantumToChar(a) 0
#define ScaleQuantumToShort(a) 0
#define WriteBlob(a,b,c) 0
#define RelinquishMagickMemory(a) NULL
#define GetVirtualPixels(a,b,c,d,e,f) NULL
#define GetPixelIndex(a,b) 0
#define GetPixelChannels(a) 0
#define CloseBlob(a) 0