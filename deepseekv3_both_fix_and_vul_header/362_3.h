#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

#define MagickCoreSignature 0xabacadabUL
#define QuantumRange 65535
#define MagickExport
#define magick_restrict __restrict

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  DirectClass,
  CMYKColorspace
} ColorspaceType;

typedef enum {
  TraceEvent
} LogEventType;

typedef long MagickOffsetType;
typedef double MagickRealType;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _CacheView CacheView;
typedef struct _Image {
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  size_t rows;
  size_t columns;
  ColorspaceType colorspace;
  void *progress_monitor;
  ExceptionInfo exception;
} Image;

typedef struct _PixelPacket {
  double red;
  double green;
  double blue;
  double opacity;
} PixelPacket;

typedef unsigned short IndexPacket;
typedef unsigned short Quantum;

typedef struct _MagickPixelPacket {
  double red;
  double green;
  double blue;
  double opacity;
  double index;
} MagickPixelPacket;

typedef void *(*MagickProgressMonitor)(const char *, MagickOffsetType, MagickOffsetType, void *);

extern Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
extern MagickBooleanType SetImageStorageClass(Image *, int);
extern void InheritException(ExceptionInfo *, ExceptionInfo *);
extern Image *DestroyImage(Image *);
extern CacheView *AcquireVirtualCacheView(const Image *, ExceptionInfo *);
extern CacheView *AcquireAuthenticCacheView(Image *, ExceptionInfo *);
extern const PixelPacket *GetCacheViewVirtualPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern PixelPacket *GetCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern const IndexPacket *GetCacheViewVirtualIndexQueue(CacheView *);
extern IndexPacket *GetCacheViewAuthenticIndexQueue(CacheView *);
extern MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
extern CacheView *DestroyCacheView(CacheView *);
extern void GetMagickPixelPacket(const Image *, MagickPixelPacket *);
extern double GetPixelRed(const PixelPacket *);
extern double GetPixelGreen(const PixelPacket *);
extern double GetPixelBlue(const PixelPacket *);
extern double GetPixelOpacity(const PixelPacket *);
extern unsigned short GetPixelIndex(const IndexPacket *);
extern void SetPixelRed(PixelPacket *, double);
extern void SetPixelGreen(PixelPacket *, double);
extern void SetPixelBlue(PixelPacket *, double);
extern void SetPixelOpacity(PixelPacket *, double);
extern void SetPixelIndex(IndexPacket *, unsigned short);
extern MagickBooleanType SetImageProgress(const Image *, const char *, MagickOffsetType, size_t);
extern void LogMagickEvent(LogEventType, const void *, const char *, ...);
extern const void *GetMagickModule(void);