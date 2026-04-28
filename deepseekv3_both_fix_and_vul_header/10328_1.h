#include <stdio.h>
#include <stddef.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef ptrdiff_t ssize_t;
typedef size_t size_t;

#define DDSCAPS_MIPMAP 0x00400000
#define DDSCAPS_TEXTURE 0x00001000
#define DDSCAPS2_CUBEMAP 0x00000200
#define CorruptImageError 1
#define SEEK_CUR 1

#define DIV2(x) ((x) >> 1)
#define MagickFalse 0
#define MagickTrue 1

typedef struct _Image {
    const char *filename;
} Image;

typedef struct _DDSInfo {
    unsigned int ddscaps1;
    unsigned int ddscaps2;
    unsigned int width;
    unsigned int height;
    unsigned int mipmapcount;
} DDSInfo;

typedef struct _ExceptionInfo ExceptionInfo;

MagickBooleanType EOFBlob(Image *image);
void ThrowFileException(ExceptionInfo *exception, int error, const char *reason, const char *filename);
MagickOffsetType SeekBlob(Image *image, MagickOffsetType offset, int whence);