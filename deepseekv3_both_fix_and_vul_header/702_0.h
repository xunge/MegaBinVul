#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;

typedef struct {
    BYTE id;
    BYTE samp_factor_h;
    BYTE samp_factor_v;
    BYTE qtab_idx;
    BYTE htab_idx_dc;
    BYTE htab_idx_ac;
} COMP_INFO;

typedef struct {
    BYTE huftab[256];
} HUFCODEC;

typedef struct {
    int width;
    int height;
    int comp_num;
    COMP_INFO comp_info[4];
    int *pqtab[4];
    HUFCODEC *phcdc[4];
    HUFCODEC *phcac[4];
    long datalen;
    BYTE *databuf;
} JFIF;

static const BYTE ZIGZAG[64] = {
    0,  1,  5,  6, 14, 15, 27, 28,
    2,  4,  7, 13, 16, 26, 29, 42,
    3,  8, 12, 17, 25, 30, 41, 43,
    9, 11, 18, 24, 31, 40, 44, 53,
    10, 19, 23, 32, 39, 45, 52, 54,
    20, 22, 33, 38, 46, 51, 55, 60,
    21, 34, 37, 47, 50, 56, 59, 61,
    35, 36, 48, 49, 57, 58, 62, 63
};

void jfif_free(JFIF *jfif);