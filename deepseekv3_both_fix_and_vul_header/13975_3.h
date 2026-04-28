#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    int endian;
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    unsigned long colors;
    unsigned long type;
    struct _BlobInfo *blob;
    struct _Image *next;
    struct _Image *previous;
    ExceptionInfo exception;
    struct {
        long x;
        long y;
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
#define CoderEvent 4
#define GRAYColorspace 5
#define GrayscaleType 6
#define BilevelType 7

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

#define FLAG_COMPLEX 0x0800
#define FLAG_LOGICAL 0x0200

typedef size_t MagickSizeType;
typedef ssize_t MagickOffsetType;

// Function prototypes
Image *AcquireImage(const ImageInfo *);
unsigned int OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void ThrowReaderException(int, const char *);
unsigned short ReadBlobLSBShort(Image *);
unsigned int ReadBlobLSBLong(Image *);
unsigned short ReadBlobMSBShort(Image *);
unsigned int ReadBlobMSBLong(Image *);
void ReadBlobDoublesLSB(Image *, size_t, double *);
void ReadBlobDoublesMSB(Image *, size_t, double *);
void ReadBlobFloatsLSB(Image *, size_t, float *);
void ReadBlobFloatsMSB(Image *, size_t, float *);
Image *ReadMATImageV4(const ImageInfo *, Image *, ExceptionInfo *);
int LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
MagickOffsetType TellBlob(Image *);
int EOFBlob(Image *);
int SeekBlob(Image *, MagickOffsetType, int);
MagickSizeType GetBlobSize(Image *);
ImageInfo *CloneImageInfo(const ImageInfo *);
Image *decompress_block(Image *, unsigned int *, ImageInfo *, ExceptionInfo *);
void SetImageOption(ImageInfo *, const char *, const char *);
int SetImageExtent(Image *, size_t, size_t);
void InheritException(ExceptionInfo *, ExceptionInfo *);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
void *AcquireQuantumMemory(size_t, size_t);
void ResetMagickMemory(void *, int, size_t);
void CalcMinMax(Image *, int, unsigned int, unsigned int, size_t, ssize_t, unsigned char *, double *, double *);
PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
int ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, int, unsigned char *, ExceptionInfo *);
int SyncAuthenticPixels(Image *, ExceptionInfo *);
void FixLogical(unsigned char *, ssize_t);
void FixSignedValues(PixelPacket *, unsigned int);
void InsertComplexDoubleRow(double *, int, Image *, double, double);
void InsertComplexFloatRow(float *, int, Image *, double, double);
Image *RotateImage(Image *, double, ExceptionInfo *);
void AppendImageToList(Image **, Image *);
void DeleteImageFromList(Image **);
void AcquireNextImage(const ImageInfo *, Image *);
Image *SyncNextImageInList(Image *);
void *RelinquishMagickMemory(void *);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
void CloseBlob(Image *);
int remove_utf8(const char *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void SetImageColorspace(Image *, int);
Image *DestroyImage(Image *);
int ReadBlob(Image *, size_t, unsigned char *);

// z2qtype array for ImportQuantumPixels
static const int z2qtype[] = {0, 1, 2, 3};

// MSC warning macros
#define DisableMSCWarning(n)
#define RestoreMSCWarning

// Fix the missing semicolon in the ThrowReaderException call
#define ThrowReaderException(code,msg) ThrowReaderException(code,msg);