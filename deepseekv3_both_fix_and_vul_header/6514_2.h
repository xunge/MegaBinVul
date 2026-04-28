#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef struct png_struct_def png_struct;
typedef struct png_text_struct {
    char *text;
    size_t text_length;
    char *key;
} png_text;
typedef png_text* png_textp;
typedef char* png_charp;
typedef unsigned long png_uint_32;

typedef struct _Image Image;
typedef struct _ImageInfo {
    int verbose;
} ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _StringInfo StringInfo;

typedef enum {
    CoderEvent
} LogEventType;

typedef struct _MagickModule MagickModule;

StringInfo *BlobToStringInfo(const void *data, size_t length);
unsigned char *GetStringInfoDatum(StringInfo *string_info);
StringInfo *DestroyStringInfo(StringInfo *string_info);
void LogMagickEvent(LogEventType event, const MagickModule *module, const char *format, ...);
long StringToLong(const char *str);
MagickBooleanType SetImageProfile(Image *image, const char *name, StringInfo *profile, ExceptionInfo *exception);
const MagickModule *GetMagickModule(void);
void png_warning(png_struct *ping, const char *message);