#include <stddef.h>
#include <assert.h>

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef long ssize_t;

typedef struct _ImageInfo {
    int signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    int signature;
} ExceptionInfo;

typedef struct _Image {
    size_t depth;
    int endian;
    size_t columns;
    size_t rows;
    const char *filename;
} Image;

typedef struct _QuantumInfo {
} QuantumInfo;

typedef struct _CacheView {
} CacheView;

#define MagickCoreSignature 0
#define MagickFalse 0
#define MSBEndian 0
#define ReadBinaryBlobMode 0
#define GRAYColorspace 0
#define GrayQuantum 0
#define LoadImageTag 0

#define CorruptImageError 0
#define ResourceLimitError 0
#define TraceEvent 0

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
short ReadBlobLSBShort(Image *);
void ThrowReaderException(int, const char *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void SetImageColorspace(Image *, int, ExceptionInfo *);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
size_t GetQuantumExtent(Image *, QuantumInfo *, int);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
Quantum *GetQuantumPixels(QuantumInfo *);
const unsigned char *ReadBlobStream(Image *, size_t, Quantum *, ssize_t *);
void ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, int, const unsigned char *, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, ssize_t, size_t);
void SetQuantumImageType(Image *, int);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
MagickBooleanType EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void *LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);

#define magick_restrict