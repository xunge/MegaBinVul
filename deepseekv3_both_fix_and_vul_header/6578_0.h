#include <stdlib.h>

typedef struct _Image Image;
typedef struct _DrawInfo DrawInfo;
typedef struct _ImageInfo ImageInfo;

typedef struct _MSLInfo {
    int number_groups;
    int n;
    Image **image;
    Image **attributes;
    DrawInfo **draw_info;
    ImageInfo **image_info;
} MSLInfo;

Image *DestroyImage(Image *);
DrawInfo *DestroyDrawInfo(DrawInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);