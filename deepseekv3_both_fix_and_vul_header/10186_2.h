#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef unsigned char Quantum;
typedef int MagickStatusType;
typedef size_t MagickSizeType;
typedef ptrdiff_t MagickOffsetType;
typedef int MagickBooleanType;
typedef ptrdiff_t ssize_t;
typedef double MagickRealType;

#define MagickFalse 0
#define MagickTrue 1
#define MagickCoreSignature 0xabacadabUL
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
#define GetPixelChannels(image) 4
#define EOF (-1)

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _MemoryInfo MemoryInfo;
typedef struct _PixelInfo PixelInfo;

struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t scene;
    size_t colors;
    int storage_class;
    int alpha_trait;
    struct {
        int x;
        int y;
    } page;
    char *filename;
    Image *previous;
    Image *next;
    PixelInfo *colormap;
};

struct _ImageInfo {
    unsigned long signature;
    int debug;
    int ping;
    size_t number_scenes;
    size_t scene;
    char *filename;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _MemoryInfo {
};

struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
Image *DestroyImageList(Image *);
int OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
void ThrowReaderException(int, const char *);
int ReadBlobLSBShort(Image *);
int ReadBlobByte(Image *);
int EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void *AcquireQuantumMemory(size_t, size_t);
int ReadBlobLSBSignedShort(Image *);
void *RelinquishMagickMemory(void *);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
void *GetVirtualMemoryBlob(MemoryInfo *);
void *DestroyString(void *);
int SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
int SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
int SyncAuthenticPixels(Image *, ExceptionInfo *);
int SetImageProgress(Image *, int, MagickOffsetType, size_t);
int AcquireImageColormap(Image *, size_t, ExceptionInfo *);
int SyncImage(Image *, ExceptionInfo *);
void ValidateColormapValue(Image *, ssize_t, Quantum *, ExceptionInfo *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
void SetPixelIndex(Image *, Quantum, Quantum *);
Quantum ScaleCharToQuantum(unsigned char);
Quantum ScaleShortToQuantum(int);
Quantum ClampToQuantum(MagickRealType);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
ssize_t TellBlob(Image *);
ssize_t GetBlobSize(Image *);
int CloseBlob(Image *);
size_t MagickMax(size_t, size_t);