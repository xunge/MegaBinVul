#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define FLAC_API
#define OVERREAD_ 1

typedef int32_t FLAC__int32;
typedef uint32_t FLAC__bool;

enum {
    FLAC__STREAM_ENCODER_OK,
    FLAC__STREAM_ENCODER_CLIENT_ERROR
};

struct FLAC__StreamEncoderProtected {
    uint32_t channels;
    uint32_t blocksize;
    uint32_t bits_per_sample;
    bool verify;
    int state;
    bool do_mid_side_stereo;
};

struct FLAC__StreamEncoderPrivate {
    uint32_t current_sample_number;
    FLAC__int32 **integer_signal;
    FLAC__int32 *integer_signal_mid_side[2];
    struct {
        void *input_fifo;
    } verify;
};

typedef struct FLAC__StreamEncoder {
    struct FLAC__StreamEncoderProtected *protected_;
    struct FLAC__StreamEncoderPrivate *private_;
} FLAC__StreamEncoder;

#define FLAC__ASSERT(expr) ((void)0)

static inline uint32_t flac_min(uint32_t a, uint32_t b) { return a < b ? a : b; }

static bool process_frame_(FLAC__StreamEncoder *encoder, bool is_fractional_block, bool is_last_block) { return true; }
static void append_to_verify_fifo_(void *fifo, const FLAC__int32 * const buffer[], uint32_t j, uint32_t channels, uint32_t n) {}