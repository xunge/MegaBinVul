#include <stddef.h>
#include <string.h>
#include <sys/types.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

struct _ImageInfo {
    char *filename;
    char *magick;
};

struct _MagickImageInfo {
    const char *name;
    const char *magick;
    const void *blob;
    size_t extent;
};

enum {
    OptionError
};

extern struct _MagickImageInfo MagickImageList[];
extern size_t MaxTextExtent;

static int LocaleCompare(const char *, const char *);
static ImageInfo *CloneImageInfo(const ImageInfo *);
static void CopyMagickString(char *, const char *, size_t);
static void ThrowReaderException(unsigned int, const char *);
static Image *BlobToImage(ImageInfo *, const void *, size_t, ExceptionInfo *);
static ImageInfo *DestroyImageInfo(ImageInfo *);
static Image *GetFirstImageInList(Image *);