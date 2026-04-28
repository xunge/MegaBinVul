#include <assert.h>
#include <stddef.h>

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { TraceEvent } LogEventType;

typedef struct _ImageInfo {
    unsigned long signature;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
} Image;

typedef struct _ExceptionInfo {
} ExceptionInfo;

#define MagickCoreSignature 0x12345678UL

const char* GetMagickModule(void);
void* LogMagickEvent(LogEventType, const char*, const char*, ...);
Image* CloneImage(Image*, size_t, size_t, MagickBooleanType, ExceptionInfo*);
MagickBooleanType ProcessMSLScript(const ImageInfo*, Image**, ExceptionInfo*);