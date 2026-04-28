#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CLASS
#define FORC(n) for (int c = 0; c < (n); c++)

struct jhead {
    int restart;
    int sraw;
    int bits;
    int high;
    int wide;
    int clrs;
    void *free[4];
    void *huff[6];
    int psv;
    unsigned short *row;
};

extern FILE *ifp;
extern int dng_version;
extern int zero_after_ff;

typedef unsigned char uchar;
typedef unsigned short ushort;

void *make_decoder_ref(const uchar **dp);
void merror(void *ptr, const char *msg);