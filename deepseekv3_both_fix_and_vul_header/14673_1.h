#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char Quantum;
typedef unsigned int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef long MagickOffsetType;
typedef size_t MagickSizeType;

#define ReadBinaryBlobMode 0
#define MagickCoreSignature 0xabacadabUL
#define CoderEvent 0
#define LSBEndian 0
#define MSBEndian 1

#define miCOMPRESSED 15
#define miMATRIX 14
#define miINT8 1
#define miUINT8 2
#define miINT16 3
#define miUINT16 4
#define miINT32 5
#define miUINT32 6
#define miINT64 7
#define miUINT64 8
#define miSINGLE 9
#define miDOUBLE 10

#define mxCHAR_CLASS 4
#define mxSINGLE_CLASS 7
#define mxDOUBLE_CLASS 6
#define mxINT8_CLASS 8
#define mxUINT8_CLASS 9
#define mxINT16_CLASS 10
#define mxUINT16_CLASS 11
#define mxINT32_CLASS 12
#define mxUINT32_CLASS 13
#define mxINT64_CLASS 14
#define mxUINT64_CLASS 15

#define FLAG_COMPLEX 0x0800
#define FLAG_LOGICAL 0x0200

typedef enum {
  UndefinedType,
  BilevelType,
  GrayscaleType,
  GRAYColorspace,
  ResourceLimitError,
  CorruptImageError,
  CoderError
} ImageType;

typedef struct _ImageInfo {
  unsigned long signature;
  int ping;
  int endian;
  FILE *file;
  char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
  unsigned long signature;
  int endian;
  size_t depth;
  size_t columns;
  size_t rows;
  size_t colors;
  ImageType type;
  struct _Image *next;
  struct _Image *previous;
  struct _BlobInfo *blob;
  struct {
    int x;
    int y;
  } page;
  ssize_t scene;
} Image;

typedef struct _QuantumInfo {
  double minimum;
  double maximum;
} QuantumInfo;

typedef struct _BlobInfo {
  void *data;
  size_t length;
  size_t offset;
} BlobInfo;

typedef struct _CacheView {
  Image *image;
  Quantum *pixels;
  ssize_t x;
  ssize_t y;
  size_t columns;
  size_t rows;
} CacheView;

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

static const int z2qtype[] = {0, 1, 2};

#define DisableMSCWarning(n)
#define RestoreMSCWarning

static Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static void ThrowReaderException(ImageType, const char *);
static ImageInfo *CloneImageInfo(const ImageInfo *);
static unsigned short ReadBlobLSBShort(Image *);
static unsigned int ReadBlobLSBLong(Image *);
static unsigned short ReadBlobMSBShort(Image *);
static unsigned int ReadBlobMSBLong(Image *);
static void ReadBlobDoublesLSB(Image *, size_t, double *);
static void ReadBlobDoublesMSB(Image *, size_t, double *);
static void ReadBlobFloatsLSB(Image *, size_t, float *);
static void ReadBlobFloatsMSB(Image *, size_t, float *);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static MagickBooleanType LogMagickEvent(int, const char *, const char *, ...);
static const char *GetMagickModule(void);
static MagickOffsetType TellBlob(Image *);
static MagickBooleanType EOFBlob(Image *);
static MagickBooleanType SeekBlob(Image *, MagickOffsetType, int);
static Image *DecompressBlock(Image *, unsigned int, ImageInfo *, ExceptionInfo *);
static QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
static MagickBooleanType SetImageOption(ImageInfo *, const char *, const char *);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
static unsigned char *AcquireQuantumMemory(size_t, size_t);
static void CalcMinMax(Image *, int, unsigned int, unsigned int, size_t, ssize_t, unsigned char *, double *, double *);
static Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static MagickBooleanType ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, int, const unsigned char *, ExceptionInfo *);
static void FixLogical(unsigned char *, ssize_t);
static void FixSignedValues(Image *, Quantum *, size_t);
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
static void InsertComplexDoubleRow(Image *, double *, ssize_t, double, double, ExceptionInfo *);
static void InsertComplexFloatRow(Image *, float *, ssize_t, double, double, ExceptionInfo *);
static Image *RotateImage(Image *, double, ExceptionInfo *);
static void AppendImageToList(Image **, Image *);
static void DeleteImageFromList(Image **);
static int remove_utf8(const char *);
static void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
static Image *SyncNextImageInList(Image *);
static void RelinquishMagickMemory(void *);
static void CloseBlob(Image *);
static ImageInfo *DestroyImageInfo(ImageInfo *);
static void SetImageColorspace(Image *, int, ExceptionInfo *);
static QuantumInfo *DestroyQuantumInfo(QuantumInfo *);

