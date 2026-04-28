#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;

typedef enum
{
  UndefinedPixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef enum
{
  PseudoClass,
  DirectClass
} ClassType;

typedef enum
{
  LSBEndian,
  MSBEndian
} EndianType;

typedef enum
{
  TraceEvent
} LogEventType;

typedef enum
{
  CorruptImageError,
  ResourceLimitError,
  CoderError
} ExceptionType;

typedef unsigned long Quantum;

#define MAGICKCORE_QUANTUM_DEPTH 16
#define QuantumRange ((Quantum) ~0UL)
#define OpaqueAlpha QuantumRange
#define MagickCoreSignature 0xabacadabUL
#define ReadBinaryBlobMode 0
#define LoadImageTag 0
#define LoadImagesTag 0

typedef struct _ImageInfo
{
  unsigned long signature;
  MagickBooleanType debug;
  const char *filename;
  MagickBooleanType ping;
  unsigned long number_scenes;
  unsigned long scene;
} ImageInfo;

typedef struct _ExceptionInfo
{
  unsigned long signature;
} ExceptionInfo;

typedef struct _Colormap
{
  Quantum red;
  Quantum green;
  Quantum blue;
} Colormap;

typedef struct _Image
{
  unsigned long signature;
  unsigned long columns;
  unsigned long rows;
  unsigned long depth;
  unsigned long colors;
  ClassType storage_class;
  PixelTrait alpha_trait;
  EndianType endian;
  struct _Image *previous;
  struct _Image *next;
  const char *filename;
  unsigned long scene;
  Colormap *colormap;
} Image;

typedef struct _ModuleInfo
{
  const char *name;
} ModuleInfo;

ModuleInfo *GetMagickModule(void);
MagickBooleanType LogMagickEvent(LogEventType,ModuleInfo *,const char *,...);
Image *AcquireImage(const ImageInfo *,ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *,Image *,int,ExceptionInfo *);
Image *DestroyImageList(Image *);
ssize_t ReadBlob(Image *,size_t,void *);
void ThrowReaderException(ExceptionType,const char *);
MagickBooleanType SetImageProperty(Image *,const char *,const char *,ExceptionInfo *);
unsigned int ReadBlobLong(Image *);
int ReadBlobByte(Image *);
MagickBooleanType EOFBlob(Image *);
MagickBooleanType AcquireImageColormap(Image *,unsigned long,ExceptionInfo *);
void *AcquireQuantumMemory(size_t,size_t);
void MSBOrderShort(void *,size_t);
void MSBOrderLong(void *,size_t);
Quantum ScaleCharToQuantum(unsigned char);
void *RelinquishMagickMemory(void *);
MagickBooleanType SetImageExtent(Image *,unsigned long,unsigned long,ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
void SetPixelRed(Image *,Quantum,Quantum *);
void SetPixelGreen(Image *,Quantum,Quantum *);
void SetPixelBlue(Image *,Quantum,Quantum *);
void SetPixelIndex(Image *,Quantum,Quantum *);
size_t GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *,ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *,int,MagickOffsetType,unsigned long);
Quantum GetPixelRed(Image *,Quantum *);
Quantum GetPixelGreen(Image *,Quantum *);
Quantum GetPixelBlue(Image *,Quantum *);
ssize_t ConstrainColormapIndex(Image *,ssize_t,ExceptionInfo *);
void SetPixelAlpha(Image *,Quantum,Quantum *);
MagickBooleanType SyncImage(Image *,ExceptionInfo *);
void ThrowFileException(ExceptionInfo *,ExceptionType,const char *,const char *);
MagickBooleanType AcquireNextImage(const ImageInfo *,Image *,ExceptionInfo *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickOffsetType TellBlob(Image *);
MagickOffsetType GetBlobSize(Image *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);