#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

typedef unsigned char Quantum;
typedef unsigned char MagickBooleanType;
typedef long MagickOffsetType;

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _MemoryInfo MemoryInfo;
typedef struct _PCXInfo PCXInfo;
typedef struct _PixelPacket PixelPacket;
typedef Quantum IndexPacket;

struct _ImageInfo {
    unsigned long signature;
    char *magick;
    MagickBooleanType adjoin;
    int compression;
    int debug;
};

struct _Image {
    unsigned long signature;
    char *filename;
    unsigned long columns;
    unsigned long rows;
    int storage_class;
    int colors;
    int matte;
    double x_resolution;
    double y_resolution;
    int units;
    int debug;
    void *exception;
    Image *previous;
    Image *next;
    PixelPacket *colormap;
};

struct _MemoryInfo {
    void *blob;
};

struct _PCXInfo {
    unsigned char identifier;
    unsigned char version;
    unsigned char encoding;
    unsigned char bits_per_pixel;
    unsigned short left;
    unsigned short top;
    unsigned short right;
    unsigned short bottom;
    unsigned short horizontal_resolution;
    unsigned short vertical_resolution;
    unsigned char reserved;
    unsigned char planes;
    unsigned short bytes_per_line;
    unsigned char palette_info;
    unsigned char colormap_signature;
};

struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum alpha;
};

enum {
    MagickFalse,
    MagickTrue
};

enum {
    NoCompression,
    UndefinedResolution,
    PixelsPerInchResolution,
    PixelsPerCentimeterResolution,
    PseudoClass,
    DirectClass,
    sRGBColorspace,
    WriteBinaryBlobMode,
    TraceEvent,
    SaveImageTag,
    SaveImagesTag,
    ImageError,
    ResourceLimitError,
    CorruptImageError,
    FileOpenError
};

#define MagickSignature 0x12345678
#define QuantumRange 255
#define GetMagickModule() "PCX"
#define GetImageListLength(image) 0
#define GetNextImageInList(image) ((image)->next)
#define SyncNextImageInList(image) ((image)->next)
#define GetVirtualPixels(image,x,y,width,height,exception) NULL
#define GetVirtualIndexQueue(image) NULL
#define ScaleQuantumToChar(value) ((unsigned char)(value))
#define GetPixelRed(p) ((p)->red)
#define GetPixelGreen(p) ((p)->green)
#define GetPixelBlue(p) ((p)->blue)
#define GetPixelAlpha(p) ((p)->alpha)
#define GetPixelLuma(image,p) 0
#define GetPixelIndex(indexes) 0
#define AcquireQuantumMemory(size,element_size) malloc((size)*(element_size))
#define RelinquishMagickMemory(memory) (free(memory), NULL)
#define AcquireVirtualMemory(length,size) malloc((length)*(size))
#define RelinquishVirtualMemory(memory) (free(memory), NULL)
#define GetVirtualMemoryBlob(memory) ((memory)->blob)
#define DestroyString(string) (free(string), NULL)

int LocaleCompare(const char *, const char *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, void *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType WriteBlobByte(Image *, unsigned char);
MagickBooleanType WriteBlob(Image *, size_t, const unsigned char *);
MagickBooleanType WriteBlobLSBShort(Image *, unsigned short);
MagickBooleanType WriteBlobLSBLong(Image *, unsigned int);
MagickBooleanType PCXWritePixels(PCXInfo *, unsigned char *, Image *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, unsigned long);
MagickBooleanType TransformImageColorspace(Image *, int);
MagickBooleanType SetImageMonochrome(Image *, void *);
void *LogMagickEvent(int, const char *, const char *, ...);
void *ThrowWriterException(int, const char *);
void *ThrowMagickException(void *, const char *, int, const char *, const char *, ...);
char *GetExceptionMessage(int);
MagickOffsetType TellBlob(Image *);
MagickOffsetType SeekBlob(Image *, long, int);