#include <stdio.h>
#include <stddef.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef ptrdiff_t ssize_t;
typedef size_t size_t;

#define MagickFalse 0
#define MagickTrue 1
#define DIV2(x) ((x) >> 1)

#define DDSCAPS_MIPMAP 0x00400000
#define DDSCAPS_TEXTURE 0x00001000
#define DDSCAPS2_CUBEMAP 0x00000200

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
    char *description;
    char *filename;
} ExceptionInfo;

typedef struct _DDSInfo {
    size_t width;
    size_t height;
    size_t mipmapcount;
    unsigned int ddscaps1;
    unsigned int ddscaps2;
} DDSInfo;

typedef struct _Image {
    char *filename;
} Image;

#define EOFBlob(image) 0
#define ThrowFileException(exception, type, message, filename) 
#define SeekBlob(image, offset, whence) 0