#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef struct _Image {
    size_t columns;
    size_t rows;
    struct _Image *next;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    char *size;
    char *magick;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _MontageInfo {
    // Placeholder structure
} MontageInfo;

typedef struct _RectangleInfo {
    ssize_t x;
    ssize_t y;
    size_t width;
    size_t height;
} RectangleInfo;

typedef void (*MagickProgressMonitor)(const char *, const size_t, const size_t);

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096
#define DefaultTileGeometry "120x120"
#define DefaultTileLabel "%f"

#define TraceEvent 0
#define CoderEvent 1
#define LoadImagesTag "Load/Images"
#define ResourceLimitError "ResourceLimitError"
#define CorruptImageError "CorruptImageError"
#define MemoryAllocationFailed "MemoryAllocationFailed"
#define ImageFileDoesNotContainAnyImageData "ImageFileDoesNotContainAnyImageData"

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
void *AcquireMagickMemory(size_t);
char *ConstantString(const char *);
void ThrowReaderException(const char *, const char *);
char *DestroyString(char *);
void *RelinquishMagickMemory(void *);
Image *DestroyImage(Image *);
Image *NewImageList(void);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageInfoBlob(ImageInfo *, void *, size_t);
void SetImageInfoProgressMonitor(ImageInfo *, MagickProgressMonitor, void *);
char *CloneString(char **, const char *);
void LogMagickEvent(int, const char *, const char *, ...);
void CopyMagickString(char *, const char *, size_t);
Image *ReadImage(ImageInfo *, ExceptionInfo *);
void CatchException(ExceptionInfo *);
char *InterpretImageProperties(ImageInfo *, Image *, const char *, ExceptionInfo *);
void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
void SetGeometry(Image *, RectangleInfo *);
void ParseMetaGeometry(const char *, ssize_t *, ssize_t *, size_t *, size_t *);
Image *ThumbnailImage(Image *, size_t, size_t, ExceptionInfo *);
void AppendImageToList(Image **, Image *);
MagickBooleanType SetImageProgress(Image *, const char *, ssize_t, ssize_t);
ImageInfo *DestroyImageInfo(ImageInfo *);
MontageInfo *CloneMontageInfo(const ImageInfo *, MontageInfo *);
Image *MontageImageList(const ImageInfo *, MontageInfo *, Image *, ExceptionInfo *);
MontageInfo *DestroyMontageInfo(MontageInfo *);
Image *DestroyImageList(Image *);
Image *GetFirstImageInList(Image *);
const char *GetMagickModule(void);
MagickBooleanType ExpandFilenames(int *, char ***);