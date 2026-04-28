#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1

enum {
    TraceEvent,
    CorruptImageError,
    FileOpenError,
    LoadImagesTag,
    ReadBinaryBlobMode
};

typedef int MagickBooleanType;

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;

typedef void (*MagickProgressMonitor)(const char *,const size_t,const size_t);

struct _Image {
    char filename[MagickPathExtent];
    Image *next;
    Image *previous;
    size_t scene;
    unsigned long signature;
    MagickBooleanType debug;
};

struct _ImageInfo {
    char filename[MagickPathExtent];
    size_t scene;
    size_t number_scenes;
    unsigned long signature;
    MagickBooleanType debug;
};

struct _ExceptionInfo {
    unsigned long signature;
};

/* Function prototypes */
Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImage(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
int LocaleNCompare(const char *, const char *, size_t);
void ThrowReaderException(int, const char *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageInfoProgressMonitor(ImageInfo *, MagickProgressMonitor, void *);
void SetImageInfoBlob(ImageInfo *, void *, size_t);
int AcquireUniqueFileResource(char *);
int FormatLocaleString(char *, size_t, const char *, ...);
int ReadBlobByte(Image *);
void RelinquishUniqueFileResource(const char *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
Image *DestroyImageList(Image *);
Image *ReadImage(const ImageInfo *, ExceptionInfo *);
Image *GetNextImageInList(const Image *);
MagickBooleanType SetImageProgress(Image *, const char *, size_t, size_t);
size_t TellBlob(Image *);
size_t GetBlobSize(Image *);
MagickBooleanType EOFBlob(Image *);
char *GetExceptionMessage(int);
void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
char *DestroyString(char *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(int, const char *, const char *, const char *);
const char *GetMagickModule(void);