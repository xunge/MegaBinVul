#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef unsigned char Quantum;
typedef int MagickStatusType;
typedef long long MagickSizeType;
typedef long long MagickOffsetType;
typedef long ssize_t;
typedef unsigned long size_t;
typedef double MagickRealType;

typedef struct _MemoryInfo MemoryInfo;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _PixelInfo PixelInfo;

struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
};

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define UndefinedPixelTrait 0
#define BlendPixelTrait 1
#define DirectClass 1
#define PseudoClass 2
#define LoadImageTag 0
#define LoadImagesTag 0
#define TraceEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define ReadBinaryBlobMode "rb"
#define EOF (-1)

#define MagickMax(a,b) ((a) > (b) ? (a) : (b))

struct _Image {
    size_t columns;
    size_t rows;
    ssize_t scene;
    PixelInfo *colormap;
    size_t colors;
    unsigned int storage_class;
    unsigned int alpha_trait;
    struct _Image *previous;
    struct _Image *next;
    char *filename;
    struct {
        ssize_t x;
        ssize_t y;
    } page;
};

struct _ImageInfo {
    unsigned long signature;
    unsigned int debug;
    unsigned int ping;
    char *filename;
    ssize_t scene;
    size_t number_scenes;
};

struct _ExceptionInfo {
    unsigned long signature;
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
int OpenBlob(const ImageInfo *, Image *, const char *, ExceptionInfo *);
Image *DestroyImageList(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
void *GetVirtualMemoryBlob(MemoryInfo *);
void ThrowReaderException(ExceptionInfo *, const char *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
int EOFBlob(const Image *);
int ReadBlobByte(Image *);
short ReadBlobLSBShort(Image *);
short ReadBlobLSBSignedShort(Image *);
void *ResetMagickMemory(void *, int, size_t);
int SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
int SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
char *DestroyString(char *);
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
size_t GetPixelChannels(Image *);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
MagickOffsetType TellBlob(Image *);
MagickOffsetType GetBlobSize(Image *);
int CloseBlob(Image *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
Quantum ScaleCharToQuantum(unsigned char);
unsigned char ScaleQuantumToChar(Quantum);
Quantum ScaleShortToQuantum(short);
Quantum ClampToQuantum(MagickRealType);