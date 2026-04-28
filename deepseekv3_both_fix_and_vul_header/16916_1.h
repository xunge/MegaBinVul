#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define FLAC_API
#define FLAC__ASSERT(expr) ((void)0)
#define FLAC__STREAM_ENCODER_OK 0
#define FLAC__STREAM_ENCODER_CLIENT_ERROR 1
#define OVERREAD_ 1

typedef bool FLAC__bool;
typedef struct FLAC__StreamEncoder FLAC__StreamEncoder;
typedef int32_t FLAC__int32;

struct FLAC__StreamEncoder {
    struct {
        uint32_t channels;
        uint32_t blocksize;
        uint32_t bits_per_sample;
        bool do_mid_side_stereo;
        bool verify;
        uint32_t state;
    } *protected_;
    struct {
        uint32_t current_sample_number;
        FLAC__int32 **integer_signal;
        FLAC__int32 **integer_signal_mid_side;
        struct {
            struct {
                FLAC__int32 *buffer;
            } input_fifo;
        } verify;
    } *private_;
};

static inline uint32_t flac_min(uint32_t a, uint32_t b) { return a < b ? a : b; }
static bool process_frame_(FLAC__StreamEncoder *encoder, bool is_fractional_block, bool is_last_block) { return false; }
static void append_to_verify_fifo_interleaved_(void *fifo, const FLAC__int32 buffer[], uint32_t start, uint32_t channels, uint32_t samples) {}