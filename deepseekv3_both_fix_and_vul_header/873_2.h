#include <stdbool.h>
#include <stddef.h>

typedef struct _GifColorType {
    unsigned char Red, Green, Blue;
} GifColorType;

typedef struct _ColorMapObject {
    int ColorCount;
    GifColorType *Colors;
} ColorMapObject;

typedef struct _GifImageDesc {
    int Left, Top, Width, Height;
    ColorMapObject *ColorMap;
} GifImageDesc;

typedef struct _GifFileType {
    int SWidth, SHeight;
    ColorMapObject *SColorMap;
    GifImageDesc Image;
} GifFileType;

typedef unsigned char GifByteType;
#define GIF_ERROR (-1)
#define TRUE 1

typedef struct _VipsObjectClass {
    const char *nickname;
} VipsObjectClass;

typedef struct _VipsForeignLoadGif {
    GifFileType *file;
    bool has_colour;
} VipsForeignLoadGif;

#define VIPS_OBJECT_GET_CLASS(obj) ((VipsObjectClass*)0)

void vips_foreign_load_gif_error(VipsForeignLoadGif *gif);
int vips_foreign_load_gif_code_next(VipsForeignLoadGif *gif, GifByteType **extension);
void vips_error(const char *domain, const char *fmt, ...);
const char *_(const char *str);
int DGifGetImageDesc(GifFileType *file);