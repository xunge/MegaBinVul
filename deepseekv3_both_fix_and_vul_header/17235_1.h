#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

typedef unsigned long Quantum;
typedef unsigned long QuantumAny;
typedef unsigned long MagickRealType;
typedef unsigned int MagickBooleanType;
typedef unsigned int ColorspaceType;
typedef unsigned int PixelTrait;

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define UndefinedPixelTrait 0
#define BlendPixelTrait 1
#define CorruptImageError 1
#define TraceEvent 1
#define ReadBinaryBlobMode 1
#define LoadImagesTag 1

static const char *MagickColorspaceOptions[] = {
    "RGB",
    "GRAY",
    "CMYK",
    "Lab",
    NULL
};

enum ColorspaceOptions {
    RGBColorspace,
    GRAYColorspace,
    CMYKColorspace,
    LabColorspace
};

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    ColorspaceType colorspace;
    PixelTrait alpha_trait;
    unsigned long signature;
} Image;

typedef struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
    MagickRealType black;
    MagickRealType alpha;
} PixelInfo;

static const char MagickID[] = "magick";

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void *ResetMagickMemory(void *, int, size_t);
char *ReadBlobString(Image *, char *);
int LocaleNCompare(const char *, const char *, size_t);
void ThrowReaderException(unsigned long, const char *);
unsigned long GetQuantumRange(unsigned long);
MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long, ExceptionInfo *);
char *LocaleLower(char *);
ssize_t ParseCommandOption(const char *[], MagickBooleanType, const char *);
MagickBooleanType SetImageBackgroundColor(Image *, ExceptionInfo *);
MagickBooleanType SetImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
void GetPixelInfo(Image *, PixelInfo *);
Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, unsigned long, unsigned long, ExceptionInfo *);
void SetPixelViaPixelInfo(Image *, const PixelInfo *, Quantum *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickBooleanType SetImageProgress(Image *, int, ssize_t, ssize_t);
ssize_t TellBlob(Image *);
ssize_t GetBlobSize(Image *);
void CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(unsigned long, const char *, const char *, ...);
const char *GetMagickModule(void);
QuantumAny ScaleAnyToQuantum(QuantumAny, QuantumAny);