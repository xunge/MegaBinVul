#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short Quantum;
typedef int MagickBooleanType;
typedef size_t MagickSizeType;
typedef long ssize_t;
typedef long MagickOffsetType;
typedef double MagickRealType;

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define QuantumRange ((Quantum) 65535)
#define ReadBinaryBlobMode 0
#define PseudoClass 1
#define CorruptImageError 1
#define ResourceLimitError 2
#define TraceEvent 3
#define LoadImageTag "LoadImage"

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _MagickPixelPacket MagickPixelPacket;

struct _Image {
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    unsigned long storage_class;
    unsigned long colors;
    MagickPixelPacket *colormap;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _MagickPixelPacket {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
char *ReadBlobString(Image *, char *);
int LocaleCompare(const char *, const char *);
MagickBooleanType AcquireImageColormap(Image *, unsigned long, ExceptionInfo *);
void ThrowReaderException(int, const char *);
MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long, ExceptionInfo *);
void *AcquireQuantumMemory(MagickSizeType, MagickSizeType);
int XBMInteger(Image *, short *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, unsigned long, unsigned long, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, const char *, MagickOffsetType, unsigned long);
void *RelinquishMagickMemory(void *);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
MagickBooleanType EOFBlob(const Image *);
unsigned long GetPixelChannels(const Image *);
void SetPixelIndex(Image *, Quantum, Quantum *);