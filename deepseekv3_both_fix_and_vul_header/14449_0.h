#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

typedef struct {
    int width;
    int height;
    int depth;
    uchar *pixels;
    int use;
} image_t;

#define BI_RLE4 2
#define BI_RLE8 1
#define Encryption 0

static unsigned short read_word(FILE *fp);
static unsigned int read_dword(FILE *fp);
static int read_long(FILE *fp);