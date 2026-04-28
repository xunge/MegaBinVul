#include <stdio.h>
#include <stddef.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef ptrdiff_t ssize_t;
typedef size_t size_t;

#define MagickFalse 0
#define MagickTrue 1
#define DDSCAPS_MIPMAP (1 << 0)
#define DDSCAPS_TEXTURE (1 << 0)
#define DDSCAPS2_CUBEMAP (1 << 0)
#define CorruptImageError 1
#define SEEK_CUR 1

#define DIV2(x) ((x) >> 1)

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _DDSInfo DDSInfo;

struct _Image {
    char *filename;
};

struct _DDSInfo {
    size_t width;
    size_t height;
    size_t mipmapcount;
    unsigned int ddscaps1;
    unsigned int ddscaps2;
};

int EOFBlob(Image *);
int SeekBlob(Image *, MagickOffsetType, int);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);