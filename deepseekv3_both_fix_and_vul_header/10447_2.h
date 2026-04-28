#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPORT
#define Z_OK 0

typedef unsigned int u32;

struct png_header {
    unsigned width;
    unsigned height;
    int bpp;
    int mode;
};

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} COL;

int uncompress(unsigned char *dest, unsigned long *destLen, 
               const unsigned char *source, unsigned long sourceLen);

int png_read_header(FILE *fi, struct png_header *header);
int png_read_chunk(char *tagid, int *len, unsigned char **data, FILE *fi);
void applyfilter1(int mode, unsigned char *src, unsigned char *old, unsigned char *dest, int width);
void applyfilter2(int mode, unsigned char *src, unsigned char *old, unsigned char *dest, int width);
void applyfilter3(int mode, unsigned char *src, unsigned char *old, unsigned char *dest, int width);
void png_inverse_filter_32(int mode, unsigned char *src, unsigned char *old, unsigned char *dest, int width);