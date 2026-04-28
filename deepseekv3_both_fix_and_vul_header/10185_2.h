#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _MemoryInfo MemoryInfo;
typedef unsigned char PixelPacket;
typedef unsigned char IndexPacket;
typedef int MagickStatusType;
typedef unsigned long long MagickSizeType;
typedef long long MagickOffsetType;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { TraceEvent } LogEventType;
typedef enum { CorruptImageError, ResourceLimitError } ErrorType;
typedef enum { ReadBinaryBlobMode } BlobMode;
typedef enum { LoadImageTag, LoadImagesTag } ProgressTag;
typedef enum { DirectClass } ClassType;

#define MagickSignature 0xabacadabUL
#define MagickMax(a,b) ((a) > (b) ? (a) : (b))

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    struct {
        ssize_t x;
        ssize_t y;
    } page;
    MagickBooleanType matte;
    size_t scene;
    size_t colors;
    struct {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    } *colormap;
    ClassType storage_class;
    ExceptionInfo exception;
    Image *previous;
    const char *filename;
};

void *AcquireQuantumMemory(size_t,size_t);
void *RelinquishMagickMemory(void *);
MemoryInfo *AcquireVirtualMemory(size_t,size_t);
void *GetVirtualMemoryBlob(MemoryInfo *);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
Image *AcquireImage(const ImageInfo *);
Image *DestroyImageList(Image *);
MagickBooleanType OpenBlob(const ImageInfo *,Image *,BlobMode,ExceptionInfo *);
ssize_t ReadBlob(Image *,size_t,unsigned char *);
short ReadBlobLSBShort(Image *);
short ReadBlobLSBSignedShort(Image *);
unsigned char ReadBlobByte(Image *);
void ThrowReaderException(ErrorType,const char *);
void ThrowFileException(ExceptionInfo *,ErrorType,const char *,const char *);
void LogMagickEvent(LogEventType,const char *,const char *,...);
const char *GetMagickModule(void);
MagickBooleanType SetImageExtent(Image *,size_t,size_t);
void InheritException(ExceptionInfo *,ExceptionInfo *);
MagickBooleanType SetImageProperty(Image *,const char *,const char *);
char *DestroyString(char *);
MagickBooleanType EOFBlob(const Image *);
MagickBooleanType SyncAuthenticPixels(Image *,ExceptionInfo *);
PixelPacket *QueueAuthenticPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
IndexPacket *GetAuthenticIndexQueue(Image *);
MagickBooleanType SetImageProgress(Image *,ProgressTag,MagickOffsetType,size_t);
MagickBooleanType SyncImage(Image *);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType AcquireImageColormap(Image *,size_t);
MagickBooleanType IsValidColormapIndex(Image *,size_t,IndexPacket *,ExceptionInfo *);
void SetPixelRed(PixelPacket *,unsigned char);
void SetPixelGreen(PixelPacket *,unsigned char);
void SetPixelBlue(PixelPacket *,unsigned char);
void SetPixelAlpha(PixelPacket *,unsigned char);
void SetPixelIndex(IndexPacket *,unsigned char);
unsigned char ScaleShortToQuantum(short);
unsigned char ScaleCharToQuantum(unsigned char);
MagickOffsetType TellBlob(Image *);
MagickSizeType GetBlobSize(Image *);
Image *AcquireNextImage(const ImageInfo *,Image *);