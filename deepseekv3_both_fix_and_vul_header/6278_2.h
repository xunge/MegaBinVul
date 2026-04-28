#include <stdint.h>

#define MAX_PCE_SIZE 64
#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA 1

typedef struct AVFormatContext AVFormatContext;

typedef struct ADTSContext {
    int objecttype;
    int sample_rate_index;
    int channel_conf;
    uint8_t pce_data[MAX_PCE_SIZE];
    int pce_size;
    int write_adts;
} ADTSContext;

typedef struct MPEG4AudioConfig {
    int object_type;
    int sampling_index;
    int chan_config;
} MPEG4AudioConfig;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct PutBitContext {
    uint8_t *buf;
    int bit_left;
    uint32_t bit_buf;
} PutBitContext;

void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size);
int avpriv_mpeg4audio_get_config2(MPEG4AudioConfig *m4ac, const uint8_t *buf, int bit_size, int sync_extension, AVFormatContext *s);
void skip_bits_long(GetBitContext *s, int n);
int get_bits(GetBitContext *s, int n);
void av_log(AVFormatContext *s, int level, const char *fmt, ...);
void init_put_bits(PutBitContext *s, uint8_t *buffer, int buffer_size);
void put_bits(PutBitContext *s, int n, unsigned int value);
int ff_copy_pce_data(PutBitContext *pb, GetBitContext *gb);
void flush_put_bits(PutBitContext *s);