#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MaxTextExtent 4096
#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define FileOpenError 0
#define LoadImagesTag 0

typedef int MagickBooleanType;

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;

struct _Image {
    char filename[MaxTextExtent];
    Image *previous;
    Image *next;
    size_t scene;
    void *blob;
    size_t blob_size;
};

struct _ImageInfo {
    unsigned long signature;
    char filename[MaxTextExtent];
    MagickBooleanType debug;
    size_t scene;
    size_t number_scenes;
    void *blob;
    size_t blob_size;
};

struct _ExceptionInfo {
    unsigned long signature;
};

typedef void (*MagickProgressMonitor)(const char *,const size_t,const size_t);

static const char *GetMagickModule(void);
static Image *AcquireImage(const ImageInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *,Image *,int,ExceptionInfo *);
static ssize_t ReadBlob(Image *,size_t,unsigned char *);
static void ThrowReaderException(int,const char *);
static ImageInfo *CloneImageInfo(const ImageInfo *);
static void SetImageInfoProgressMonitor(ImageInfo *,MagickProgressMonitor,void *);
static void SetImageInfoBlob(ImageInfo *,void *,size_t);
static int AcquireUniqueFileResource(char *);
static int ReadBlobByte(Image *);
static int LocaleNCompare(const char *,const char *,size_t);
static void RelinquishUniqueFileResource(const char *);
static void ThrowFileException(ExceptionInfo *,int,const char *,const char *);
static Image *DestroyImageList(Image *);
static Image *ReadImage(const ImageInfo *,ExceptionInfo *);
static int FormatLocaleString(char *,size_t,const char *,...);
static Image *GetNextImageInList(const Image *);
static size_t TellBlob(const Image *);
static size_t GetBlobSize(const Image *);
static MagickBooleanType SetImageProgress(Image *,const char *,size_t,size_t);
static MagickBooleanType EOFBlob(const Image *);
static char *GetExceptionMessage(int);
static void *ThrowMagickException(ExceptionInfo *,const char *,int,const char *,const char *,...);
static char *DestroyString(char *);
static MagickBooleanType CloseBlob(Image *);
static Image *GetFirstImageInList(Image *);
static void LogMagickEvent(int,const char *,const char *,...);