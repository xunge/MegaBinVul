#include <stddef.h>
#include <sys/types.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;

typedef struct _Image {
    char *filename;
} Image;

typedef struct _ExceptionInfo {
    // placeholder for exception info
} ExceptionInfo;

typedef struct _DDSInfo {
    unsigned int ddscaps1;
    unsigned int ddscaps2;
    unsigned int width;
    unsigned int height;
    unsigned int mipmapcount;
} DDSInfo;

#define DDSCAPS_MIPMAP 0x00400000
#define DDSCAPS_TEXTURE 0x00001000
#define DDSCAPS2_CUBEMAP 0x00000200

#define DIV2(x) ((x) >> 1)
#define MagickFalse 0
#define MagickTrue 1

enum {
    CorruptImageError
};

int EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void SeekBlob(Image *, MagickOffsetType, int);

#define SEEK_CUR 1