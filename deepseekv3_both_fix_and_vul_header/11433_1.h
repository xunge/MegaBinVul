#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0x1234
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define PseudoClass 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define LoadImageTag 0
#define QuantumRange 65535

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef long ssize_t;
typedef double MagickRealType;
typedef long MagickOffsetType;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _PixelPacket {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} PixelPacket;

typedef struct _Image {
    unsigned long signature;
    unsigned int columns;
    unsigned int rows;
    unsigned int depth;
    unsigned int storage_class;
    unsigned int colors;
    PixelPacket *colormap;
} Image;

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
char *ReadBlobString(Image *, char *);
int LocaleCompare(const char *, const char *);
MagickBooleanType EOFBlob(const Image *);
void ThrowReaderException(int, const char *);
MagickBooleanType AcquireImageColormap(Image *, unsigned int, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
MagickBooleanType SetImageExtent(Image *, unsigned int, unsigned int, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
int XBMInteger(Image *, short int *);
void *RelinquishMagickMemory(void *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, unsigned int, unsigned int, ExceptionInfo *);
unsigned int GetPixelChannels(const Image *);
void SetPixelIndex(Image *, Quantum, Quantum *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, unsigned int);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
const char *GetMagickModule(void);
int LogMagickEvent(int, const char *, const char *, ...);