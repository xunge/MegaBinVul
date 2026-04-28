#include <assert.h>
#include <stddef.h>

typedef unsigned char Quantum;
typedef unsigned int MagickBooleanType;
typedef size_t MagickSizeType;
typedef long long MagickOffsetType;
typedef int ssize_t;
typedef double MagickRealType;

typedef struct _ExceptionInfo {
    unsigned int signature;
} ExceptionInfo;

typedef struct _ImageInfo {
    unsigned int signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    unsigned int number_scenes;
    unsigned int scene;
} ImageInfo;

typedef struct _ColormapEntry {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} ColormapEntry;

typedef struct _Image {
    unsigned int columns;
    unsigned int rows;
    unsigned int depth;
    unsigned int storage_class;
    unsigned int colors;
    ColormapEntry *colormap;
    unsigned int alpha_trait;
    struct _Image *previous;
    struct _Image *next;
    unsigned int scene;
    const char *filename;
} Image;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0x12345678
#define MAGICKCORE_QUANTUM_DEPTH 16
#define PseudoClass 1
#define UndefinedPixelTrait 0
#define BlendPixelTrait 1
#define LoadImageTag 1
#define LoadImagesTag 2
#define TraceEvent 1
#define CorruptImageError 1
#define ResourceLimitError 2
#define CoderError 3
#define ReadBinaryBlobMode 1

#define ThrowReaderException(code,message) return((Image *) NULL)
#define ThrowFileException(exception,code,message,file) return((Image *) NULL)

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned int ReadBlobMSBLong(Image *);
void ResetMagickMemory(void *, int, size_t);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
Image *GetFirstImageInList(Image *);
MagickBooleanType AcquireImageColormap(Image *, unsigned int, ExceptionInfo *);
ssize_t ReadBlob(Image *, size_t, void *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
MagickBooleanType SetImageExtent(Image *, unsigned int, unsigned int, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelIndex(Image *, Quantum, Quantum *);
unsigned int GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, unsigned int);
void SetPixelAlpha(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelRed(Image *, Quantum, Quantum *);
Quantum GetPixelRed(Image *, Quantum *);
Quantum GetPixelGreen(Image *, Quantum *);
Quantum GetPixelBlue(Image *, Quantum *);
Quantum ClampToQuantum(Quantum);
Quantum ScaleCharToQuantum(unsigned char);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
int EOFBlob(Image *);
Image *GetNextImageInList(Image *);
MagickBooleanType AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *SyncNextImageInList(Image *);
MagickOffsetType TellBlob(Image *);
MagickSizeType GetBlobSize(Image *);
MagickBooleanType CloseBlob(Image *);
void DecodeImage(unsigned char *, size_t, unsigned char *, size_t);