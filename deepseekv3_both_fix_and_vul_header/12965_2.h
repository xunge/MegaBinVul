#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxTextExtent 4096
#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define DefaultResolution 72.0
#define PSDensityGeometry "72x72"
#define PSPageGeometry "612x792"

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum
{
  CMYKColorspace
} ColorspaceType;

typedef enum
{
  FileOpenError,
  DelegateError
} ExceptionType;

typedef enum
{
  TraceEvent
} LogEventType;

typedef enum
{
  ReadBinaryBlobMode
} BlobMode;

typedef enum
{
  RhoValue,
  SigmaValue
} GeometryFlags;

typedef unsigned long MagickStatusType;
typedef long ssize_t;
typedef unsigned long size_t;

typedef struct _PointInfo
{
  double x, y;
} PointInfo;

typedef struct _RectangleInfo
{
  size_t width, height;
} RectangleInfo;

typedef struct _SegmentInfo
{
  double x1, y1, x2, y2;
} SegmentInfo;

typedef struct _GeometryInfo
{
  double rho, sigma;
} GeometryInfo;

typedef struct _ExceptionInfo
{
  unsigned long signature;
} ExceptionInfo;

typedef struct _DelegateInfo
{
  const char *(*commands)(void);
} DelegateInfo;

typedef struct _ImageInfo
{
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  char *page;
  MagickBooleanType monochrome;
  MagickBooleanType ping;
  char *magick;
  unsigned long number_scenes;
  unsigned long scene;
  char *scenes;
  MagickBooleanType antialias;
  MagickBooleanType verbose;
} ImageInfo;

typedef struct _Image
{
  double x_resolution;
  double y_resolution;
  ColorspaceType colorspace;
  char *magick;
  size_t magick_columns;
  size_t magick_rows;
  size_t columns;
  size_t rows;
  RectangleInfo page;
  char *filename;
  ExceptionInfo exception;
} Image;

Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
MagickBooleanType AcquireUniqueSymbolicLink(const char *, char *);
MagickStatusType ParseGeometry(const char *, GeometryInfo *);
int LocaleNCompare(const char *, const char *, size_t);
int ReadBlobByte(Image *);
int CloseBlob(Image *);
void ParseAbsoluteGeometry(const char *, RectangleInfo *);
DelegateInfo *GetDelegateInfo(const char *, char *, ExceptionInfo *);
char *AcquireString(const char *);
char *DestroyString(char *);
void FormatLocaleString(char *, size_t, const char *, ...);
void CopyMagickString(char *, const char *, size_t);
MagickBooleanType AcquireUniqueFilename(char *);
const char *GetDelegateCommands(const DelegateInfo *);
MagickBooleanType ExternalDelegateCommand(MagickBooleanType, MagickBooleanType, const char *, char *, ExceptionInfo *);
Image *ReadImage(ImageInfo *, ExceptionInfo *);
void RelinquishUniqueFileResource(const char *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void ThrowReaderException(ExceptionType, const char *);
int LocaleCompare(const char *, const char *);
Image *ConsolidateCMYKImages(Image *, ExceptionInfo *);
Image *SyncNextImageInList(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(LogEventType, const char *, const char *, const char *);
const char *GetMagickModule(void);
Image *DestroyImage(Image *);
ImageInfo *CloneImageInfo(const ImageInfo *);