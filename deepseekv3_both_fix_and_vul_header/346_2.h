#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define DefaultResolution 72.0
#define PSDensityGeometry "72x72"
#define PSPageGeometry "612x792"
#define MagickEpsilon 1.0e-10
#define MagickSizeType size_t

typedef enum {
    CMYKColorspace,
    sRGBColorspace
} ColorspaceType;

typedef enum {
    TraceEvent,
    OptionError,
    DelegateError,
    CorruptImageError,
    FileOpenError
} ExceptionType;

typedef enum {
    NoValue,
    SigmaValue
} GeometryFlags;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef int MagickBooleanType;
typedef unsigned long MagickStatusType;
typedef long ssize_t;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
    double x;
    double y;
} RectangleInfo;

typedef struct _SegmentInfo {
    double x1;
    double y1;
    double x2;
    double y2;
} SegmentInfo;

typedef struct _GeometryInfo {
    double rho;
    double sigma;
} GeometryInfo;

typedef struct _Image {
    char filename[MagickPathExtent];
    char magick[MagickPathExtent];
    size_t magick_columns;
    size_t magick_rows;
    RectangleInfo page;
    PointInfo resolution;
    unsigned long signature;
    void *blob;
    size_t length;
    unsigned long scene;
} Image;

typedef struct _ImageInfo {
    char filename[MagickPathExtent];
    char *density;
    char *page;
    ColorspaceType colorspace;
    MagickBooleanType debug;
    MagickBooleanType monochrome;
    unsigned long signature;
    unsigned long number_scenes;
    unsigned long scene;
    char *scenes;
    char magick[MagickPathExtent];
    MagickBooleanType antialias;
    MagickBooleanType verbose;
    void *blob;
    size_t length;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _DelegateInfo {
    const char *commands;
} DelegateInfo;

typedef struct _StringInfo {
    unsigned char *datum;
    size_t length;
} StringInfo;

static Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
static void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
static MagickBooleanType AcquireUniqueSymbolicLink(const char *, char *);
static void LogMagickEvent(int, const char *, const char *, ...);
static int ReadBlobByte(Image *);
static int LocaleNCompare(const char *, const char *, size_t);
static int GlobExpression(const char *, const char *, MagickBooleanType);
static char *ConstantString(const char *);
static char *SubstituteString(char **, const char *, const char *);
static void StripString(char *);
static MagickStatusType ParseGeometry(const char *, GeometryInfo *);
static MagickStatusType ParseMetaGeometry(const char *, double *, double *, size_t *, size_t *);
static MagickStatusType ParseAbsoluteGeometry(const char *, RectangleInfo *);
static void FormatLocaleString(char *, size_t, const char *, ...);
static void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
static const DelegateInfo *GetDelegateInfo(const char *, char *, ExceptionInfo *);
static char *AcquireString(const char *);
static char *DestroyString(char *);
static void ConcatenateMagickString(char *, const char *, size_t);
static ImageInfo *CloneImageInfo(const ImageInfo *);
static char *GetImageOption(const ImageInfo *, const char *);
static int IsStringTrue(const char *);
static void CopyMagickString(char *, const char *, size_t);
static char *GetPageGeometry(const char *);
static int AcquireUniqueFileResource(char *);
static void RelinquishUniqueFileResource(const char *);
static const char *GetDelegateCommands(const DelegateInfo *);
static MagickBooleanType InvokePostscriptDelegate(MagickBooleanType, const char *, char *, ExceptionInfo *);
static void InterpretImageFilename(const ImageInfo *, Image *, const char *, int, char *, ExceptionInfo *);
static MagickBooleanType IsPostscriptRendered(const char *);
static Image *ReadImage(const ImageInfo *, ExceptionInfo *);
static void AppendImageToList(Image **, Image *);
static void ThrowMagickException(ExceptionInfo *, const char *, ExceptionType, const char *, const char *, ...);
static Image *ConsolidateCMYKImages(Image *, ExceptionInfo *);
static int SeekBlob(Image *, long, int);
static int CloseBlob(Image *);
static Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
static void PrependImageToList(Image **, Image *);
static Image *SyncNextImageInList(Image *);
static Image *GetFirstImageInList(Image *);
static Image *GetNextImageInList(Image *);
static void CloneImageProfiles(Image *, const Image *);
static void CloneImageProperties(Image *, const Image *);
static StringInfo *AcquireStringInfo(size_t);
static unsigned char *GetStringInfoDatum(StringInfo *);
static void SetStringInfoLength(StringInfo *, size_t);
static size_t GetStringInfoLength(StringInfo *);
static StringInfo *DestroyStringInfo(StringInfo *);
static void SetImageProfile(Image *, const char *, StringInfo *, ExceptionInfo *);
static int ProfileInteger(Image *, short int *);
static StringInfo *BlobToStringInfo(const void *, size_t);
static size_t GetBlobSize(Image *);
static StringInfo *StringToStringInfo(const char *);
static int IssRGBCompatibleColorspace(ColorspaceType);
static const char *GetMagickModule(void);
static Image *DestroyImage(Image *);
static ImageInfo *DestroyImageInfo(ImageInfo *);
static void ThrowReaderException(ExceptionType, const char *);
static int AcquireUniqueFilename(char *);
static int LocaleCompare(const char *, const char *);