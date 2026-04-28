#include <ctype.h>
#include <stdlib.h>

typedef long long MagickOffsetType;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _Image {
    int filter;
} Image;

Image *ResizeImage(const Image *image, size_t width, size_t height, int filter, ExceptionInfo *exception);
Image *DestroyImageList(Image *images);
void AppendImageToList(Image **images, Image *image);