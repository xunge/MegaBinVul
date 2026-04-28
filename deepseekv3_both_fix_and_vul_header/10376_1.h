#include <assert.h>
#include <stddef.h>

typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef ptrdiff_t ssize_t;
typedef size_t MagickOffsetType;

#define MagickSignature 0x12345678
#define TraceEvent 0
#define sRGBColorspace 0
#define BilevelType 0
#define SaveImageTag 0
#define WriteBinaryBlobMode 0
#define ImageError 0
#define QuantumRange 65535.0

struct _PixelPacket {
    unsigned char r, g, b, a;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _ImageInfo {
    unsigned long signature;
};

struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
    struct _ExceptionInfo exception;
};

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _PixelPacket PixelPacket;

MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
void LogMagickEvent(int, const char *, const char *, ...);
void TransformImageColorspace(Image *, int);
void ThrowWriterException(int, const char *);
void WriteBlobByte(Image *, unsigned char);
void SetImageType(Image *, int);
const PixelPacket *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
double GetPixelLuma(Image *, const PixelPacket *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
void CloseBlob(Image *);
const char *GetMagickModule(void);