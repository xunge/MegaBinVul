#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef long ssize_t;
typedef long MagickOffsetType;
typedef unsigned int MagickBooleanType;
typedef size_t MagickSizeType;
#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define QuantumRange 65535
#define CorruptImageError 410
#define CoderError 404 
#define ResourceLimitError 420
#define PixelsPerCentimeterResolution 1
#define ReadBinaryBlobMode 0
#define SEEK_SET 0

typedef struct _PixelPacket {
    double red;
    double green;
    double blue;
} PixelPacket;

typedef struct _Image {
    size_t columns;
    size_t rows;
    size_t colors;
    size_t depth;
    double x_resolution;
    double y_resolution;
    unsigned int units;
    struct {
        unsigned int width;
        unsigned int height;
        int x;
        int y;
    } page;
    PixelPacket *colormap;
    struct _Image *previous;
    struct _Image *next;
    size_t scene;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef double tCTM[3][3];

typedef struct {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
} WPG1_PaletteEntry;
extern WPG1_PaletteEntry WPG1_Palette[256];

MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
Image *AcquireImage(const ImageInfo *);
MagickOffsetType TellBlob(const Image *);
MagickBooleanType SeekBlob(Image *, MagickOffsetType, int);
MagickBooleanType EOFBlob(const Image *);
MagickSizeType GetBlobSize(const Image *);
unsigned int ReadBlobLSBLong(Image *);
unsigned short ReadBlobLSBShort(Image *);
unsigned char ReadBlobByte(Image *);
size_t ReadBlob(Image *, size_t, unsigned char *);
void Rd_WP_DWORD(Image *, size_t *);
void ThrowReaderException(unsigned int, const char *);
MagickBooleanType AcquireImageColormap(Image *, unsigned long);
unsigned char ScaleCharToQuantum(unsigned char);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
int UnpackWPGRaster(Image *, int);
int UnpackWPG2Raster(Image *, int);
Image *ExtractPostscript(Image *, const ImageInfo *, MagickOffsetType, ssize_t, ExceptionInfo *);
Image *FlopImage(Image *, ExceptionInfo *);
Image *FlipImage(Image *, ExceptionInfo *);
Image *RotateImage(Image *, double, ExceptionInfo *);
void DuplicateBlob(Image *, const Image *);
void ReplaceImageInList(Image **, Image *);
void AcquireNextImage(const ImageInfo *, Image *);
Image *SyncNextImageInList(Image *);
void InsertRow(unsigned char *, ssize_t, Image *, int);
void *AcquireQuantumMemory(size_t, size_t);
void *ResizeQuantumMemory(void *, size_t, size_t);
void *RelinquishMagickMemory(void *);
int LoadWPG2Flags(Image *, unsigned char, tCTM *, double (*)[3]);
MagickBooleanType CloseBlob(Image *);
void DeleteImageFromList(Image **);