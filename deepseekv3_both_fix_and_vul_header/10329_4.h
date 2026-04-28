#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

typedef unsigned char Quantum;
typedef int MagickStatusType;
typedef unsigned long long MagickSizeType;
typedef double MagickRealType;
typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef ptrdiff_t ssize_t;

typedef struct _MemoryInfo MemoryInfo;

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} PixelTrait;

typedef struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} PixelInfo;

typedef struct _Image {
    unsigned long signature;
    struct _Image *previous;
    struct _Image *next;
    struct {
        ssize_t x;
        ssize_t y;
    } page;
    unsigned long columns;
    unsigned long rows;
    unsigned long scene;
    unsigned long colors;
    PixelTrait alpha_trait;
    unsigned long storage_class;
    PixelInfo *colormap;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    unsigned long scene;
    unsigned long number_scenes;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

#define ThrowReaderException(severity,tag) 
#define ThrowFileException(exception,severity,tag,reason) 
#define ScaleShortToQuantum(x) (x)
#define ScaleCharToQuantum(x) (x)
#define ClampToQuantum(x) (x)
#define GetPixelChannels(image) 0
#define GetFirstImageInList(image) (image)
#define SyncNextImageInList(image) (image)
#define GetNextImageInList(image) (NULL)
#define AcquireNextImage(image_info,image,exception) 
#define TellBlob(image) 0
#define GetBlobSize(image) 0
#define LoadImagesTag 0
#define LoadImageTag 0
#define TraceEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define MagickCoreSignature 0
#define ReadBinaryBlobMode 0
#define DirectClass 0
#define PseudoClass 0

#define AcquireImage(image_info,exception) (NULL)
#define DestroyImageList(image) (NULL)
#define OpenBlob(image_info,image,mode,exception) (0)
#define ReadBlob(image,count,data) (0)
#define ReadBlobLSBShort(image) (0)
#define ReadBlobByte(image) (0)
#define EOFBlob(image) (MagickFalse)
#define CloseBlob(image) (0)
#define LogMagickEvent(event,module,format,...) (void)0
#define GetMagickModule() (NULL)
#define AcquireQuantumMemory(count,size) (NULL)
#define RelinquishMagickMemory(ptr) (NULL)
#define AcquireVirtualMemory(length,size) (NULL)
#define GetVirtualMemoryBlob(memory) (NULL)
#define RelinquishVirtualMemory(memory) (NULL)
#define SetImageExtent(image,width,height,exception) (0)
#define SetImageProperty(image,property,value,exception) (0)
#define DestroyString(string) (NULL)
#define QueueAuthenticPixels(image,x,y,columns,rows,exception) (NULL)
#define SyncAuthenticPixels(image,exception) (MagickFalse)
#define SetImageProgress(image,tag,offset,span) (0)
#define AcquireImageColormap(image,colors,exception) (MagickFalse)
#define SyncImage(image,exception) (0)
#define SetPixelRed(image,value,q) 
#define SetPixelGreen(image,value,q) 
#define SetPixelBlue(image,value,q) 
#define SetPixelAlpha(image,value,q) 
#define SetPixelIndex(image,index,q) 
#define IsValidColormapIndex(image,index,result,exception) (MagickFalse)

static inline size_t MagickMax(size_t a, size_t b) {
    return (a > b) ? a : b;
}