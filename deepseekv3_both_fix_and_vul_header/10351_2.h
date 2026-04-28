#include <assert.h>
#include <stddef.h>
#include <stdint.h>

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef size_t MagickSizeType;
typedef ptrdiff_t ssize_t;
typedef int64_t MagickOffsetType;
typedef double MagickRealType;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    unsigned long scene;
    unsigned long number_scenes;
} ImageInfo;

typedef struct _ColormapEntry {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} ColormapEntry;

typedef struct _Image {
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    unsigned long storage_class;
    unsigned long colors;
    ColormapEntry *colormap;
    unsigned long alpha_trait;
    unsigned long signature;
    struct _Image *previous;
    struct _Image *next;
    unsigned long scene;
    const char *filename;
} Image;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0x12345678
#define MAGICKCORE_QUANTUM_DEPTH 16
#define BlendPixelTrait 1
#define UndefinedPixelTrait 0
#define PseudoClass 1
#define ReadBinaryBlobMode 0
#define LoadImageTag 0
#define LoadImagesTag 1

#define ThrowReaderException(code,reason) return((Image *) NULL)
#define ThrowFileException(exception,code,reason,file) return((Image *) NULL)
#define CoderError 1
#define CorruptImageError 2
#define ResourceLimitError 3

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned long ReadBlobMSBLong(Image *);
void *ResetMagickMemory(void *, int, size_t);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
int TraceEvent;
MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
ssize_t ReadBlob(Image *, size_t, void *);
void *RelinquishMagickMemory(void *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, unsigned long, unsigned long, ExceptionInfo *);
void SetPixelIndex(Image *, Quantum, Quantum *);
unsigned long GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, unsigned long);
void SetPixelAlpha(Image *, Quantum, Quantum *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
Quantum GetPixelRed(Image *, Quantum *);
Quantum GetPixelGreen(Image *, Quantum *);
Quantum GetPixelBlue(Image *, Quantum *);
Quantum ClampToQuantum(Quantum);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
MagickBooleanType EOFBlob(Image *);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
MagickOffsetType TellBlob(Image *);
MagickSizeType GetBlobSize(Image *);
void CloseBlob(Image *);
Quantum ScaleCharToQuantum(unsigned char);
MagickBooleanType AcquireImageColormap(Image *, unsigned long, ExceptionInfo *);
size_t MagickMax(size_t, size_t);
void DecodeImage(const unsigned char *, size_t, unsigned char *, size_t);