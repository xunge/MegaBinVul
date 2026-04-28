#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int len;
} hcode16_t;

typedef struct {
    int datacnt;
    struct {
        int data;
        int len;
    } s[1024];
    int num_data_cw[1024];
    int cur_cw;
#ifdef DRM
    int iLenReordSpData;
    int iLenLongestCW;
#endif
} CoderInfo;

extern hcode16_t book01[], book02[], book03[], book04[], book05[], 
                book06[], book07[], book08[], book09[], book10[], book11[];

#define HCB_ZERO 0
#define HCB_INTENSITY 0
#define HCB_INTENSITY2 0
#define HCB_ESC 11
#define DRMDATA

static int escape(int val, int *data) {
    *data = val;
    return 0;
}

static hcode16_t * const hmap[12] = {
    NULL, book01, book02, book03, book04, book05, 
    book06, book07, book08, book09, book10, book11
};

#ifdef DRM
static int vcb11;
#endif