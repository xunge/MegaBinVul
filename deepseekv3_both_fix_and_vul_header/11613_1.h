#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>

typedef enum {
    UndefinedCompression,
    NoCompression
} CompressionType;

typedef enum {
    UndefinedPixelTrait,
    TrueColorType
} PixelTrait;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    sRGBColorspace
} ColorspaceType;

typedef enum {
    TraceEvent
} EventType;

typedef enum {
    ImageError,
    ResourceLimitError
} ExceptionType;

typedef enum {
    SaveImageTag,
    SaveImagesTag
} ProgressType;

typedef enum {
    WriteBinaryBlobMode
} BlobMode;

typedef struct _Image Image;

typedef struct {
    unsigned long signature;
    CompressionType compression;
    int type;
    int debug;
    int adjoin;
    char *filename;
    size_t columns;
    size_t rows;
    size_t depth;
    PixelTrait alpha_trait;
    Image *previous;
    Image *next;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    ImageInfo *image_info;
    size_t columns;
    size_t rows;
    size_t depth;
    CompressionType compression;
    PixelTrait alpha_trait;
    MagickBooleanType debug;
    Image *previous;
    Image *next;
    char *filename;
} Image;

typedef struct {
    unsigned long signature;
} ExceptionInfo;

typedef struct {
    size_t size;
    void *blob;
} MemoryInfo;

typedef struct {
    unsigned short magic;
    unsigned char storage;
    unsigned char bytes_per_pixel;
    unsigned short dimension;
    unsigned short columns;
    unsigned short rows;
    unsigned short depth;
    size_t minimum_value;
    size_t maximum_value;
    size_t sans;
    char name[80];
    size_t pixel_format;
    unsigned char filler[404];
} SGIInfo;

typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;
typedef unsigned char Quantum;

#define MagickCoreSignature 0x12345678
#define QuantumRange 65535
#define ScaleQuantumToChar(x) ((unsigned char)((x) >> 8))
#define ScaleQuantumToShort(x) ((unsigned short)(x))

void *AcquireVirtualMemory(size_t count, size_t quantum);
void *AcquireQuantumMemory(size_t count, size_t quantum);
void *GetVirtualMemoryBlob(MemoryInfo *);
void *RelinquishMagickMemory(void *);
void *RelinquishVirtualMemory(MemoryInfo *);
void *SyncNextImageInList(Image *);
const Quantum *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
const char *GetImageProperty(Image *, const char *, ExceptionInfo *);
Image *GetNextImageInList(Image *);
size_t GetImageListLength(Image *);
size_t SGIEncode(const unsigned char *, size_t, unsigned char *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType SetImageProgress(Image *, ProgressType, MagickOffsetType, size_t);
MagickBooleanType SetImageGray(Image *, ExceptionInfo *);
MagickBooleanType TransformImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
void LogMagickEvent(EventType, const char *, const char *, ...);
void ThrowWriterException(ExceptionType, const char *);
void WriteBlob(Image *, size_t, const unsigned char *);
void WriteBlobByte(Image *, unsigned char);
void WriteBlobMSBShort(Image *, unsigned short);
void WriteBlobMSBLong(Image *, unsigned int);
void CopyMagickString(char *, const char *, size_t);
unsigned char GetPixelRed(const Image *, const Quantum *);
unsigned char GetPixelGreen(const Image *, const Quantum *);
unsigned char GetPixelBlue(const Image *, const Quantum *);
unsigned char GetPixelAlpha(const Image *, const Quantum *);
size_t GetPixelChannels(const Image *);
const char *GetMagickModule(void);