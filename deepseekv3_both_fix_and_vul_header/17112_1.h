#include <stdint.h>
#include <string.h>

typedef struct {
    void *internal;
    const uint8_t *next_in;
    size_t avail_in;
    uint8_t *next_out;
    size_t avail_out;
} lzma_stream;

#define LZMA_STREAM_INIT {0}
#define UINT64_MAX (18446744073709551615UL)
#define LZMA_OK 0
#define LZMA_MEM_ERROR 1
#define LZMA_DATA_ERROR 2

typedef struct {
    void *zalloc;
    void *zfree;
    void *opaque;
    const uint8_t *next_in;
    size_t avail_in;
    uint8_t *next_out;
    size_t avail_out;
    unsigned long adler;
} z_stream;

#define Z_NULL 0
#define Z_OK 0

typedef struct xz_state {
    lzma_stream strm;
    z_stream zstrm;
    unsigned char *in;
    unsigned char *out;
    size_t size;
    size_t want;
    int init;
    int how;
    int direct;
    unsigned long pos;
    unsigned char *next;
    unsigned have;
    unsigned long raw;
} *xz_statep;

#define GZIP 1
#define COPY 2
#define LZMA 3

extern int lzma_auto_decoder(lzma_stream *strm, uint64_t memlimit, uint32_t flags);
extern int inflateInit2(z_stream *strm, int windowBits);
extern int inflateReset(z_stream *strm);
extern unsigned long crc32(unsigned long crc, const unsigned char *buf, unsigned int len);