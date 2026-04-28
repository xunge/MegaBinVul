#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum {
    LSBEndian,
    MSBEndian
} EndianType;

typedef struct _BlobInfo {
    void *data;
} BlobInfo;

typedef struct _Image {
    unsigned long signature;
    EndianType endian;
    unsigned depth;
    size_t columns;
    size_t rows;
    size_t colors;
    int type;
    BlobInfo *blob;
    struct _Image *next;
    struct _Image *previous;
    struct {
        unsigned long signature;
    } exception;
    struct {
        int x;
        int y;
    } page;
    ssize_t scene;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    int ping;
    EndianType endian;
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

typedef struct _PixelPacket {
    unsigned char r, g, b, a;
} PixelPacket;

typedef struct _CacheView {
    void *data;
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

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

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

#define FLAG_LOGICAL 0x0200
#define FLAG_COMPLEX 0x0800
#define SEEK_CUR 1

#define MagickSignature 0xabacadabUL
#define CoderEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define CoderError 0
#define ReadBinaryBlobMode 0
#define BilevelType 0
#define GrayscaleType 0
#define GRAYColorspace 0

typedef long ssize_t;
typedef unsigned long size_t;
typedef long MagickOffsetType;
typedef unsigned long MagickSizeType;

unsigned int ReadBlobLSBLong(Image *);
unsigned short ReadBlobLSBShort(Image *);
void ReadBlobDoublesLSB(Image *, size_t, double *);
void ReadBlobFloatsLSB(Image *, size_t, float *);
unsigned int ReadBlobMSBLong(Image *);
unsigned short ReadBlobMSBShort(Image *);
void ReadBlobDoublesMSB(Image *, size_t, double *);
void ReadBlobFloatsMSB(Image *, size_t, float *);
Image *ReadMATImageV4(const ImageInfo *, Image *, ExceptionInfo *);
Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void ThrowReaderException(int, const char *);
unsigned int ReadBlob(Image *, size_t, unsigned char *);
unsigned short ReadBlobLSBShort(Image *);
int LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
void *AcquireQuantumMemory(size_t, size_t);
void ResetMagickMemory(void *, int, size_t);
void *RelinquishMagickMemory(void *);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
ImageInfo *CloneImageInfo(const ImageInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
Image *DestroyImage(Image *);
void DeleteImageFromList(Image **);
Image *RotateImage(Image *, double, ExceptionInfo *);
void AppendImageToList(Image **, Image *);
void InheritException(ExceptionInfo *, ExceptionInfo *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
int ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, int, unsigned char *, ExceptionInfo *);
void FixLogical(unsigned char *, ssize_t);
void FixSignedValues(PixelPacket *, size_t);
void CalcMinMax(Image *, EndianType, size_t, size_t, DataType, ssize_t, unsigned char *, double *, double *);
void InsertComplexDoubleRow(double *, int, Image *, double, double);
void InsertComplexFloatRow(float *, int, Image *, double, double);
void SetImageColorspace(Image *, int);
void SetImageOption(ImageInfo *, const char *, const char *);
MagickOffsetType TellBlob(Image *);
MagickBooleanType SeekBlob(Image *, MagickOffsetType, int);
MagickBooleanType EOFBlob(Image *);
MagickSizeType GetBlobSize(Image *);
Image *SyncNextImageInList(Image *);
void AcquireNextImage(const ImageInfo *, Image *);
int remove_utf8(const char *);
int unlink(const char *);
void CloseBlob(Image *);

#define DisableMSCWarning(n)
#define RestoreMSCWarning

static const int z2qtype[] = {0, 1, 2};