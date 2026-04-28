#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned char MagickBooleanType;
typedef unsigned long MagickSizeType;
typedef unsigned long Quantum;
typedef unsigned long MagickOffsetType;

#define MagickFalse 0
#define MagickTrue 1
#define MaxPSDChannels 24
#define CoderEvent 0
#define LoadImagesTag 0
#define CorruptImageError 0
#define ResourceLimitError 0

typedef struct _RectangleInfo {
    ssize_t x;
    ssize_t y;
    size_t width;
    size_t height;
} RectangleInfo;

typedef struct _MaskInfo {
    RectangleInfo page;
    unsigned char background;
    unsigned char flags;
} MaskInfo;

typedef struct _ChannelInfo {
    short type;
    size_t size;
} ChannelInfo;

typedef struct _StringInfo {
    unsigned char *datum;
    size_t length;
} StringInfo;

struct _Image;
typedef struct _Image Image;

struct _Image {
    MagickBooleanType debug;
    MagickBooleanType matte;
    char *filename;
    Image *next;
    Image *previous;
    RectangleInfo page;
};

typedef struct _ImageInfo {
    MagickBooleanType ping;
} ImageInfo;

typedef struct _PSDInfo {
    /* PSD specific info */
} PSDInfo;

typedef struct _ExceptionInfo {
    /* Exception handling info */
} ExceptionInfo;

typedef struct _LayerInfo {
    RectangleInfo page;
    MaskInfo mask;
    short channels;
    ChannelInfo channel_info[24];
    char blendkey[4];
    Quantum opacity;
    unsigned char clipping;
    unsigned char flags;
    MagickBooleanType visible;
    char name[256];
    StringInfo *info;
    Image *image;
} LayerInfo;

typedef struct _MagickModule {
    /* Module info */
} MagickModule;

static ssize_t ReadBlobShort(Image *);
static ssize_t ReadBlobSignedLong(Image *);
static ssize_t ReadBlobLong(Image *);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static unsigned char ReadBlobByte(Image *);
static MagickBooleanType DiscardBlobBytes(Image *, MagickSizeType);
static MagickSizeType GetPSDSize(const PSDInfo *, const Image *);
static void ReversePSDString(Image *, char *, size_t);
static int LocaleNCompare(const char *, const char *, size_t);
static void *AcquireQuantumMemory(size_t, size_t);
static void *ResetMagickMemory(void *, int, size_t);
static LayerInfo *DestroyLayerInfo(LayerInfo *, ssize_t);
static StringInfo *AcquireStringInfo(size_t);
static StringInfo *DestroyStringInfo(StringInfo *);
static Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
static MagickBooleanType SetImageProfile(Image *, const char *, StringInfo *);
static MagickBooleanType ReadPSDLayer(Image *, const ImageInfo *, const PSDInfo *, LayerInfo *, ExceptionInfo *);
static MagickBooleanType SetImageProgress(Image *, int, ssize_t, MagickSizeType);
static void LogMagickEvent(int, const MagickModule *, const char *, ...);
static const MagickModule *GetMagickModule(void);
static void ThrowBinaryException(int, const char *, const char *);
static size_t MagickAbsoluteValue(ssize_t);
static unsigned char ScaleCharToQuantum(unsigned char);
static size_t GetBlobSize(Image *);
static unsigned char *GetStringInfoDatum(StringInfo *);
static void *RelinquishMagickMemory(void *);