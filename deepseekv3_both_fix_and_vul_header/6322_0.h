#include <stdint.h>

typedef struct Gt_Frame Gt_Frame;
typedef struct Gif_Stream Gif_Stream;
typedef struct Gif_Image Gif_Image;
typedef struct Gif_Colormap Gif_Colormap;
typedef struct Gif_Color Gif_Color;

struct Gif_Color {
    uint8_t haspixel;
};

struct Gif_Colormap {
    int ncol;
    Gif_Color* col;
};

struct Gif_Image {
    int transparent;
    int disposal;
    int left;
    int top;
    int width;
    int height;
};

struct Gif_Stream {
    int screen_width;
    int screen_height;
    int background;
    Gif_Colormap* global;
};

struct Gt_Frame {
    Gif_Stream* stream;
    Gif_Image* image;
    struct {
        int haspixel;
    } transparent;
    int disposal;
};

#define GIF_DISPOSAL_BACKGROUND 2