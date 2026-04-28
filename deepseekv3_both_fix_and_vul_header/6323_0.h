#include <stdint.h>

typedef struct Gif_Color Gif_Color;
typedef struct Gif_Stream Gif_Stream;
typedef struct Gif_Image Gif_Image;
typedef struct Gif_Colormap Gif_Colormap;

struct Gif_Color {
    int haspixel;
    uint32_t pixel;
};

struct Gif_Colormap {
    int ncol;
};

struct Gif_Image {
    Gif_Colormap *local;
};

struct Gif_Stream {
    Gif_Colormap *global;
    const char *landmark;
};

int Gif_FindColor(Gif_Colormap *gfcm, Gif_Color *color);
void lwarning(const char *landmark, const char *format, ...);