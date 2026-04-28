#include <assert.h>
#include <stddef.h>
#include <stdint.h>

typedef unsigned char Quantum;
typedef uint64_t MagickSizeType;
typedef unsigned int MagickBooleanType;
typedef int ssize_t;
typedef size_t MagickOffsetType;
typedef double MagickRealType;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    unsigned long number_scenes;
    unsigned long scene;
} ImageInfo;

typedef struct _Colormap {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} Colormap;

typedef struct _Image {
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    unsigned long colors;
    unsigned long alpha_trait;
    unsigned long storage_class;
    const char *filename;
    struct _Image *previous;
    struct _Image *next;
    unsigned long scene;
    Colormap *colormap;
} Image;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0x12345678
#define MAGICKCORE_QUANTUM_DEPTH 16
#define UndefinedPixelTrait 0
#define BlendPixelTrait 1
#define PseudoClass 1
#define LoadImageTag 1
#define LoadImagesTag 2
#define TraceEvent 1
#define CorruptImageError 1
#define CoderError 2
#define ResourceLimitError 3
#define ReadBinaryBlobMode 1

#define ThrowReaderException(code,reason) return((Image *) NULL)
#define ThrowFileException(exception,code,reason,description) return((Image *) NULL)

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned long ReadBlobMSBLong(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
MagickBooleanType AcquireImageColormap(Image *, unsigned long, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
Image *GetFirstImageInList(Image *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, unsigned long, unsigned long, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, unsigned long);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
MagickBooleanType EOFBlob(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickOffsetType TellBlob(Image *);
MagickOffsetType GetBlobSize(Image *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
void LogMagickEvent(int, const char *, const char *, ...);
void ResetMagickMemory(void *, int, size_t);
unsigned char ScaleCharToQuantum(unsigned char);
Quantum ClampToQuantum(MagickRealType);
Quantum GetPixelRed(Image *, Quantum *);
Quantum GetPixelGreen(Image *, Quantum *);
Quantum GetPixelBlue(Image *, Quantum *);
void SetPixelIndex(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
unsigned long GetPixelChannels(Image *);
void DecodeImage(unsigned char *, size_t, unsigned char *, size_t);
size_t MagickMax(size_t, size_t);
const char *GetMagickModule(void);