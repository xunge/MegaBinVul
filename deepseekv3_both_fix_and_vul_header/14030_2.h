#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct _Image {
    unsigned long signature;
    int endian;
    unsigned depth;
    unsigned columns;
    unsigned rows;
    unsigned colors;
    unsigned type;
    struct _Image *next;
    struct _Image *previous;
    struct _BlobInfo *blob;
    struct {
        int x;
        int y;
    } page;
    unsigned scene;
    struct _ExceptionInfo *exception;
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
#define GRAYColorspace 3
#define GrayscaleType 2
#define BilevelType 1
#define CoderEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define CoderError 0
#define ReadBinaryBlobMode 0
#define SEEK_SET 0

typedef unsigned int MagickSizeType;
typedef long long MagickOffsetType;

// Function prototypes
unsigned int ReadBlobLSBLong(Image *image);
unsigned short ReadBlobLSBShort(Image *image);
void ReadBlobDoublesLSB(Image *image, size_t len, double *data);
void ReadBlobFloatsLSB(Image *image, size_t len, float *data);
unsigned int ReadBlobMSBLong(Image *image);
unsigned short ReadBlobMSBShort(Image *image);
void ReadBlobDoublesMSB(Image *image, size_t len, double *data);
void ReadBlobFloatsMSB(Image *image, size_t len, float *data);
Image *ReadMATImageV4(const ImageInfo *image_info, Image *image, ExceptionInfo *exception);
void CalcMinMax(Image *image, int endian, unsigned int sizeX, unsigned int sizeY, size_t cellType, ssize_t ldblk, unsigned char *bImgBuff, double *min, double *max);
void FixLogical(unsigned char *data, ssize_t length);
void FixSignedValues(PixelPacket *q, unsigned int sizeX);
void InsertComplexDoubleRow(double *data, int row, Image *image, double minVal, double maxVal);
void InsertComplexFloatRow(float *data, int row, Image *image, double minVal, double maxVal);

// Stub functions
#define LogMagickEvent(a,b,c,...) 0
#define GetMagickModule() ""
#define ThrowReaderException(a,b) return NULL
#define AcquireImage(a) NULL
#define OpenBlob(a,b,c,d) 0
#define DestroyImageList(a) NULL
#define ReadBlob(a,b,c) 0
#define TellBlob(a) 0
#define EOFBlob(a) 0
#define SeekBlob(a,b,c) 0
#define CloneImageInfo(a) NULL
#define DestroyImageInfo(a) NULL
#define DestroyImage(a) NULL
#define SetImageOption(a,b,c) 0
#define GetBlobSize(a) 0
#define SetImageColorspace(a,b) 
#define SetImageExtent(a,b,c) 0
#define InheritException(a,b) 
#define AcquireQuantumInfo(a,b) NULL
#define AcquireQuantumMemory(a,b) NULL
#define ResetMagickMemory(a,b,c) memset(a,b,c)
#define GetAuthenticPixels(a,b,c,d,e,f) NULL
#define ImportQuantumPixels(a,b,c,d,e,f) 0
#define SyncAuthenticPixels(a,b) 0
#define RotateImage(a,b,c) NULL
#define AppendImageToList(a,b) 
#define DeleteImageFromList(a) 
#define AcquireNextImage(a,b) 
#define SyncNextImageInList(a) NULL
#define RelinquishMagickMemory(a) free(a)
#define DestroyQuantumInfo(a) NULL
#define CloseBlob(a) 
#define remove_utf8(a) unlink(a)
#define DisableMSCWarning(a)
#define RestoreMSCWarning