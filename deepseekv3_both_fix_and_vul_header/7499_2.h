#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define LZMA_OK 0
#define LZMA_RUN 0

#define ARCHIVE_OK 0
#define ARCHIVE_FAILED 1
#define ARCHIVE_FATAL 2
#define ARCHIVE_ERRNO_MISC (-1)
#define ARCHIVE_ERRNO_FILE_FORMAT (-2)
#define ARCHIVE_ERRNO_PROGRAMMER (-3)

typedef int lzma_ret;

struct lzma_stream {
    void *next_in;
    unsigned int avail_in;
    uint64_t total_in;
    void *next_out;
    unsigned int avail_out;
    uint64_t total_out;
};

struct archive {
    int dummy;
};

struct archive_read {
    struct archive archive;
};

struct zip {
    int zipx_lzma_valid;
    struct lzma_stream zipx_lzma_stream;
    uint8_t* uncompressed_buffer;
    size_t uncompressed_buffer_size;
    int64_t entry_bytes_remaining;
    int64_t entry_compressed_bytes_read;
    int decompress_init;
};

void lzma_end(struct lzma_stream *strm);
lzma_ret lzma_alone_decoder(struct lzma_stream *strm, uint64_t memlimit);
lzma_ret lzma_code(struct lzma_stream *strm, int action);
void archive_set_error(struct archive *, int, const char *, ...);
const uint8_t* __archive_read_ahead(struct archive_read *, size_t, ssize_t *);
void __archive_read_consume(struct archive_read *, size_t);