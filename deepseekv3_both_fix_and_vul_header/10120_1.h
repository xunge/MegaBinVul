#include <stdlib.h>
#include <string.h>

typedef unsigned short Quantum;
typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

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

typedef struct _LayerMaskInfo {
    RectangleInfo page;
    unsigned char background;
    unsigned char flags;
} LayerMaskInfo;

typedef struct _StringInfo {
    size_t length;
    unsigned char *datum;
} StringInfo;

typedef struct _Image {
    char *filename;
    MagickBooleanType debug;
    MagickBooleanType matte;
    struct _Image *previous;
    struct _Image *next;
    RectangleInfo page;
} Image;

typedef struct _ImageInfo {
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
} ExceptionInfo;

typedef struct _PSDInfo {
    size_t version;
    size_t channels;
    size_t rows;
    size_t columns;
    size_t depth;
    size_t mode;
} PSDInfo;

typedef struct _LayerInfo {
    RectangleInfo page;
    short channels;
    ChannelInfo channel_info[24];
    char blendkey[4];
    Quantum opacity;
    unsigned char clipping;
    unsigned char flags;
    MagickBooleanType visible;
    LayerMaskInfo mask;
    char name[256];
    StringInfo *info;
    Image *image;
} LayerInfo;

#define MaxPSDChannels 24
#define CoderEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define LoadImagesTag 0

typedef size_t MagickSizeType;
typedef off_t MagickOffsetType;
#define ModuleExport

#define MagickAbsoluteValue(x) ((x) < 0 ? -(x) : (x))

extern size_t GetPSDSize(const PSDInfo *, const Image *);
extern ssize_t ReadBlobLong(Image *);
extern ssize_t ReadBlob(Image *, size_t, unsigned char *);
extern void ReversePSDString(Image *, char *, size_t);
extern int LocaleNCompare(const char *, const char *, size_t);
extern ssize_t ReadBlobShort(Image *);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void *ResetMagickMemory(void *, int, size_t);
extern LayerInfo *DestroyLayerInfo(LayerInfo *, ssize_t);
extern void LogMagickEvent(int, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern void ThrowBinaryException(int, const char *, const char *);
extern ssize_t ReadBlobSignedLong(Image *);
extern unsigned char ReadBlobByte(Image *);
extern unsigned char ScaleCharToQuantum(unsigned char);
extern MagickBooleanType DiscardBlobBytes(Image *, MagickSizeType);
extern StringInfo *AcquireStringInfo(const size_t);
extern unsigned char *GetStringInfoDatum(StringInfo *);
extern Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
extern void *SetImageProfile(Image *, const char *, StringInfo *);
extern StringInfo *DestroyStringInfo(StringInfo *);
extern MagickBooleanType ReadPSDLayer(Image *, const ImageInfo *, const PSDInfo *, LayerInfo *, ExceptionInfo *);
extern MagickBooleanType SetImageProgress(Image *, int, ssize_t, MagickSizeType);
extern void *RelinquishMagickMemory(void *);