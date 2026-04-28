#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char MagickBooleanType;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned char IndexPacket;
typedef struct _PixelPacket PixelPacket;
typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _ColorPacket ColorPacket;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define TraceEvent 0
#define LoadImageTag 0
#define LoadImagesTag 0
#define PseudoClass 0
#define CorruptImageError 0
#define CoderError 0
#define ResourceLimitError 0
#define ReadBinaryBlobMode 0

struct _Image {
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    unsigned long colors;
    MagickBooleanType matte;
    ColorPacket *colormap;
    void *exception;
    Image *previous;
    Image *next;
    unsigned long scene;
    char *filename;
    unsigned long storage_class;
    unsigned long signature;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    unsigned long number_scenes;
    unsigned long scene;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _PixelPacket {
    unsigned long red;
    unsigned long green;
    unsigned long blue;
    unsigned long alpha;
};

struct _ColorPacket {
    unsigned long red;
    unsigned long green;
    unsigned long blue;
};

Image *AcquireImage(const ImageInfo *);
Image *DestroyImageList(Image *);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
void AcquireNextImage(const ImageInfo *, Image *);
void InheritException(ExceptionInfo *, void *);
void ResetMagickMemory(void *, int, size_t);
void CopyMagickMemory(void *, const void *, size_t);
void SyncImage(Image *);
unsigned long ScaleCharToQuantum(unsigned char);
unsigned long GetPixelRed(const PixelPacket *);
unsigned long GetPixelGreen(const PixelPacket *);
unsigned long GetPixelBlue(const PixelPacket *);
unsigned long ConstrainColormapIndex(Image *, unsigned char);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
MagickBooleanType AcquireImageColormap(Image *, unsigned long);
MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, unsigned long);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType EOFBlob(const Image *);
PixelPacket *QueueAuthenticPixels(Image *, long, long, unsigned long, unsigned long, ExceptionInfo *);
IndexPacket *GetAuthenticIndexQueue(Image *);
ssize_t ReadBlob(Image *, size_t, void *);
unsigned long ReadBlobMSBLong(Image *);
long TellBlob(Image *);
long GetBlobSize(Image *);
int CloseBlob(Image *);
int LogMagickEvent(int, const char *, const char *, ...);
void ThrowReaderException(int, const char *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void DecodeImage(const unsigned char *, size_t, unsigned char *, size_t);
void SetPixelIndex(IndexPacket *, unsigned long);
void SetPixelRed(PixelPacket *, unsigned long);
void SetPixelGreen(PixelPacket *, unsigned long);
void SetPixelBlue(PixelPacket *, unsigned long);
void SetPixelAlpha(PixelPacket *, unsigned long);
const char *GetMagickModule(void);
size_t MagickMax(size_t, size_t);