#include <stdio.h>
#include <stdlib.h>

#define IMAGE_MAX_DIM 16384
#define BI_RLE4 2
#define BI_RLE8 1

typedef unsigned char uchar;

typedef struct {
    int width;
    int height;
    int depth;
    uchar *pixels;
    int use;
} image_t;

extern int Encryption;

static unsigned short read_word(FILE *fp);
static unsigned int read_dword(FILE *fp);
static int read_long(FILE *fp);