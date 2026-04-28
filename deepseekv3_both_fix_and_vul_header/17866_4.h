#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdint.h>
#include <stdio.h>

#define LIBRAW_EXCEPTION_IO_CORRUPT 1
#define LIBRAW_EXCEPTION_IO_EOF 2
#define LIBRAW_MAX_THUMBNAIL_MB 100
#define THUMB_READ_BEYOND 100
#define LIBRAW_HISTOGRAM_SIZE 0x2000
#define LIBRAW_PROCESSING_NO_ROTATE_FOR_KODAK_THUMBNAILS 1
#define CLIP(x) ((x) < 0 ? 0 : ((x) > 65535 ? 65535 : (x)))
#define SEEK_SET 0

typedef int64_t INT64;
typedef unsigned short ushort;

struct LibRaw {
    void kodak_ycbcr_load_raw();
    void kodak_thumb_loader();
    void (LibRaw::*thumb_load_raw)();
};

struct ID_struct {
    int64_t toffset;
    struct {
        size_t (*size)();
        void (*seek)(int64_t, int);
    } *input;
};

struct S_struct {
    int height;
    int width;
    int iwidth;
    int iheight;
    int flip;
};

struct P1_struct {
    int colors;
    unsigned filters;
};

struct C_struct {
    double pre_mul[4];
    int maximum;
    ushort curve[0x10000];
};

struct T_struct {
    char* thumb;
    int tlength;
    int twidth;
    int theight;
    int tcolors;
};

struct IO_struct {
    int fuji_width;
};

struct O_struct {
    float gamm[2];
    int bright;
    int highlight;
    int no_auto_bright;
};

struct output_data_struct {
    int (*histogram)[LIBRAW_HISTOGRAM_SIZE];
};

struct libraw_internal_data_struct {
    output_data_struct output_data;
    struct {
        int load_flags;
    } unpacker_data;
};

struct imgdata_struct {
    ushort (*image)[4];
    struct {
        int flip;
    } sizes;
    struct {
        int raw_processing_options;
    } params;
    struct {
        ushort curve[0x10000];
    } color;
};

extern ID_struct ID;
extern S_struct S;
extern P1_struct P1;
extern C_struct C;
extern T_struct T;
extern IO_struct IO;
extern O_struct O;
extern libraw_internal_data_struct libraw_internal_data;
extern imgdata_struct imgdata;
extern void merror(void *ptr, const char *msg);
extern void gamma_curve(float gamm, float gamm2, int gamm3, int gamm4);
extern int flip_index(int row, int col);
#define SWAP(a,b) { a ^= b; b ^= a; a ^= b; }