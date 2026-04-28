#include <assert.h>
#include <stdlib.h>

typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo {
    int code;
    char *reason;
    char *description;
} ExceptionInfo;
typedef struct _PixelPacket {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
} PixelPacket;
typedef struct _IndexPacket {
    unsigned short index;
} IndexPacket;

struct _ImageInfo {
    unsigned long signature;
    int debug;
    ExceptionInfo exception;
};

struct _Image {
    unsigned long signature;
    int debug;
    size_t columns;
    size_t rows;
    size_t colors;
    PixelPacket *colormap;
    char *filename;
    ExceptionInfo exception;
};

#define MagickSignature 0x12345678
#define TraceEvent 0
#define WriteBinaryBlobMode 0
#define sRGBColorspace 0
#define PaletteType 0
#define ResourceLimitError 0

void *AcquireQuantumMemory(size_t count, size_t size);
void *RelinquishMagickMemory(void *memory);
unsigned char ScaleQuantumToChar(unsigned short quantum);
unsigned short ScaleQuantumToShort(unsigned short quantum);
unsigned short GetPixelIndex(const IndexPacket *indexes);
const PixelPacket *GetVirtualPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
const IndexPacket *GetVirtualIndexQueue(Image *image);
MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception);
MagickBooleanType IsPaletteImage(Image *image, ExceptionInfo *exception);
MagickBooleanType SetImageType(Image *image, int type);
MagickBooleanType TransformImageColorspace(Image *image, int colorspace);
size_t GetImageQuantumDepth(Image *image, MagickBooleanType dummy);
void WriteBlob(Image *image, size_t length, const unsigned char *data);
void CloseBlob(Image *image);
void LogMagickEvent(int event, const char *module, const char *format, ...);
const char *GetMagickModule(void);
void ThrowWriterException(int error, const char *reason);