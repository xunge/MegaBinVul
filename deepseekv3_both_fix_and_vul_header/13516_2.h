#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int MagickBooleanType;
typedef unsigned long size_t;
typedef long ssize_t;

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 1
#define CoderEvent 2
#define DelegateError 3

#define magick_fallthrough

typedef struct _ImageInfo {
    unsigned long signature;
    FILE *file;
    char magick[1];
    char *unique;
    char filename[MagickPathExtent];
    MagickBooleanType verbose;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    char filename[MagickPathExtent];
    size_t scene;
    double delay;
    double ticks_per_second;
    MagickBooleanType debug;
    size_t iterations;
    struct _Image *next;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _DelegateInfo {
    const char *commands;
} DelegateInfo;

#define MagickMax(a,b) ((a) > (b) ? (a) : (b))

extern int IsEventLogging(void);
extern const char *GetMagickModule(void);
extern MagickBooleanType LogMagickEvent(int,const char *,const char *,...);
extern Image *CloneImageList(Image *,ExceptionInfo *);
extern int AcquireUniqueFileResource(char *);
extern int close(int);
extern char *FormatLocaleString(char *,size_t,const char *,...);
extern ImageInfo *CloneImageInfo(const ImageInfo *);
extern const char *GetIntermediateFormat(const ImageInfo *);
extern Image *GetNextImageInList(Image *);
extern Image *CloneImage(Image *,size_t,size_t,MagickBooleanType,ExceptionInfo *);
extern MagickBooleanType WriteImage(ImageInfo *,Image *,ExceptionInfo *);
extern Image *DestroyImage(Image *);
extern unsigned char *FileToBlob(const char *,size_t,size_t *,ExceptionInfo *);
extern MagickBooleanType BlobToFile(const char *,const unsigned char *,size_t,ExceptionInfo *);
extern void *RelinquishMagickMemory(void *);
extern const DelegateInfo *GetDelegateInfo(char *,const char *,ExceptionInfo *);
extern char *AcquireString(const char *);
extern const char *GetImageOption(const ImageInfo *,const char *);
extern char *SanitizeDelegateString(const char *);
extern char *DestroyString(char *);
extern void ConcatenateMagickString(char *,const char *,size_t);
extern void AcquireUniqueFilename(char *);
extern const char *GetDelegateCommands(const DelegateInfo *);
extern int ExternalDelegateCommand(MagickBooleanType,MagickBooleanType,const char *,char *,ExceptionInfo *);
extern MagickBooleanType CopyDelegateFile(const char *,const char *);
extern void RelinquishUniqueFileResource(const char *);
extern void *ThrowMagickException(ExceptionInfo *,const char *,int,const char *,const char *,...);
extern ImageInfo *DestroyImageInfo(ImageInfo *);
extern void CopyMagickString(char *,const char *,size_t);
extern Image *DestroyImageList(Image *);