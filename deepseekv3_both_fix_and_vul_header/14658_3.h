#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct _BlobInfo BlobInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _MATHeader MATHeader;
typedef struct _PixelPacket PixelPacket;
typedef struct _QuantumInfo QuantumInfo;
typedef struct _CacheView CacheView;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef unsigned char MagickByteType;
typedef size_t MagickSizeType;
typedef ssize_t MagickOffsetType;
typedef unsigned int MagickStatusType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    LSBEndian,
    MSBEndian
} EndianType;

typedef enum {
    CoderEvent
} LogEventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError,
    CoderError
} ExceptionType;

typedef enum {
    GrayscaleType,
    BilevelType
} ImageType;

typedef enum {
    GRAYColorspace
} ColorspaceType;

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
} MATLABClassType;

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
} MATLABDataType;

#define MagickSignature 0xabacadabUL
#define FLAG_COMPLEX 0x08
#define FLAG_LOGICAL 0x20
#define GetMagickModule() "MAT"

struct _ImageInfo {
    unsigned long signature;
    int ping;
    FILE *file;
    char *filename;
    EndianType endian;
};

struct _ExceptionInfo {
    unsigned long signature;
    ExceptionInfo *exception;
};

struct _Image {
    unsigned long signature;
    Image *next;
    Image *previous;
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    ImageType type;
    EndianType endian;
    BlobInfo *blob;
    struct {
        int x;
        int y;
    } page;
    ssize_t scene;
    ExceptionInfo exception;
};

struct _MATHeader {
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
};

struct _QuantumInfo {
    double minimum;
    double maximum;
};

static int LogMagickEvent(LogEventType, const char *, const char *, ...) { return 0; }
static Image *AcquireImage(const ImageInfo *) { return NULL; }
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *) { return MagickFalse; }
static Image *DestroyImageList(Image *) { return NULL; }
static ImageInfo *CloneImageInfo(const ImageInfo *) { return NULL; }
static size_t ReadBlob(Image *, size_t, unsigned char *) { return 0; }
static void ThrowReaderException(ExceptionType, const char *) {}
static unsigned short ReadBlobLSBShort(Image *) { return 0; }
static unsigned int ReadBlobLSBLong(Image *) { return 0; }
static unsigned int ReadBlobMSBLong(Image *) { return 0; }
static unsigned short ReadBlobMSBShort(Image *) { return 0; }
static void ReadBlobDoublesLSB(Image *, size_t, double *) {}
static void ReadBlobDoublesMSB(Image *, size_t, double *) {}
static void ReadBlobFloatsLSB(Image *, size_t, float *) {}
static void ReadBlobFloatsMSB(Image *, size_t, float *) {}
static MagickOffsetType TellBlob(Image *) { return 0; }
static int EOFBlob(Image *) { return 0; }
static int SeekBlob(Image *, MagickOffsetType, int) { return 0; }
static MagickBooleanType SetImageOption(ImageInfo *, const char *, const char *) { return MagickFalse; }
static QuantumInfo *AcquireQuantumInfo(ImageInfo *, Image *) { return NULL; }
static void SetImageColorspace(Image *, ColorspaceType) {}
static MagickBooleanType SetImageExtent(Image *, size_t, size_t) { return MagickFalse; }
static void InheritException(ExceptionInfo *, ExceptionInfo *) {}
static void *AcquireQuantumMemory(size_t, size_t) { return NULL; }
static PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *) { return NULL; }
static int ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, const char *, unsigned char *, ExceptionInfo *) { return 0; }
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *) { return MagickFalse; }
static void FixLogical(unsigned char *, ssize_t) {}
static void FixSignedValues(PixelPacket *, unsigned int) {}
static void CalcMinMax(Image *, EndianType, unsigned int, unsigned int, size_t, ssize_t, unsigned char *, double *, double *) {}
static void InsertComplexDoubleRow(double *, int, Image *, double, double) {}
static void InsertComplexFloatRow(float *, int, Image *, double, double) {}
static Image *RotateImage(Image *, double, ExceptionInfo *) { return NULL; }
static void AppendImageToList(Image **, Image *) {}
static void DeleteImageFromList(Image **) {}
static int remove_utf8(const char *) { return 0; }
static void AcquireNextImage(const ImageInfo *, Image *) {}
static Image *SyncNextImageInList(Image *) { return NULL; }
static void RelinquishMagickMemory(void *) {}
static void CloseBlob(Image *) {}
static ImageInfo *DestroyImageInfo(ImageInfo *) { return NULL; }

#define DisableMSCWarning(n)
#define RestoreMSCWarning

static const char *z2qtype[] = {NULL};