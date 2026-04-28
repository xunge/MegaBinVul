#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

typedef struct _Image {
    unsigned long signature;
    int endian;
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    unsigned long colors;
    unsigned long type;
    unsigned long scene;
    struct _BlobInfo *blob;
    struct _ExceptionInfo *exception;
    struct _Image *next;
    struct _Image *previous;
    struct {
        long x;
        long y;
    } page;
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
    unsigned long DataType;
    unsigned long ObjectSize;
    unsigned long unknown1;
    unsigned long unknown2;
    unsigned long unknown5;
    unsigned char StructureClass;
    unsigned char StructureFlag;
    unsigned long unknown3;
    unsigned long unknown4;
    unsigned long DimFlag;
    unsigned long SizeX;
    unsigned long SizeY;
    unsigned short Flag1;
    unsigned short NameFlag;
} MATHeader;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef long long MagickOffsetType;
typedef unsigned long size_t;
typedef long ssize_t;

#define MagickSignature 0xabacadab
#define LSBEndian 0
#define MSBEndian 1
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define CoderError 0
#define CoderEvent 0
#define GetMagickModule() ""
#define LogMagickEvent(a,b,c,...) 0
#define MAGICKCORE_ZLIB_DELEGATE 1

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

#define FLAG_COMPLEX 0x8
#define FLAG_LOGICAL 0x20

#define GRAYColorspace 1
#define GrayscaleType 1
#define BilevelType 2

static const int z2qtype[] = {0, 1, 2}; // Placeholder for z2qtype array

#define DisableMSCWarning(n)
#define RestoreMSCWarning

Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void ThrowReaderException(int, const char *);
ImageInfo *CloneImageInfo(const ImageInfo *);
unsigned short ReadBlobLSBShort(Image *);
unsigned long ReadBlobLSBLong(Image *);
unsigned long ReadBlobMSBLong(Image *);
unsigned short ReadBlobMSBShort(Image *);
void ReadBlobDoublesLSB(Image *, size_t, double *);
void ReadBlobDoublesMSB(Image *, size_t, double *);
void ReadBlobFloatsLSB(Image *, size_t, float *);
void ReadBlobFloatsMSB(Image *, size_t, float *);
MagickOffsetType TellBlob(Image *);
int EOFBlob(Image *);
int SeekBlob(Image *, MagickOffsetType, int);
Image *DecompressBlock(Image *, unsigned long, ImageInfo *, ExceptionInfo *);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
void SetImageColorspace(Image *, int);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
void InheritException(ExceptionInfo *, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void ResetMagickMemory(void *, int, size_t);
PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
int ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, int, void *, ExceptionInfo *);
int SyncAuthenticPixels(Image *, ExceptionInfo *);
Image *RotateImage(Image *, double, ExceptionInfo *);
void AppendImageToList(Image **, Image *);
void DeleteImageFromList(Image **);
void AcquireNextImage(const ImageInfo *, Image *);
Image *SyncNextImageInList(Image *);
void RelinquishMagickMemory(void *);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void CloseBlob(Image *);
int SetImageOption(ImageInfo *, const char *, const char *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
int remove_utf8(const char *);

static Image *ReadMATImageV4(const ImageInfo *, Image *, ExceptionInfo *);
static void FixLogical(unsigned char *, ssize_t);
static void FixSignedValues(PixelPacket *, size_t);
static void CalcMinMax(Image *, int, size_t, size_t, size_t, ssize_t, unsigned char *, double *, double *);
static void InsertComplexDoubleRow(double *, int, Image *, double, double);
static void InsertComplexFloatRow(float *, int, Image *, double, double);