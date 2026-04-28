#include <stddef.h>
#include <sys/types.h>

typedef struct _Image Image;

typedef struct _ImageInfo {
    char *filename;
    char *magick;
    char *size;
} ImageInfo;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct {
    const void *blob;
    const char *name;
    const char *magick;
    size_t extent;
} PatternImageEntry;

extern PatternImageEntry PatternImageList[];

#define MaxTextExtent 4096
#define OptionError 1

ImageInfo *CloneImageInfo(const ImageInfo *);
Image *BlobToImage(ImageInfo *, const void *, size_t, ExceptionInfo *);
int LocaleCompare(const char *, const char *);
void CopyMagickString(char *, const char *, size_t);
void ThrowReaderException(int, const char *);
Image *AcquireImage(const ImageInfo *);
void TextureImage(Image *, Image *);
Image *DestroyImage(Image *);
ImageInfo *DestroyImageInfo(ImageInfo *);
Image *GetFirstImageInList(Image *);