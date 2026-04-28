#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct AVBPrint {
    char *str;
    unsigned len;
    unsigned size;
} AVBPrint;

typedef struct z_stream_s {
    void *zalloc;
    void *zfree;
    void *opaque;
    unsigned char *next_in;
    unsigned int avail_in;
    unsigned char *next_out;
    unsigned int avail_out;
} z_stream;

#define Z_OK 0
#define Z_STREAM_END 1
#define Z_PARTIAL_FLUSH 1

void *ff_png_zalloc(void *opaque, unsigned int items, unsigned int size);
void ff_png_zfree(void *opaque, void *ptr);

int inflateInit(z_stream *strm);
int inflate(z_stream *strm, int flush);
int inflateEnd(z_stream *strm);

void av_bprint_init(AVBPrint *bp, unsigned size_init, unsigned size_max);
void av_bprint_get_buffer(AVBPrint *bp, unsigned size, unsigned char **buf, unsigned *buf_size);
void av_bprint_finalize(AVBPrint *bp, char **ret_str);

#define AVERROR(e) (-(e))
#define AVERROR_EXTERNAL (-0x10000)
#define ENOMEM 12