#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct RectangleInfo {
  ssize_t x;
  ssize_t y;
  size_t width;
  size_t height;
} RectangleInfo;

typedef struct _Image {
  MagickBooleanType debug;
  unsigned int alpha_trait;
  char *filename;
  struct _Image *next;
  struct _Image *previous;
  RectangleInfo page;
} Image;

typedef struct _ImageInfo {
  MagickBooleanType ping;
} ImageInfo;

typedef struct _PSDInfo PSDInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _StringInfo StringInfo;

typedef struct _LayerInfo {
  RectangleInfo page;
  struct {
    short type;
    size_t size;
  } channel_info[24];
  short channels;
  char blendkey[4];
  unsigned long opacity;
  unsigned char clipping;
  unsigned char flags;
  MagickBooleanType visible;
  struct {
    RectangleInfo page;
    unsigned char background;
    unsigned char flags;
  } mask;
  char name[256];
  StringInfo *info;
  Image *image;
} LayerInfo;

typedef unsigned long Quantum;
typedef long MagickOffsetType;
typedef unsigned long long MagickSizeType;

#define MaxPSDChannels 24
#define BlendPixelTrait 1
#define CoderEvent 1
#define CorruptImageError 1
#define ResourceLimitError 1
#define LoadImagesTag 1

extern MagickSizeType GetPSDSize(const PSDInfo *, const Image *);
extern long ReadBlobLong(Image *);
extern ssize_t ReadBlob(Image *, size_t, unsigned char *);
extern void ReversePSDString(Image *, char *, size_t);
extern int LocaleNCompare(const char *, const char *, size_t);
extern short ReadBlobShort(Image *);
extern ssize_t MagickAbsoluteValue(ssize_t);
extern void *LogMagickEvent(size_t, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern void ThrowBinaryException(size_t, const char *, const char *);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void *ResetMagickMemory(void *, int, size_t);
extern LayerInfo *DestroyLayerInfo(LayerInfo *, ssize_t);
extern signed long ReadBlobSignedLong(Image *);
extern unsigned char ReadBlobByte(Image *);
extern unsigned char ScaleCharToQuantum(unsigned char);
extern MagickBooleanType DiscardBlobBytes(Image *, MagickSizeType);
extern StringInfo *AcquireStringInfo(const size_t);
extern unsigned char *GetStringInfoDatum(StringInfo *);
extern Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
extern MagickBooleanType SetImageProfile(Image *, const char *, StringInfo *, ExceptionInfo *);
extern StringInfo *DestroyStringInfo(StringInfo *);
extern MagickBooleanType ReadPSDLayer(Image *, const ImageInfo *, const PSDInfo *, LayerInfo *, ExceptionInfo *);
extern MagickBooleanType SetImageProgress(Image *, size_t, ssize_t, MagickSizeType);
extern void *RelinquishMagickMemory(void *);