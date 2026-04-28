#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>  // for ssize_t

typedef unsigned char Quantum;
typedef unsigned int MagickBooleanType;
#define MagickFalse 0
#define MagickCoreSignature 0xabacadabUL

typedef struct _BlobInfo BlobInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _QuantumInfo QuantumInfo;

typedef enum {
    BilevelType,
    GrayscaleType
} ImageType;

typedef enum {
    GRAYColorspace
} ColorspaceType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

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
} MATDataType;

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
} MATStructureClass;

typedef enum {
    LSBEndian,
    MSBEndian
} EndianType;

#define FLAG_COMPLEX 0x08
#define FLAG_LOGICAL 0x20

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

typedef ptrdiff_t MagickOffsetType;
typedef size_t MagickSizeType;

#define CoderEvent 0
#define CorruptImageError 0
#define CoderError 0
#define ResourceLimitError 0

struct _Image {
    unsigned long signature;
    EndianType endian;
    unsigned int depth;
    size_t columns;
    size_t rows;
    size_t colors;
    ImageType type;
    BlobInfo *blob;
    Image *next;
    Image *previous;
    ssize_t scene;
    struct {
        int x;
        int y;
    } page;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType ping;
    EndianType endian;
    FILE *file;
    char *filename;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _QuantumInfo {
    double minimum;
    double maximum;
};

static unsigned int ReadBlobLSBLong(Image *image) { return 0; }
static unsigned int ReadBlobMSBLong(Image *image) { return 0; }
static unsigned short ReadBlobLSBShort(Image *image) { return 0; }
static unsigned short ReadBlobMSBShort(Image *image) { return 0; }
static void ReadBlobDoublesLSB(Image *image, size_t len, double *data) {}
static void ReadBlobDoublesMSB(Image *image, size_t len, double *data) {}
static void ReadBlobFloatsLSB(Image *image, size_t len, float *data) {}
static void ReadBlobFloatsMSB(Image *image, size_t len, float *data) {}

#define LogMagickEvent(a,b,c,...) 0
#define GetMagickModule() NULL
#define ThrowReaderException(a,b) return NULL
#define DestroyImageList(a) NULL
#define DestroyImage(a) NULL
#define DestroyImageInfo(a) NULL
#define DestroyQuantumInfo(a) NULL
#define AcquireImage(a,b) NULL
#define OpenBlob(a,b,c,d) 0
#define ReadBlob(a,b,c) 0
#define TellBlob(a) 0
#define EOFBlob(a) 0
#define SeekBlob(a,b,c) 0
#define GetBlobSize(a) 0
#define CloneImageInfo(a) NULL
#define SetImageOption(a,b,c) NULL
#define SetImageExtent(a,b,c,d) 0
#define AcquireQuantumInfo(a,b) NULL
#define AcquireQuantumMemory(a,b) NULL
#define ResetMagickMemory(a,b,c) NULL
#define GetAuthenticPixels(a,b,c,d,e,f) NULL
#define ImportQuantumPixels(a,b,c,d,e,f) 0
#define SyncAuthenticPixels(a,b) 0
#define SetImageColorspace(a,b,c) 
#define RotateImage(a,b,c) NULL
#define AppendImageToList(a,b) 
#define DeleteImageFromList(a) 
#define AcquireNextImage(a,b,c) 
#define SyncNextImageInList(a) NULL
#define RelinquishMagickMemory(a) 
#define CloseBlob(a) 
#define remove_utf8(a) 0
#define DisableMSCWarning(a)
#define RestoreMSCWarning

static Image *ReadMATImageV4(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) { return NULL; }
static void FixLogical(unsigned char *data, ssize_t length) {}
static void FixSignedValues(Image *image, Quantum *q, unsigned int size) {}
static void CalcMinMax(Image *image, EndianType endian, unsigned int size_x, unsigned int size_y, MATDataType type, ssize_t ldblk, unsigned char *buffer, double *min, double *max) {}
static void InsertComplexDoubleRow(Image *image, double *data, int row, double min, double max, ExceptionInfo *exception) {}
static void InsertComplexFloatRow(Image *image, float *data, int row, double min, double max, ExceptionInfo *exception) {}