#include <stdint.h>
#include <string.h>

#define ENSURE(cond) if (!(cond)) goto FAIL
#define TRY_IO(cond) if (cond) goto FAIL

typedef struct {
    int sample_rate;
    int bits_per_channel;
    int bytes_per_frame;
    int channels_per_frame;
    int channel_mask;
    int sample_type;
} sample_format_t;

typedef struct {
    sample_format_t sample_format;
    void *io;
} wav_reader_t;

typedef enum {
    PCM_TYPE_FLOAT,
    PCM_TYPE_UINT,
    PCM_TYPE_SINT
} pcm_type_t;

extern const uint8_t WAV_GUID_FLOAT[16];
extern const uint8_t WAV_GUID_PCM[16];

int pcm_scanl(void *io, const char *fmt, ...);
int pcm_read(void *io, void *buf, size_t size);
int pcm_skip(void *io, size_t size);