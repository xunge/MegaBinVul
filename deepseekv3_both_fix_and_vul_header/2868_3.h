#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ok_wav_ima_state {
    int16_t predictor;
    int8_t step_index;
} ok_wav_ima_state;

typedef struct ok_wav {
    uint8_t num_channels;
    uint64_t num_frames;
    int16_t *data;
    bool little_endian;
    uint8_t bit_depth;
} ok_wav;

typedef struct ok_wav_decoder {
    struct ok_wav *wav;
    size_t block_size;
    uint64_t frames_per_block;
} ok_wav_decoder;

static uint16_t readLE16(const uint8_t *data) {
    return data[0] | (data[1] << 8);
}

static uint16_t readBE16(const uint8_t *data) {
    return (data[0] << 8) | data[1];
}

static int16_t ok_wav_decode_ima_adpcm_nibble(ok_wav_ima_state *state, uint8_t nibble);
static bool ok_read(ok_wav_decoder *decoder, void *buffer, size_t bytes);
static void ok_wav_error(ok_wav *wav, const char *message);

#define min(a, b) ((a) < (b) ? (a) : (b))