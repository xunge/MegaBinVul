#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MaxTextExtent 4096
#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define FileOpenError 0
#define ResourceLimitError 0
#define Group4Compression 4
#define BilevelType 0
#define MSBEndian 0
#define WriteBinaryBlobMode 0
#define TIFFTAG_STRIPBYTECOUNTS 0

typedef int MagickBooleanType;
typedef long ssize_t;
typedef uint64_t toff_t;
typedef uint32_t uint32;
typedef ssize_t tsize_t;

typedef struct _ImageInfo {
    unsigned long signature;
    char *filename;
    int compression;
    int type;
    void *exception;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    char filename[MaxTextExtent];
    int debug;
    int endian;
    int type;
    int depth;
    void *exception;
} Image;

typedef struct _TIFF TIFF;

/* TIFF function stubs */
TIFF* TIFFOpen(const char*, const char*);
int TIFFGetField(TIFF*, int, ...);
int TIFFNumberOfStrips(TIFF*);
int TIFFReadRawStrip(TIFF*, uint32, void*, tsize_t);
void TIFFClose(TIFF*);

extern MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, void *);
extern void *CloneImage(Image *, unsigned long, unsigned long, MagickBooleanType, void *);
extern MagickBooleanType CloseBlob(Image *);
extern int AcquireUniqueFileResource(char *);
extern FILE *fdopen(int, const char *);
extern void ThrowFileException(void *, int, const char *, const char *);
extern void FormatLocaleString(char *, size_t, const char *, ...);
extern void SetImageType(Image *, int);
extern void SetImageDepth(Image *, int);
extern ImageInfo *CloneImageInfo(ImageInfo *);
extern void SetImageInfoFile(ImageInfo *, FILE *);
extern void SetImageOption(ImageInfo *, const char *, const char *);
extern MagickBooleanType WriteTIFFImage(ImageInfo *, Image *);
extern int fflush(FILE *);
extern ImageInfo *DestroyImageInfo(ImageInfo *);
extern void InheritException(void *, void *);
extern Image *DestroyImage(Image *);
extern int fclose(FILE *);
extern int RelinquishUniqueFileResource(const char *);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void ThrowBinaryException(int, const char *, const char *);
extern ssize_t WriteBlob(Image *, size_t, const unsigned char *);
extern void *RelinquishMagickMemory(void *);
extern void *LogMagickEvent(int, const char *, const char *, const char *);
extern const char *GetMagickModule(void);