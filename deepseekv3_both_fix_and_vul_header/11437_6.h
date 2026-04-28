#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
} ImageInfo;

typedef struct _ExceptionInfo {
    int dummy;
} ExceptionInfo;

#define MagickCoreSignature 0x12345678
#define MagickPathExtent 4096
#define MaxTextExtent 2048

#define TraceEvent 0
#define OptionWarning 0

char *ConstantString(const char *);
char *AcquireString(const char *);
char *DestroyString(char *);
char *ResizeQuantumMemory(void *, size_t, size_t);
int LocaleNCompare(const char *, const char *, size_t);
void *LogMagickEvent(int, const char *, const char *, ...);
void *GetMagickModule(void);
void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
char *GetMagickPropertyLetter(ImageInfo *, Image *, int, ExceptionInfo *);
void DisableMSCWarning(int);
void RestoreMSCWarning(void);
int FormatLocaleString(char *, size_t, const char *, ...);
void CopyMagickString(char *, const char *, size_t);

#define DisableMSCWarning(x) 
#define RestoreMSCWarning() 