#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

typedef unsigned int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} PixelTrait;

typedef enum {
    TransparentAlpha
} AlphaType;

typedef struct _ColorInfo {
    AlphaType alpha;
    PixelTrait alpha_trait;
} ColorInfo;

typedef struct _PixelPacket {
    double red;
    double green;
    double blue;
} PixelPacket;

typedef struct _Image {
    unsigned long signature;
    unsigned long columns;
    unsigned long rows;
    unsigned short depth;
    unsigned short endian;
    MagickBooleanType debug;
    unsigned long colors;
    PixelPacket *colormap;
    unsigned char storage_class;
    PixelTrait alpha_trait;
    ColorInfo background_color;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    unsigned long number_scenes;
    unsigned long scene;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _PSDInfo {
    char signature[4];
    unsigned short version;
    char reserved[6];
    unsigned short channels;
    unsigned long rows;
    unsigned long columns;
    unsigned short depth;
    unsigned short mode;
} PSDInfo;

typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    MSBEndian
} EndianType;

typedef enum {
    LabMode,
    CMYKMode,
    BitmapMode,
    GrayscaleMode,
    DuotoneMode
} PSDImageType;

typedef enum {
    LabColorspace,
    CMYKColorspace,
    GRAYColorspace
} ColorspaceType;

typedef enum {
    PseudoClass
} ClassType;

typedef enum {
    TransparentAlphaChannel
} AlphaChannelType;

typedef enum {
    TraceEvent,
    CoderEvent
} EventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ErrorType;

typedef enum {
    FlattenLayer
} LayerMethod;

#define MagickCoreSignature 0xABACADABUL
#define MaxPSDChannels 56
#define SEEK_SET 0

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
unsigned short ReadBlobMSBShort(Image *);
int LocaleNCompare(const char *, const char *, size_t);
void ThrowReaderException(ErrorType, const char *);
unsigned long ReadBlobMSBLong(Image *);
const char *ModeToString(PSDImageType);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType SetImageBackgroundColor(Image *, ExceptionInfo *);
void SetImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
unsigned char ReadBlobByte(Image *);
unsigned char *AcquireQuantumMemory(size_t, size_t);
unsigned char *RelinquishMagickMemory(void *);
void ParseImageResourceBlocks(Image *, unsigned char *, size_t, MagickBooleanType *, ExceptionInfo *);
MagickSizeType GetPSDSize(PSDInfo *, Image *);
MagickOffsetType TellBlob(Image *);
MagickBooleanType ReadPSDLayers(Image *, const ImageInfo *, PSDInfo *, MagickBooleanType, ExceptionInfo *);
void SeekBlob(Image *, MagickOffsetType, int);
Image *GetFirstImageInList(Image *);
MagickBooleanType ReadPSDMergedImage(const ImageInfo *, Image *, PSDInfo *, ExceptionInfo *);
size_t GetImageListLength(Image *);
void SetImageAlphaChannel(Image *, AlphaChannelType, ExceptionInfo *);
Image *MergeImageLayers(Image *, LayerMethod, ExceptionInfo *);
void ReplaceImageInList(Image **, Image *);
MagickBooleanType CloseBlob(Image *);
void *LogMagickEvent(EventType, const char *, const char *, ...);
const char *GetMagickModule(void);
double ScaleCharToQuantum(unsigned char);