#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef long long MagickOffsetType;

typedef struct _Image {
    unsigned int signature;
    int endian;
    unsigned int depth;
    size_t columns;
    size_t rows;
    unsigned int colors;
    unsigned int type;
    struct _Image *next;
    struct _Image *previous;
    struct _BlobInfo *blob;
    struct {
        int x;
        int y;
    } page;
    ssize_t scene;
} Image;

typedef struct _ImageInfo {
    unsigned int signature;
    int endian;
    int ping;
    FILE *file;
    char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned int signature;
} ExceptionInfo;

typedef unsigned char Quantum;

typedef struct _QuantumInfo {
    double minimum;
    double maximum;
} QuantumInfo;

typedef struct _BlobInfo {
    // blob info fields
} BlobInfo;

typedef struct _CacheView {
    // cache view fields
} CacheView;

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

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define LSBEndian 0
#define MSBEndian 1
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
#define CoderEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define CoderError 0
#define GrayscaleType 0
#define GRAYColorspace 0
#define BilevelType 0
#define ReadBinaryBlobMode 0
#define SEEK_SET 0
#define SEEK_CUR 1

enum {
    z2qtype_red = 0,
    z2qtype_green = 1,
    z2qtype_blue = 2
};

static int z2qtype[] = {z2qtype_red, z2qtype_green, z2qtype_blue};

#define DisableMSCWarning(n)
#define RestoreMSCWarning

static unsigned int ReadBlobLSBLong(Image *image) { return 0; }
static unsigned short ReadBlobLSBShort(Image *image) { return 0; }
static unsigned int ReadBlobMSBLong(Image *image) { return 0; }
static unsigned short ReadBlobMSBShort(Image *image) { return 0; }
static void ReadBlobDoublesLSB(Image *image, size_t len, double *data) {}
static void ReadBlobDoublesMSB(Image *image, size_t len, double *data) {}
static void ReadBlobFloatsLSB(Image *image, size_t len, float *data) {}
static void ReadBlobFloatsMSB(Image *image, size_t len, float *data) {}
static Image *ReadMATImageV4(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) { return NULL; }
static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception) { return NULL; }
static unsigned int OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception) { return 0; }
static Image *DestroyImageList(Image *image) { return NULL; }
static void ThrowReaderException(int code, const char *reason) {}
static ImageInfo *CloneImageInfo(const ImageInfo *image_info) { return NULL; }
static int LogMagickEvent(int event, const char *module, const char *format, ...) { return 0; }
static const char *GetMagickModule(void) { return ""; }
static MagickOffsetType TellBlob(Image *image) { return 0; }
static int EOFBlob(Image *image) { return 0; }
static int SeekBlob(Image *image, MagickOffsetType offset, int whence) { return 0; }
static Image *DecompressBlock(Image *image, unsigned int size, ImageInfo *info, ExceptionInfo *exception) { return NULL; }
static QuantumInfo *AcquireQuantumInfo(const ImageInfo *image_info, Image *image) { return NULL; }
static int SetImageOption(ImageInfo *image_info, const char *option, const char *value) { return 0; }
static int SetImageExtent(Image *image, size_t columns, size_t rows, ExceptionInfo *exception) { return 0; }
static void *AcquireQuantumMemory(size_t count, size_t size) { return NULL; }
static void CalcMinMax(Image *image, int endian, unsigned int size_x, unsigned int size_y, size_t cell_type, ssize_t ldblk, unsigned char *buffer, double *min, double *max) {}
static Quantum *GetAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception) { return NULL; }
static int ImportQuantumPixels(Image *image, CacheView *view, QuantumInfo *quantum_info, int type, unsigned char *pixels, ExceptionInfo *exception) { return 0; }
static void FixLogical(unsigned char *buffer, ssize_t length) {}
static void FixSignedValues(Image *image, Quantum *quantum, size_t length) {}
static int SyncAuthenticPixels(Image *image, ExceptionInfo *exception) { return 0; }
static QuantumInfo *DestroyQuantumInfo(QuantumInfo *quantum_info) { return NULL; }
static void InsertComplexDoubleRow(Image *image, double *row, int y, double min, double max, ExceptionInfo *exception) {}
static void InsertComplexFloatRow(Image *image, float *row, int y, double min, double max, ExceptionInfo *exception) {}
static Image *RotateImage(Image *image, double degrees, ExceptionInfo *exception) { return NULL; }
static void AppendImageToList(Image **list, Image *image) {}
static void DeleteImageFromList(Image **list) {}
static int remove_utf8(const char *filename) { return 0; }
static void AcquireNextImage(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) {}
static Image *SyncNextImageInList(Image *image) { return NULL; }
static void *RelinquishMagickMemory(void *memory) { return NULL; }
static void CloseBlob(Image *image) {}
static ImageInfo *DestroyImageInfo(ImageInfo *image_info) { return NULL; }
static int ReadBlob(Image *image, size_t length, unsigned char *buffer) { return 0; }
static void SetImageColorspace(Image *image, int colorspace, ExceptionInfo *exception) {}