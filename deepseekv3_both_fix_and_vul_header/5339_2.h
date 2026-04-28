#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef int MagickStatusType;
typedef int MagickOffsetType;
typedef double MagickRealType;

#define MagickCoreSignature 0
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define DirectClass 0
#define PseudoClass 1
#define LoadImageTag 0
#define MSBFirst 0
#define LSBFirst 1
#define StaticGray 0
#define GrayScale 1
#define StaticColor 2
#define PseudoColor 3
#define TrueColor 4
#define DirectColor 5
#define XYBitmap 0
#define XYPixmap 1
#define ZPixmap 2
#define XWD_FILE_VERSION 7

#define sz_XWDheader 100
#define sz_XWDColor 12

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} PixelInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    unsigned storage_class;
    size_t colors;
    PixelInfo *colormap;
    char *filename;
} Image;

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
    int byte_order;
    int bitmap_unit;
    int bitmap_bit_order;
    int bitmap_pad;
    int bits_per_pixel;
    int bytes_per_line;
    int visual_class;
    int red_mask;
    int green_mask;
    int blue_mask;
    int ncolors;
} XWDFileHeader;

typedef struct _XWDColor {
    unsigned long pixel;
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    char flags;
} XWDColor;

static Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
static MagickStatusType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static void MSBOrderLong(unsigned char *, size_t);
static void MSBOrderShort(unsigned char *, size_t);
static void ThrowReaderException(int, const char *);
static char *AcquireQuantumMemory(size_t, size_t);
static void *AcquireMagickMemory(size_t);
static void *RelinquishMagickMemory(void *);
static char *DestroyString(char *);
static int XInitImage(XImage *);
static unsigned long XGetPixel(XImage *, int, int);
static void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
static Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
static MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
static MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
static void SetPixelRed(Image *, Quantum, Quantum *);
static void SetPixelGreen(Image *, Quantum, Quantum *);
static void SetPixelBlue(Image *, Quantum, Quantum *);
static void SetPixelIndex(Image *, Quantum, Quantum *);
static void SetPixelViaPixelInfo(Image *, PixelInfo *, Quantum *);
static Quantum ScaleShortToQuantum(unsigned short);
static ssize_t ConstrainColormapIndex(Image *, ssize_t, ExceptionInfo *);
static int GetPixelChannels(Image *);
static int EOFBlob(Image *);
static void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
static int CloseBlob(Image *);
static Image *GetFirstImageInList(Image *);
static void LogMagickEvent(int, const char *, const char *, ...);
static const char *GetMagickModule(void);