#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum {
    LSBEndian,
    MSBEndian
} EndianType;

typedef struct _Image {
    unsigned long signature;
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    unsigned long colors;
    unsigned long type;
    EndianType endian;
    struct _BlobInfo *blob;
    struct _Image *next;
    struct _Image *previous;
    struct _ExceptionInfo *exception;
    struct {
        long x;
        long y;
    } page;
    long scene;
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
    struct _ExceptionInfo *exception;
} ExceptionInfo;

typedef struct _QuantumInfo {
    double minimum;
    double maximum;
} QuantumInfo;

typedef struct _BlobInfo {
    void *data;
} BlobInfo;

typedef struct _PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
} PixelPacket;

typedef struct _CacheView {
    void *data;
} CacheView;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef long long MagickOffsetType;
typedef size_t MagickSizeType;

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

#define FLAG_LOGICAL 0x0200
#define FLAG_COMPLEX 0x0800
#define MagickSignature 0xabacadabUL
#define CoderEvent 0x01
#define ReadBinaryBlobMode 0x01
#define CorruptImageError 0x01
#define ResourceLimitError 0x02
#define CoderError 0x03
#define GRAYColorspace 1
#define GrayscaleType 1
#define BilevelType 2

typedef struct {
    char identific[124];
    unsigned short Version;
    char EndianIndicator[2];
    unsigned int DataType;
    unsigned int ObjectSize;
    unsigned int unknown1;
    unsigned int unknown2;
    unsigned int unknown5;
    unsigned int StructureClass;
    unsigned int StructureFlag;
    unsigned int unknown3;
    unsigned int unknown4;
    unsigned int DimFlag;
    unsigned int SizeX;
    unsigned int SizeY;
    unsigned short Flag1;
    unsigned short NameFlag;
} MATHeader;

static const int z2qtype[] = {0,1,2,3};

unsigned int ReadBlobLSBLong(Image *image);
unsigned int ReadBlobMSBLong(Image *image);
unsigned short ReadBlobLSBShort(Image *image);
unsigned short ReadBlobMSBShort(Image *image);
void ReadBlobDoublesLSB(Image *image, size_t len, double *data);
void ReadBlobDoublesMSB(Image *image, size_t len, double *data);
void ReadBlobFloatsLSB(Image *image, size_t len, float *data);
void ReadBlobFloatsMSB(Image *image, size_t len, float *data);
int LogMagickEvent(int event, const char *module, const char *format, ...);
const char *GetMagickModule(void);
Image *AcquireImage(const ImageInfo *image_info);
MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception);
Image *DestroyImageList(Image *image);
Image *DestroyImage(Image *image);
size_t ReadBlob(Image *image, size_t length, unsigned char *data);
void ThrowReaderException(int error, const char *reason);
Image *ReadMATImageV4(const ImageInfo *image_info, Image *image, ExceptionInfo *exception);
MagickOffsetType TellBlob(Image *image);
int EOFBlob(Image *image);
int SeekBlob(Image *image, MagickOffsetType offset, int whence);
MagickSizeType GetBlobSize(Image *image);
ImageInfo *CloneImageInfo(const ImageInfo *image_info);
ImageInfo *DestroyImageInfo(ImageInfo *image_info);
void SetImageColorspace(Image *image, int colorspace);
MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *image_info, Image *image);
void *AcquireQuantumMemory(size_t count, size_t quantum);
void ResetMagickMemory(void *memory, int c, size_t size);
PixelPacket *GetAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
int ImportQuantumPixels(Image *image, CacheView *cache_view, QuantumInfo *quantum_info, int storage_type, void *pixels, ExceptionInfo *exception);
MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception);
void FixLogical(unsigned char *buffer, size_t length);
void FixSignedValues(PixelPacket *q, size_t length);
Image *RotateImage(Image *image, double degrees, ExceptionInfo *exception);
void AppendImageToList(Image **images, Image *image);
void DeleteImageFromList(Image **images);
void AcquireNextImage(const ImageInfo *image_info, Image *image);
Image *SyncNextImageInList(Image *image);
void *RelinquishMagickMemory(void *memory);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *quantum_info);
void CloseBlob(Image *image);
int remove_utf8(const char *filename);
int unlink(const char *filename);
void SetImageOption(ImageInfo *image_info, const char *option, const char *value);
void InheritException(ExceptionInfo *exception, ExceptionInfo **destination);
void CalcMinMax(Image *image, EndianType endian, size_t width, size_t height, size_t cell_type, ssize_t ldblk, unsigned char *buffer, double *min_val, double *max_val);
void InsertComplexDoubleRow(double *data, int row, Image *image, double min_val, double max_val);
void InsertComplexFloatRow(float *data, int row, Image *image, double min_val, double max_val);

#define DisableMSCWarning(n)
#define RestoreMSCWarning