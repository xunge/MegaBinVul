#include <assert.h>
#include <string.h>
#include <unistd.h>

typedef long ssize_t;
typedef unsigned short Quantum;
typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef struct _PixelInfo {
    Quantum red;
    Quantum green;
    Quantum blue;
} PixelInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    size_t colors;
    unsigned depth;
    struct _Image *previous;
    struct _Image *next;
    size_t scene;
    struct {
        unsigned width;
        unsigned height;
        int x;
        int y;
    } page;
    struct {
        double x;
        double y;
    } resolution;
    unsigned units;
    PixelInfo *colormap;
} Image;

typedef struct _ImageInfo {
    unsigned signature;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned signature;
} ExceptionInfo;

typedef struct {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
} WPG1_PaletteEntry;

static const WPG1_PaletteEntry WPG1_Palette[256];

typedef float float_matrix[3][3];
typedef float_matrix tCTM;

typedef long MagickOffsetType;
typedef unsigned int MagickSizeType;

#define MagickCoreSignature 0xABACADABUL
#define QuantumRange 65535
#define ScaleCharToQuantum(x) ((Quantum)((x)*257UL))

#define CorruptImageError 1
#define CoderError 2
#define ResourceLimitError 3

#define ThrowReaderException(code,message) return((Image *) NULL)
#define EOF (-1)
#define SEEK_SET 0

#define PixelsPerCentimeterResolution 1
#define ReadBinaryBlobMode 0

MagickBooleanType AcquireImageColormap(Image *image,const size_t length,
  ExceptionInfo *exception);
Image *AcquireImage(const ImageInfo *image_info,ExceptionInfo *exception);
MagickBooleanType OpenBlob(const ImageInfo *image_info,Image *image,
  const int mode,ExceptionInfo *exception);
Image *DestroyImageList(Image *image);
unsigned int ReadBlobLSBLong(Image *image);
unsigned short ReadBlobLSBShort(Image *image);
unsigned char ReadBlobByte(Image *image);
MagickOffsetType TellBlob(Image *image);
MagickBooleanType SeekBlob(Image *image,const MagickOffsetType offset,
  const int whence);
MagickBooleanType EOFBlob(Image *image);
void Rd_WP_DWORD(Image *image,size_t *value);
MagickBooleanType SetImageExtent(Image *image,const size_t columns,
  const size_t rows,ExceptionInfo *exception);
int UnpackWPGRaster(Image *image,int bpp,ExceptionInfo *exception);
int UnpackWPG2Raster(Image *image,int bpp,ExceptionInfo *exception);
Image *ExtractPostscript(Image *image,const ImageInfo *image_info,
  const MagickOffsetType offset,const ssize_t length,ExceptionInfo *exception);
Image *FlopImage(Image *image,ExceptionInfo *exception);
Image *FlipImage(Image *image,ExceptionInfo *exception);
Image *RotateImage(Image *image,const double degrees,ExceptionInfo *exception);
void DuplicateBlob(Image *clone,const Image *image);
void ReplaceImageInList(Image **images,Image *replace_image);
MagickBooleanType AcquireNextImage(const ImageInfo *image_info,Image *image,
  ExceptionInfo *exception);
Image *SyncNextImageInList(Image *image);
void InsertRow(Image *image,const unsigned char *pixels,const ssize_t row,
  const int bpp,ExceptionInfo *exception);
MagickBooleanType CloseBlob(Image *image);
void DeleteImageFromList(Image **image);
int LoadWPG2Flags(Image *image,unsigned char precision,MagickSizeType *flags,
  tCTM *CTM);
ssize_t ReadBlob(Image *image,const size_t length,unsigned char *buffer);

void *AcquireQuantumMemory(const size_t count,const size_t quantum);
void *ResizeQuantumMemory(void *memory,const size_t count,const size_t quantum);
void *RelinquishMagickMemory(void *memory);