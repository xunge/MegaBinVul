#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

typedef struct {
    int width;
    int height;
    int stride;
    void *pdata;
} BMP;

typedef struct {
    int samp_factor_h;
    int samp_factor_v;
    int htab_idx_ac;
    int htab_idx_dc;
    int qtab_idx;
} JFIF_COMP_INFO;

typedef struct {
    void *input;
} HUFCODEC;

typedef struct {
    BYTE *databuf;
    int datalen;
    int width;
    int height;
    int comp_num;
    JFIF_COMP_INFO comp_info[3];
    int *pqtab[16];
    HUFCODEC *phcac[16];
    HUFCODEC *phcdc[16];
} JFIF;

#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))

void init_dct_module();
void init_idct_ftab(int *ftab, int *pqtab);
void *bitstr_open(void *databuf, const char *mode, int datalen);
void bitstr_close(void *bs);
int bitstr_get_bits(void *bs, int n);
void huffman_decode_init(HUFCODEC *hc);
int huffman_decode_step(HUFCODEC *hc);
void huffman_decode_done(HUFCODEC *hc);
int category_decode(int code, int size);
void zigzag_decode(int *du);
void idct2d8x8(int *du, int *ftab);
void bmp_create(BMP *pb, int width, int height);
void yuv_to_rgb(int y, int u, int v, BYTE *r, BYTE *g, BYTE *b);