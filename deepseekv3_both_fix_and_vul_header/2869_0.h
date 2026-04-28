#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

struct ok_wav_ms_adpcm_state {
    int16_t sample1;
    int16_t sample2;
    int16_t coeff1;
    int16_t coeff2;
    int16_t delta;
};

typedef struct ok_wav {
    uint8_t num_channels;
    uint64_t num_frames;
    bool little_endian;
    int16_t *data;
    uint16_t bit_depth;
} ok_wav;

typedef struct ok_wav_decoder {
    ok_wav *wav;
    size_t block_size;
    uint64_t frames_per_block;
} ok_wav_decoder;

static uint16_t readLE16(const uint8_t *data);
static uint16_t readBE16(const uint8_t *data);
static int16_t ok_wav_decode_ms_adpcm_nibble(struct ok_wav_ms_adpcm_state *state, uint8_t nibble);
static bool ok_read(ok_wav_decoder *decoder, uint8_t *data, size_t size);
static void ok_wav_error(ok_wav *wav, const char *message);