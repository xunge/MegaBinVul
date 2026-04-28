#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MagickCoreSignature ((void *)0xabacadabUL)
#define MagickPathExtent 4096
#define MaxColormapSize 65535
#define MagickFalse 0
#define MagickTrue 1
#define BlendPixelTrait 1
#define DirectClass 1
#define PseudoClass 2
#define XPMCompliance 1
#define ResourceLimitError 1
#define CorruptImageError 1
#define TraceEvent 1
#define ReadBinaryBlobMode 1

typedef unsigned int MagickBooleanType;
typedef unsigned long Quantum;
typedef unsigned long size_t;
typedef long ssize_t;

typedef struct _PixelInfo {
    unsigned long depth;
} PixelInfo;

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _SplayTreeInfo SplayTreeInfo;

struct _Image {
    unsigned long columns;
    unsigned long rows;
    unsigned long colors;
    unsigned long depth;
    unsigned long storage_class;
    unsigned long alpha_trait;
    PixelInfo *colormap;
    void *signature;
    int debug;
    char *filename;
    MagickBooleanType ping;
};

struct _ImageInfo {
    void *signature;
    int debug;
    char *filename;
    MagickBooleanType ping;
};

struct _ExceptionInfo {
    void *signature;
};

static inline size_t MagickMin(size_t a, size_t b) {
    return (a < b) ? a : b;
}

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void *AcquireQuantumMemory(size_t, size_t);
void ThrowReaderException(int, const char *);
char *ReadBlobString(Image *, char *);
void *ResizeQuantumMemory(void *, size_t, size_t);
char *DestroyString(char *);
SplayTreeInfo *NewSplayTree(int (*)(const void *, const void *), void *(*)(void *), void *(*)(void *));
MagickBooleanType AcquireImageColormap(Image *, unsigned long, ExceptionInfo *);
char *NextXPMLine(char *);
ssize_t CopyXPMColor(char *, const char *, size_t);
int CompareXPMColor(const void *, const void *);
void *RelinquishMagickMemory(void *);
char *ConstantString(const char *);
MagickBooleanType AddValueToSplayTree(SplayTreeInfo *, const void *, void *);
char *ParseXPMColor(const char *, MagickBooleanType);
void CopyMagickString(char *, const char *, size_t);
void StripString(char *);
int LocaleCompare(const char *, const char *);
MagickBooleanType QueryColorCompliance(const char *, int, PixelInfo *, ExceptionInfo *);
MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, unsigned long, unsigned long, ExceptionInfo *);
void SetPixelIndex(Image *, Quantum, Quantum *);
void SetPixelViaPixelInfo(Image *, PixelInfo *, Quantum *);
unsigned long GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
void *GetValueFromSplayTree(SplayTreeInfo *, const void *);
SplayTreeInfo *DestroySplayTree(SplayTreeInfo *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void *LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);