#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

#define NGIFLIB_MODE_FROM_MEM 1
#define NGIFLIB_MODE_FROM_FILE 2
#define NGIFLIB_MODE_INDEXED 4
#define SDL_SWSURFACE 0
#define SDL_SRCCOLORKEY 0

struct ngiflib_rgb {
    u8 r, g, b;
};

struct ngiflib_gif {
    int width;
    int height;
    int ncolors;
    struct ngiflib_rgb *palette;
    struct {
        struct ngiflib_rgb *palette;
        int localpalbits;
        struct {
            int gce_present;
            int delay_time;
        } gce;
    } *cur_img;
    union {
        FILE *file;
        struct {
            u8 *bytes;
            unsigned long count;
        } buffer;
    } input;
    int mode;
    struct {
        u8 *p8;
    } frbuff;
};

struct SDL_Surface {
    void *pixels;
    int pitch;
    struct {
        struct {
            struct ngiflib_rgb *colors;
        } *palette;
    } *format;
};

struct ngiflibSDL_image {
    struct SDL_Surface *surface;
    int delay_time;
};

struct ngiflibSDL_animation {
    int image_count;
    struct ngiflibSDL_image images[];
};

typedef struct SDL_Surface SDL_Surface;

void *ngiflib_malloc(size_t size);
void ngiflib_memset(void *ptr, int value, size_t num);
void ngiflib_memcpy(void *dest, const void *src, size_t n);
int LoadGif(struct ngiflib_gif *gif);
void GifDestroy(struct ngiflib_gif *gif);
SDL_Surface *SDL_CreateRGBSurface(int flags, int width, int height, int depth, 
                                int Rmask, int Gmask, int Bmask, int Amask);
void SDL_LockSurface(SDL_Surface *surface);
void SDL_UnlockSurface(SDL_Surface *surface);
const char *SDL_GetError(void);