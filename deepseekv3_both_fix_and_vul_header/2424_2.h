#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef long long MagickOffsetType;
typedef unsigned int MagickBooleanType;
#define MagickFalse 0
#define MagickCoreSignature 0xabacadabUL
#define QuantumRange 65535
#define CorruptImageError 1
#define CoderError 2
#define ResourceLimitError 3
#define PixelsPerCentimeterResolution 1
#define ReadBinaryBlobMode 0
#define EOF (-1)
#define SEEK_SET 0

typedef long ssize_t;

typedef struct _PixelInfo {
    double red;
    double green;
    double blue;
} PixelInfo;

typedef struct {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
} WPG1_PaletteEntry;
static WPG1_PaletteEntry WPG1_Palette[256];

typedef double tCTM[3][3];

typedef struct _Image {
    size_t columns;
    size_t rows;
    size_t colors;
    unsigned depth;
    struct {
        double x;
        double y;
    } resolution;
    struct {
        unsigned int width;
        unsigned int height;
        int x;
        int y;
    } page;
    PixelInfo *colormap;
    unsigned units;
    struct _Image *previous;
    struct _Image *next;
    size_t scene;
} Image;

typedef struct _ImageInfo {
    unsigned signature;
    int ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned signature;
} ExceptionInfo;

static unsigned char ScaleCharToQuantum(unsigned char value) {
    return value;
}

static Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static unsigned long ReadBlobLSBLong(Image *);
static unsigned short ReadBlobLSBShort(Image *);
static int ReadBlobByte(Image *);
static void ThrowReaderException(int, const char *);
static void Rd_WP_DWORD(Image *, size_t *);
static int EOFBlob(Image *);
static MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
static MagickOffsetType TellBlob(Image *);
static MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
static Image *ExtractPostscript(Image *, const ImageInfo *, MagickOffsetType, ssize_t, ExceptionInfo *);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
static int UnpackWPGRaster(Image *, int, ExceptionInfo *);
static Image *FlopImage(Image *, ExceptionInfo *);
static void DuplicateBlob(Image *, Image *);
static void ReplaceImageInList(Image **, Image *);
static Image *FlipImage(Image *, ExceptionInfo *);
static Image *RotateImage(Image *, double, ExceptionInfo *);
static void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
static Image *SyncNextImageInList(Image *);
static void *ResizeQuantumMemory(void *, size_t, size_t);
static unsigned char *AcquireQuantumMemory(size_t, size_t);
static void *RelinquishMagickMemory(void *);
static int UnpackWPG2Raster(Image *, int, ExceptionInfo *);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static void InsertRow(Image *, unsigned char *, ssize_t, int, ExceptionInfo *);
static int LoadWPG2Flags(Image *, unsigned char, void *, tCTM);
static MagickBooleanType CloseBlob(Image *);
static void DeleteImageFromList(Image **);