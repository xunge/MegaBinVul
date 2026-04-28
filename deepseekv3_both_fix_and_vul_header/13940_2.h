#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef struct _Image {
    char filename[4096];
    char magick_filename[4096];
    char magick[4096];
    size_t columns;
    size_t rows;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char filename[4096];
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

typedef struct _PESBlockInfo {
    ssize_t offset;
    Color *color;
} PESBlockInfo;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _SegmentInfo {
    double x1;
    double y1;
    double x2;
    double y2;
} SegmentInfo;

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define FileOpenError 0

extern Color *PESColor;
extern Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
extern MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
extern Image *DestroyImageList(Image *);
extern ssize_t ReadBlob(Image *, size_t, unsigned char *);
extern int LocaleNCompare(const char *, const char *, size_t);
extern void ThrowReaderException(int, const char *);
extern ssize_t ReadBlobLSBSignedLong(Image *);
extern MagickBooleanType DiscardBlobBytes(Image *, ssize_t);
extern void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
extern int EOFBlob(Image *);
extern int ReadBlobByte(Image *);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void *ResizeQuantumMemory(void *, size_t, size_t);
extern MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
extern int AcquireUniqueFileResource(char *);
extern FILE *fdopen(int, const char *);
extern void ThrowImageException(int, const char *);
extern int FormatLocaleFile(FILE *, const char *, ...);
extern int CloseBlob(Image *);
extern Image *DestroyImage(Image *);
extern ImageInfo *CloneImageInfo(const ImageInfo *);
extern void SetImageInfoBlob(ImageInfo *, void *, size_t);
extern int FormatLocaleString(char *, size_t, const char *, ...);
extern Image *ReadImage(ImageInfo *, ExceptionInfo *);
extern ImageInfo *DestroyImageInfo(ImageInfo *);
extern void RelinquishUniqueFileResource(const char *);
extern Image *GetFirstImageInList(Image *);
extern void LogMagickEvent(int, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern void CopyMagickString(char *, const char *, size_t);