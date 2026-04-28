#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;

#define DDSCAPS_MIPMAP 0x00400000
#define DDSCAPS_TEXTURE 0x00001000
#define DDSCAPS2_CUBEMAP 0x00000200
#define CorruptImageError 1
#define SEEK_CUR 1

#define DIV2(x) ((x) >> 1)
#define MagickFalse 0
#define MagickTrue 1

typedef struct _Image {
    char *filename;
} Image;

typedef struct _DDSInfo {
    unsigned int ddscaps1;
    unsigned int ddscaps2;
    unsigned int width;
    unsigned int height;
    unsigned int mipmapcount;
} DDSInfo;

typedef struct _ExceptionInfo ExceptionInfo;

MagickBooleanType EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
MagickBooleanType SeekBlob(Image *, MagickOffsetType, int);