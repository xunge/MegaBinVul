#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char MagickBooleanType;
typedef unsigned long Quantum;
typedef unsigned long size_t;
typedef long ssize_t;
typedef long MagickOffsetType;

#define MagickCoreSignature 0xABACADABUL
#define MagickFalse 0
#define MagickTrue 1
#define QuantumRange 65535UL
#define MagickPathExtent 4096

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    struct _Colormap *colormap;
    int storage_class;
    char *filename;
} Image;

typedef struct _Colormap {
    Quantum red;
    Quantum green;
    Quantum blue;
} Colormap;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    FILE *file;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct {
    unsigned short Width;
    unsigned short Height;
    unsigned short Reserved;
} CUTHeader;

typedef struct {
    char FileId[2];
    unsigned short Version;
    unsigned short Size;
    char FileType;
    char SubType;
    unsigned short BoardID;
    unsigned short GraphicsMode;
    unsigned short MaxIndex;
    unsigned short MaxRed;
    unsigned short MaxGreen;
    unsigned short MaxBlue;
    char PaletteId[20];
} CUTPalHeader;

#define TraceEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define PseudoClass 0

#define ReadBinaryBlobMode 0
#define SEEK_SET 0

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned short ReadBlobLSBShort(Image *);
unsigned char ReadBlobByte(Image *);
MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
MagickOffsetType TellBlob(Image *);
MagickBooleanType EOFBlob(Image *);
void ThrowReaderException(int, const char *);
size_t GetQuantumRange(unsigned long);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
ImageInfo *CloneImageInfo(const ImageInfo *);
size_t CopyMagickString(char *, const char *, size_t);
FILE *fopen_utf8(const char *, const char *);
ImageInfo *DestroyImageInfo(ImageInfo *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
size_t ReadBlob(Image *, size_t, unsigned char *);
Quantum ClampToQuantum(double);
Quantum ScaleCharToQuantum(unsigned char);
void *AcquireQuantumMemory(size_t, size_t);
void *ResetMagickMemory(void *, int, size_t);
void InsertRow(Image *, ssize_t, unsigned char *, ssize_t, ExceptionInfo *);
void SyncImage(Image *, ExceptionInfo *);
MagickBooleanType SetImageGray(Image *, ExceptionInfo *);
int GetCutColors(Image *, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
Quantum GetPixelRed(const Image *, const Quantum *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
size_t GetPixelChannels(const Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
void *RelinquishMagickMemory(void *);
Image *DestroyImage(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
const char *GetMagickModule(void);
int LogMagickEvent(int, const char *, const char *, const char *);