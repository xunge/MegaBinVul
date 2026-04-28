#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _MemoryInfo MemoryInfo;
typedef struct _PCXInfo PCXInfo;
typedef unsigned char IndexPacket;
typedef struct _PixelPacket PixelPacket;
typedef unsigned long Quantum;
typedef long MagickOffsetType;
typedef unsigned long size_t;
typedef long ssize_t;

typedef enum { 
    MagickFalse, 
    MagickTrue 
} MagickBooleanType;

typedef enum { 
    PseudoClass, 
    DirectClass 
} ClassType;

typedef enum { 
    ReadBinaryBlobMode 
} BlobMode;

typedef enum { 
    CorruptImageError, 
    ResourceLimitError, 
    UnexpectedEndOfFile 
} ExceptionType;

typedef enum { 
    TraceEvent 
} LogEventType;

typedef enum { 
    PixelsPerInchResolution 
} ResolutionType;

typedef enum { 
    LoadImageTag, 
    LoadImagesTag 
} ProgressType;

struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum opacity;
};

struct _PCXInfo {
    unsigned char identifier;
    unsigned char version;
    unsigned char encoding;
    unsigned char bits_per_pixel;
    short left;
    short top;
    short right;
    short bottom;
    short horizontal_resolution;
    short vertical_resolution;
    unsigned char reserved;
    unsigned char planes;
    unsigned short bytes_per_line;
    unsigned short palette_info;
    unsigned short horizontal_screensize;
    unsigned short vertical_screensize;
    unsigned char colormap_signature;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    ResolutionType units;
    double x_resolution;
    double y_resolution;
    size_t colors;
    ClassType storage_class;
    MagickBooleanType matte;
    PixelPacket *colormap;
    ExceptionInfo exception;
    Image *previous;
    Image *next;
    size_t scene;
    char *filename;
    MagickBooleanType debug;
    unsigned long signature;
};

struct _ImageInfo {
    char *magick;
    char *filename;
    MagickBooleanType debug;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
    unsigned long signature;
};

struct _MemoryInfo {
    void *blob;
};

#define MagickSignature 0xabacadabUL
#define QuantumRange 255UL

#define ThrowReaderException(severity,tag)
#define LogMagickEvent(event,module,message,...) ((void)0)
#define GetMagickModule() NULL
#define AcquireImage(info) NULL
#define DestroyImageList(image) NULL
#define OpenBlob(info,image,mode,exception) MagickFalse
#define ReadBlob(image,count,buffer) 0
#define ReadBlobByte(image) 0
#define ReadBlobLSBShort(image) 0
#define ReadBlobLSBLong(image) 0
#define SeekBlob(image,offset,whence) 0
#define CloseBlob(image) ((void)0)
#define EOFBlob(image) MagickFalse
#define AcquireQuantumMemory(count,size) NULL
#define RelinquishMagickMemory(memory) NULL
#define AcquireVirtualMemory(count,size) NULL
#define RelinquishVirtualMemory(memory) NULL
#define GetVirtualMemoryBlob(memory) NULL
#define CopyMagickMemory(destination,source,size) memcpy(destination,source,size)
#define AcquireImageColormap(image,colors) MagickFalse
#define SetImageExtent(image,columns,rows) MagickFalse
#define InheritException(exception,image_exception) ((void)0)
#define QueueAuthenticPixels(image,x,y,columns,rows,exception) NULL
#define GetAuthenticIndexQueue(image) NULL
#define SyncAuthenticPixels(image,exception) MagickFalse
#define SetImageProgress(image,tag,offset,span) MagickFalse
#define SyncImage(image) ((void)0)
#define AcquireNextImage(info,image) ((void)0)
#define GetNextImageInList(image) NULL
#define SyncNextImageInList(image) NULL
#define GetFirstImageInList(image) NULL
#define TellBlob(image) 0
#define GetBlobSize(image) 0
#define ThrowFileException(exception,severity,tag,message) ((void)0)
#define ScaleCharToQuantum(c) ((Quantum)(c))
#define MagickAbsoluteValue(x) ((x) < 0 ? -(x) : (x))
#define MagickMin(a,b) ((a) < (b) ? (a) : (b))
#define HeapOverflowSanityCheck(a,b) MagickFalse
#define LocaleCompare(s1,s2) 0
#define MagickMax(a,b) ((a) > (b) ? (a) : (b))

static inline void SetPixelIndex(IndexPacket *index, unsigned char value) {
    *index = value;
}

static inline void SetPixelRed(PixelPacket *pixel, Quantum red) {
    pixel->red = red;
}

static inline void SetPixelGreen(PixelPacket *pixel, Quantum green) {
    pixel->green = green;
}

static inline void SetPixelBlue(PixelPacket *pixel, Quantum blue) {
    pixel->blue = blue;
}

static inline void SetPixelAlpha(PixelPacket *pixel, Quantum alpha) {
    pixel->opacity = alpha;
}