#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct _PixelPacket {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
} PixelPacket;

typedef struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    unsigned storage_class;
    size_t colors;
    char *filename;
    void *exception;
    PixelPacket *colormap;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    unsigned debug;
    char *filename;
    unsigned ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _XColor {
    unsigned long pixel;
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    char flags;
} XColor;

typedef struct _XImage {
    int width;
    int height;
    int depth;
    int format;
    int xoffset;
    char *data;
    int bitmap_pad;
    int bytes_per_line;
    int byte_order;
    int bitmap_unit;
    int bitmap_bit_order;
    int bits_per_pixel;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
} XImage;

typedef struct _XWDFileHeader {
    int header_size;
    int file_version;
    int pixmap_format;
    int pixmap_depth;
    int pixmap_width;
    int pixmap_height;
    int xoffset;
    int bitmap_pad;
    int bytes_per_line;
    int byte_order;
    int bitmap_unit;
    int bitmap_bit_order;
    int bits_per_pixel;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    unsigned ncolors;
    int visual_class;
} XWDFileHeader;

typedef struct _XWDColor {
    unsigned long pixel;
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    char flags;
} XWDColor;

typedef unsigned char MagickBooleanType;
typedef unsigned char MagickStatusType;
typedef long MagickOffsetType;
typedef unsigned long IndexPacket;
typedef PixelPacket *PixelPacketPtr;
typedef long ssize_t;
typedef unsigned long size_t;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define XWD_FILE_VERSION 7
#define sz_XWDheader (sizeof(XWDFileHeader))
#define sz_XWDColor (sizeof(XWDColor))

enum {
    StaticGray,
    GrayScale,
    StaticColor,
    PseudoColor,
    TrueColor,
    DirectColor
};

enum {
    XYBitmap,
    XYPixmap,
    ZPixmap
};

#define DirectClass 1
#define PseudoClass 2
#define TraceEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define LoadImageTag 0
#define ReadBinaryBlobMode 0

Image *AcquireImage(const ImageInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void *AcquireMagickMemory(size_t);
void *RelinquishMagickMemory(void *);
char *DestroyString(char *);
MagickStatusType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void ThrowReaderException(int, const char *);
void MSBOrderLong(unsigned char *, size_t);
void MSBOrderShort(unsigned char *, size_t);
int XInitImage(XImage *);
PixelPacketPtr QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
void InheritException(ExceptionInfo *, void *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
int EOFBlob(Image *);
int CloseBlob(Image *);
unsigned long XGetPixel(XImage *, int, int);
IndexPacket ConstrainColormapIndex(Image *, unsigned long);
MagickBooleanType AcquireImageColormap(Image *, size_t);
void SetImageProperty(Image *, const char *, const char *);
void LogMagickEvent(int, const char *, const char *, const char *);
const char *GetMagickModule(void);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
IndexPacket *GetAuthenticIndexQueue(Image *);
void SetPixelRed(PixelPacketPtr, unsigned short);
void SetPixelGreen(PixelPacketPtr, unsigned short);
void SetPixelBlue(PixelPacketPtr, unsigned short);
void SetPixelIndex(IndexPacket *, IndexPacket);
void SetPixelRGBO(PixelPacketPtr, PixelPacket *);
unsigned short ScaleShortToQuantum(unsigned short);
Image *GetFirstImageInList(Image *);