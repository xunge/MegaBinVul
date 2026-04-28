#include <stdio.h>
#include <string.h>

#define QLZ_STREAMING_BUFFER 0

typedef struct {
    size_t stream_counter;
    unsigned char stream_buffer[QLZ_STREAMING_BUFFER];
} qlz_state_decompress;

size_t qlz_size_decompressed(const char *source);
size_t qlz_size_header(const char *source);
void reset_table_decompress(qlz_state_decompress *state);
size_t qlz_decompress_core(const unsigned char *source, unsigned char *destination, size_t dsiz, qlz_state_decompress *state, const unsigned char *history);