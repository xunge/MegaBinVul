#include <stdint.h>

typedef struct io_t {
    // Placeholder for IO operations
} io_t;

typedef struct sample_format_t {
    unsigned channels_per_frame;
    // Other format fields would go here
} sample_format_t;

typedef struct caf_reader_t {
    io_t io;
    sample_format_t sample_format;
    void *chanmap;
    int64_t data_offset;
} caf_reader_t;

#define M4AF_FOURCC(a, b, c, d) ((uint32_t)((a) << 24 | (b) << 16 | (c) << 8 | (d)))
#define TRY_IO(x) if ((x) < 0) goto FAIL
#define ENSURE(x) if (!(x)) goto FAIL

static uint32_t caf_next_chunk(caf_reader_t *reader, int64_t *chunk_size);
static int caf_desc(caf_reader_t *reader, int64_t chunk_size);
static int caf_info(caf_reader_t *reader, int64_t chunk_size);
static int apple_chan_chunk(io_t *io, int64_t chunk_size, sample_format_t *sample_format, void *chanmap);
static int pcm_read32be(io_t *io, uint32_t *val);
static int64_t pcm_skip(io_t *io, int64_t bytes);
static int64_t pcm_tell(io_t *io);