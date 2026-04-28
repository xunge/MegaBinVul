#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _QuantumInfo QuantumInfo;
typedef struct _BlobInfo BlobInfo;
typedef struct _PixelPacket PixelPacket;
typedef struct _CacheView CacheView;

typedef int64_t MagickOffsetType;
typedef size_t MagickSizeType;
typedef int MagickBooleanType;

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

typedef enum {
  MagickFalse,
  MagickTrue
} MagickStatusType;

typedef enum {
  LSBEndian,
  MSBEndian
} EndianType;

typedef enum {
  miCOMPRESSED,
  miMATRIX,
  miINT8,
  miUINT8,
  miINT16,
  miUINT16,
  miINT32,
  miUINT32,
  miINT64,
  miUINT64,
  miSINGLE,
  miDOUBLE
} DataType;

typedef enum {
  mxCHAR_CLASS,
  mxSINGLE_CLASS,
  mxDOUBLE_CLASS,
  mxINT8_CLASS,
  mxUINT8_CLASS,
  mxINT16_CLASS,
  mxUINT16_CLASS,
  mxINT32_CLASS,
  mxUINT32_CLASS,
  mxINT64_CLASS,
  mxUINT64_CLASS
} StructureClass;

typedef enum {
  GRAYColorspace,
  RGBColorspace
} ColorspaceType;

typedef enum {
  GrayscaleType,
  BilevelType,
  TrueColorType
} ImageType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  CoderEvent
} LogEventType;

typedef enum {
  CorruptImageError,
  ResourceLimitError,
  CoderError
} ExceptionType;

#define FLAG_LOGICAL 0x01
#define FLAG_COMPLEX 0x02
#define MagickSignature 0xABACADABUL

struct _ImageInfo {
  unsigned long signature;
  int ping;
  EndianType endian;
  FILE *file;
  char *filename;
};

struct _ExceptionInfo {
  unsigned long signature;
  Image *exception;
};

struct _Image {
  unsigned long signature;
  EndianType endian;
  size_t columns;
  size_t rows;
  size_t depth;
  size_t colors;
  ImageType type;
  BlobInfo *blob;
  Image *next;
  Image *previous;
  ExceptionInfo exception;
  struct _Image *scene;
  struct {
    int x;
    int y;
  } page;
};

struct _QuantumInfo {
  double minimum;
  double maximum;
};

typedef struct {
  char identific[124];
  unsigned short Version;
  char EndianIndicator[2];
  unsigned int DataType;
  unsigned int ObjectSize;
  unsigned int unknown1;
  unsigned int unknown2;
  unsigned int unknown3;
  unsigned int unknown4;
  unsigned int unknown5;
  unsigned int StructureClass;
  unsigned int StructureFlag;
  unsigned int DimFlag;
  unsigned int SizeX;
  unsigned int SizeY;
  unsigned short Flag1;
  unsigned short NameFlag;
} MATHeader;

unsigned int ReadBlobLSBLong(Image *);
unsigned int ReadBlobMSBLong(Image *);
unsigned short ReadBlobLSBShort(Image *);
unsigned short ReadBlobMSBShort(Image *);
void ReadBlobDoublesLSB(Image *, size_t, double *);
void ReadBlobDoublesMSB(Image *, size_t, double *);
void ReadBlobFloatsLSB(Image *, size_t, float *);
void ReadBlobFloatsMSB(Image *, size_t, float *);
int LogMagickEvent(LogEventType, const char *, const char *, ...);
const char *GetMagickModule(void);
Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
ImageInfo *CloneImageInfo(const ImageInfo *);
size_t ReadBlob(Image *, size_t, unsigned char *);
void ThrowReaderException(ExceptionType, const char *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
void InheritException(ExceptionInfo *, ExceptionInfo *);
unsigned char *AcquireQuantumMemory(size_t, size_t);
void RelinquishMagickMemory(void *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
int ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, int, unsigned char *, ExceptionInfo *);
void FixLogical(unsigned char *, ssize_t);
void FixSignedValues(PixelPacket *, size_t);
void CalcMinMax(Image *, EndianType, size_t, size_t, size_t, ssize_t, unsigned char *, double *, double *);
void InsertComplexDoubleRow(double *, int, Image *, double, double);
void InsertComplexFloatRow(float *, int, Image *, double, double);
Image *RotateImage(Image *, double, ExceptionInfo *);
void AppendImageToList(Image **, Image *);
void DeleteImageFromList(Image **);
MagickBooleanType AcquireNextImage(const ImageInfo *, Image *);
Image *SyncNextImageInList(Image *);
void CloseBlob(Image *);
ImageInfo *DestroyImageInfo(ImageInfo *);
int remove_utf8(const char *);
int unlink(const char *);
Image *ReadMATImageV4(const ImageInfo *, Image *, ExceptionInfo *);
MagickOffsetType TellBlob(Image *);
int EOFBlob(Image *);
int SeekBlob(Image *, MagickOffsetType, int);
int SetImageOption(ImageInfo *, const char *, const char *);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
int SetImageColorspace(Image *, ColorspaceType);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);

static const int z2qtype[] = {0,1,2};
#define DisableMSCWarning(n)
#define RestoreMSCWarning