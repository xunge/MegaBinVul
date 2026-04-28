#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxTextExtent 4096
#define MagickSignature 0xabacadabUL
#define QuantumRange 65535
#define MagickFalse 0
#define MagickTrue 1

typedef long MagickOffsetType;
#define LoadImageTag 0

typedef enum {
  TraceEvent,
  ResourceLimitError,
  CorruptImageError
} ExceptionType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  NoCompression,
  RLECompression
} CompressionType;

typedef enum {
  RGBColorspace,
  XYZColorspace
} ColorspaceType;

typedef struct _PrimaryInfo {
  double x, y;
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
  double gamma;
  ChromaticityInfo chromaticity;
  CompressionType compression;
  ColorspaceType colorspace;
  char *filename;
  unsigned char *blob;
  size_t blob_length;
  size_t blob_offset;
} Image;

typedef struct _ImageInfo {
  unsigned long signature;
  int debug;
  int ping;
  char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef unsigned char Quantum;

typedef int MagickBooleanType;

typedef struct _StringInfo {
  char *string;
  size_t length;
} StringInfo;

/* Function prototypes */
Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
int ReadBlobByte(Image *);
Image *DestroyImage(Image *);
char *AcquireString(char *);
void *ResizeQuantumMemory(void *, size_t, size_t);
void ThrowReaderException(ExceptionType, const char *);
MagickBooleanType SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
char *DestroyString(char *);
int LocaleCompare(const char *, const char *);
MagickBooleanType CopyMagickString(char *, const char *, size_t);
MagickBooleanType FormatLocaleString(char *, size_t, const char *, ...);
double StringToDouble(const char *, char **);
MagickBooleanType SetImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
Quantum ClampToQuantum(double);
size_t GetPixelChannels(const Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
void *RelinquishMagickMemory(void *);
MagickBooleanType EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);