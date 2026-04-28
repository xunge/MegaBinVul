#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

typedef int MagickBooleanType;
typedef long ssize_t;
typedef size_t size_t;

#define MagickCoreSignature 0x1234
#define MagickFalse 0
#define MaxTextExtent 4096

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;

typedef void (*MagickProgressMonitor)(const char *,const size_t,void *);

struct _Image {
    Image *next;
    Image *previous;
    char filename[MaxTextExtent];
    long scene;
    // Other members omitted
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    unsigned long number_scenes;
    unsigned long scene;
    // Other members omitted
};

struct _ExceptionInfo {
    unsigned long signature;
    // Other members omitted
};

enum {
    TraceEvent,
    CorruptImageError,
    FileOpenError
};

#define ReadBinaryBlobMode 0
#define LoadImagesTag 0

Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
void ResetMagickMemory(void *, int, size_t);
ssize_t ReadBlob(Image *, size_t, void *);
int LocaleNCompare(const char *, const char *, size_t);
void ThrowReaderException(int, const char *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageInfoProgressMonitor(ImageInfo *, MagickProgressMonitor, void *);
void SetImageInfoBlob(ImageInfo *, void *, size_t);
int AcquireUniqueFileResource(char *);
int ReadBlobByte(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
Image *DestroyImageList(Image *);
int fputc(int, FILE *);
int fclose(FILE *);
Image *ReadImage(ImageInfo *, ExceptionInfo *);
int FormatLocaleString(char *, size_t, const char *, ...);
Image *GetNextImageInList(Image *);
MagickBooleanType SetImageProgress(Image *, int, ssize_t, size_t);
ssize_t TellBlob(Image *);
size_t GetBlobSize(Image *);
int close(int);
void RelinquishUniqueFileResource(char *);
ImageInfo *DestroyImageInfo(ImageInfo *);
MagickBooleanType EOFBlob(Image *);
char *GetExceptionMessage(int);
void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
char *DestroyString(char *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(int, const char *, const char *, const char *);
const char *GetMagickModule(void);