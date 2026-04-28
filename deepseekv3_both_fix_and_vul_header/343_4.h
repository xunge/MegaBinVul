#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef double MagickRealType;
typedef uint32_t MagickBooleanType;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t depth;
    unsigned int alpha_trait;
    unsigned int colors;
    unsigned int storage_class;
    unsigned int endian;
    unsigned int colorspace;
    struct _Image *previous;
    struct _Image *next;
    unsigned long scene;
    char *filename;
    struct {
        MagickRealType red;
        MagickRealType green;
        MagickRealType blue;
    } *colormap;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    unsigned long number_scenes;
    unsigned long scene;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef uint8_t Quantum;
typedef uint64_t MagickSizeType;
typedef int64_t ssize_t;
typedef uint64_t size_t;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define LSBEndian 0
#define MSBEndian 1
#define UndefinedPixelTrait 0
#define BlendPixelTrait 1
#define GRAYColorspace 1
#define PseudoClass 1
#define DirectClass 2
#define QuantumRange 65535
#define OpaqueAlpha QuantumRange
#define TraceEvent 1
#define CorruptImageError 1
#define ResourceLimitError 1
#define CoderError 1
#define LoadImageTag 1
#define LoadImagesTag 2

#define MAGICKCORE_QUANTUM_DEPTH 16

#define ThrowReaderException(code,reason) \
    { image=DestroyImageList(image); return((Image *) NULL); }

#define ThrowFileException(exception,severity,reason,description) ((void)0)

static void *AcquireQuantumMemory(size_t count, size_t size) {
    return malloc(count * size);
}

static void *RelinquishMagickMemory(void *memory) {
    free(memory);
    return NULL;
}

#define AcquireImageColormap(image,colors,exception) MagickTrue
#define SetImageProperty(image,property,value,exception) MagickTrue
#define SetImageExtent(image,columns,rows,exception) MagickTrue
#define SetImageBackgroundColor(image,exception) MagickTrue
#define QueueAuthenticPixels(image,x,y,columns,rows,exception) ((Quantum *) NULL)
#define SyncAuthenticPixels(image,exception) MagickTrue
#define SetImageProgress(image,tag,offset,span) MagickTrue
#define SyncImage(image,exception) MagickTrue
#define GetNextImageInList(image) ((Image *) NULL)
#define AcquireNextImage(image_info,image,exception) ((void)0)
#define SyncNextImageInList(image) (image)
#define GetFirstImageInList(image) (image)
#define DestroyImageList(image) ((Image *) NULL)
#define LogMagickEvent(event,module,format,...) 0
#define GetMagickModule() "VIFF"
#define ReadBlob(image,count,data) 0
#define ReadBlobLong(image) 0
#define ReadBlobSignedLong(image) 0
#define ReadBlobByte(image) 0
#define OpenBlob(image_info,image,mode,exception) MagickFalse
#define CloseBlob(image) 0
#define TellBlob(image) 0
#define GetBlobSize(image) 0
#define EOFBlob(image) MagickFalse
#define MSBOrderShort(buffer,length) ((void) 0)
#define MSBOrderLong(buffer,length) ((void) 0)
#define ScaleCharToQuantum(value) ((Quantum) (value))
#define ClampToQuantum(value) ((Quantum) (value))
#define ConstrainColormapIndex(image,index,exception) (index)
#define SetPixelRed(image,value,q) ((void) 0)
#define SetPixelGreen(image,value,q) ((void) 0)
#define SetPixelBlue(image,value,q) ((void) 0)
#define SetPixelAlpha(image,value,q) ((void) 0)
#define SetPixelIndex(image,value,q) ((void) 0)
#define GetPixelRed(image,q) 0
#define GetPixelGreen(image,q) 0
#define GetPixelBlue(image,q) 0
#define GetPixelChannels(image) 1
#define HeapOverflowSanityCheck(a,b) MagickFalse
#define AcquireImage(image_info,exception) ((Image *) NULL)
#define ThrowMagickException(exception,module,severity,reason,description,...) 0
#define MagickMax(a,b) ((a) > (b) ? (a) : (b))