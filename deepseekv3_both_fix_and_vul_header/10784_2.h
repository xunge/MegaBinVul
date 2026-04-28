#include <stddef.h>

#define CoderEvent 1
#define ResourceLimitError 1

typedef unsigned char png_byte;

typedef struct _Image Image;
typedef struct _StringInfo StringInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _PNGErrorInfo PNGErrorInfo;

typedef struct png_struct_def png_struct;
typedef struct png_unknown_chunk_t {
    png_byte name[5];
    png_byte *data;
    size_t size;
} png_unknown_chunk;
typedef png_unknown_chunk *png_unknown_chunkp;

struct _Image {
    char *filename;
    struct {
        size_t width;
        size_t height;
        size_t x;
        size_t y;
    } page;
};

struct _StringInfo {
    png_byte *datum;
};

struct _ExceptionInfo {
    int severity;
};

struct _PNGErrorInfo {
    ExceptionInfo *exception;
};

extern void LogMagickEvent(int, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern StringInfo *BlobToStringInfo(const void *, size_t);
extern png_byte *GetStringInfoDatum(StringInfo *);
extern void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
extern void SetImageProfile(Image *, const char *, StringInfo *, ExceptionInfo *);
extern void *png_get_user_chunk_ptr(png_struct *);
extern void *png_get_error_ptr(png_struct *);