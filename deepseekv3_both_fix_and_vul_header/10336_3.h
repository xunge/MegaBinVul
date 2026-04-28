#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned char MagickBooleanType;
typedef size_t MagickSizeType;
typedef unsigned char IndexPacket;
typedef unsigned char Quantum;

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum alpha;
} PixelPacket;

typedef struct _ColormapEntry {
    Quantum red;
    Quantum green;
    Quantum blue;
} ColormapEntry;

typedef struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    MagickBooleanType matte;
    ColormapEntry *colormap;
    void *previous;
    int storage_class;
    size_t scene;
    char *filename;
    void *exception;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define PseudoClass 0
#define TraceEvent 1

typedef ssize_t MagickOffsetType;

static inline void CloseBlob(Image *image) {}
static inline void SyncImage(Image *image) {}
static inline void LogMagickEvent(int event, const char *module, const char *format, ...) {}
static inline void DecodeImage(const unsigned char *src, size_t src_len, 
                             unsigned char *dst, size_t dst_len) {}

#define ThrowReaderException(code,reason) 
#define ThrowFileException(exception,code,reason,file) 
#define InheritException(exception,image_exception) 
#define GetFirstImageInList(image) ((Image *) NULL)
#define GetNextImageInList(image) ((Image *) NULL)
#define SyncNextImageInList(image) ((Image *) NULL)
#define AcquireNextImage(image_info,image) 
#define DestroyImageList(image) ((Image *) NULL)
#define AcquireImage(image_info) ((Image *) NULL)
#define AcquireImageColormap(image,colors) MagickFalse
#define AcquireQuantumMemory(size,element_size) ((void *) NULL)
#define RelinquishMagickMemory(memory) ((void *) NULL)
#define ResetMagickMemory(memory,value,size) memset(memory,value,size)
#define CopyMagickMemory(destination,source,size) memcpy(destination,source,size)
#define ScaleCharToQuantum(value) ((Quantum) (value))
#define ConstrainColormapIndex(image,index) (index)
#define QueueAuthenticPixels(image,x,y,columns,rows,exception) ((PixelPacket *) NULL)
#define GetAuthenticIndexQueue(image) ((IndexPacket *) NULL)
#define SyncAuthenticPixels(image,exception) MagickFalse
#define SetImageProgress(image,tag,offset,span) MagickFalse
#define SetImageExtent(image,columns,rows) MagickFalse
#define GetMagickModule() ""
#define ReadBlob(image,count,data) 0
#define ReadBlobMSBLong(image) 0
#define OpenBlob(image_info,image,mode,exception) MagickFalse
#define EOFBlob(image) MagickFalse
#define TellBlob(image) 0
#define GetBlobSize(image) 0
#define CoderError 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define LoadImageTag 0
#define LoadImagesTag 0
#define ReadBinaryBlobMode 0

static inline void SetPixelIndex(IndexPacket *index, unsigned char value) {}
static inline void SetPixelAlpha(PixelPacket *p, Quantum value) {}
static inline void SetPixelRed(PixelPacket *p, Quantum value) {}
static inline void SetPixelGreen(PixelPacket *p, Quantum value) {}
static inline void SetPixelBlue(PixelPacket *p, Quantum value) {}
static inline Quantum GetPixelRed(PixelPacket *p) { return 0; }
static inline Quantum GetPixelGreen(PixelPacket *p) { return 0; }
static inline Quantum GetPixelBlue(PixelPacket *p) { return 0; }