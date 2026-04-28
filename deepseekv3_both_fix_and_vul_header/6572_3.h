#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define LoadImageTag "LoadImage"

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    MSBEndian,
    LSBEndian
} EndianType;

typedef enum {
    GRAYColorspace
} ColorspaceType;

typedef enum {
    GrayQuantum
} QuantumType;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ExceptionType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _Image {
    size_t depth;
    EndianType endian;
    size_t columns;
    size_t rows;
    const char *filename;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _QuantumInfo QuantumInfo;
typedef struct _CacheView CacheView;

typedef unsigned char Quantum;
typedef long MagickOffsetType;

#define magick_restrict __restrict

extern size_t GetMagickModule(void);
extern void LogMagickEvent(LogEventType, size_t, const char *, ...);
extern void ThrowReaderException(ExceptionType, const char *);
extern void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
extern int LocaleCompare(const char *, const char *);
extern char *ReadBlobString(Image *, char *);
extern const unsigned char *ReadBlobStream(Image *, size_t, unsigned char *, ssize_t *);
extern Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
extern MagickBooleanType SetImageProgress(Image *, const char *, MagickOffsetType, size_t);
extern MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
extern MagickBooleanType SetImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
extern MagickBooleanType ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, QuantumType, const unsigned char *, ExceptionInfo *);
extern MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
extern MagickBooleanType EOFBlob(Image *);
extern Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
extern Image *DestroyImageList(Image *);
extern Image *GetFirstImageInList(Image *);
extern QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
extern QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
extern void CloseBlob(Image *);
extern size_t GetQuantumExtent(Image *, QuantumInfo *, QuantumType);
extern unsigned char *GetQuantumPixels(QuantumInfo *);
extern void SetQuantumImageType(Image *, QuantumType);