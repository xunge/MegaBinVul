#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef unsigned char MagickBooleanType;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned char IndexPacket;
typedef signed long ssize_t;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _PixelPacket {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    unsigned short alpha;
} PixelPacket;

typedef struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    MagickBooleanType matte;
    struct _Image *previous;
    struct _Image *next;
    ExceptionInfo *exception;
    unsigned long signature;
    int storage_class;
    int scene;
    char *filename;
    PixelPacket *colormap;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    MagickBooleanType ping;
    char *filename;
    size_t number_scenes;
    size_t scene;
} ImageInfo;

struct _ExceptionInfo {
    unsigned long signature;
};

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define PseudoClass 1
#define ReadBinaryBlobMode 1

enum {
    TraceEvent,
    LoadImageTag,
    LoadImagesTag,
    CorruptImageError,
    ResourceLimitError,
    CoderError
};

void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void*);
void ResetMagickMemory(void*, int, size_t);
void *CopyMagickMemory(void*, const void*, size_t);
unsigned long ReadBlobMSBLong(Image*);
ssize_t ReadBlob(Image*, size_t, void*);
Image *AcquireImage(const ImageInfo*);
Image *DestroyImageList(Image*);
Image *GetFirstImageInList(Image*);
Image *GetNextImageInList(Image*);
Image *SyncNextImageInList(Image*);
MagickBooleanType OpenBlob(const ImageInfo*, Image*, int, ExceptionInfo*);
MagickBooleanType SetImageExtent(Image*, size_t, size_t);
MagickBooleanType SetImageProgress(Image*, int, MagickOffsetType, size_t);
MagickBooleanType SyncAuthenticPixels(Image*, ExceptionInfo*);
MagickBooleanType DecodeImage(const unsigned char*, size_t, unsigned char*, size_t);
MagickBooleanType EOFBlob(const Image*);
MagickBooleanType AcquireImageColormap(Image*, size_t);
MagickBooleanType HeapOverflowSanityCheck(size_t, size_t);
PixelPacket *QueueAuthenticPixels(Image*, ssize_t, ssize_t, size_t, size_t, ExceptionInfo*);
IndexPacket *GetAuthenticIndexQueue(Image*);
void LogMagickEvent(int, const char*, const char*, ...);
void CloseBlob(Image*);
void AcquireNextImage(const ImageInfo*, Image*);
void InheritException(ExceptionInfo*, ExceptionInfo*);
void ThrowReaderException(int, const char*);
void ThrowFileException(ExceptionInfo*, int, const char*, const char*);
void SetPixelIndex(IndexPacket*, unsigned char);
void SetPixelRed(PixelPacket*, unsigned short);
void SetPixelGreen(PixelPacket*, unsigned short);
void SetPixelBlue(PixelPacket*, unsigned short);
void SetPixelAlpha(PixelPacket*, unsigned short);
unsigned short ScaleCharToQuantum(unsigned char);
unsigned char ConstrainColormapIndex(Image*, unsigned char);
unsigned short GetPixelRed(PixelPacket*);
unsigned short GetPixelGreen(PixelPacket*);
unsigned short GetPixelBlue(PixelPacket*);
long TellBlob(Image*);
long GetBlobSize(Image*);
void SyncImage(Image*);
const char *GetMagickModule(void);