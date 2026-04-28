#include <assert.h>
#include <stddef.h>
#include <string.h>

#define MagickExport
#define MagickPathExtent 4096

typedef long ssize_t;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedPixelTrait
} PixelTrait;

typedef enum {
  BasePath,
  HeadPath,
  ExtensionPath
} PathType;

typedef enum {
  TraceEvent
} LogEventType;

typedef struct _ImageInfo {
  MagickBooleanType debug;
  char *filename;
  char *unique;
  size_t number_scenes;
  size_t scene;
} ImageInfo;

typedef struct _Image {
  MagickBooleanType debug;
  char *filename;
  char *magick;
  char *magick_filename;
  size_t depth;
  size_t magick_rows;
  size_t magick_columns;
  size_t quality;
  size_t scene;
  PixelTrait alpha_trait;
  struct {
    double x;
    double y;
  } resolution;
  struct {
    size_t width;
    size_t height;
  } page;
  int colorspace;
  int compose;
  int compression;
  int interlace;
  int orientation;
  int units;
  double gamma;
} Image;

typedef struct _ExceptionInfo {
  int dummy;
} ExceptionInfo;

typedef struct _StringInfo {
  void *dummy;
} StringInfo;

extern const char *GetMagickModule(void);
extern const char *GetMagickCopyright(void);
extern const char *GetMagickVersion(size_t *);
extern size_t GetMagickPrecision(void);
extern void *GetImageArtifact(Image *, const char *);
extern void *GetImageOption(ImageInfo *, const char *);
extern const char *GetNextImageProfile(Image *);
extern const StringInfo *GetImageProfile(Image *, const char *);
extern void ResetImageProfileIterator(Image *);
extern const char *CommandOptionToMnemonic(const void *, ssize_t);
extern void GetPathComponent(const char *, PathType, char *);
extern void FormatLocaleString(char *, size_t, const char *, ...);
extern void ConcatenateMagickString(char *, const char *, size_t);
extern void CopyMagickString(char *, const char *, size_t);
extern void FormatMagickSize(size_t, MagickBooleanType, const char *, size_t, char *);
extern int LocaleCompare(const char *, const char *);
extern void LocaleLower(char *);
extern void LogMagickEvent(LogEventType, const char *, const char *, ...);
extern void WarnNoImageReturn(const char *, const char *);
extern void WarnNoImageInfoReturn(const char *, const char *);
extern const char *GetMagickPropertyLetter(ImageInfo *, Image *, char, ExceptionInfo *);
extern size_t GetBlobSize(Image *);
extern size_t GetImageListLength(Image *);
extern MagickBooleanType IsImageOpaque(Image *, ExceptionInfo *);
extern size_t GetImageDepth(Image *, ExceptionInfo *);
extern void GetImageEntropy(Image *, double *, ExceptionInfo *);
extern void GetImageKurtosis(Image *, double *, double *, ExceptionInfo *);
extern void GetImageRange(Image *, double *, double *, ExceptionInfo *);
extern void GetImageMean(Image *, double *, double *, ExceptionInfo *);
extern size_t IdentifyImageType(Image *, ExceptionInfo *);
extern void SetImageArtifact(Image *, const char *, const char *);
extern void SetImageOption(ImageInfo *, const char *, const char *);

extern const void *MagickColorspaceOptions;
extern const void *MagickComposeOptions;
extern const void *MagickCompressOptions;
extern const void *MagickInterlaceOptions;
extern const void *MagickBooleanOptions;
extern const void *MagickOrientationOptions;
extern const void *MagickResolutionOptions;
extern const void *MagickTypeOptions;