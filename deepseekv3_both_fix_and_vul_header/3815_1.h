#include <string.h>
#include <stdio.h>

typedef unsigned char byte;
typedef unsigned short word;

#define min_rows 0
#define row_bytes 0
#define W sizeof(word)

typedef struct gp_file gp_file;

typedef struct {
    byte ***raster_buf;
    int ln_idx;
    int vskip1;
    int vskip2;
    int img_rows;
    int num_comps;
    int plane_size;
    byte *print_buf;
    int storage_size_words;
    word *storage;
    void *mem;
} ep_globals;

void gp_fputs(const char *str, gp_file *stream);
int gp_fputc(int c, gp_file *stream);
size_t gp_fwrite(const void *ptr, size_t size, size_t nmemb, gp_file *stream);
void memflip8x8(const byte *in, int in_stride, byte *out, int out_stride);
void fputshort(int val, gp_file *stream);
void errprintf(void *mem, const char *format, ...);