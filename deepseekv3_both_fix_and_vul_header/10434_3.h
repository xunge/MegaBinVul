#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct _Image {
    unsigned int signature;
    int endian;
    unsigned int columns;
    unsigned int rows;
    unsigned int depth;
    unsigned int colors;
    unsigned int type;
    struct _BlobInfo *blob;
    struct _Image *next;
    struct _Image *previous;
    struct _ExceptionInfo *exception;
    struct {
        int x;
        int y;
    } page;
    unsigned int scene;
} Image;

typedef struct _ImageInfo {
    unsigned int signature;
    int ping;
    FILE *file;
    char *filename;
    int endian;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned int signature;
    struct _ExceptionInfo *exception;
} ExceptionInfo;

typedef struct _QuantumInfo {
    double minimum;
    double maximum;
} QuantumInfo;

typedef struct _BlobInfo {
    // blob info fields
} BlobInfo;

typedef struct _PixelPacket {
    // pixel packet fields
} PixelPacket;

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
    unsigned int unknown5;
    unsigned char StructureClass;
    unsigned char StructureFlag;
    unsigned int unknown3;
    unsigned int unknown4;
    unsigned int DimFlag;
    unsigned int SizeX;
    unsigned int SizeY;
    unsigned short Flag1;
    unsigned short NameFlag;
} MATHeader;

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef long long MagickOffsetType;
typedef unsigned int MagickSizeType;
typedef unsigned int Quantum;
typedef unsigned int MagickStatusType;
typedef unsigned int MagickSignatureType;

#define MagickSignature 0xabacadabUL
#define LSBEndian 0
#define MSBEndian 1
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define CoderError 0
#define CoderEvent 0
#define GetMagickModule() ""
#define LogMagickEvent(a,b,c,...) 0

// MATLAB constants
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

#define FLAG_LOGICAL 0x0200
#define FLAG_COMPLEX 0x0800

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

#define GRAYColorspace 1
#define GrayscaleType 1
#define BilevelType 2

// z2qtype array
static const int z2qtype[] = {0, 1, 2};

// Dummy implementations for required functions
static void ThrowReaderException(int code, const char *message) {
    (void)code;
    (void)message;
    abort();
}

static void InheritException(ExceptionInfo *dst, ExceptionInfo *src) {
    (void)dst;
    (void)src;
}

static unsigned int ReadBlobLSBLong(Image *image) {
    (void)image;
    return 0;
}

static unsigned short ReadBlobLSBShort(Image *image) {
    (void)image;
    return 0;
}

static unsigned int ReadBlobMSBLong(Image *image) {
    (void)image;
    return 0;
}

static unsigned short ReadBlobMSBShort(Image *image) {
    (void)image;
    return 0;
}

static void ReadBlobDoublesLSB(Image *image, size_t len, double *data) {
    (void)image;
    (void)len;
    (void)data;
}

static void ReadBlobDoublesMSB(Image *image, size_t len, double *data) {
    (void)image;
    (void)len;
    (void)data;
}

static void ReadBlobFloatsLSB(Image *image, size_t len, float *data) {
    (void)image;
    (void)len;
    (void)data;
}

static void ReadBlobFloatsMSB(Image *image, size_t len, float *data) {
    (void)image;
    (void)len;
    (void)data;
}

static Image *AcquireImage(const ImageInfo *image_info) {
    (void)image_info;
    return NULL;
}

static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception) {
    (void)image_info;
    (void)image;
    (void)mode;
    (void)exception;
    return MagickFalse;
}

static Image *DestroyImageList(Image *image) {
    (void)image;
    return NULL;
}

static ImageInfo *CloneImageInfo(const ImageInfo *image_info) {
    (void)image_info;
    return NULL;
}

static ssize_t ReadBlob(Image *image, size_t count, unsigned char *data) {
    (void)image;
    (void)count;
    (void)data;
    return 0;
}

static MagickOffsetType TellBlob(Image *image) {
    (void)image;
    return 0;
}

static int EOFBlob(Image *image) {
    (void)image;
    return 1;
}

