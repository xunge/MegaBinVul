#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char filename[4096];
    char magick[16];
    size_t number_scenes;
    size_t scene;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _PrimaryInfo {
    float x;
    float y;
} PrimaryInfo;

typedef struct _ChromaticityInfo {
    PrimaryInfo red_primary;
    PrimaryInfo green_primary;
    PrimaryInfo blue_primary;
    PrimaryInfo white_point;
} ChromaticityInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    size_t scene;
    char filename[4096];
    char magick_filename[4096];
    ChromaticityInfo chromaticity;
    float gamma;
    int colorspace;
    struct _Image *previous;
    struct _Image *next;
    void *client_data;
} Image;

typedef int (*MagickProgressMonitor)(const char *, MagickOffsetType, MagickOffsetType, void *);

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define ResourceLimitError 0
#define CorruptImageError 0
#define YCCColorspace 0
#define sRGBColorspace 0
#define LoadImageTag 0
#define ReadBinaryBlobMode 0
#define MagickPathExtent 4096
#define SEEK_SET 0

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void *AcquireQuantumMemory(size_t, size_t);
void ThrowReaderException(int, const char *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
int LocaleNCompare(const char *, const char *, size_t);
void *RelinquishMagickMemory(void *);
size_t MagickMin(size_t, size_t);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void Upsample(size_t, size_t, size_t, unsigned char *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
Quantum ScaleCharToQuantum(unsigned char);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
size_t GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
int LocaleCompare(const char *, const char *);
MagickBooleanType SetImageColorspace(Image *, int, ExceptionInfo *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickProgressMonitor SetImageProgressMonitor(Image *, MagickProgressMonitor, void *);
int FormatLocaleString(char *, size_t, const char *, ...);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, MagickOffsetType);
Image *GetFirstImageInList(Image *);
Image *OverviewImage(const ImageInfo *, Image *, ExceptionInfo *);
MagickBooleanType DecodeImage(Image *, unsigned char *, unsigned char *, unsigned char *, ExceptionInfo *);
MagickOffsetType TellBlob(Image *);
MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
MagickBooleanType EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
int CloseBlob(Image *);
Image *RotateImage(Image *, double, ExceptionInfo *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
Image *DestroyImage(Image *);
int ReadBlobByte(Image *);