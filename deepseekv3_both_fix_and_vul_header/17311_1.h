#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum
{
  UndefinedPixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef enum
{
  ReadBinaryBlobMode
} BlobMode;

typedef enum
{
  CorruptImageError,
  ResourceLimitError
} ExceptionType;

typedef enum
{
  TraceEvent
} LogEventType;

typedef enum
{
  LoadImageTag
} ProgressMonitorTag;

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef long long MagickOffsetType;
typedef unsigned short Quantum;

struct _ExceptionInfo
{
  int signature;
};

struct _ImageInfo
{
  int signature;
  MagickBooleanType debug;
  const char *filename;
  MagickBooleanType ping;
};

struct _Image
{
  size_t columns;
  size_t rows;
  PixelTrait alpha_trait;
  char *filename;
};

typedef struct _MagickModule
{
  const char *name;
} MagickModule;

const MagickModule *GetMagickModule(void);
void *AcquireQuantumMemory(size_t,size_t);
void *RelinquishMagickMemory(void *);
void ResetMagickMemory(void *,int,size_t);
MagickBooleanType OpenBlob(const ImageInfo *,Image *,BlobMode,ExceptionInfo *);
MagickBooleanType SetImageExtent(Image *,size_t,size_t,ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *,ProgressMonitorTag,MagickOffsetType,size_t);
MagickBooleanType SyncAuthenticPixels(Image *,ExceptionInfo *);
short ReadBlobMSBShort(Image *);
int ReadBlobMSBSignedLong(Image *);
int ReadBlobMSBSignedShort(Image *);
int ReadBlobByte(Image *);
size_t ReadBlob(Image *,size_t,unsigned char *);
MagickOffsetType SeekBlob(Image *,MagickOffsetType,int);
Image *AcquireImage(const ImageInfo *,ExceptionInfo *);
Image *DestroyImageList(Image *);
Image *GetFirstImageInList(Image *);
Quantum *GetAuthenticPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
void SetPixelRed(Image *,Quantum,Quantum *);
void SetPixelGreen(Image *,Quantum,Quantum *);
void SetPixelBlue(Image *,Quantum,Quantum *);
void SetPixelAlpha(Image *,Quantum,Quantum *);
void SetImageProperty(Image *,const char *,const char *,ExceptionInfo *);
void CloseBlob(Image *);
void LogMagickEvent(LogEventType,const MagickModule *,const char *,...);
Quantum ScaleCharToQuantum(unsigned char);
void ThrowReaderException(ExceptionType,const char *);
void ThrowFileException(ExceptionInfo *,ExceptionType,const char *,const char *);
MagickBooleanType EOFBlob(Image *);

#define MagickCoreSignature 0x12345678