#include <assert.h>
#include <stddef.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    UndefinedQuantumFormat,
    SignedQuantumFormat,
    FloatingPointQuantumFormat
} QuantumFormat;

typedef enum {
    MSBEndian,
    LSBEndian
} EndianType;

typedef enum {
    GrayQuantum,
    RedQuantum,
    GreenQuantum,
    BlueQuantum
} QuantumType;

typedef enum {
    sRGBColorspace
} ColorspaceType;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    ResourceLimitError
} ExceptionType;

typedef enum {
    SaveImageTag,
    SaveImagesTag
} ProgressMonitorTag;

typedef enum {
    WriteBinaryBlobMode
} BlobMode;

#define MagickSignature 0x12345678

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
    char *description;
} ExceptionInfo;

typedef struct _IPLInfo {
    unsigned int byteType;
    unsigned int z;
    unsigned int time;
    unsigned int width;
    unsigned int height;
    unsigned int colors;
    unsigned int size;
} IPLInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    EndianType endian;
    MagickBooleanType adjoin;
    MagickBooleanType debug;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    ColorspaceType colorspace;
    MagickBooleanType debug;
    char *filename;
    ExceptionInfo exception;
    struct _Image *previous;
    EndianType endian;
} Image;

typedef struct _QuantumInfo {
    QuantumFormat format;
    unsigned int depth;
} QuantumInfo;

typedef struct _PixelPacket {
    int dummy;
} PixelPacket;

typedef struct _CacheView {
    int dummy;
} CacheView;

typedef long MagickOffsetType;
typedef long ssize_t;

MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
MagickBooleanType LogMagickEvent(LogEventType, const char *, const char *, ...);
const char *GetMagickModule(void);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
void ThrowWriterException(ExceptionType, const char *);
MagickBooleanType IsHighDynamicRangeImage(Image *, ExceptionInfo *);
void SetQuantumFormat(Image *, QuantumInfo *, QuantumFormat);
unsigned long GetImageListLength(Image *);
void TransformImageColorspace(Image *, ColorspaceType);
MagickBooleanType IssRGBCompatibleColorspace(ColorspaceType);
void WriteBlob(Image *, size_t, const unsigned char *);
void WriteBlobLong(Image *, unsigned int);
unsigned char *GetQuantumPixels(QuantumInfo *);
const PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
const PixelPacket *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void ExportQuantumPixels(Image *, const CacheView *, QuantumInfo *, QuantumType, unsigned char *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ProgressMonitorTag, MagickOffsetType, unsigned long);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
void CloseBlob(Image *);