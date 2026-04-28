#include <stdint.h>
#include <stddef.h>

typedef int vpx_codec_err_t;
typedef void (*vpx_decrypt_cb)(void *, const uint8_t *, uint8_t *, unsigned int);

typedef struct {
    int is_kf;
    unsigned int w;
    unsigned int h;
} vpx_codec_stream_info_t;

typedef enum {
    VPX_CODEC_OK,
    VPX_CODEC_INVALID_PARAM,
    VPX_CODEC_UNSUP_BITSTREAM
} vpx_codec_err_enum;

typedef enum {
    PROFILE_0,
    PROFILE_1,
    PROFILE_2,
    PROFILE_3,
    MAX_PROFILES
} BITSTREAM_PROFILE;

#define VP9_FRAME_MARKER 2
#define REF_FRAMES 3
#define VPXMIN(a, b) ((a) < (b) ? (a) : (b))

struct vpx_read_bit_buffer {
    const uint8_t *bit_buffer;
    const uint8_t *bit_buffer_end;
    int bit_offset;
    void *error_handler;
    void *user_priv;
};

static int vpx_rb_read_bit(struct vpx_read_bit_buffer *rb) { return 0; }
static int vpx_rb_read_literal(struct vpx_read_bit_buffer *rb, int bits) { return 0; }
static BITSTREAM_PROFILE vp9_read_profile(struct vpx_read_bit_buffer *rb) { return PROFILE_0; }
static int vp9_read_sync_code(struct vpx_read_bit_buffer *rb) { return 1; }
static int parse_bitdepth_colorspace_sampling(BITSTREAM_PROFILE profile, struct vpx_read_bit_buffer *rb) { return 1; }
static void vp9_read_frame_size(struct vpx_read_bit_buffer *rb, int *w, int *h) { *w = *h = 0; }