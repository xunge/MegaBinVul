#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

#define NGIFLIB_MODE_FROM_FILE 0x01
#define NGIFLIB_MODE_INDEXED 0x02
#define SDL_SWSURFACE 0x00000000
#define SDL_SRCCOLORKEY 0x00001000

struct ngiflib_rgb {
    u8 r;
    u8 g;
    u8 b;
};

struct ngiflib_gif {
    struct {
        FILE* file;
        u8* bytes;
    } input;
    int mode;
    int width;
    int height;
    int ncolors;
    struct ngiflib_rgb* palette;
    struct {
        u8* p8;
    } frbuff;
    struct {
        struct ngiflib_rgb* palette;
        int localpalbits;
        struct {
            int gce_present;
            int delay_time;
        } gce;
    } *cur_img;
    FILE* log;
};

struct ngiflibSDL_image {
    void* surface;
    int delay_time;
};

struct ngiflibSDL_animation {
    int image_count;
    struct ngiflibSDL_image images[];
};

extern void* ngiflib_malloc(size_t size);
extern void ngiflib_memset(void* ptr, int value, size_t num);
extern void ngiflib_memcpy(void* dest, const void* src, size_t n);
extern int LoadGif(struct ngiflib_gif* gif);
extern void GifDestroy(struct ngiflib_gif* gif);

typedef struct {
    void* pixels;
    int pitch;
    struct {
        struct {
            struct ngiflib_rgb* colors;
        }* palette;
    }* format;
} SDL_Surface;

SDL_Surface* SDL_CreateRGBSurface(unsigned int flags, int width, int height, int depth,
                                 unsigned int Rmask, unsigned int Gmask, unsigned int Bmask, unsigned int Amask);
void SDL_LockSurface(SDL_Surface* surface);
void SDL_UnlockSurface(SDL_Surface* surface);