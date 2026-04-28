#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

struct jhead {
    int restart;
    int sraw;
    int algo;
    int bits;
    int high;
    int wide;
    int clrs;
    void *free[20];
    void *huff[20];
    int psv;
    int quant[64];
    ushort *row;
};

struct LibRaw {
    int ljpeg_start(struct jhead *jh, int info_only);
    FILE *ifp;
    int dng_version;
    int zero_after_ff;
};

#define FORC(cnt) for (c = 0; c < cnt; c++)

void *make_decoder_ref(const uchar **dp);
void merror(void *ptr, const char *where);