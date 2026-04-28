#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef long MagickOffsetType;
typedef unsigned int MagickSizeType;
typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1
#define MagickCoreSignature 0xabacadabUL

typedef struct _ImageInfo {
    unsigned long signature;
    int ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _PixelInfo {
    double red;
    double green;
    double blue;
} PixelInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t colors;
    int depth;
    PixelInfo *colormap;
    struct _Image *previous;
    struct _Image *next;
    size_t scene;
    struct {
        unsigned int width;
        unsigned int height;
        int x;
        int y;
    } page;
    struct {
        double x;
        double y;
    } resolution;
    int units;
} Image;

typedef struct _WPG1_PaletteEntry {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
} WPG1_PaletteEntry;

typedef double tCTM[3][3];

#define QuantumRange 65535
#define ScaleCharToQuantum(x) ((unsigned short)((unsigned char)(x)*257))
typedef unsigned short Quantum;

#define CorruptImageError 1
#define CoderError 2
#define ResourceLimitError 3
#define ThrowReaderException(code,message) return((Image *) NULL)

#define EOF (-1)
#define SEEK_SET 0
#define ReadBinaryBlobMode 0
#define PixelsPerCentimeterResolution 1

typedef ptrdiff_t ssize_t;

static Image *DestroyImageList(Image *);
static Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static MagickOffsetType TellBlob(Image *);
static MagickBooleanType EOFBlob(Image *);
static MagickBooleanType SeekBlob(Image *, MagickOffsetType, int);
static unsigned int ReadBlobLSBLong(Image *);
static unsigned short ReadBlobLSBShort(Image *);
static int ReadBlobByte(Image *);
static MagickBooleanType ReadBlob(Image *, size_t, unsigned char *);
static void Rd_WP_DWORD(Image *, size_t *);
static MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
static Image *ExtractPostscript(Image *, const ImageInfo *, MagickOffsetType, ssize_t, ExceptionInfo *);
static int UnpackWPGRaster(Image *, int, ExceptionInfo *);
static int UnpackWPG2Raster(Image *, int, ExceptionInfo *);
static Image *FlopImage(Image *, ExceptionInfo *);
static Image *FlipImage(Image *, ExceptionInfo *);
static Image *RotateImage(Image *, double, ExceptionInfo *);
static void DuplicateBlob(Image *, const Image *);
static void RemoveLastImageFromList(Image **);
static void AppendImageToList(Image **, Image *);
static void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
static Image *SyncNextImageInList(Image *);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
static MagickBooleanType CloseBlob(Image *);
static void DeleteImageFromList(Image **);
static void InsertRow(Image *, unsigned char *, ssize_t, int, ExceptionInfo *);
static int LoadWPG2Flags(Image *, unsigned char, void *, double (*)[3]);
static void *ResizeQuantumMemory(void *, size_t, size_t);
static void *AcquireQuantumMemory(size_t, size_t);
static void *RelinquishMagickMemory(void *);

static WPG1_PaletteEntry WPG1_Palette[256] = {0};