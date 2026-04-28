#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

#define NGIFLIB_MODE_INDEXED 1

struct ngiflib_rgb {
    u8 r;
    u8 g;
    u8 b;
};

struct ngiflib_gce {
    int gce_present;
    u8 disposal_method;
    u8 transparent_flag;
    u8 user_input_flag;
    unsigned short delay_time;
    u8 transparent_color;
};

struct ngiflib_img {
    struct ngiflib_gce gce;
    struct ngiflib_img *next;
    void *parent;
};

struct ngiflib_gif {
    char signature[7];
    unsigned short width;
    unsigned short height;
    u8 colorresolution;
    u8 sort_flag;
    u8 imgbits;
    u8 ncolors;
    u8 backgroundindex;
    u8 pixaspectratio;
    struct ngiflib_rgb *palette;
    int netscape_loop_count;
    int nimg;
    struct ngiflib_img *cur_img;
    struct ngiflib_img *first_img;
    FILE *log;
    int mode;
    union {
        void *p8;
        void *p32;
    } frbuff;
};

void *ngiflib_malloc(size_t size);
void ngiflib_memcpy(void *dest, const void *src, size_t n);
int ngiflib_memcmp(const void *s1, const void *s2, size_t n);
void ngiflib_memset(void *s, int c, size_t n);
u8 GetByte(struct ngiflib_gif *g);
void GetByteStr(struct ngiflib_gif *g, void *buf, size_t len);
unsigned short GetWord(struct ngiflib_gif *g);
void FillGifBackGround(struct ngiflib_gif *g);
int DecodeGifImg(struct ngiflib_img *img);