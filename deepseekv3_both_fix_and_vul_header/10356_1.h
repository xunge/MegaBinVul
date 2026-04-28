#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>

#define DIV2(x) ((x) >> 1)
#define DDSCAPS_MIPMAP 0x00400000
#define DDSCAPS_TEXTURE 0x00001000
#define DDSCAPS2_CUBEMAP 0x00000200
#define CorruptImageError 1
#define SEEK_CUR 1

typedef long long MagickOffsetType;

typedef enum
{
  MagickFalse = 0,
  MagickTrue = 1
} MagickBooleanType;

typedef struct _Image
{
  const char *filename;
} Image;

typedef struct _DDSInfo
{
  size_t width;
  size_t height;
  size_t mipmapcount;
  unsigned int ddscaps1;
  unsigned int ddscaps2;
} DDSInfo;

typedef struct _ExceptionInfo ExceptionInfo;

int EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
int SeekBlob(Image *, MagickOffsetType, int);