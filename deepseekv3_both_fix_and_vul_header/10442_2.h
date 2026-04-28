#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define SEEK_SET 0
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define CorruptImageWarning 0
#define MagickPathExtent 4096
#define TraceEvent 0

typedef unsigned int MagickBooleanType;
typedef long long MagickOffsetType;

typedef struct _Image {
    char filename[MagickPathExtent];
    char magick[MagickPathExtent];
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char filename[MagickPathExtent];
    char magick[MagickPathExtent];
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _EPTInfo {
    unsigned long magick;
    MagickOffsetType postscript_offset;
    unsigned long postscript_length;
    MagickOffsetType tiff_offset;
    unsigned long tiff_length;
    unsigned char *postscript;
    unsigned char *tiff;
} EPTInfo;

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned long ReadBlobLSBLong(Image *);
void ThrowReaderException(int, const char *);
unsigned short ReadBlobLSBShort(Image *);
void *AcquireQuantumMemory(size_t, size_t);
void ResetMagickMemory(void *, int, size_t);
MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
ssize_t ReadBlob(Image *, size_t, void *);
void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
void CloseBlob(Image *);
Image *DestroyImage(Image *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void CopyMagickString(char *, const char *, size_t);
Image *BlobToImage(ImageInfo *, const void *, size_t, ExceptionInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void *RelinquishMagickMemory(void *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);