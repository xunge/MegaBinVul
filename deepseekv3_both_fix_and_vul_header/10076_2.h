#include <assert.h>
#include <stddef.h>

#define MagickExport

typedef unsigned int MagickBooleanType;
typedef unsigned int MagickStatusType;
typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;
typedef size_t ssize_t;

typedef struct _ImageInfo {
    unsigned long signature;
    char *magick;
    char filename[4096];
    MagickBooleanType adjoin;
    MagickBooleanType debug;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    char *filename;
    char *magick;
    size_t scene;
    MagickBooleanType debug;
    void *client_data;
} Image;

typedef struct _ExceptionInfo ExceptionInfo;
typedef MagickBooleanType (*MagickProgressMonitor)(const char *,
  const MagickOffsetType,const MagickSizeType,void *);

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MagickPathExtent 4096

enum {
  TraceEvent
};

Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
size_t GetImageListLength(Image *);
ImageInfo *CloneImageInfo(const ImageInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
ExceptionInfo *AcquireExceptionInfo();
ExceptionInfo *DestroyExceptionInfo(ExceptionInfo *);
void SetImageInfo(ImageInfo *, unsigned int, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, const char *, MagickOffsetType, MagickSizeType);
MagickProgressMonitor SetImageProgressMonitor(Image *, MagickProgressMonitor, void *);
MagickBooleanType WriteImage(ImageInfo *, Image *, ExceptionInfo *);
void *LogMagickEvent(unsigned int, const char *, const char *, ...);
const char *GetMagickModule();
void CopyMagickString(char *, const char *, size_t);