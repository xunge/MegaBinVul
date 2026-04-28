#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxTextExtent 4096
#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define LoadImagesTag 0

typedef unsigned char MagickBooleanType;

typedef enum {
    GRAYColorspace,
    CMYKColorspace,
    LabColorspace
} ColorspaceType;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    MagickBooleanType matte;
    ColorspaceType colorspace;
    char *filename;
    ExceptionInfo exception;
} Image;

typedef unsigned long QuantumAny;
typedef unsigned long Quantum;
typedef double MagickRealType;

typedef struct {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
    MagickRealType index;
    MagickRealType opacity;
} MagickPixelPacket;

typedef unsigned char *PixelPacket;
typedef unsigned char *IndexPacket;

static const char MagickID[] = "Magick";
static const char *MagickColorspaceOptions[] = {"GRAY", "CMYK", "Lab", NULL};

static Image *AcquireImage(const ImageInfo *);
static Image *DestroyImageList(Image *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static void LogMagickEvent(int, const char *, const char *, ...);
static void ResetMagickMemory(void *, int, size_t);
static char *ReadBlobString(Image *, char *);
static int LocaleNCompare(const char *, const char *, size_t);
static void ThrowReaderException(int, const char *);
static unsigned long GetQuantumRange(unsigned long);
static MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long);
static void InheritException(ExceptionInfo *, ExceptionInfo *);
static char *LocaleLower(char *);
static int ParseCommandOption(const char *[], MagickBooleanType, const char *);
static void SetImageBackgroundColor(Image *);
static PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, unsigned long, unsigned long, ExceptionInfo *);
static IndexPacket *GetAuthenticIndexQueue(Image *);
static void SetPixelRed(PixelPacket *, MagickRealType);
static void SetPixelGreen(PixelPacket *, MagickRealType);
static void SetPixelBlue(PixelPacket *, MagickRealType);
static void SetPixelIndex(IndexPacket *, MagickRealType);
static void SetPixelAlpha(PixelPacket *, MagickRealType);
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
static MagickBooleanType EOFBlob(const Image *);
static void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
static void AcquireNextImage(const ImageInfo *, Image *);
static Image *GetNextImageInList(const Image *);
static Image *SyncNextImageInList(Image *);
static MagickBooleanType SetImageProgress(Image *, int, long, long);
static long TellBlob(const Image *);
static long GetBlobSize(const Image *);
static int CloseBlob(Image *);
static Image *GetFirstImageInList(const Image *);
static QuantumAny ScaleAnyToQuantum(QuantumAny, QuantumAny);
static const char *GetMagickModule(void);