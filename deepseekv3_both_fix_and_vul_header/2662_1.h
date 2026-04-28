#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  LSBEndian,
  MSBEndian
} EndianType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  TraceEvent
} LogEventType;

typedef enum {
  CMYKColorspace,
  GRAYColorspace,
  RGBColorspace,
  sRGBColorspace
} ColorspaceType;

typedef enum {
  PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
  VIPSBandFormatUCHAR,
  VIPSBandFormatCHAR,
  VIPSBandFormatUSHORT,
  VIPSBandFormatSHORT,
  VIPSBandFormatUINT,
  VIPSBandFormatINT,
  VIPSBandFormatFLOAT,
  VIPSBandFormatDOUBLE,
  VIPSBandFormatCOMPLEX,
  VIPSBandFormatDPCOMPLEX,
  VIPSBandFormatNOTSET
} VIPSBandFormat;

typedef enum {
  VIPSCodingNONE
} VIPSCoding;

typedef enum {
  VIPSTypeB_W,
  VIPSTypeCMYK,
  VIPSTypeFOURIER,
  VIPSTypeGREY16,
  VIPSTypeHISTOGRAM,
  VIPSTypeLAB,
  VIPSTypeLABS,
  VIPSTypeLABQ,
  VIPSTypeLCH,
  VIPSTypeMULTIBAND,
  VIPSTypeRGB,
  VIPSTypeRGB16,
  VIPSTypesRGB,
  VIPSTypeUCS,
  VIPSTypeXYZ,
  VIPSTypeYXY
} VIPSType;

typedef enum {
  CorruptImageError,
  CoderError
} ErrorType;

typedef struct _ImageInfo {
  unsigned long signature;
  MagickBooleanType debug;
  const char *filename;
  MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
  size_t columns;
  size_t rows;
  unsigned int depth;
  MagickBooleanType matte;
  EndianType endian;
  ColorspaceType colorspace;
  ResolutionType units;
  double x_resolution;
  double y_resolution;
  struct _ExceptionInfo exception;
} Image;

#define MagickSignature 0xabacadabUL
#define MaxTextExtent 2048
#define VIPS_MAGIC_LSB 0x01
#define VIPS_MAGIC_MSB 0x02

Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned int ReadBlobLSBLong(Image *);
unsigned int ReadBlobLong(Image *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
void InheritException(ExceptionInfo *, ExceptionInfo *);
float ReadBlobFloat(Image *);
long long ReadBlobLongLong(Image *);
MagickBooleanType IsSupportedCombination(VIPSBandFormat, VIPSType);
MagickBooleanType ReadVIPSPixelsNONE(Image *, VIPSBandFormat, VIPSType, unsigned int, ExceptionInfo *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
char *ConstantString(const char *);
void ConcatenateString(char **, const char *);
void SetImageProperty(Image *, const char *, const char *);
MagickBooleanType CloseBlob(Image *);
void ThrowReaderException(ErrorType, const char *);
void LogMagickEvent(LogEventType, const char *, const char *, ...);
const char *GetMagickModule(void);
void SetImageColorspace(Image *, ColorspaceType);