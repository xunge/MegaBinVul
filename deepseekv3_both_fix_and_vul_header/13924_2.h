#include <stddef.h>
#include <assert.h>
#include <sys/types.h>

typedef unsigned int MagickBooleanType;
typedef unsigned int Quantum;
typedef unsigned int IndexPacket;
typedef long MagickOffsetType;
typedef double MagickRealType;

typedef struct _ExceptionInfo {
    // exception fields
} ExceptionInfo;

typedef struct _PixelPacket {
    Quantum opacity;
    // other pixel fields
} PixelPacket;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    ExceptionInfo exception;
    size_t columns;
    size_t rows;
    size_t colors;
    PixelPacket *colormap;
    MagickBooleanType matte;
    unsigned int storage_class;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    char *filename;
    int type;
} ImageInfo;

typedef struct _MagickPixelPacket {
    MagickRealType opacity;
    unsigned int depth;
    int colorspace;
} MagickPixelPacket;

typedef struct _QuantizeInfo {
    // quantize info fields
} QuantizeInfo;

typedef struct _RectangleInfo {
    ssize_t x;
    ssize_t y;
    size_t width;
    size_t height;
} RectangleInfo;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define MaxTextExtent 2053
#define OpaqueOpacity 0U
#define TransparentOpacity QuantumRange
#define PseudoClass 1
#define PaletteType 1
#define TrueColorType 2
#define sRGBColorspace 1
#define XPMCompliance 1
#define TriangleFilter 1
#define QuantumRange ((Quantum) ~0)
#define SaveImageTag 1
#define WriteBinaryBlobMode 1
#define TraceEvent 1
#define BasePath 1

enum {
    ResourceLimitError,
    MemoryAllocationError
};

MagickBooleanType LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
MagickBooleanType TransformImageColorspace(Image *, int);
void SetGeometry(Image *, RectangleInfo *);
MagickBooleanType ParseMetaGeometry(const char *, ssize_t *, ssize_t *, size_t *, size_t *);
Image *ResizeImage(Image *, size_t, size_t, double, double, ExceptionInfo *);
ImageInfo *CloneImageInfo(const ImageInfo *);
MagickBooleanType AcquireUniqueFilename(char *);
MagickBooleanType SetImageGray(Image *, ExceptionInfo *);
Image *BlobToImage(ImageInfo *, const unsigned char *, size_t, ExceptionInfo *);
MagickBooleanType RelinquishUniqueFileResource(char *);
ImageInfo *DestroyImageInfo(ImageInfo *);
QuantizeInfo *AcquireQuantizeInfo(const ImageInfo *);
MagickBooleanType RemapImage(QuantizeInfo *, Image *, Image *);
QuantizeInfo *DestroyQuantizeInfo(QuantizeInfo *);
Image *DestroyImage(Image *);
MagickBooleanType CompressImageColormap(Image *);
PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelOpacity(PixelPacket *, Quantum);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageType(Image *, int);
void *ResizeQuantumMemory(void **, size_t, size_t);
void ThrowWriterException(int, const char *);
IndexPacket *GetAuthenticIndexQueue(Image *);
void SetPixelIndex(IndexPacket *, size_t);
MagickBooleanType WriteBlobString(Image *, const char *);
void GetPathComponent(const char *, int, char *);
MagickBooleanType FormatLocaleString(char *, size_t, const char *, ...);
void GetMagickPixelPacket(Image *, MagickPixelPacket *);
void SetMagickPixelPacket(Image *, PixelPacket *, IndexPacket *, MagickPixelPacket *);
MagickBooleanType QueryMagickColorname(Image *, MagickPixelPacket *, int, char *, ExceptionInfo *);
MagickBooleanType CopyMagickString(char *, const char *, size_t);
const PixelPacket *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
const IndexPacket *GetVirtualIndexQueue(Image *);
size_t GetPixelIndex(const IndexPacket *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
MagickBooleanType CloseBlob(Image *);