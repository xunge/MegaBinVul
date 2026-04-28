#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct _CacheView CacheView;

typedef struct _Image {
    unsigned long signature;
    int endian;
    unsigned depth;
    unsigned columns;
    unsigned rows;
    unsigned colors;
    unsigned type;
    struct _BlobInfo *blob;
    struct _Image *next;
    struct _Image *previous;
    struct _ExceptionInfo *exception;
    struct {
        int x;
        int y;
    } page;
    ssize_t scene;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    int ping;
    int endian;
    FILE *file;
    char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
    struct _ExceptionInfo *exception;
} ExceptionInfo;

typedef struct _QuantumInfo {
    double minimum;
    double maximum;
} QuantumInfo;

typedef struct _BlobInfo {
    void *data;
} BlobInfo;

typedef struct _PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} PixelPacket;

typedef struct _MATHeader {
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

#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define LSBEndian 0
#define MSBEndian 1
#define ReadBinaryBlobMode 0
#define CorruptImageError 1
#define ResourceLimitError 2
#define CoderError 3
#define miCOMPRESSED 15
#define miMATRIX 14
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
#define FLAG_LOGICAL 0x0200
#define FLAG_COMPLEX 0x0800
#define GRAYColorspace 1
#define GrayscaleType 1
#define BilevelType 2
#define CoderEvent 1

typedef size_t MagickSizeType;
typedef long long MagickOffsetType;
typedef unsigned char MagickBooleanType;

static unsigned int ReadBlobLSBLong(Image *image) { return 0; }
static unsigned short ReadBlobLSBShort(Image *image) { return 0; }
static unsigned int ReadBlobMSBLong(Image *image) { return 0; }
static unsigned short ReadBlobMSBShort(Image *image) { return 0; }
static void ReadBlobDoublesLSB(Image *image, size_t len, double *data) {}
static void ReadBlobDoublesMSB(Image *image, size_t len, double *data) {}
static void ReadBlobFloatsLSB(Image *image, size_t len, float *data) {}
static void ReadBlobFloatsMSB(Image *image, size_t len, float *data) {}

static Image *ReadMATImageV4(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) { return NULL; }
static void FixLogical(unsigned char *data, ssize_t len) {}
static void FixSignedValues(PixelPacket *q, unsigned int size) {}
static void CalcMinMax(Image *image, int endian, unsigned int sizeX, unsigned int sizeY, size_t cellType, ssize_t ldblk, unsigned char *bImgBuff, double *min, double *max) {}
static void InsertComplexDoubleRow(double *data, int row, Image *image, double minVal, double maxVal) {}
static void InsertComplexFloatRow(float *data, int row, Image *image, float minVal, float maxVal) {}

static int LogMagickEvent(int event, const char *module, const char *format, ...) { return 0; }
static const char *GetMagickModule() { return ""; }
static void ThrowReaderException(int error, const char *reason) {}
static Image *AcquireImage(const ImageInfo *image_info) { return NULL; }
static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception) { return MagickFalse; }
static Image *DestroyImageList(Image *image) { return NULL; }
static size_t ReadBlob(Image *image, size_t length, unsigned char *data) { return 0; }
static MagickOffsetType TellBlob(Image *image) { return 0; }
static int EOFBlob(Image *image) { return 1; }
static int SeekBlob(Image *image, MagickOffsetType offset, int whence) { return 0; }
static MagickSizeType GetBlobSize(Image *image) { return 0; }
static ImageInfo *CloneImageInfo(const ImageInfo *image_info) { return NULL; }
static ImageInfo *DestroyImageInfo(ImageInfo *image_info) { return NULL; }
static void SetImageOption(ImageInfo *image_info, const char *option, const char *value) {}
static void SetImageColorspace(Image *image, int colorspace) {}
static MagickBooleanType SetImageExtent(Image *image, unsigned columns, unsigned rows) { return MagickFalse; }
static void InheritException(ExceptionInfo *exception, ExceptionInfo *image_exception) {}
static QuantumInfo *AcquireQuantumInfo(const ImageInfo *image_info, Image *image) { return NULL; }
static QuantumInfo *DestroyQuantumInfo(QuantumInfo *quantum_info) { return NULL; }
static void *AcquireQuantumMemory(size_t count, size_t quantum) { return NULL; }
static void ResetMagickMemory(void *target, int c, size_t length) {}
static PixelPacket *GetAuthenticPixels(Image *image, long x, long y, unsigned columns, unsigned rows, ExceptionInfo *exception) { return NULL; }
static int ImportQuantumPixels(Image *image, CacheView *cache_view, QuantumInfo *quantum_info, int storage_type, unsigned char *pixels, ExceptionInfo *exception) { return 0; }
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception) { return MagickFalse; }
static void AppendImageToList(Image **images, Image *image) {}
static void DeleteImageFromList(Image **images) {}
static void AcquireNextImage(const ImageInfo *image_info, Image *image) {}
static Image *SyncNextImageInList(Image *image) { return NULL; }
static void RelinquishMagickMemory(void *memory) {}
static void CloseBlob(Image *image) {}
static Image *RotateImage(Image *image, double degrees, ExceptionInfo *exception) { return NULL; }
static int remove_utf8(const char *filename) { return unlink(filename); }

#define DisableMSCWarning(n)
#define RestoreMSCWarning

static const int z2qtype[] = {0, 1, 2};