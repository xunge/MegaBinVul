#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  LSBEndian,
  MSBEndian
} EndianType;

typedef enum {
  GrayQuantum
} QuantumType;

typedef enum {
  FloatingPointQuantumFormat,
  UnsignedQuantumFormat,
  SignedQuantumFormat
} QuantumFormatType;

typedef struct _Image {
  size_t columns;
  size_t rows;
  unsigned int depth;
  char *filename;
  void *blob;
  void *previous;
  unsigned int scene;
  unsigned int colors;
  struct {
    int x;
    int y;
  } page;
} Image;

typedef struct _ImageInfo {
  MagickBooleanType ping;
  unsigned int number_scenes;
  unsigned int scene;
} ImageInfo;

typedef struct _ExceptionInfo {
  int dummy;
} ExceptionInfo;

typedef struct _QuantumInfo {
  int dummy;
} QuantumInfo;

typedef struct _CacheView {
  int dummy;
} CacheView;

typedef unsigned char Quantum;

typedef long MagickOffsetType;

#define ReferenceBlob(blob) ((void *)blob)
#define DestroyBlob(image) (void)(image)
#define DestroyImageList(image) ((Image *)NULL)
#define GetFirstImageInList(image) ((Image *)NULL)
#define GetNextImageInList(image) ((Image *)NULL)
#define SyncNextImageInList(image) ((Image *)NULL)
#define AppendImageToList(list,image) (void)0
#define DeleteImageFromList(list) (void)0
#define AcquireNextImage(info,image,exception) (void)0
#define ThrowFileException(exception,error,reason,filename) (void)0
#define SetImageExtent(image,width,height,exception) MagickFalse
#define SetImageBackgroundColor(image,exception) (void)0
#define SetImageColorspace(image,colorspace,exception) (void)0
#define AcquireQuantumInfo(info,image) ((QuantumInfo *)NULL)
#define DestroyQuantumInfo(info) ((QuantumInfo *)NULL)
#define SetQuantumFormat(image,info,format) MagickFalse
#define SetQuantumDepth(image,info,depth) MagickFalse
#define SetQuantumEndian(image,info,endian) MagickFalse
#define SetQuantumScale(info,scale) (void)0
#define GetQuantumPixels(info) ((unsigned char *)NULL)
#define QueueAuthenticPixels(image,x,y,width,height,exception) ((Quantum *)NULL)
#define ImportQuantumPixels(image,view,info,quantum,pixels,exception) (void)0
#define SyncAuthenticPixels(image,exception) MagickFalse
#define SetImageProgress(image,tag,offset,span) MagickFalse
#define RotateImage(image,degrees,exception) ((Image *)NULL)
#define CloseBlob(image) (void)0
#define TellBlob(image) (0L)
#define GetBlobSize(image) (0L)
#define SeekBlob(image,offset,whence) (0)
#define ReadBlobLSBLong(image) (0U)
#define ReadBlobMSBLong(image) (0U)
#define ReadBlobByte(image) (EOF)
#define ReadBlob(image,count,buffer) (0)
#define EOFBlob(image) (MagickFalse)
#define Swap(a,b) { size_t tmp = a; a = b; b = tmp; }

static void FixSignedValues(Image *image, Quantum *q, int columns) {}

#define magick_restrict __restrict__

static void InsertComplexDoubleRow(Image *image, double *pixels, ssize_t y, int x1, int x2, ExceptionInfo *exception) {}
static void InsertComplexFloatRow(Image *image, float *pixels, ssize_t y, int x1, int x2, ExceptionInfo *exception) {}