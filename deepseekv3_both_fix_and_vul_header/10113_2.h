#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0x1234
#define ReadBinaryBlobMode 0

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef void (*MagickProgressMonitor)(const char *, const size_t, void *);

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char filename[MagickPathExtent];
    unsigned long number_scenes;
    unsigned long scene;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    struct _Image *previous;
    struct _Image *next;
    unsigned long scene;
    char filename[MagickPathExtent];
} Image;

#define CorruptImageError 1
#define FileOpenError 2
#define LoadImagesTag "LoadImages"
#define TraceEvent "Trace"

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
void ThrowReaderException(int, const char *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageInfoProgressMonitor(ImageInfo *, MagickProgressMonitor, void *);
void SetImageInfoBlob(ImageInfo *, void *, size_t);
int AcquireUniqueFileResource(char *);
int ReadBlobByte(Image *);
int LocaleNCompare(const char *, const char *, size_t);
void RelinquishUniqueFileResource(char *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
Image *DestroyImageList(Image *);
Image *ReadImage(const ImageInfo *, ExceptionInfo *);
int FormatLocaleString(char *, size_t, const char *, ...);
Image *GetNextImageInList(Image *);
ssize_t TellBlob(Image *);
ssize_t GetBlobSize(Image *);
MagickBooleanType SetImageProgress(Image *, const char *, ssize_t, ssize_t);
ImageInfo *DestroyImageInfo(ImageInfo *);
void CloseBlob(Image *);
Image *DestroyImage(Image *);
MagickBooleanType EOFBlob(Image *);
char *GetExceptionMessage(int);
void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
char *DestroyString(char *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(const char *, const char *, const char *, ...);
const char *GetMagickModule(void);