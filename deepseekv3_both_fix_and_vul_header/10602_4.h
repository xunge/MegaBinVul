#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _IconFile IconFile;
typedef struct _IconInfo IconInfo;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define MaxIcons 256
#define MaxTextExtent 4096
#define TransparentOpacity 0
#define OpaqueOpacity (~0)
#define LoadImageTag 0
#define LoadImagesTag 1
#define CoderEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define PseudoClass 0
#define DirectClass 1
#define ReadBinaryBlobMode 0
#define SEEK_SET 0

typedef unsigned char MagickBooleanType;
typedef unsigned long Quantum;
typedef unsigned long MagickOffsetType;
typedef unsigned long MagickSizeType;

struct _Image {
    unsigned long signature;
    char *filename;
    size_t columns;
    size_t rows;
    size_t depth;
    MagickBooleanType matte;
    MagickBooleanType debug;
    unsigned long scene;
    unsigned long colors;
    unsigned long storage_class;
    struct {
        Quantum red;
        Quantum green;
        Quantum blue;
    } *colormap;
    void *blob;
    ExceptionInfo *exception;
    struct _Image *previous;
    struct _Image *next;
};

struct _ImageInfo {
    unsigned long signature;
    char *filename;
    char magick[MaxTextExtent];
    MagickBooleanType ping;
    unsigned long scene;
    unsigned long number_scenes;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _IconFile {
    short reserved;
    short resource_type;
    short count;
    struct {
        unsigned char width;
        unsigned char height;
        unsigned char colors;
        unsigned char reserved;
        unsigned short planes;
        unsigned short bits_per_pixel;
        unsigned long size;
        unsigned long offset;
    } directory[MaxIcons];
};

struct _IconInfo {
    unsigned long size;
    unsigned char width;
    unsigned char height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned long compression;
    unsigned long image_size;
    unsigned long x_pixels;
    unsigned long y_pixels;
    unsigned long number_colors;
    unsigned long colors_important;
};

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum opacity;
} PixelPacket;

typedef unsigned short IndexPacket;

static inline Quantum ScaleCharToQuantum(unsigned char value) {
    return (Quantum) value;
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

static inline void SetPixelOpacity(PixelPacket *pixel, Quantum opacity) {
    pixel->opacity = opacity;
}

static inline void SetPixelIndex(IndexPacket *indexes, IndexPacket index) {
    *indexes = index;
}

static inline MagickSizeType MagickMax(MagickSizeType a, MagickSizeType b) {
    return (a > b) ? a : b;
}

static Image *AcquireImage(const ImageInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static short ReadBlobLSBShort(Image *);
static unsigned char ReadBlobByte(Image *);
static long ReadBlobLSBLong(Image *);
static long ReadBlobLSBSignedLong(Image *);
static MagickBooleanType EOFBlob(const Image *);
static MagickSizeType GetBlobSize(const Image *);
static ssize_t SeekBlob(Image *, MagickOffsetType, int);
static void ThrowReaderException(int, const char *);
static void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
static void *AcquireQuantumMemory(size_t, size_t);
static void *RelinquishMagickMemory(void *);
static void CopyMagickMemory(void *, const void *, size_t);
static ImageInfo *CloneImageInfo(const ImageInfo *);
static void CopyMagickString(char *, const char *, size_t);
static Image *BlobToImage(ImageInfo *, const void *, size_t, ExceptionInfo *);
static ImageInfo *DestroyImageInfo(ImageInfo *);
static void DestroyBlob(Image *);
static void *ReferenceBlob(void *);
static void ReplaceImageInList(Image **, Image *);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t);
static void InheritException(ExceptionInfo *, ExceptionInfo *);
static PixelPacket *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static IndexPacket *GetAuthenticIndexQueue(Image *);
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
static MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, MagickSizeType);
static void SyncImage(Image *);
static PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static void AcquireNextImage(const ImageInfo *, Image *);
static Image *GetNextImageInList(Image *);
static Image *SyncNextImageInList(Image *);
static MagickOffsetType TellBlob(const Image *);
static int CloseBlob(Image *);
static Image *GetFirstImageInList(Image *);
static void LogMagickEvent(int, const char *, const char *, ...);
static const char *GetMagickModule(void);
static MagickBooleanType AcquireImageColormap(Image *, size_t);
static ssize_t ReadBlob(Image *, size_t, void *);