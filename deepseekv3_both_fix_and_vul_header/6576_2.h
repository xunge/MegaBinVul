#include <assert.h>
#include <stddef.h>

typedef unsigned int MagickBooleanType;
#define MagickFalse 0
#define MagickCoreSignature 0
#define MagickTrue 1

typedef struct _ExceptionInfo {
    int code;
    char *description;
    // other exception fields
} ExceptionInfo;

typedef struct _ImageInfo {
    unsigned int signature;
    // other image info fields
} ImageInfo;

typedef struct _Image {
    unsigned int signature;
    MagickBooleanType debug;
    char *filename;
    ExceptionInfo exception;
    // other image fields
} Image;

typedef enum {
    TraceEvent
} LogEventType;

Image *CloneImage(Image *image, size_t columns, size_t rows, MagickBooleanType sync, ExceptionInfo *exception);
MagickBooleanType ProcessMSLScript(const ImageInfo *image_info, Image **image, ExceptionInfo *exception);
Image *DestroyImage(Image *image);
void LogMagickEvent(LogEventType event, const char *module, const char *format, ...);
const char *GetMagickModule(void);