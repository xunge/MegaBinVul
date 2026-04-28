#include <stddef.h>

typedef struct _ImageInfo {
    char filename[4096];
    char magick[4096];
} ImageInfo;

typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef unsigned int MagickBooleanType;
typedef signed long ssize_t;

#define MagickTrue 1
#define MagickFalse 0
#define MagickPathExtent 4096

ImageInfo *CloneImageInfo(const ImageInfo *);
void *CopyMagickString(void *, const void *, size_t);
Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
unsigned char *ImageToBlob(const ImageInfo *, Image *, size_t *, ExceptionInfo *);
Image *DestroyImage(Image *);
ImageInfo *DestroyImageInfo(ImageInfo *);
ssize_t WriteBlob(Image *, size_t, const unsigned char *);
void *RelinquishMagickMemory(void *);