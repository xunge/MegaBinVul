#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

typedef unsigned char Quantum;
typedef int MagickStatusType;
typedef unsigned long long MagickSizeType;
typedef long long MagickOffsetType;
typedef double MagickRealType;
typedef int MagickBooleanType;
typedef ptrdiff_t ssize_t;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define BlendPixelTrait 1
#define UndefinedPixelTrait 0
#define DirectClass 1
#define PseudoClass 2
#define LoadImageTag 1
#define LoadImagesTag 2
#define TraceEvent 1
#define CorruptImageError 1
#define ResourceLimitError 1
#define ReadBinaryBlobMode 1

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} PixelInfo;

typedef struct _MemoryInfo {
    void *blob;
} MemoryInfo;

typedef struct _Image {
    unsigned long signature;
    struct _Image *previous;
    struct _Image *next;
    size_t scene;
    size_t columns;
    size_t rows;
    struct {
        ssize_t x;
        ssize_t y;
    } page;
    unsigned char alpha_trait;
    size_t colors;
    PixelInfo *colormap;
    unsigned char storage_class;
    const char *filename;
} Image;

#define ThrowReaderException(code,reason) return(DestroyImageList(image))
#define ThrowFileException(exception,code,reason,description) break
#define ValidateColormapValue(image,value,index,exception) *index = value

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
int ReadBlobByte(Image *);
short ReadBlobLSBShort(Image *);
short ReadBlobLSBSignedShort(Image *);
MagickBooleanType EOFBlob(const Image *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
void *GetVirtualMemoryBlob(MemoryInfo *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
char *DestroyString(char *);
MagickBooleanType SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
Image *DestroyImageList(Image *);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickBooleanType AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
MagickOffsetType TellBlob(Image *);
MagickOffsetType GetBlobSize(Image *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
void SetPixelIndex(Image *, Quantum, Quantum *);
size_t GetPixelChannels(const Image *);

#define ScaleShortToQuantum(x) ((Quantum) (x))
#define ScaleCharToQuantum(x) ((Quantum) (x))
#define ClampToQuantum(x) ((Quantum) (x))