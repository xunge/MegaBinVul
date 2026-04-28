#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef size_t MagickSizeType;
typedef ssize_t MagickOffsetType;

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096

enum {
  CorruptImageError,
  FileOpenError
};

enum {
  TraceEvent,
  LoadImagesTag
};

typedef void (*MagickProgressMonitor)(const char *,const MagickOffsetType,
  const MagickSizeType,void *);

struct _Image {
  Image *previous;
  Image *next;
  char filename[MagickPathExtent];
  size_t scene;
};

struct _ImageInfo {
  unsigned long signature;
  char filename[MagickPathExtent];
  MagickBooleanType debug;
  size_t scene;
  size_t number_scenes;
};

struct _ExceptionInfo {
  unsigned long signature;
};

enum {
  ReadBinaryBlobMode
};

Image *AcquireImage(const ImageInfo *,ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *,Image *,int,ExceptionInfo *);
ssize_t ReadBlob(Image *,const size_t,unsigned char *);
int ReadBlobByte(Image *);
void ThrowReaderException(int,const char *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageInfoProgressMonitor(ImageInfo *,MagickProgressMonitor,void *);
void SetImageInfoBlob(ImageInfo *,void *,size_t);
int AcquireUniqueFileResource(char *);
void RelinquishUniqueFileResource(const char *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void ThrowFileException(ExceptionInfo *,int,const char *,const char *);
Image *DestroyImageList(Image *);
Image *ReadImage(const ImageInfo *,ExceptionInfo *);
int FormatLocaleString(char *,const size_t,const char *,...);
Image *GetNextImageInList(const Image *);
MagickBooleanType SetImageProgress(Image *,const char *,MagickOffsetType,
  MagickSizeType);
MagickOffsetType TellBlob(const Image *);
MagickSizeType GetBlobSize(const Image *);
MagickBooleanType EOFBlob(const Image *);
char *GetExceptionMessage(int);
void *ThrowMagickException(ExceptionInfo *,const char *,const char *,
  const char *,const char *,...);
char *DestroyString(char *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void ResetMagickMemory(void *,int,size_t);
int LocaleNCompare(const char *,const char *,size_t);
void LogMagickEvent(int,const char *,const char *,...);
const char *GetMagickModule(void);