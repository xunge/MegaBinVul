#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxTextExtent 4096
#define MagickSignature 0xabacadabUL
#define OpaqueOpacity 0UL

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _PixelPacket PixelPacket;

typedef size_t MagickSizeType;
typedef ssize_t MagickOffsetType;

struct _ExceptionInfo
{
  unsigned long signature;
};

struct _PixelPacket
{
  unsigned long red;
  unsigned long green;
  unsigned long blue;
  unsigned long opacity;
};

struct _Image
{
  size_t columns;
  size_t rows;
  unsigned depth;
  size_t scene;
  struct _ExceptionInfo exception;
  Image *previous;
  Image *next;
  char *filename;
};

struct _ImageInfo
{
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  MagickBooleanType ping;
  size_t number_scenes;
  size_t scene;
};

enum
{
  TraceEvent,
  LoadImageTag,
  LoadImagesTag
};

enum
{
  ReadBinaryBlobMode
};

enum
{
  CorruptImageError,
  ResourceLimitError
};

extern void *AcquireQuantumMemory(size_t,size_t);
extern void *RelinquishMagickMemory(void *);
extern Image *AcquireImage(const ImageInfo *);
extern Image *DestroyImageList(Image *);
extern MagickBooleanType OpenBlob(const ImageInfo *,Image *,int,ExceptionInfo *);
extern MagickBooleanType SetImageExtent(Image *,size_t,size_t);
extern void InheritException(ExceptionInfo *,ExceptionInfo *);
extern PixelPacket *QueueAuthenticPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
extern MagickBooleanType SyncAuthenticPixels(Image *,ExceptionInfo *);
extern MagickBooleanType SetImageProgress(Image *,int,MagickOffsetType,size_t);
extern int EOFBlob(const Image *);
extern void ThrowFileException(ExceptionInfo *,int,const char *,const char *);
extern void ThrowReaderException(int,const char *);
extern void AcquireNextImage(const ImageInfo *,Image *);
extern Image *GetNextImageInList(const Image *);
extern Image *SyncNextImageInList(Image *);
extern MagickOffsetType TellBlob(const Image *);
extern MagickSizeType GetBlobSize(const Image *);
extern int CloseBlob(Image *);
extern Image *GetFirstImageInList(Image *);
extern char *ReadBlobString(Image *,char *);
extern size_t ReadBlob(Image *,size_t,unsigned char *);
extern void LogMagickEvent(int,const char *,const char *,...);
extern const char *GetMagickModule(void);
extern unsigned long ScaleCharToQuantum(unsigned char);
extern void SetPixelRed(PixelPacket *,unsigned long);
extern void SetPixelGreen(PixelPacket *,unsigned long);
extern void SetPixelBlue(PixelPacket *,unsigned long);
extern void SetPixelOpacity(PixelPacket *,unsigned long);