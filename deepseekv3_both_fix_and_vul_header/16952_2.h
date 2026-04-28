#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

typedef int MagickBooleanType;
typedef int MagickStatusType;
typedef int StorageType;
typedef int ExceptionType;
typedef int MagickSizeType;

#define WandExport

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char filename[4096];
} ImageInfo;

typedef struct _ExceptionInfo {
    ExceptionType severity;
} ExceptionInfo;

typedef struct _Image {
    // Placeholder for Image structure
} Image;

typedef struct _StreamInfo {
    // Placeholder for StreamInfo structure
} StreamInfo;

typedef struct _ImageStack {
    // Placeholder for ImageStack structure
} ImageStack;

#define MagickFalse 0
#define MagickTrue 1
#define MaxImageStackDepth 32
#define MagickCoreSignature 0xabacadab
#define MagickPathExtent 4096
#define ErrorException 1
#define OptionError 2
#define ResourceLimitError 3
#define TraceEvent 4

#define GetMagickModule() "MagickCore"
#define GetExceptionMessage(errno) strerror(errno)

enum {
    FireOptionFlag = 1
};

void DestroyImageStack(void);
StreamInfo *DestroyStreamInfo(StreamInfo *);
char *DestroyString(char *);
void *RelinquishMagickMemory(void *);
void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
void ListMagickVersion(FILE *);
MagickBooleanType StreamUsage(void);
void NewImageStack(void);
StreamInfo *AcquireStreamInfo(ImageInfo *, ExceptionInfo *);
void ReadCommandlLine(int, char ***);
MagickBooleanType ExpandFilenames(int *, char ***);
MagickBooleanType OpenStream(ImageInfo *, StreamInfo *, const char *, ExceptionInfo *);
void FireImageStack(MagickBooleanType, MagickBooleanType, MagickBooleanType);
void PushImageStack(void);
void PopImageStack(void);
MagickBooleanType IsCommandOption(const char *);
void CopyMagickString(char *, const char *, size_t);
Image *StreamImage(ImageInfo *, StreamInfo *, ExceptionInfo *);
void AppendImageStack(Image *);
ssize_t ParseChannelOption(const char *);
ssize_t ParseCommandOption(const void *, MagickBooleanType, const char *);
void SetLogEventMask(const char *);
const char *GetImageOption(ImageInfo *, const char *);
double StringToDouble(const char *, char **);
MagickBooleanType IsGeometry(const char *);
MagickBooleanType MogrifyImageInfo(ImageInfo *, int, const char **, ExceptionInfo *);
void SetStreamInfoMap(StreamInfo *, const char *);
void SetStreamInfoStorageType(StreamInfo *, StorageType);
void FinalizeImageSettings(ImageInfo *, Image *, MagickBooleanType);
int GetCommandOptionFlags(const void *, MagickBooleanType, const char *);
int LocaleCompare(const char *, const char *);
int LocaleNCompare(const char *, const char *, size_t);
void LogMagickEvent(int, const char *, const char *);

extern const void *MagickColorspaceOptions;
extern const void *MagickCompressOptions;
extern const void *MagickLogEventOptions;
extern const void *MagickInterlaceOptions;
extern const void *MagickInterpolateOptions;
extern const void *MagickResourceOptions;
extern const void *MagickListOptions;
extern const void *MagickStorageOptions;
extern const void *MagickVirtualPixelOptions;
extern const void *MagickCommandOptions;