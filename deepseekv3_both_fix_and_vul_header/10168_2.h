#include <stdlib.h>
#include <string.h>

typedef unsigned long Quantum;
typedef unsigned long long MagickSizeType;
typedef long long MagickOffsetType;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
#define ModuleExport

typedef enum {
  UndefinedException,
  CorruptImageError,
  ResourceLimitError
} ExceptionType;

typedef enum {
  UndefinedEvent,
  CoderEvent
} LogEventType;

typedef enum {
  UndefinedTag,
  LoadImagesTag
} ProgressMonitorTag;

typedef struct _StringInfo {
    unsigned char *datum;
    size_t length;
} StringInfo;

typedef struct _RectangleInfo {
    ssize_t x;
    ssize_t y;
    size_t width;
    size_t height;
} RectangleInfo;

typedef struct _ChannelInfo {
    short type;
    size_t size;
} ChannelInfo;

typedef struct _LayerMask {
    RectangleInfo page;
    unsigned char background;
    unsigned char flags;
} LayerMask;

typedef struct _LayerInfo {
    RectangleInfo page;
    short channels;
    ChannelInfo channel_info[24];
    char blendkey[4];
    Quantum opacity;
    unsigned char clipping;
    unsigned char flags;
    MagickBooleanType visible;
    StringInfo *info;
    struct _Image *image;
    char name[256];
    LayerMask mask;
} LayerInfo;

typedef struct _PSDInfo {
    size_t version;
    size_t channels;
    size_t rows;
    size_t columns;
    size_t depth;
    size_t mode;
} PSDInfo;

typedef struct _Image {
    char *filename;
    MagickBooleanType debug;
    MagickBooleanType matte;
    struct _Image *next;
    struct _Image *previous;
    RectangleInfo page;
} Image;

typedef struct _ImageInfo {
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    int severity;
} ExceptionInfo;

#define MaxPSDChannels 24

/* Function declarations */
MagickSizeType GetPSDSize(const PSDInfo *,const Image *);
long ReadBlobLong(Image *);
ssize_t ReadBlob(Image *,size_t,unsigned char *);
void ReversePSDString(Image *,char *,size_t);
int LocaleNCompare(const char *,const char *,size_t);
short ReadBlobShort(Image *);
ssize_t MagickAbsoluteValue(ssize_t);
void LogMagickEvent(LogEventType,const char *,const char *,...);
const char *GetMagickModule(void);
void ThrowBinaryException(ExceptionType,const char *,const char *);
void *AcquireQuantumMemory(size_t,size_t);
void *ResetMagickMemory(void *,int,size_t);
LayerInfo *DestroyLayerInfo(LayerInfo *,ssize_t);
signed long ReadBlobSignedLong(Image *);
unsigned char ReadBlobByte(Image *);
unsigned char ScaleCharToQuantum(unsigned char);
MagickBooleanType DiscardBlobBytes(Image *,MagickSizeType);
StringInfo *AcquireStringInfo(const size_t);
unsigned char *GetStringInfoDatum(StringInfo *);
Image *CloneImage(const Image *,size_t,size_t,MagickBooleanType,ExceptionInfo *);
void *RelinquishMagickMemory(void *);
MagickBooleanType ReadPSDLayer(Image *,const ImageInfo *,const PSDInfo *,LayerInfo *,ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *,ProgressMonitorTag,ssize_t,MagickSizeType);
void SetImageProfile(Image *,const char *,const StringInfo *);
StringInfo *DestroyStringInfo(StringInfo *);