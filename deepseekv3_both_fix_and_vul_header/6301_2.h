#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

#define NGIFLIB_MODE_FROM_MEM 0x01
#define NGIFLIB_MODE_FROM_FILE 0x02
#define NGIFLIB_MODE_INDEXED 0x10
#define NGIFLIB_MODE_TRUE_COLOR 0x20

#define SDL_SWSURFACE 0x00000000
#define SDL_SRCCOLORKEY 0x00001000

struct ngiflib_gif {
    int width;
    int height;
    int ncolors;
    int mode;
    struct {
        FILE *file;
        u8 *bytes;
    } input;
    struct {
        u8 *p8;
    } frbuff;
    struct {
        struct {
            int transparent_flag;
            u8 transparent_color;
        } gce;
    } *cur_img;
    struct {
        u8 r;
        u8 g;
        u8 b;
    } *palette;
};

typedef struct {
    void *pixels;
    int pitch;
    struct {
        struct {
            struct {
                u8 r;
                u8 g;
                u8 b;
            } *colors;
        } *palette;
    } *format;
} SDL_Surface;

void *ngiflib_malloc(size_t size);
void ngiflib_memset(void *ptr, int value, size_t num);
void ngiflib_memcpy(void *dest, const void *src, size_t n);
int LoadGif(struct ngiflib_gif *gif);
void GifDestroy(struct ngiflib_gif *gif);
SDL_Surface *SDL_CreateRGBSurface(unsigned int flags, int width, int height, int depth, unsigned int Rmask, unsigned int Gmask, unsigned int Bmask, unsigned int Amask);
void SDL_LockSurface(SDL_Surface *surface);
void SDL_UnlockSurface(SDL_Surface *surface);
void SDL_SetColorKey(SDL_Surface *surface, int flag, u8 key);