static int SeekBlob(Image *image, MagickOffsetType offset, int whence) {
    (void)image;
    (void)offset;
    (void)whence;
    return 0;
}

static Image *DecompressBlock(Image *image, size_t size, ImageInfo *clone_info, ExceptionInfo *exception) {
    (void)image;
    (void)size;
    (void)clone_info;
    (void)exception;
    return NULL;
}

static void SetImageOption(ImageInfo *image_info, const char *option, const char *value) {
    (void)image_info;
    (void)option;
    (void)value;
}

static QuantumInfo *AcquireQuantumInfo(const ImageInfo *image_info, Image *image) {
    (void)image_info;
    (void)image;
    return NULL;
}

static void SetImageColorspace(Image *image, int colorspace) {
    (void)image;
    (void)colorspace;
}

static MagickBooleanType SetImageExtent(Image *image, unsigned int columns, unsigned int rows) {
    (void)image;
    (void)columns;
    (void)rows;
    return MagickFalse;
}

static void *AcquireQuantumMemory(size_t count, size_t size) {
    (void)count;
    (void)size;
    return NULL;
}

static void ResetMagickMemory(void *memory, int c, size_t size) {
    (void)memory;
    (void)c;
    (void)size;
}

static void CalcMinMax(Image *image, int endian, unsigned int size_x, unsigned int size_y, size_t cell_type, ssize_t ldblk, unsigned char *buffer, double *min, double *max) {
    (void)image;
    (void)endian;
    (void)size_x;
    (void)size_y;
    (void)cell_type;
    (void)ldblk;
    (void)buffer;
    (void)min;
    (void)max;
}

static PixelPacket *GetAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception) {
    (void)image;
    (void)x;
    (void)y;
    (void)columns;
    (void)rows;
    (void)exception;
    return NULL;
}

static int ImportQuantumPixels(Image *image, CacheView *view, QuantumInfo *quantum_info, int storage_type, unsigned char *pixels, ExceptionInfo *exception) {
    (void)image;
    (void)view;
    (void)quantum_info;
    (void)storage_type;
    (void)pixels;
    (void)exception;
    return 0;
}

static void FixLogical(unsigned char *buffer, ssize_t length) {
    (void)buffer;
    (void)length;
}

static void FixSignedValues(PixelPacket *pixels, unsigned int count) {
    (void)pixels;
    (void)count;
}

static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception) {
    (void)image;
    (void)exception;
    return MagickFalse;
}

static QuantumInfo *DestroyQuantumInfo(QuantumInfo *quantum_info) {
    (void)quantum_info;
    return NULL;
}

static void InsertComplexDoubleRow(double *buffer, int row, Image *image, double min, double max) {
    (void)buffer;
    (void)row;
    (void)image;
    (void)min;
    (void)max;
}

static void InsertComplexFloatRow(float *buffer, int row, Image *image, double min, double max) {
    (void)buffer;
    (void)row;
    (void)image;
    (void)min;
    (void)max;
}

static Image *RotateImage(Image *image, double degrees, ExceptionInfo *exception) {
    (void)image;
    (void)degrees;
    (void)exception;
    return NULL;
}

static void AppendImageToList(Image **list, Image *image) {
    (void)list;
    (void)image;
}

static void DeleteImageFromList(Image **list) {
    (void)list;
}

static void AcquireNextImage(const ImageInfo *image_info, Image *image) {
    (void)image_info;
    (void)image;
}

static Image *SyncNextImageInList(Image *image) {
    (void)image;
    return NULL;
}

static void RelinquishMagickMemory(void *memory) {
    (void)memory;
}

static void CloseBlob(Image *image) {
    (void)image;
}

static ImageInfo *DestroyImageInfo(ImageInfo *image_info) {
    (void)image_info;
    return NULL;
}

static int remove_utf8(const char *filename) {
    (void)filename;
    return 0;
}

static Image *ReadMATImageV4(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) {
    (void)image_info;
    (void)image;
    (void)exception;
    return NULL;
}

#define DisableMSCWarning(n)
#define RestoreMSCWarning