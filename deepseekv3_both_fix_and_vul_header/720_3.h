#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MagickPathExtent 4096
#define MaxTextExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define WITH_CGRAPH 1

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    TraceEvent
} LogEventType;

typedef struct _Image Image;
typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char filename[MagickPathExtent];
    char magick[MagickPathExtent];
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _graph_t graph_t;
typedef struct _GVC_t GVC_t;
typedef struct _Agdisc_t Agdisc_t;

extern GVC_t *graphic_context;

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageInfoBlob(ImageInfo *, void *, size_t);
void CopyMagickString(char *, const char *, size_t);
int AcquireUniqueFilename(char *);
int FormatLocaleString(char *, size_t, const char *, ...);
FILE *GetBlobFileHandle(Image *);
graph_t *agread(FILE *, Agdisc_t *);
int RelinquishUniqueFileResource(const char *);
const char *GetImageOption(const ImageInfo *, const char *);
int gvLayout(GVC_t *, graph_t *, char *);
int gvRenderFilename(GVC_t *, graph_t *, char *, const char *);
int gvFreeLayout(GVC_t *, graph_t *);
int agclose(graph_t *);
Image *ReadImage(ImageInfo *, ExceptionInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(LogEventType, const char *, const char *, ...);
const char *GetMagickModule(void);