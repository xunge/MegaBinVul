#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Image {
    char filename[4096];
    char magick_filename[4096];
    char magick[4];
    size_t columns;
    size_t rows;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    int debug;
    char filename[4096];
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

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

typedef struct _PESBlockInfo {
    struct _PESColor *color;
    long offset;
} PESBlockInfo;

struct _PESColor {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

#define PESColor PESColors

typedef int MagickBooleanType;

#define MagickFalse 0
#define MagickTrue 1
#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define TraceEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define FileOpenError 0
#define ReadBinaryBlobMode 0

extern struct _PESColor PESColors[];
extern const char *GetMagickModule(void);
extern int LocaleNCompare(const char *, const char *, size_t);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void *ResizeQuantumMemory(void *, size_t, size_t);
extern Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
extern Image *DestroyImageList(Image *);
extern Image *DestroyImage(Image *);
extern Image *GetFirstImageInList(Image *);
extern Image *ReadImage(ImageInfo *, ExceptionInfo *);
extern ImageInfo *CloneImageInfo(const ImageInfo *);
extern ImageInfo *DestroyImageInfo(ImageInfo *);
extern int AcquireUniqueFileResource(char *);
extern int EOFBlob(Image *);
extern int LogMagickEvent(int, const char *, const char *, ...);
extern int ReadBlobByte(Image *);
extern long ReadBlob(Image *, size_t, unsigned char *);
extern long ReadBlobLSBSignedLong(Image *);
extern MagickBooleanType DiscardBlobBytes(Image *, long);
extern MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
extern MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
extern void CloseBlob(Image *);
extern void CopyMagickString(char *, const char *, size_t);
extern void FormatLocaleString(char *, size_t, const char *, ...);
extern void RelinquishUniqueFileResource(const char *);
extern void SetImageInfoBlob(ImageInfo *, void *, size_t);
extern void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
extern void ThrowImageException(int, const char *);
extern void ThrowReaderException(int, const char *);
extern void FormatLocaleFile(FILE *, const char *, ...);