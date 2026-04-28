#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _QuantumInfo QuantumInfo;
typedef struct _BlobInfo BlobInfo;
typedef struct _MATHeader MATHeader;
typedef struct _CacheView CacheView;
typedef unsigned char Quantum;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define ReadBinaryBlobMode 0
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
#define GrayscaleType 2
#define GRAYColorspace 3
#define BilevelType 1
#define CoderEvent 0
#define CorruptImageError 0
#define CoderError 0
#define ResourceLimitError 0
#define SEEK_SET 0
#define SEEK_CUR 1

typedef size_t MagickSizeType;
typedef ssize_t MagickOffsetType;
typedef unsigned int MagickBooleanType;

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
    unsigned char StructureClass;
    unsigned char StructureFlag;
    unsigned int DimFlag;
    unsigned int SizeX;
    unsigned int SizeY;
    unsigned short Flag1;
    unsigned short NameFlag;
};

struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    int type;
    int endian;
    void *blob;
    Image *next;
    Image *previous;
    ssize_t scene;
    struct {
        ssize_t x;
        ssize_t y;
    } page;
};

struct _ImageInfo {
    unsigned long signature;
    int ping;
    int endian;
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

static const int z2qtype[] = {0, 1, 2}; // RGB channel types

#define DisableMSCWarning(n)
#define RestoreMSCWarning

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void ThrowReaderException(int, const char *);
unsigned short ReadBlobLSBShort(Image *);
unsigned int ReadBlobLSBLong(Image *);
unsigned short ReadBlobMSBShort(Image *);
unsigned int ReadBlobMSBLong(Image *);
void ReadBlobDoublesLSB(Image *, size_t, double *);
void ReadBlobFloatsLSB(Image *, size_t, float *);
void ReadBlobDoublesMSB(Image *, size_t, double *);
void ReadBlobFloatsMSB(Image *, size_t, float *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
MagickOffsetType TellBlob(Image *);
MagickBooleanType EOFBlob(Image *);
MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
MagickSizeType GetBlobSize(Image *);
Image *decompress_block(Image *, unsigned int *, ImageInfo *, ExceptionInfo *);
Image *ReadMATImageV4(const ImageInfo *, Image *, ExceptionInfo *);
int LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageOption(ImageInfo *, const char *, const char *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
QuantumInfo *AcquireQuantumInfo(ImageInfo *, Image *);
void *AcquireQuantumMemory(size_t, size_t);
void *ResetMagickMemory(void *, int, size_t);
void CalcMinMax(Image *, int, unsigned int, unsigned int, size_t, ssize_t, unsigned char *, double *, double *);
Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
int ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, int, unsigned char *, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
void FixLogical(unsigned char *, ssize_t);
void FixSignedValues(Image *, Quantum *, size_t);
void InsertComplexDoubleRow(Image *, double *, ssize_t, double, double, ExceptionInfo *);
void InsertComplexFloatRow(Image *, float *, ssize_t, double, double, ExceptionInfo *);
Image *RotateImage(Image *, double, ExceptionInfo *);
void AppendImageToList(Image **, Image *);
void DeleteImageFromList(Image **);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *SyncNextImageInList(Image *);
void *RelinquishMagickMemory(void *);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
void CloseBlob(Image *);
ImageInfo *DestroyImageInfo(ImageInfo *);
int remove_utf8(const char *);
void SetImageColorspace(Image *, int, ExceptionInfo *);