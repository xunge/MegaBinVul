#include <stddef.h>
#include <sys/types.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  PseudoClass,
  DirectClass
} ClassType;

typedef enum {
  UndefinedCompression,
  RLECompression
} CompressionType;

typedef enum {
  UndefinedColorspace,
  RGBColorspace,
  CMYKColorspace,
  GRAYColorspace
} ColorspaceType;

typedef enum {
  UndefinedQuantum,
  AlphaQuantum,
  IndexQuantum,
  GrayQuantum,
  RedQuantum,
  GreenQuantum,
  BlueQuantum,
  BlackQuantum
} QuantumType;

typedef enum {
  UndefinedRegistryType,
  ImageRegistryType
} RegistryType;

typedef struct _ExceptionInfo {
  int severity;
  char *reason;
  char *description;
} ExceptionInfo;

typedef struct _ImageInfo {
  void *dummy;
} ImageInfo;

typedef struct _PSDInfo {
  int version;
} PSDInfo;

typedef struct _Image {
  CompressionType compression;
  ClassType storage_class;
  ColorspaceType colorspace;
  MagickBooleanType matte;
  size_t rows;
  ExceptionInfo exception;
} Image;

typedef long long MagickOffsetType;

unsigned char *AcquireCompactPixels(Image *);
ssize_t WriteCompressionStart(const PSDInfo *, Image *, Image *, size_t);
ssize_t WritePSDChannel(const PSDInfo *, const ImageInfo *, Image *, Image *, QuantumType, unsigned char *, MagickOffsetType, MagickBooleanType);
ssize_t WritePSDSize(const PSDInfo *, Image *, size_t, MagickOffsetType);
MagickBooleanType IsGrayImage(Image *, ExceptionInfo *);
MagickBooleanType NegateImage(Image *, MagickBooleanType);
const char *GetImageArtifact(Image *, const char *);
void *GetImageRegistry(RegistryType, const char *, ExceptionInfo *);
MagickOffsetType TellBlob(Image *);
void *RelinquishMagickMemory(void *);