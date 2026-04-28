#include <stdint.h>

#define M4AF_FOURCC(a,b,c,d) ((uint32_t)((a)<<24)|((b)<<16)|((c)<<8)|(d))

typedef struct {
    double sample_rate;
    uint32_t bits_per_channel;
    uint32_t bytes_per_frame;
    uint32_t channels_per_frame;
    int sample_type;
} pcm_sample_description_t;

typedef struct {
    pcm_sample_description_t sample_format;
    void *io;
} caf_reader_t;

enum {
    PCM_TYPE_SINT_BE,
    PCM_TYPE_FLOAT_BE,
    PCM_TYPE_SINT,
    PCM_TYPE_FLOAT
};

#define ENSURE(cond) if (!(cond)) goto FAIL
#define TRY_IO(cond) if (cond) goto FAIL