#include <stddef.h>
#include <stdio.h>

#define DIV2(x) ((x) >> 1)
#define MagickFalse 0
#define MagickTrue 1
#define DDSCAPS_MIPMAP (1 << 0)
#define DDSCAPS_TEXTURE (1 << 0)
#define DDSCAPS2_CUBEMAP (1 << 0)

typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef ptrdiff_t ssize_t;

typedef struct _ExceptionInfo {
    int dummy;
} ExceptionInfo;

typedef struct _DDSInfo {
    unsigned int ddscaps1;
    unsigned int ddscaps2;
    unsigned int width;
    unsigned int height;
    unsigned int mipmapcount;
} DDSInfo;

typedef struct _Image {
    char *filename;
} Image;

#define EOFBlob(image) feof(stdin)
#define ThrowFileException(exception, type, message, filename) 
#define SeekBlob(image, offset, whence) fseek(stdin, offset, whence)