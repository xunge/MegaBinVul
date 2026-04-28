#include <assert.h>
#include <string.h>
#include <sys/types.h>

#define MagickSignature 0xabacadabUL
#define MaxTextExtent 2048
#define MagickPathExtent 4096
#define QuantumRange 65535
#define SaveImageTag "SaveImage"

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum
{
  BasePath,
  HeadPath,
  TailPath,
  RootPath,
  ExtensionPath,
  MagickPath
} PathType;

typedef enum
{
  UndefinedColorspace,
  RGBColorspace,
  GRAYColorspace,
  sRGBColorspace
} ColorspaceType;

typedef enum
{
  TraceEvent,
  DebugEvent
} LogEventType;

typedef enum
{
  WriteBinaryBlobMode
} BlobMode;

typedef ssize_t MagickOffsetType;

typedef struct _ExceptionInfo
{
  int dummy;
} ExceptionInfo;

typedef struct _ImageInfo
{
  unsigned long signature;
  int debug;
  ExceptionInfo exception;
} ImageInfo;

typedef struct _PixelPacket
{
  unsigned long red;
  unsigned long green;
  unsigned long blue;
  unsigned long opacity;
} PixelPacket;

typedef struct _Image
{
  unsigned long signature;
  char *filename;
  int debug;
  struct
  {
    double x;
    double y;
  } page;
  size_t columns;
  size_t rows;
  ExceptionInfo exception;
} Image;

typedef struct _ModuleInfo
{
  const char *name;
} ModuleInfo;

extern ModuleInfo *GetMagickModule(void);
extern MagickBooleanType LogMagickEvent(LogEventType,const ModuleInfo *,const char *,...);
extern MagickBooleanType OpenBlob(const ImageInfo *,Image *,BlobMode,ExceptionInfo *);
extern void WriteBlobString(Image *,const char *);
extern const char *GetImageProperty(const Image *,const char *);
extern void GetPathComponent(const char *,PathType,char *);
extern char *FormatLocaleString(char *,const size_t,const char *,...);
extern const PixelPacket *GetVirtualPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
extern unsigned long GetPixelLuma(const Image *,const PixelPacket *);
extern unsigned long ClampToQuantum(unsigned long);
extern MagickBooleanType SetImageProgress(Image *,const char *,MagickOffsetType,size_t);
extern void CloseBlob(Image *);
extern MagickBooleanType TransformImageColorspace(Image *,ColorspaceType);
extern unsigned long MagickMin(unsigned long,unsigned long);