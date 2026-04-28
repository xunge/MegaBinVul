#include <assert.h>
#include <string.h>

#define MagickExport
typedef unsigned int MagickStatusType;
typedef unsigned int MagickBooleanType;
typedef unsigned int Quantum;
typedef double MagickRealType;

#define MagickFalse 0
#define MagickTrue 1
#define MagickPathExtent 4096
#define TransparentAlpha 0
#define AllCompliance 0
#define ReadPixelMask 0
#define MagickCoreSignature 0xabacadabUL

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _ImageInfo ImageInfo;

typedef struct _DrawInfo {
    char *clip_mask;
    char *primitive;
    void *fill;
} DrawInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
    struct {
        MagickRealType alpha;
    } background_color;
} Image;

enum {
    TraceEvent,
    DrawEvent
};

extern void *GetMagickModule(void);
extern void LogMagickEvent(int, void *, const char *, ...);
extern int FormatLocaleString(char *, size_t, const char *, ...);
extern const char *GetImageArtifact(Image *, const char *);
extern Image *CloneImage(Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
extern int QueryColorCompliance(const char *, int, void *, ExceptionInfo *);
extern int SetImageBackgroundColor(Image *, ExceptionInfo *);
extern DrawInfo *CloneDrawInfo(ImageInfo *, const DrawInfo *);
extern int CloneString(char **, const char *);
extern MagickBooleanType NegateImage(Image *, MagickBooleanType, ExceptionInfo *);
extern int SetImageMask(Image *, int, Image *, ExceptionInfo *);
extern MagickBooleanType DrawImage(Image *, DrawInfo *, ExceptionInfo *);
extern Image *DestroyImage(Image *);
extern DrawInfo *DestroyDrawInfo(DrawInfo *);