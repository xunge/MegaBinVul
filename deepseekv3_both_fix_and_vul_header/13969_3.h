#include <stddef.h>
#include <assert.h>
#include <stdio.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef unsigned short Quantum;

typedef struct _ImageInfo {
  unsigned long signature;
  int compression;
  char magick[4096];
} ImageInfo;

typedef struct _ResolutionInfo {
  double x;
  double y;
} ResolutionInfo;

typedef struct _Image {
  unsigned long signature;
  size_t columns;
  size_t rows;
  unsigned long storage_class;
  unsigned long alpha_trait;
  ResolutionInfo resolution;
  unsigned long colors;
  struct _PixelPacket *colormap;
  int debug;
  char filename[4096];
  struct _Image *previous;
} Image;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _StringInfo {
  size_t length;
  void *datum;
} StringInfo;

typedef struct _PixelPacket {
  Quantum red;
  Quantum green;
  Quantum blue;
} PixelPacket;

typedef long MagickOffsetType;
typedef long ssize_t;
typedef unsigned long size_t;

typedef enum {
  UndefinedPixelTrait,
  DirectClass,
  PseudoClass
} StorageType;

typedef enum {
  JPEGCompression
} CompressionType;

typedef enum {
  sRGBColorspace
} ColorspaceType;

typedef enum {
  WriteBinaryBlobMode
} BlobMode;

typedef enum {
  TraceEvent
} LogEventType;

typedef enum {
  ImageError,
  ResourceLimitError
} ExceptionType;

typedef enum {
  SaveImageTag
} ProgressTag;

typedef struct {
  short top;
  short left;
  short bottom;
  short right;
} PICTRectangle;

typedef struct {
  unsigned short version;
  unsigned short pack_type;
  unsigned long pack_size;
  unsigned short pixel_type;
  unsigned short bits_per_pixel;
  unsigned short component_count;
  unsigned short component_size;
  unsigned long plane_bytes;
  unsigned long table;
  unsigned long reserved;
} PICTPixmap;

#define MagickCoreSignature 0x12345678
#define DefaultResolution 72.0
#define MagickPathExtent 4096
#define SEEK_SET 0

void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
void ResetMagickMemory(void *, int, size_t);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType SetImageProgress(Image *, ProgressTag, MagickOffsetType, size_t);
const Quantum *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
unsigned char GetPixelIndex(const Image *, const Quantum *);
unsigned char ScaleQuantumToChar(Quantum);
unsigned short ScaleQuantumToShort(Quantum);
size_t EncodeImage(Image *, const unsigned char *, size_t, unsigned char *);
void WriteBlob(Image *, size_t, const void *);
void WriteBlobByte(Image *, unsigned char);
void WriteBlobString(Image *, const char *);
void WriteBlobMSBShort(Image *, unsigned short);
void WriteBlobMSBLong(Image *, unsigned long);
MagickOffsetType TellBlob(Image *);
MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
const StringInfo *GetImageProfile(const Image *, const char *);
const void *GetStringInfoDatum(const StringInfo *);
size_t GetStringInfoLength(const StringInfo *);
void ThrowWriterException(ExceptionType, const char *);
void LogMagickEvent(LogEventType, const char *, const char *, ...);
void CopyMagickString(char *, const char *, size_t);
Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
ImageInfo *CloneImageInfo(const ImageInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
Image *DestroyImage(Image *);
unsigned char *ImageToBlob(const ImageInfo *, Image *, size_t *, ExceptionInfo *);
MagickBooleanType TransformImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
const char *GetMagickModule(void);
unsigned char GetPixelRed(const Image *, const Quantum *);
unsigned char GetPixelGreen(const Image *, const Quantum *);
unsigned char GetPixelBlue(const Image *, const Quantum *);
unsigned char GetPixelAlpha(const Image *, const Quantum *);
size_t GetPixelChannels(const Image *);