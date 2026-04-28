#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MagickSignature 0xabacadabUL
#define MaxIcons 256
#define MaxTextExtent 2048
#define QuantumRange 255
#define TransparentOpacity 0
#define OpaqueOpacity QuantumRange

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    UndefinedClass,
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    CoderEvent,
    CorruptImageError,
    ResourceLimitError
} ExceptionType;

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _BlobInfo BlobInfo;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char opacity;
} PixelPacket;

typedef unsigned char IndexPacket;
typedef unsigned char Quantum;
typedef size_t MagickSizeType;
typedef long MagickOffsetType;

struct _ExceptionInfo {
    unsigned long signature;
    int severity;
    char *reason;
    char *description;
};

struct _BlobInfo {
    void *data;
    size_t length;
};

struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    MagickBooleanType matte;
    MagickBooleanType debug;
    ClassType storage_class;
    size_t colors;
    PixelPacket *colormap;
    Image *previous;
    Image *next;
    size_t scene;
    BlobInfo *blob;
    ExceptionInfo exception;
    char filename[MaxTextExtent];
};

struct _ImageInfo {
    unsigned long signature;
    char filename[MaxTextExtent];
    MagickBooleanType ping;
    size_t scene;
    size_t number_scenes;
    char magick[MaxTextExtent];
};

typedef struct {
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
} IconFile;

typedef struct {
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
} IconInfo;

#define SEEK_SET 0
#define LoadImageTag 0
#define LoadImagesTag 1

/* Function prototypes */
Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
short ReadBlobLSBShort(Image *);
void ThrowReaderException(ExceptionType, const char *);
unsigned char ReadBlobByte(Image *);
unsigned long ReadBlobLSBLong(Image *);
MagickBooleanType EOFBlob(Image *);
MagickSizeType MagickMax(MagickSizeType, MagickSizeType);
size_t GetBlobSize(Image *);
ssize_t SeekBlob(Image *, MagickOffsetType, int);
long ReadBlobLSBSignedLong(Image *);
void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
void *AcquireQuantumMemory(size_t, size_t);
void CopyMagickMemory(void *, const void *, size_t);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void CopyMagickString(char *, const char *, size_t);
Image *BlobToImage(ImageInfo *, const unsigned char *, size_t, ExceptionInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void *RelinquishMagickMemory(void *);
void DestroyBlob(Image *);
BlobInfo *ReferenceBlob(BlobInfo *);
void ReplaceImageInList(Image **, Image *);
MagickBooleanType AcquireImageColormap(Image *, size_t);
Quantum ScaleCharToQuantum(unsigned char);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
void InheritException(ExceptionInfo *, ExceptionInfo *);
PixelPacket *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
IndexPacket *GetAuthenticIndexQueue(Image *);
void SetPixelIndex(IndexPacket *, IndexPacket);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, ssize_t, size_t);
void SetPixelBlue(PixelPacket *, Quantum);
void SetPixelGreen(PixelPacket *, Quantum);
void SetPixelRed(PixelPacket *, Quantum);
void SetPixelAlpha(PixelPacket *, Quantum);
void SyncImage(Image *);
PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelOpacity(PixelPacket *, Quantum);
void AcquireNextImage(const ImageInfo *, Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickOffsetType TellBlob(Image *);
void CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
const char *GetMagickModule(void);
void LogMagickEvent(int, const char *, const char *, ...);