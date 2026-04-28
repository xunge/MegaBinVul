#include <stddef.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  ResourceLimitError
} ExceptionType;

typedef enum {
  RLECompression
} CompressionType;

typedef enum {
  PseudoClass
} ClassType;

typedef enum {
  GrayQuantum,
  AlphaQuantum,
  IndexQuantum,
  RedQuantum,
  GreenQuantum,
  BlueQuantum,
  BlackQuantum
} QuantumType;

typedef enum {
  CMYKColorspace
} ColorspaceType;

typedef enum {
  SaveImagesTag
} ProgressTag;

typedef struct _PSDInfo PSDInfo;
typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;

struct _ExceptionInfo {
  int placeholder;
};

struct _Image {
  size_t depth;
  size_t columns;
  CompressionType compression;
  MagickBooleanType matte;
  ClassType storage_class;
  ColorspaceType colorspace;
  ExceptionInfo exception;
};

void ThrowWriterException(ExceptionType, const char *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
MagickBooleanType IsGrayImage(Image *, ExceptionInfo *);
void WriteBlobMSBShort(Image *, short);
void WritePackbitsLength(const PSDInfo *, const ImageInfo *, Image *, Image *, unsigned char *, QuantumType);
void WriteOneChannel(const PSDInfo *, const ImageInfo *, Image *, Image *, unsigned char *, QuantumType, MagickBooleanType);
void SetImageProgress(Image *, ProgressTag, int, int);
MagickBooleanType NegateImage(Image *, MagickBooleanType);