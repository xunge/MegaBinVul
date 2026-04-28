#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned char Quantum;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedIntent,
  SaturationIntent,
  RelativeIntent,
  PerceptualIntent,
  AbsoluteIntent
} RenderingIntent;

typedef enum {
  UndefinedPixelTrait
} PixelTrait;

typedef enum {
  UndefinedResolution,
  PixelsPerInchResolution,
  PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
  UndefinedCompression,
  NoCompression,
  RLECompression
} CompressionType;

typedef enum {
  BI_RGB,
  BI_RLE8,
  BI_BITFIELDS
} BMPCompression;

typedef enum {
  DirectClass,
  PseudoClass
} ClassType;

typedef enum {
  TraceEvent,
  CoderEvent
} LogEventType;

typedef enum {
  WriteBinaryBlobMode
} BlobMode;

typedef struct _ColorPacket {
  Quantum red;
  Quantum green;
  Quantum blue;
} ColorPacket;

typedef struct _Image {
  unsigned long signature;
  ClassType storage_class;
  ssize_t colors;
  ColorPacket *colormap;
  PixelTrait alpha_trait;
  ssize_t columns;
  ssize_t rows;
  ResolutionType units;
  struct {
    double x;
    double y;
  } resolution;
  struct {
    struct {
      double x;
      double y;
    } red_primary;
    struct {
      double x;
      double y;
    } green_primary;
    struct {
      double x;
      double y;
    } blue_primary;
  } chromaticity;
  RenderingIntent rendering_intent;
  double gamma;
  unsigned long depth;
  struct _Image *previous;
  const char *filename;
  MagickBooleanType debug;
} Image;

typedef struct {
  unsigned long signature;
  const char *magick;
  CompressionType compression;
  MagickBooleanType adjoin;
  const char *filename;
  MagickBooleanType debug;
} ImageInfo;

typedef struct {
  unsigned long signature;
} ExceptionInfo;

typedef struct {
} StringInfo;

typedef struct {
} MemoryInfo;

typedef struct {
  unsigned long file_size;
  unsigned long ba_offset;
  unsigned long offset_bits;
  unsigned long size;
  unsigned long width;
  unsigned long height;
  unsigned short planes;
  unsigned short bits_per_pixel;
  unsigned long compression;
  unsigned long image_size;
  unsigned long x_pixels;
  unsigned long y_pixels;
  unsigned long number_colors;
  unsigned long colors_important;
  struct {
    float x;
    float y;
    float z;
  } gamma_scale;
} BMPInfo;

typedef long MagickOffsetType;
typedef unsigned long size_t;

#define MagickCoreSignature 0xabacadabUL
#define LCS_GM_BUSINESS 1
#define LCS_GM_GRAPHICS 2
#define LCS_GM_IMAGES 4
#define LCS_GM_ABS_COLORIMETRIC 8
#define sRGBColorspace 1
#define SaveImageTag 1
#define SaveImagesTag 2
#define ImageError "ImageError"
#define ResourceLimitError "ResourceLimitError"

static void *AcquireQuantumMemory(size_t count, size_t quantum);
static void *AcquireVirtualMemory(size_t count, size_t quantum);
static void *GetVirtualMemoryBlob(MemoryInfo *);
static const Quantum *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static void *RelinquishMagickMemory(void *);
static void *RelinquishVirtualMemory(MemoryInfo *);
static void LogMagickEvent(LogEventType, const char *, const char *, ...);
static void ResetMagickMemory(void *, int, size_t);
static void ThrowWriterException(const char *, const char *);
static const char *GetImageOption(const ImageInfo *, const char *);
static const char *GetMagickModule(void);
static int CloseBlob(Image *);
static int IsStringTrue(const char *);
static int LocaleCompare(const char *, const char *);
static int OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
static int SetImageProgress(Image *, int, MagickOffsetType, MagickOffsetType);
static int SetImageStorageClass(Image *, ClassType, ExceptionInfo *);
static int TransformImageColorspace(Image *, int, ExceptionInfo *);
static int WriteBlob(Image *, size_t, const unsigned char *);
static int WriteBlobLSBLong(Image *, unsigned long);
static int WriteBlobLSBSignedLong(Image *, signed int);
static int WriteBlobLSBSignedShort(Image *, signed short);
static int WriteBlobLSBShort(Image *, unsigned short);
static size_t EncodeImage(Image *, size_t, unsigned char *, unsigned char *);
static unsigned char ScaleQuantumToChar(Quantum);
static StringInfo *GetImageProfile(const Image *, const char *);
static unsigned char GetPixelAlpha(const Image *, const Quantum *);
static unsigned char GetPixelBlue(const Image *, const Quantum *);
static unsigned char GetPixelGreen(const Image *, const Quantum *);
static unsigned char GetPixelIndex(const Image *, const Quantum *);
static unsigned char GetPixelRed(const Image *, const Quantum *);
static Quantum ClampToQuantum(Quantum);
static Image *GetNextImageInList(Image *);
static Image *SyncNextImageInList(Image *);
static size_t GetImageListLength(Image *);
static ssize_t GetPixelChannels(const Image *);
static ssize_t MagickMin(ssize_t, ssize_t);