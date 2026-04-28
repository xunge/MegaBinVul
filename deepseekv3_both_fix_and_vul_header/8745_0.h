#include <stdint.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef enum {
    VPX_CODEC_OK,
    VPX_CODEC_INVALID_PARAM,
    VPX_CODEC_UNSUP_BITSTREAM,
    VPX_CODEC_CORRUPT_FRAME
} vpx_codec_err_t;

typedef void (*vpx_decrypt_cb)(void *decrypt_state, const uint8_t *data, uint8_t *clear_buffer, int n);

typedef struct {
    int is_kf;
    unsigned int w;
    unsigned int h;
} vpx_codec_stream_info_t;