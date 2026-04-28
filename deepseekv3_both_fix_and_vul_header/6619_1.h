#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef long long MagickOffsetType;
typedef long ssize_t;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
    struct _ExceptionInfo *exception;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType matte;
    size_t columns;
    size_t rows;
    struct _ExceptionInfo exception;
    const char *filename;
} Image;

typedef struct _PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} PixelPacket;

#define MagickCoreSignature 0x12345678
#define TraceEvent 0
#define LoadImageTag 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define SEEK_SET 0

#define ScaleCharToQuantum(x) (x)

Image *AcquireImage(const ImageInfo *);
Image *DestroyImageList(Image *);
Image *GetFirstImageInList(Image *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
void ResetMagickMemory(void *, int, size_t);
short ReadBlobMSBShort(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
long ReadBlobMSBSignedLong(Image *);
unsigned char ReadBlobByte(Image *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
void InheritException(ExceptionInfo *, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void ThrowReaderException(int, const char *);
void SetImageProperty(Image *, const char *, char *);
MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
short ReadBlobMSBSignedShort(Image *);
PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
void *RelinquishMagickMemory(void *);
int EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);

void SetPixelRed(PixelPacket *, unsigned char);
void SetPixelGreen(PixelPacket *, unsigned char);
void SetPixelBlue(PixelPacket *, unsigned char);
void SetPixelAlpha(PixelPacket *, unsigned char);