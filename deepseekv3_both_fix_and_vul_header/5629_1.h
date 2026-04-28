#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

struct jhead {
    int restart;
    int sraw;
    int bits;
    int high;
    int wide;
    int clrs;
    int psv;
    void *free[4];
    void *huff[6];
    ushort *row;
};

extern FILE *ifp;
extern int dng_version;
extern int zero_after_ff;

#define CLASS
#define FORC(cnt) for (int c = 0; c < cnt; c++)

void *make_decoder_ref(const uchar **dp);
void merror(void *ptr, const char *msg);