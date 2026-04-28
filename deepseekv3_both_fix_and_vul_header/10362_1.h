#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MagickEpsilon 1.0e-10

typedef unsigned char MagickBooleanType;
typedef double Quantum;
typedef size_t MagickSizeType;
typedef ssize_t MagickOffsetType;

typedef struct _ExceptionInfo
{
  unsigned long signature;
} ExceptionInfo;

typedef struct _PrimaryInfo
{
  double x, y;
} PrimaryInfo;

typedef struct _ChromaticityInfo
{
  PrimaryInfo red_primary;
  PrimaryInfo green_primary;
  PrimaryInfo blue_primary;
  PrimaryInfo white_point;
} ChromaticityInfo;

typedef struct _Image
{
  unsigned long signature;
  MagickBooleanType debug;
  const char *filename;
  size_t columns;
  size_t rows;
  double gamma;
  ChromaticityInfo chromaticity;
  int colorspace;
  size_t (*GetPixelChannels)(const struct _Image *);
  Quantum *(*GetVirtualPixels)(struct _Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
  MagickBooleanType (*SetImageProgress)(struct _Image *, const char *, MagickOffsetType, size_t);
} Image;

typedef struct _ImageInfo
{
  unsigned long signature;
  MagickBooleanType debug;
} ImageInfo;

enum ColorspaceType
{
  RGBColorspace
};

#define QuantumScale ((double) 1.0/(double) QuantumRange)
#define QuantumRange ((Quantum) 65535)

#define WriteBinaryBlobMode 1
#define ResourceLimitError 1
#define SaveImageTag "SaveImage"
#define TraceEvent 1

const char *GetMagickModule(void);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
void LogMagickEvent(int, const char *, const char *, ...);
void ResetMagickMemory(void *, int, size_t);
size_t CopyMagickString(char *, const char *, size_t);
ssize_t FormatLocaleString(char *, size_t, const char *, ...);
ssize_t WriteBlob(Image *, size_t, const unsigned char *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType TransformImageColorspace(Image *, int, ExceptionInfo *);
const char *GetImageProperty(Image *, const char *, ExceptionInfo *);
void ThrowWriterException(int, const char *);
size_t HDRWriteRunlengthPixels(Image *, unsigned char *);
MagickBooleanType IsRGBColorspace(int);
Quantum *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
double GetPixelRed(const Image *, const Quantum *);
double GetPixelGreen(const Image *, const Quantum *);
double GetPixelBlue(const Image *, const Quantum *);
size_t GetPixelChannels(const Image *);
MagickBooleanType SetImageProgress(Image *, const char *, MagickOffsetType, size_t);