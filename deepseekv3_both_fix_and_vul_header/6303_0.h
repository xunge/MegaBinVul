#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ngiflib_gif {
    FILE *log;
    FILE *input_file;
    union {
        FILE *file;
        unsigned char *bytes;
    } input;
    int mode;
    struct ngiflib_img *cur_img;
    int nimg;
    int width;
    int height;
    union {
        unsigned char *p8;
        unsigned int *p32;
    } frbuff;
};

struct ngiflib_img {
    int localpalbits;
    struct {
        unsigned char r;
        unsigned char g;
        unsigned char b;
    } *palette;
};

typedef unsigned char u8;
typedef unsigned int u32;

#define NGIFLIB_MODE_FROM_MEM 1
#define NGIFLIB_MODE_FROM_FILE 2
#define NGIFLIB_MODE_INDEXED 4
#define NGIFLIB_MODE_TRUE_COLOR 8

FILE *fgif;
FILE *ftga;

int LoadGif(struct ngiflib_gif *gif);
void GifDestroy(struct ngiflib_gif *gif);