#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define DefaultResolution 72.0
#define CMYKColorspace 1
#define PSDensityGeometry "72x72"
#define PSPageGeometry "612x792"
#define DelegateError 1
#define TraceEvent 1
#define ReadBinaryBlobMode 0
#define FileOpenError 1

typedef unsigned int MagickBooleanType;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
} RectangleInfo;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

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
    unsigned long signature;
    struct {
        double x;
        double y;
    } resolution;
    int colorspace;
    char *magick;
    size_t magick_columns;
    size_t magick_rows;
    size_t columns;
    size_t rows;
    char *filename;
    RectangleInfo page;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    char *page;
    MagickBooleanType monochrome;
    MagickBooleanType ping;
    unsigned long number_scenes;
    unsigned long scene;
    char *scenes;
    char *magick;
    MagickBooleanType antialias;
    MagickBooleanType verbose;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _DelegateInfo {
    const char *commands;
} DelegateInfo;

typedef enum {
    RhoValue = 0x01,
    SigmaValue = 0x02
} MagickStatusType;

typedef long ssize_t;
typedef size_t size_t;

extern Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
extern MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
extern Image *DestroyImageList(Image *);
extern Image *DestroyImage(Image *);
extern MagickBooleanType AcquireUniqueSymbolicLink(const char *, char *);
extern void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
extern int LogMagickEvent(int, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern MagickStatusType ParseGeometry(const char *, GeometryInfo *);
extern int ReadBlobByte(Image *);
extern int LocaleNCompare(const char *, const char *, size_t);
extern int LocaleCompare(const char *, const char *);
extern int sscanf(const char *, const char *, ...);
extern double floor(double);
extern MagickBooleanType CloseBlob(Image *);
extern void ParseAbsoluteGeometry(const char *, RectangleInfo *);
extern int FormatLocaleString(char *, size_t, const char *, ...);
extern const DelegateInfo *GetDelegateInfo(const char *, char *, ExceptionInfo *);
extern char *AcquireString(const char *);
extern char *DestroyString(char *);
extern const char *GetDelegateCommands(const DelegateInfo *);
extern int ExternalDelegateCommand(MagickBooleanType, int, const char *, char *, ExceptionInfo *);
extern Image *ReadImage(ImageInfo *, ExceptionInfo *);
extern void RelinquishUniqueFileResource(const char *);
extern void AcquireUniqueFilename(char *);
extern ImageInfo *CloneImageInfo(const ImageInfo *);
extern ImageInfo *DestroyImageInfo(ImageInfo *);
extern void ThrowReaderException(int, const char *);
extern Image *ConsolidateCMYKImages(Image *, ExceptionInfo *);
extern Image *SyncNextImageInList(Image *);
extern Image *GetFirstImageInList(Image *);
extern void CopyMagickString(char *, const char *, size_t);