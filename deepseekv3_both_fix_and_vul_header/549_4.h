#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

#define CorruptImageError 1
#define SEEK_SET 0
#define SEEK_CUR 1

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { LSBEndian, MSBEndian } EndianType;
typedef enum { FloatingPointQuantumFormat, UnsignedQuantumFormat, SignedQuantumFormat } QuantumFormatType;
typedef enum { GRAYColorspace } ColorspaceType;
typedef enum { GrayQuantum } QuantumType;
typedef enum { LoadImageTag, LoadImagesTag } ProgressTag;

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _QuantumInfo QuantumInfo;
typedef struct _CacheView CacheView;
typedef unsigned char Quantum;

typedef long MagickOffsetType;

struct _Image {
    size_t columns;
    size_t rows;
    unsigned int depth;
    char *filename;
    Image *previous;
    Image *next;
    unsigned int scene;
    void *blob;
    struct {
        int x;
        int y;
    } page;
    unsigned int colors;
};

struct _ImageInfo {
    MagickBooleanType ping;
    unsigned int number_scenes;
    unsigned int scene;
};

struct _ExceptionInfo {
    int severity;
    char *reason;
    char *description;
};

struct _QuantumInfo {
    QuantumFormatType format;
    EndianType endian;
    unsigned int depth;
    double scale;
};

static void Swap(size_t *a, size_t *b) {
    size_t temp = *a;
    *a = *b;
    *b = temp;
}

static void *GetQuantumPixels(QuantumInfo *quantum_info) { return NULL; }
static void SetQuantumScale(QuantumInfo *quantum_info, double scale) {}
static MagickBooleanType SetQuantumEndian(Image *image, QuantumInfo *quantum_info, EndianType endian) { return MagickTrue; }
static MagickBooleanType SetQuantumFormat(Image *image, QuantumInfo *quantum_info, QuantumFormatType format) { return MagickTrue; }
static MagickBooleanType SetQuantumDepth(Image *image, QuantumInfo *quantum_info, unsigned int depth) { return MagickTrue; }
static QuantumInfo *DestroyQuantumInfo(QuantumInfo *quantum_info) { return NULL; }
static Quantum *QueueAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception) { return NULL; }
static MagickBooleanType ImportQuantumPixels(Image *image, CacheView *cache_view, QuantumInfo *quantum_info, QuantumType quantum_type, unsigned char *pixels, ExceptionInfo *exception) { return MagickTrue; }
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception) { return MagickTrue; }
static MagickBooleanType SetImageProgress(Image *image, ProgressTag tag, MagickOffsetType offset, MagickOffsetType span) { return MagickTrue; }
static void ThrowFileException(ExceptionInfo *exception, int error, const char *reason, const char *description) {}
static void DestroyBlob(Image *image) {}
static void *ReferenceBlob(void *blob) { return NULL; }
static void AppendImageToList(Image **images, Image *image) {}
static void DeleteImageFromList(Image **images) {}
static Image *GetFirstImageInList(Image *image) { return NULL; }
static Image *GetNextImageInList(Image *image) { return NULL; }
static Image *SyncNextImageInList(Image *image) { return NULL; }
static void AcquireNextImage(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) {}
static Image *DestroyImageList(Image *image) { return NULL; }
static MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows, ExceptionInfo *exception) { return MagickTrue; }
static void SetImageBackgroundColor(Image *image, ExceptionInfo *exception) {}
static void SetImageColorspace(Image *image, ColorspaceType colorspace, ExceptionInfo *exception) {}
static QuantumInfo *AcquireQuantumInfo(const ImageInfo *image_info, Image *image) { return NULL; }
static void FixSignedValues(Image *image, Quantum *quantum, int columns) {}
static Image *RotateImage(Image *image, double degrees, ExceptionInfo *exception) { return NULL; }
static void InsertComplexDoubleRow(Image *image, double *pixels, ssize_t y, ssize_t x, ssize_t columns, ExceptionInfo *exception) {}
static void InsertComplexFloatRow(Image *image, float *pixels, ssize_t y, ssize_t x, ssize_t columns, ExceptionInfo *exception) {}

static long ReadBlobLSBLong(Image *image) { return 0; }
static long ReadBlobMSBLong(Image *image) { return 0; }
static int ReadBlobByte(Image *image) { return 0; }
static long TellBlob(Image *image) { return 0; }
static long GetBlobSize(Image *image) { return 0; }
static void SeekBlob(Image *image, long offset, int whence) {}
static MagickBooleanType EOFBlob(Image *image) { return MagickFalse; }
static int CloseBlob(Image *image) { return 0; }
static ssize_t ReadBlob(Image *image, size_t length, char *buffer) { return 0; }

#define magick_restrict __restrict__