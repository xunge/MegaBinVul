#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FLB_GZIP_HEADER_OFFSET 10
#define MZ_CRC32_INIT 0
#define Z_NULL 0
#define Z_DEFAULT_COMPRESSION (-1)
#define Z_DEFLATED 8
#define Z_DEFAULT_WINDOW_BITS 15
#define Z_DEFAULT_STRATEGY 0
#define Z_NO_FLUSH 0
#define Z_FINISH 4
#define Z_OK 0
#define Z_STREAM_END 1

typedef unsigned long mz_ulong;

typedef struct {
    void *zalloc;
    void *zfree;
    void *opaque;
    void *next_in;
    unsigned int avail_in;
    unsigned long total_out;
    void *next_out;
    unsigned int avail_out;
} z_stream;

extern void *flb_malloc(size_t size);
extern void flb_free(void *ptr);
extern void flb_errno(void);
extern void flb_error(const char *msg);
extern void gzip_header(void *out_buf);
extern mz_ulong mz_crc32(mz_ulong crc, const void *buf, size_t len);
extern int deflateInit2(z_stream *strm, int level, int method, int windowBits, int memLevel, int strategy);
extern int deflate(z_stream *strm, int flush);
extern int deflateEnd(z_stream *strm);