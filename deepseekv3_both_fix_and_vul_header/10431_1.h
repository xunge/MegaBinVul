#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _PCXInfo PCXInfo;
typedef struct _MemoryInfo MemoryInfo;
typedef unsigned long MagickOffsetType;
typedef unsigned char MagickBooleanType;
typedef unsigned long Quantum;
typedef unsigned char IndexPacket;
typedef struct _PixelPacket PixelPacket;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define CorruptImageError 1
#define ResourceLimitError 2
#define TraceEvent 3
#define PixelsPerInchResolution 1
#define DirectClass 1
#define PseudoClass 2
#define LoadImageTag 1
#define LoadImagesTag 2
#define QuantumRange 65535UL

#define MagickMin(a,b) ((a) < (b) ? (a) : (b))
#define MagickMax(a,b) ((a) > (b) ? (a) : (b))
#define MagickAbsoluteValue(x) ((x) < 0 ? -(x) : (x))
#define ScaleCharToQuantum(x) ((Quantum) (x))
#define ThrowReaderException(severity,tag) return((Image *) NULL)
#define ThrowFileException(exception,severity,tag,message) return((Image *) NULL)
#define AcquireImage(image_info) ((Image *) NULL)
#define DestroyImageList(image) ((Image *) NULL)
#define OpenBlob(image_info,image,mode,exception) MagickFalse
#define ReadBlob(image,count,data) 0
#define ReadBlobByte(image) 0
#define ReadBlobLSBShort(image) 0
#define ReadBlobLSBLong(image) 0
#define SeekBlob(image,offset,whence) 0
#define EOFBlob(image) MagickFalse
#define CloseBlob(image) 0
#define TellBlob(image) 0
#define GetBlobSize(image) 0
#define LogMagickEvent(event,module,format,...) 0
#define GetMagickModule() ""
#define AcquireQuantumMemory(count,size) malloc((count)*(size))
#define RelinquishMagickMemory(memory) (free(memory), NULL)
#define AcquireVirtualMemory(count,size) ((MemoryInfo *) NULL)
#define RelinquishVirtualMemory(memory) ((MemoryInfo *) NULL)
#define GetVirtualMemoryBlob(memory) ((unsigned char *) NULL)
#define CopyMagickMemory(destination,source,size) memcpy(destination,source,size)
#define QueueAuthenticPixels(image,x,y,columns,rows,exception) ((PixelPacket *) NULL)
#define GetAuthenticIndexQueue(image) ((IndexPacket *) NULL)
#define SyncAuthenticPixels(image,exception) MagickFalse
#define SyncImage(image) ((void)0)
#define SetImageProgress(image,tag,offset,span) MagickFalse
#define AcquireNextImage(image_info,image) ((void)0)
#define GetNextImageInList(image) ((Image *) NULL)
#define SyncNextImageInList(image) ((Image *) NULL)
#define GetFirstImageInList(image) ((Image *) NULL)
#define SetImageExtent(image,columns,rows) MagickFalse
#define InheritException(exception,source) ((void)0)
#define AcquireImageColormap(image,colors) MagickFalse
#define HeapOverflowSanityCheck(a,b) MagickFalse
#define LocaleCompare(s1,s2) strcmp(s1,s2)
#define SetPixelIndex(indexes,value) ((void)0)
#define SetPixelRed(pixel,value) ((void)0)
#define SetPixelGreen(pixel,value) ((void)0)
#define SetPixelBlue(pixel,value) ((void)0)
#define SetPixelAlpha(pixel,value) ((void)0)

struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum alpha;
};

struct _Image {
    size_t columns;
    size_t rows;
    unsigned long depth;
    unsigned long units;
    double x_resolution;
    double y_resolution;
    size_t colors;
    unsigned long storage_class;
    MagickBooleanType matte;
    PixelPacket *colormap;
    void *exception;
    char *filename;
    Image *previous;
    Image *next;
    size_t scene;
    MagickBooleanType debug;
    unsigned long signature;
};

struct _ImageInfo {
    char *magick;
    char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
    MagickBooleanType debug;
    unsigned long signature;
};

struct _ExceptionInfo {
    unsigned long signature;
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

struct _MemoryInfo {
    void *blob;
};