#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef int Bool;
typedef void *voidpf;
typedef void *(*alloc_func)(voidpf, u32, u32);
typedef void (*free_func)(voidpf, voidpf);
typedef unsigned char Bytef;

typedef enum {
    GF_OK,
    GF_OUT_OF_MEM,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

#define GF_EXPORT
#define GF_TRUE 1
#define GF_FALSE 0
#define MAX_WBITS 15
#define Z_OK 0
#define Z_STREAM_END 1
#define Z_NO_FLUSH 0

typedef struct {
    Bytef *next_in;
    u32 avail_in;
    u32 total_in;
    Bytef *next_out;
    u32 avail_out;
    u32 total_out;
    alloc_func zalloc;
    free_func zfree;
    voidpf opaque;
} z_stream;

void *gf_malloc(size_t size);
void *gf_realloc(void *ptr, size_t size);
void gf_free(void *ptr);

int inflateInit2(z_stream *strm, int windowBits);
int inflate(z_stream *strm, int flush);
int inflateEnd(z_stream *strm);