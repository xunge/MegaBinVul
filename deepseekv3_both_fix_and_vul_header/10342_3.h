#include <assert.h>
#include <string.h>
#include <stdio.h>

#define MagickCoreSignature 0xABACADABUL
#define QuantumRange 65535
#define EOF (-1)
#define SEEK_SET 0

typedef long long MagickOffsetType;
typedef long ssize_t;
typedef unsigned long size_t;
typedef unsigned int Quantum;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
  CorruptImageError,
  CoderError,
  ResourceLimitError
} ExceptionType;

typedef struct {
  double x;
  double y;
} PointInfo;

typedef struct {
  unsigned int width;
  unsigned int height;
  int x;
  int y;
} RectangleInfo;

typedef struct _PixelInfo {
  double red;
  double green;
  double blue;
} PixelInfo;

typedef struct _ImageInfo {
  unsigned long signature;
  int ping;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
  unsigned long signature;
  size_t columns;
  size_t rows;
  size_t colors;
  size_t depth;
  size_t scene;
  struct _Image *previous;
  struct _Image *next;
  ResolutionType units;
  PointInfo resolution;
  RectangleInfo page;
  PixelInfo *colormap;
} Image;

typedef struct {
  unsigned char Red;
  unsigned char Green;
  unsigned char Blue;
} WPG1_PaletteEntry;

static const WPG1_PaletteEntry WPG1_Palette[256];

typedef double tCTM[3][3];

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned int ReadBlobLSBLong(Image *);
unsigned short ReadBlobLSBShort(Image *);
unsigned char ReadBlobByte(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
MagickOffsetType TellBlob(Image *);
void Rd_WP_DWORD(Image *, size_t *);
void SeekBlob(Image *, MagickOffsetType, int);
MagickBooleanType EOFBlob(const Image *);
void ThrowReaderException(ExceptionType, const char *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
unsigned char ScaleCharToQuantum(unsigned char);
PixelInfo *ResizeQuantumMemory(PixelInfo *, size_t, size_t);
int UnpackWPGRaster(Image *, int, ExceptionInfo *);
Image *ExtractPostscript(Image *, const ImageInfo *, MagickOffsetType, ssize_t, ExceptionInfo *);
Image *FlopImage(Image *, ExceptionInfo *);
void RemoveLastImageFromList(Image **);
void AppendImageToList(Image **, Image *);
Image *FlipImage(Image *, ExceptionInfo *);
Image *RotateImage(Image *, double, ExceptionInfo *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *SyncNextImageInList(Image *);
int UnpackWPG2Raster(Image *, int, ExceptionInfo *);
int LoadWPG2Flags(Image *, unsigned char, RectangleInfo *, tCTM);
void InsertRow(Image *, unsigned char *, ssize_t, int, ExceptionInfo *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void CloseBlob(Image *);
void DeleteImageFromList(Image **);
void DuplicateBlob(Image *, const Image *);
unsigned char *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);