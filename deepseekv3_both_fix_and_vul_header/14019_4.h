#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SEEK_SET 0
#define SEEK_CUR 1

typedef struct _Image Image;
typedef struct _BlobInfo BlobInfo;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _QuantumInfo QuantumInfo;
typedef struct _CacheView CacheView;
typedef unsigned char Quantum;

struct _Image {
    unsigned long signature;
    int endian;
    size_t depth;
    size_t columns;
    size_t rows;
    size_t colors;
    int type;
    BlobInfo *blob;
    Image *previous;
    Image *next;
    ssize_t scene;
    struct {
        int x;
        int y;
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

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define LSBEndian 0
#define MSBEndian 1
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define CoderError 0
#define GrayscaleType 0
#define BilevelType 0
#define GRAYColorspace 0
#define miCOMPRESSED 0
#define miMATRIX 0
#define mxCHAR_CLASS 0
#define mxSINGLE_CLASS 0
#define mxDOUBLE_CLASS 0
#define mxINT8_CLASS 0
#define mxUINT8_CLASS 0
#define mxINT16_CLASS 0
#define mxUINT16_CLASS 0
#define mxINT32_CLASS 0
#define mxUINT32_CLASS 0
#define mxINT64_CLASS 0
#define mxUINT64_CLASS 0
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

enum {
    z2qtype_0,
    z2qtype_1,
    z2qtype_2,
    z2qtype_3
};

static const int z2qtype[] = {
    z2qtype_0,
    z2qtype_1,
    z2qtype_2,
    z2qtype_3
};

#define DisableMSCWarning(n)
#define RestoreMSCWarning

typedef size_t MagickSizeType;
typedef ssize_t MagickOffsetType;

unsigned int ReadBlobLSBLong(Image *);
unsigned short ReadBlobLSBShort(Image *);
void ReadBlobDoublesLSB(Image *, size_t, double *);
void ReadBlobFloatsLSB(Image *, size_t, float *);
unsigned int ReadBlobMSBLong(Image *);
unsigned short ReadBlobMSBShort(Image *);
void ReadBlobDoublesMSB(Image *, size_t, double *);
void ReadBlobFloatsMSB(Image *, size_t, float *);
Image *ReadMATImageV4(const ImageInfo *, Image *, ExceptionInfo *);
int LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
unsigned int OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void ThrowReaderException(int, const char *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
ssize_t TellBlob(Image *);
int EOFBlob(Image *);
int SeekBlob(Image *, MagickOffsetType, int);
Image *DecompressBlock(Image *, unsigned int, ImageInfo *, ExceptionInfo *);
void SetImageOption(ImageInfo *, const char *, const char *);
QuantumInfo *AcquireQuantumInfo(ImageInfo *, Image *);
int SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void ResetMagickMemory(void *, int, size_t);
void CalcMinMax(Image *, int, unsigned int, unsigned int, size_t, ssize_t, unsigned char *, double *, double *);
Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
int ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, int, unsigned char *, ExceptionInfo *);
void FixLogical(unsigned char *, ssize_t);
void FixSignedValues(Image *, Quantum *, size_t);
int SyncAuthenticPixels(Image *, ExceptionInfo *);
void InsertComplexDoubleRow(Image *, double *, int, double, double, ExceptionInfo *);
void InsertComplexFloatRow(Image *, float *, int, float, float, ExceptionInfo *);
Image *RotateImage(Image *, double, ExceptionInfo *);
void AppendImageToList(Image **, Image *);
void DeleteImageFromList(Image **);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *SyncNextImageInList(Image *);
void RelinquishMagickMemory(void *);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void CloseBlob(Image *);
int remove_utf8(const char *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageColorspace(Image *, int, ExceptionInfo *);