#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef int MagickStatusType;
typedef int MagickOffsetType;
typedef double MagickRealType;

typedef struct _ImageInfo {
    unsigned long signature;
    int debug;
    const char *filename;
    int ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    int storage_class;
    size_t colors;
    struct {
        MagickRealType red;
        MagickRealType green;
        MagickRealType blue;
    } *colormap;
    const char *filename;
} Image;

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
    unsigned int ncolors;
    int visual_class;
} XWDFileHeader;

typedef struct _XWDColor {
    unsigned long pixel;
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    char flags;
} XWDColor;

#define MagickCoreSignature 0x12345678
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define MemoryAllocationFailed ""
#define UnableToReadImageHeader ""
#define FileFormatVersionMismatch ""
#define UnexpectedEndOfFile ""
#define LoadImageTag 0
#define DirectClass 0
#define PseudoClass 1
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

#define sz_XWDheader sizeof(XWDFileHeader)
#define sz_XWDColor sizeof(XWDColor)

/* Function prototypes */
static void *LogMagickEvent(int, const char *, const char *, ...);
static const char *GetMagickModule(void);
static Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
static MagickStatusType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static void ThrowReaderException(int, const char *);
static void *AcquireQuantumMemory(size_t, size_t);
static char *DestroyString(char *);
static void *AcquireMagickMemory(size_t);
static void *RelinquishMagickMemory(void *);
static void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
static Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
static MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
static unsigned short ScaleShortToQuantum(unsigned short);
static Quantum ConstrainColormapIndex(Image *, unsigned long, ExceptionInfo *);
static void SetPixelRed(Image *, Quantum, Quantum *);
static void SetPixelGreen(Image *, Quantum, Quantum *);
static void SetPixelBlue(Image *, Quantum, Quantum *);
static void SetPixelIndex(Image *, Quantum, Quantum *);
static void SetPixelViaPixelInfo(Image *, void *, Quantum *);
static int GetPixelChannels(Image *);
static MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
static int EOFBlob(Image *);
static void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
static int CloseBlob(Image *);
static Image *GetFirstImageInList(Image *);
static void MSBOrderLong(unsigned char *, size_t);
static void MSBOrderShort(unsigned char *, size_t);
static int XInitImage(XImage *);
static unsigned long XGetPixel(XImage *, int, int);