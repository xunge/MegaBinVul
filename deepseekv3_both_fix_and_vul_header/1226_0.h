#include <stdint.h>

#define RIFF_FOURCC(a, b, c, d) ((uint32_t)((a) | ((b) << 8) | ((c) << 16) | ((d) << 24)))

typedef struct {
    void *io;
    int64_t data_offset;
} wav_reader_t;

typedef struct {
    // Define pcm_io structure members as needed
} pcm_io_t;

int riff_next_chunk(wav_reader_t *reader, uint32_t *chunk_size);
int pcm_read32le(pcm_io_t *io, uint32_t *value);
int64_t pcm_tell(pcm_io_t *io);
int pcm_skip(pcm_io_t *io, int64_t offset);
int wav_fmt(wav_reader_t *reader, uint32_t chunk_size);
int riff_ds64(wav_reader_t *reader, int64_t *data_length);

#define ENSURE(cond) if (!(cond)) goto FAIL
#define TRY_IO(expr) if ((expr) < 0) goto FAIL