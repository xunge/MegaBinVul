#include <assert.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef ptrdiff_t ssize_t;

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _RectangleInfo RectangleInfo;
typedef struct _StringInfo StringInfo;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define OpaqueAlpha 1.0
#define TransparentAlpha 0.0
#define MagickPathExtent 4096
#define NoInterlace 0

enum {
    WriteBinaryBlobMode,
    ResourceLimitError,
    TraceEvent,
    CoderEvent,
    SaveImagesTag
};

enum {
    DirectClass,
    PaletteType,
    PaletteBilevelAlphaType
};

typedef struct {
    double red;
    double green;
    double blue;
    double alpha;
} PixelInfo;

struct _RectangleInfo {
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
};

struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
    RectangleInfo page;
    size_t colors;
    PixelInfo *colormap;
    PixelInfo transparent_color;
    PixelInfo background_color;
    int storage_class;
    MagickBooleanType adjoin;
    char *magick;
    MagickBooleanType interlace;
    size_t delay;
    size_t ticks_per_second;
    int dispose;
    size_t iterations;
    float gamma;
    Image *previous;
    Image *next;
    void *profiles;
};

struct _ImageInfo {
    unsigned long signature;
    char *magick;
    MagickBooleanType adjoin;
    MagickBooleanType interlace;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _StringInfo {
    unsigned char *datum;
    size_t length;
};

#define sRGBColorspace 1

void *AcquireQuantumMemory(size_t count, size_t quantum);
void *RelinquishMagickMemory(void *memory);
void LogMagickEvent(int event, const char *module, const char *format, ...);
const char *GetMagickModule(void);
MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception);
void ThrowWriterException(int error, const char *reason);
ImageInfo *CloneImageInfo(const ImageInfo *image_info);
int LocaleCompare(const char *p, const char *q);
int LocaleNCompare(const char *p, const char *q, size_t n);
size_t WriteBlob(Image *image, size_t length, const unsigned char *data);
size_t WriteBlobByte(Image *image, unsigned char value);
size_t WriteBlobLSBShort(Image *image, unsigned short value);
MagickBooleanType TransformImageColorspace(Image *image, int colorspace, ExceptionInfo *exception);
MagickBooleanType IsImageOpaque(Image *image, ExceptionInfo *exception);
MagickBooleanType SetImageType(Image *image, int type, ExceptionInfo *exception);
unsigned char ScaleQuantumToChar(double quantum);
double ClampToQuantum(double value);
Image *GetNextImageInList(const Image *image);
Image *GetPreviousImageInList(const Image *image);
Image *SyncNextImageInList(Image *image);
size_t GetImageListLength(const Image *image);
const char *GetImageProperty(const Image *image, const char *property, ExceptionInfo *exception);
size_t MagickMin(size_t x, size_t y);
size_t MagickMax(size_t x, size_t y);
int FormatLocaleString(char *string, size_t length, const char *format, ...);
void ResetImageProfileIterator(Image *image);
const char *GetNextImageProfile(Image *image);
const StringInfo *GetImageProfile(const Image *image, const char *name);
void CopyMagickString(char *destination, const char *source, size_t length);
MagickBooleanType EncodeImage(const ImageInfo *image_info, Image *image, size_t bits_per_pixel, ExceptionInfo *exception);
MagickBooleanType SetImageProgress(Image *image, int tag, MagickOffsetType offset, size_t quantum);
MagickBooleanType CloseBlob(Image *image);
ImageInfo *DestroyImageInfo(ImageInfo *image_info);
MagickBooleanType IsPixelInfoEquivalent(const PixelInfo *p, const PixelInfo *q);
unsigned char *GetStringInfoDatum(const StringInfo *string_info);
size_t GetStringInfoLength(const StringInfo *string_info);