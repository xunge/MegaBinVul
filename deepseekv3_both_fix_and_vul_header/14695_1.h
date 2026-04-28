#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef long ssize_t;
typedef long MagickOffsetType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    UndefinedCompression,
    RLECompression
} CompressionType;

typedef enum {
    TrueColorType,
    TrueColorMatteType,
    PaletteType
} ImageType;

typedef enum {
    BottomRightOrientation,
    TopRightOrientation,
    TopLeftOrientation
} OrientationType;

typedef enum {
    sRGBColorspace
} ColorspaceType;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    ImageError,
    ResourceLimitError
} ExceptionType;

typedef struct {
    unsigned char id_length;
    unsigned char colormap_type;
    unsigned char image_type;
    unsigned short colormap_index;
    unsigned short colormap_length;
    unsigned char colormap_size;
    unsigned short x_origin;
    unsigned short y_origin;
    unsigned short width;
    unsigned short height;
    unsigned char bits_per_pixel;
    unsigned char attributes;
} TGAInfo;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
} PixelPacket;

typedef struct {
    unsigned long signature;
    void *exception;
    unsigned char debug;
    char *filename;
    size_t columns;
    size_t rows;
    CompressionType compression;
    MagickBooleanType matte;
    size_t colors;
    PixelPacket *colormap;
    void *previous;
    void *storage_class;
} Image;

typedef struct {
    unsigned long signature;
    CompressionType compression;
    ImageType type;
    unsigned char depth;
    char *properties;
    char *artifacts;
} ImageInfo;

typedef unsigned char IndexPacket;
typedef unsigned short Quantum;
typedef unsigned long QuantumAny;
#define QuantumRange 65535UL

#define MagickSignature 0x12345678
#define WriteBinaryBlobMode 0
#define TGAMonochrome 0
#define TGARGB 2
#define TGAColormap 1
#define TGARLEMonochrome 9
#define TGARLERGB 10
#define TGARLEColormap 9
#define DirectClass 0
#define SaveImageTag 0

static const char *MagickOrientationOptions = "TopLeft,TopRight,BottomRight,BottomLeft";

void *GetMagickModule(void);
void LogMagickEvent(LogEventType, void *, const char *, ...);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, void *);
void ThrowWriterException(ExceptionType, const char *);
void TransformImageColorspace(Image *, ColorspaceType);
QuantumAny GetQuantumRange(unsigned long);
const char *GetImageProperty(Image *, const char *);
size_t MagickMin(size_t, size_t);
const char *GetImageArtifact(Image *, const char *);
int ParseCommandOption(const char *, MagickBooleanType, const char *);
void WriteBlobByte(Image *, unsigned char);
void WriteBlobLSBShort(Image *, unsigned short);
void WriteBlob(Image *, size_t, unsigned char *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
unsigned char ScaleQuantumToAny(Quantum, QuantumAny);
unsigned char ScaleQuantumToChar(Quantum);
const PixelPacket *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, void *);
const IndexPacket *GetVirtualIndexQueue(Image *);
double GetPixelLuma(Image *, const PixelPacket *);
Quantum GetPixelBlue(const PixelPacket *);
Quantum GetPixelGreen(const PixelPacket *);
Quantum GetPixelRed(const PixelPacket *);
Quantum GetPixelAlpha(const PixelPacket *);
IndexPacket GetPixelIndex(const IndexPacket *);
void WriteTGAPixel(Image *, unsigned char, const IndexPacket *, const PixelPacket *, QuantumAny, double);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
void CloseBlob(Image *);
MagickBooleanType SetImageGray(Image *, void *);