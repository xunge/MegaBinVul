#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  TraceEvent
} LogEventType;

typedef enum {
  ResourceLimitError,
  CorruptImageError,
  FileOpenError
} ExceptionType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

#define MagickSignature 0xabacadabUL
#define MaxTextExtent 4096

struct _Image {
  char filename[MaxTextExtent];
  char magick[MaxTextExtent];
  ExceptionInfo *exception;
  size_t signature;
};

struct _ImageInfo {
  char filename[MaxTextExtent];
  MagickBooleanType debug;
  size_t signature;
};

struct _ExceptionInfo {
  size_t signature;
  char *reason;
  char *description;
};

const char *GetMagickModule(void);
Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
size_t GetBlobSize(Image *);
void *AcquireQuantumMemory(size_t, size_t);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
int LocaleNCompare(const char *, const char *, size_t);
void *RelinquishMagickMemory(void *);
unsigned char *SFWScan(unsigned char *, unsigned char *, const unsigned char *, size_t);
void TranslateSFWMarker(unsigned char *);
void CopyMagickMemory(void *, const void *, size_t);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageInfoBlob(ImageInfo *, void *, size_t);
int AcquireUniqueFileResource(char *);
FILE *fopen_utf8(const char *, const char *);
void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
void CloseBlob(Image *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void CopyMagickString(char *, const char *, size_t);
char *GetExceptionMessage(int);
void ThrowMagickException(ExceptionInfo *, const char *, ExceptionType, const char *, const char *, ...);
char *DestroyString(char *);
Image *ReadImage(const ImageInfo *, ExceptionInfo *);
void RelinquishUniqueFileResource(const char *);
void DuplicateBlob(Image *, Image *);
Image *FlipImage(Image *, ExceptionInfo *);
Image *DestroyImage(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(LogEventType, const char *, const char *, ...);
void ThrowReaderException(ExceptionType, const char *);