static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception) { return NULL; }
static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception) { return MagickFalse; }
static Image *DestroyImageList(Image *image) { return NULL; }
static void ThrowReaderException(ImageType type, const char *message) {}
static ImageInfo *CloneImageInfo(const ImageInfo *image_info) { return NULL; }
static unsigned short ReadBlobLSBShort(Image *image) { return 0; }
static unsigned int ReadBlobLSBLong(Image *image) { return 0; }
static unsigned short ReadBlobMSBShort(Image *image) { return 0; }
static unsigned int ReadBlobMSBLong(Image *image) { return 0; }
static void ReadBlobDoublesLSB(Image *image, size_t len, double *data) {}
static void ReadBlobDoublesMSB(Image *image, size_t len, double *data) {}
static void ReadBlobFloatsLSB(Image *image, size_t len, float *data) {}
static void ReadBlobFloatsMSB(Image *image, size_t len, float *data) {}
static ssize_t ReadBlob(Image *image, size_t length, unsigned char *data) { return 0; }
static MagickBooleanType LogMagickEvent(int event, const char *module, const char *format, ...) { return MagickFalse; }
static const char *GetMagickModule(void) { return NULL; }
static MagickOffsetType TellBlob(Image *image) { return 0; }
static MagickBooleanType EOFBlob(Image *image) { return MagickFalse; }
static MagickBooleanType SeekBlob(Image *image, MagickOffsetType offset, int whence) { return MagickFalse; }
static Image *DecompressBlock(Image *image, unsigned int length, ImageInfo *image_info, ExceptionInfo *exception) { return NULL; }
static QuantumInfo *AcquireQuantumInfo(const ImageInfo *image_info, Image *image) { return NULL; }
static MagickBooleanType SetImageOption(ImageInfo *image_info, const char *option, const char *value) { return MagickFalse; }
static MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows, ExceptionInfo *exception) { return MagickFalse; }
static unsigned char *AcquireQuantumMemory(size_t count, size_t quantum) { return NULL; }
static void CalcMinMax(Image *image, int endian, unsigned int size_x, unsigned int size_y, size_t cell_type, ssize_t ldblk, unsigned char *buffer, double *min_val, double *max_val) {}
static Quantum *GetAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception) { return NULL; }
static MagickBooleanType ImportQuantumPixels(Image *image, CacheView *cache_view, QuantumInfo *quantum_info, int quantum_type, const unsigned char *pixels, ExceptionInfo *exception) { return MagickFalse; }
static void FixLogical(unsigned char *buffer, ssize_t length) {}
static void FixSignedValues(Image *image, Quantum *quantum, size_t length) {}
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception) { return MagickFalse; }
static void InsertComplexDoubleRow(Image *image, double *buffer, ssize_t row, double min_val, double max_val, ExceptionInfo *exception) {}
static void InsertComplexFloatRow(Image *image, float *buffer, ssize_t row, double min_val, double max_val, ExceptionInfo *exception) {}
static Image *RotateImage(Image *image, double degrees, ExceptionInfo *exception) { return NULL; }
static void AppendImageToList(Image **list, Image *image) {}
static void DeleteImageFromList(Image **list) {}
static int remove_utf8(const char *filename) { return 0; }
static void AcquireNextImage(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) {}
static Image *SyncNextImageInList(Image *image) { return NULL; }
static void RelinquishMagickMemory(void *memory) {}
static void CloseBlob(Image *image) {}
static ImageInfo *DestroyImageInfo(ImageInfo *image_info) { return NULL; }
static void SetImageColorspace(Image *image, int colorspace, ExceptionInfo *exception) {}
static QuantumInfo *DestroyQuantumInfo(QuantumInfo *quantum_info) { return NULL; }