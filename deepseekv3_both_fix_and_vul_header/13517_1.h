#include <assert.h>
#include <string.h>

typedef struct _Image {
    char filename[4096];
    char magick[4096];
    struct _Image *next;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    char filename[4096];
    char unique[4096];
    char magick[4096];
    unsigned int number_scenes;
    int verbose;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _DelegateInfo {
    const char *(*GetDelegateCommands)(const struct _DelegateInfo *);
} DelegateInfo;

typedef unsigned int MagickBooleanType;

#define MagickCoreSignature 0x12345678
#define MagickPathExtent 4096
#define MagickFalse 0
#define MagickTrue 1

enum {
    TraceEvent,
    DelegateError
};

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

extern int IsEventLogging(void);
extern void *LogMagickEvent(int, const char *, const char *, ...);
extern Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
extern MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
extern Image *DestroyImageList(Image *);
extern void CloseBlob(Image *);
extern ImageInfo *CloneImageInfo(const ImageInfo *);
extern const DelegateInfo *GetDelegateInfo(const char *, char *, ExceptionInfo *);
extern char *AcquireString(const char *);
extern int FormatLocaleString(char *, size_t, const char *, ...);
extern const char *GetImageOption(const ImageInfo *, const char *);
extern char *SanitizeDelegateString(const char *);
extern char *DestroyString(char *);
extern int ConcatenateMagickString(char *, const char *, size_t);
extern int LocaleNCompare(const char *, const char *, size_t);
extern const char *GetIntermediateFormat(const ImageInfo *);
extern void AcquireUniqueFilename(char *);
extern void AcquireUniqueSymbolicLink(const char *, char *);
extern const char *GetDelegateCommands(const DelegateInfo *);
extern int ExternalDelegateCommand(MagickBooleanType, int, const char *, char *, ExceptionInfo *);
extern Image *ReadImage(ImageInfo *, ExceptionInfo *);
extern void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
extern void RelinquishUniqueFileResource(const char *);
extern void CopyMagickString(char *, const char *, size_t);
extern ImageInfo *DestroyImageInfo(ImageInfo *);
extern const char *GetMagickModule(void);