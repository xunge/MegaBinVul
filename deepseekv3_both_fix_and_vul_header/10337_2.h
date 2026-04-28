#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    MagickBooleanType matte;
    size_t colors;
    struct _PixelPacket *colormap;
    int storage_class;
    struct _Image *previous;
    ExceptionInfo exception;
    char *filename;
    size_t scene;
    struct {
        int x;
        int y;
    } page;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
} ImageInfo;

typedef struct _MemoryInfo MemoryInfo;
typedef struct _PixelPacket {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    unsigned short alpha;
} PixelPacket;

typedef unsigned int IndexPacket;

typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned int MagickStatusType;
typedef long ssize_t;
typedef unsigned long size_t;

#define MagickSignature 0xabacadabUL
#define TraceEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define LoadImageTag 0
#define LoadImagesTag 0
#define DirectClass 0
#define ReadBinaryBlobMode 0
#define EOF (-1)

Image *AcquireImage(const ImageInfo *);
Image *DestroyImageList(Image *);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
void AcquireNextImage(const ImageInfo *, Image *);
void InheritException(ExceptionInfo *, ExceptionInfo *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void ThrowReaderException(int, const char *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
void *GetVirtualMemoryBlob(MemoryInfo *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType EOFBlob(const Image *);
MagickBooleanType AcquireImageColormap(Image *, size_t);
MagickBooleanType IsValidColormapIndex(Image *, size_t, IndexPacket *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
MagickBooleanType SetImageProperty(Image *, const char *, const char *);
char *DestroyString(char *);
char *GetMagickModule(void);
int ReadBlob(Image *, size_t, unsigned char *);
int ReadBlobByte(Image *);
int ReadBlobLSBShort(Image *);
int CloseBlob(Image *);
long TellBlob(Image *);
long GetBlobSize(Image *);
void LogMagickEvent(int, const char *, const char *, const char *);
PixelPacket *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
IndexPacket *GetAuthenticIndexQueue(Image *);
unsigned short ScaleShortToQuantum(unsigned short);
unsigned char ScaleCharToQuantum(unsigned char);
void SetPixelRed(PixelPacket *, unsigned short);
void SetPixelGreen(PixelPacket *, unsigned short);
void SetPixelBlue(PixelPacket *, unsigned short);
void SetPixelAlpha(PixelPacket *, unsigned char);
void SetPixelIndex(IndexPacket *, unsigned char);
void SyncImage(Image *);