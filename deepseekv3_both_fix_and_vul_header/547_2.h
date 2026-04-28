#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef double MagickRealType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef MagickBooleanType MagickStatusType;

typedef struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    unsigned storage_class;
    size_t colors;
    struct {
        MagickRealType red;
        MagickRealType green;
        MagickRealType blue;
    } *colormap;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
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
    int depth;
    int format;
    int xoffset;
    char *data;
    int width;
    int height;
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
    int file_version;
    int header_size;
    int xoffset;
    int visual_class;
    int bits_per_pixel;
    int colormap_entries;
    int pixmap_format;
    int pixmap_depth;
    int bitmap_pad;
    int bytes_per_line;
    int byte_order;
    int bitmap_unit;
    int bitmap_bit_order;
    int pixmap_width;
    int pixmap_height;
    int ncolors;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
} XWDFileHeader;

typedef struct _XWDColor {
    unsigned long pixel;
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    char flags;
} XWDColor;

typedef unsigned char Quantum;

#define MagickCoreSignature 0xABACADABUL
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define DirectClass 0
#define PseudoClass 1
#define LoadImageTag 0

#define sz_XWDheader sizeof(XWDFileHeader)
#define sz_XWDColor sizeof(XWDColor)
#define XWD_FILE_VERSION 7

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

enum {
    LSBFirst,
    MSBFirst
};

static void *AcquireQuantumMemory(size_t count, size_t quantum);
static void *AcquireMagickMemory(size_t size);
static void *RelinquishMagickMemory(void *memory);
static char *DestroyString(char *string);
static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception);
static Image *DestroyImageList(Image *image);
static MagickStatusType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception);
static ssize_t ReadBlob(Image *image, size_t length, unsigned char *data);
static void MSBOrderLong(unsigned char *buffer, size_t length);
static void MSBOrderShort(unsigned char *buffer, size_t length);
static void ThrowReaderException(int severity, const char *reason);
static void ThrowFileException(ExceptionInfo *exception, int severity, const char *reason, const char *description);
static void LogMagickEvent(int event, const char *module, const char *format, ...);
static void SetImageProperty(Image *image, const char *property, const char *value, ExceptionInfo *exception);
static MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows, ExceptionInfo *exception);
static Quantum *QueueAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception);
static MagickBooleanType SetImageProgress(Image *image, const char *tag, MagickOffsetType offset, size_t span);
static MagickBooleanType AcquireImageColormap(Image *image, size_t colors, ExceptionInfo *exception);
static MagickBooleanType EOFBlob(const Image *image);
static void CloseBlob(Image *image);
static unsigned long XGetPixel(XImage *ximage, int x, int y);
static int XInitImage(XImage *ximage);
static Quantum ScaleShortToQuantum(unsigned short value);
static ssize_t ConstrainColormapIndex(Image *image, ssize_t index, ExceptionInfo *exception);
static void SetPixelRed(Image *image, Quantum red, Quantum *pixel);
static void SetPixelGreen(Image *image, Quantum green, Quantum *pixel);
static void SetPixelBlue(Image *image, Quantum blue, Quantum *pixel);
static void SetPixelIndex(Image *image, Quantum index, Quantum *pixel);
static void SetPixelViaPixelInfo(Image *image, void *colormap, Quantum *pixel);
static const char *GetMagickModule(void);
static size_t GetBlobSize(Image *image);
static size_t GetPixelChannels(Image *image);
static Image *GetFirstImageInList(Image *image);