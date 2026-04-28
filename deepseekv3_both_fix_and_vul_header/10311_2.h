#include <assert.h>
#include <stddef.h>

typedef unsigned int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef unsigned long long MagickSizeType;
typedef long long MagickOffsetType;
typedef long ssize_t;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    MagickBooleanType matte;
    size_t depth;
    unsigned int storage_class;
    size_t colors;
    size_t scene;
    struct _Image *previous;
    ExceptionInfo exception;
    char *filename;
    unsigned int compression;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
} ImageInfo;

typedef struct _MemoryInfo {
    void *blob;
} MemoryInfo;

typedef struct _PixelPacket {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    unsigned short opacity;
    unsigned short alpha;
} PixelPacket;

typedef struct _IndexPacket {
    size_t index;
} IndexPacket;

typedef struct {
    unsigned short magic;
    unsigned char storage;
    unsigned char bytes_per_pixel;
    unsigned short dimension;
    unsigned short columns;
    unsigned short rows;
    unsigned short depth;
    unsigned int minimum_value;
    unsigned int maximum_value;
    unsigned int sans;
    char name[80];
    unsigned int pixel_format;
    unsigned char filler[404];
} SGIInfo;

#define MagickSignature 0xabacadabUL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define NoCompression 0
#define RLECompression 1
#define PseudoClass 1
#define DirectClass 2
#define OpaqueOpacity 0
#define TraceEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define LoadImageTag 0
#define LoadImagesTag 0
#define ReadBinaryBlobMode 0
#define SEEK_SET 0

Image *AcquireImage(const ImageInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void *AcquireVirtualMemory(size_t, size_t);
void *DestroyImageList(Image *);
IndexPacket *GetAuthenticIndexQueue(Image *);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
void *GetVirtualMemoryBlob(MemoryInfo *);
PixelPacket *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void *RelinquishMagickMemory(void *);
void *RelinquishVirtualMemory(MemoryInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
Image *SyncNextImageInList(Image *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType EOFBlob(Image *);
MagickBooleanType LogMagickEvent(unsigned int, const char *, const char *, ...);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
size_t ReadBlob(Image *, size_t, unsigned char *);
unsigned char ReadBlobByte(Image *);
MagickBooleanType SGIDecode(size_t, ssize_t, unsigned char *, ssize_t, unsigned char *);
MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
MagickBooleanType SetImageProgress(Image *, unsigned int, MagickOffsetType, size_t);
MagickBooleanType SetImageProperty(Image *, const char *, const char *);
MagickBooleanType SyncImage(Image *);
MagickBooleanType AcquireImageColormap(Image *, size_t);
MagickBooleanType AcquireNextImage(const ImageInfo *, Image *);
MagickBooleanType InheritException(ExceptionInfo *, ExceptionInfo *);
MagickBooleanType ThrowReaderException(unsigned int, const char *);
MagickBooleanType ThrowFileException(ExceptionInfo *, unsigned int, const char *, const char *);
MagickOffsetType TellBlob(Image *);
unsigned short ReadBlobMSBShort(Image *);
size_t GetBlobSize(Image *);
size_t MagickMin(size_t, size_t);
unsigned char ScaleCharToQuantum(unsigned char);
unsigned int ReadBlobMSBLong(Image *);
unsigned short ScaleShortToQuantum(unsigned short);
ssize_t ReadBlobMSBSignedLong(Image *);
const char *GetMagickModule(void);
void SetPixelRed(PixelPacket *, unsigned short);
void SetPixelGreen(PixelPacket *, unsigned short);
void SetPixelBlue(PixelPacket *, unsigned short);
void SetPixelOpacity(PixelPacket *, unsigned short);
void SetPixelAlpha(PixelPacket *, unsigned short);
void SetPixelIndex(IndexPacket *, size_t);