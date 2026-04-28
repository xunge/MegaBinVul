#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t *next_in;
    size_t avail_in;
    uint8_t *next_out;
    size_t avail_out;
} lzma_stream;

typedef enum {
    LZMA_RUN,
    LZMA_FINISH
} lzma_action;

typedef enum {
    LZMA_OK,
    LZMA_STREAM_END,
    LZMA_MEM_ERROR,
    LZMA_DATA_ERROR,
    LZMA_PROG_ERROR
} lzma_ret;

typedef struct xz_state {
    lzma_stream strm;
    unsigned have;
    unsigned char *next;
    int eof;
    int how;
#ifdef LIBXML_ZLIB_ENABLED
    struct {
        uint32_t adler;
        uint64_t total_out;
        uint8_t *next_in;
        uint32_t avail_in;
        uint8_t *next_out;
        uint32_t avail_out;
    } zstrm;
#endif
} *xz_statep;

enum {
    LOOK,
    LZMA,
    GZIP
};

static void xz_error(xz_statep state, int err, const char *msg);
static int xz_avail(xz_statep state);
#ifdef LIBXML_ZLIB_ENABLED
static int gz_next4(xz_statep state, unsigned long *val);
#endif