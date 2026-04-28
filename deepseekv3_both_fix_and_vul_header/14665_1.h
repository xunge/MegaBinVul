#include <assert.h>
#include <string.h>

#define MagickCoreSignature 0xabacadabUL
#define QuantumRange 65535UL
#define MAGICKCORE_QUANTUM_DEPTH 16

typedef enum
{
  UndefinedError,
  CorruptImageError,
  ResourceLimitError,
  CoderError
} ErrorType;

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
  UndefinedClass,
  DirectClass,
  PseudoClass
} ClassType;

typedef enum
{
  LSBEndian,
  MSBEndian
} EndianType;

typedef enum
{
  LoadImageTag,
  LoadImagesTag
} ProgressTag;

typedef unsigned long Quantum;

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;

typedef struct _PixelPacket
{
  Quantum red;
  Quantum green;
  Quantum blue;
  Quantum opacity;
} PixelPacket;

typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef long ssize_t;
typedef unsigned long size_t;

struct _Image
{
  unsigned long
    columns,
    rows,
    depth,
    colors;

  ClassType
    storage_class;

  PixelTrait
    alpha_trait;

  EndianType
    endian;

  PixelPacket
    *colormap;

  Image
    *previous,
    *next;

  char
    *filename;

  unsigned long
    scene;

  void
    *signature;
};

struct _ImageInfo
{
  void
    *signature;

  MagickBooleanType
    debug,
    ping;

  unsigned long
    scene,
    number_scenes;

  char
    *filename;
};

struct _ExceptionInfo
{
  void
    *signature;
};

#define OpaqueAlpha QuantumRange

static Image *AcquireImage(const ImageInfo *,ExceptionInfo *);
static Image *DestroyImageList(Image *);
static Image *GetFirstImageInList(Image *);
static Image *GetNextImageInList(Image *);
static Image *SyncNextImageInList(Image *);
static MagickBooleanType AcquireImageColormap(Image *,const unsigned long,
  ExceptionInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *,Image *,const int,
  ExceptionInfo *);
static MagickBooleanType SetImageExtent(Image *,const unsigned long,
  const unsigned long,ExceptionInfo *);
static MagickBooleanType SetImageProgress(Image *,const char *,
  const MagickOffsetType,const MagickOffsetType);
static MagickBooleanType SyncAuthenticPixels(Image *,ExceptionInfo *);
static Quantum *QueueAuthenticPixels(Image *,const ssize_t,const ssize_t,
  const size_t,const size_t,ExceptionInfo *);
static Quantum ScaleCharToQuantum(const unsigned char);
static unsigned char *AcquireQuantumMemory(const size_t,const size_t);
static unsigned char *RelinquishMagickMemory(void *);
static void *GetMagickModule(void);
static void CloseBlob(Image *);
static void LogMagickEvent(const int,void *,const char *,...);
static void MSBOrderLong(void *,const size_t);
static void MSBOrderShort(void *,const size_t);
static void SetImageProperty(Image *,const char *,const char *,
  ExceptionInfo *);
static void SetPixelAlpha(Image *,const Quantum,Quantum *);
static void SetPixelBlue(Image *,const Quantum,Quantum *);
static void SetPixelGreen(Image *,const Quantum,Quantum *);
static void SetPixelIndex(Image *,const Quantum,Quantum *);
static void SetPixelRed(Image *,const Quantum,Quantum *);
static void SyncImage(Image *,ExceptionInfo *);
static void ThrowFileException(ExceptionInfo *,const int,const char *,
  const char *);
static void ThrowReaderException(const int,const char *);
static int EOFBlob(const Image *);
static int ReadBinaryBlobMode;
static int TraceEvent;
static ssize_t ConstrainColormapIndex(Image *,const ssize_t,ExceptionInfo *);
static ssize_t ReadBlob(Image *,const size_t,void *);
static ssize_t ReadBlobByte(Image *);
static ssize_t ReadBlobLong(Image *);
static MagickOffsetType TellBlob(const Image *);
static MagickSizeType GetBlobSize(const Image *);
static void AcquireNextImage(const ImageInfo *,Image *,ExceptionInfo *);
static size_t GetPixelChannels(const Image *);
static Quantum GetPixelRed(const Image *,Quantum *);
static Quantum GetPixelGreen(const Image *,Quantum *);
static Quantum GetPixelBlue(const Image *,Quantum *);
static size_t MagickMax(const size_t,const size_t);