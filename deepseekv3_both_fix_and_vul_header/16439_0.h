#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

typedef struct WavpackContext WavpackContext;
typedef struct WavpackConfig WavpackConfig;
typedef struct WavpackStream WavpackStream;
typedef struct WavpackHeader WavpackHeader;

struct WavpackConfig {
    int sample_rate;
    int num_channels;
    uint32_t channel_mask;
    int bits_per_sample;
    int bytes_per_sample;
    int block_samples;
    uint32_t flags;
    int qmode;
    float bitrate;
    int float_norm_exp;
    int xmode;
    int shaping_weight;
};

struct WavpackHeader {
    char ckID[4];
    uint32_t ckSize;
    uint16_t version;
    uint32_t flags;
};

struct WavpackStream {
    WavpackHeader wphdr;
    uint32_t bits;
};

struct WavpackContext {
    char error_message[80];
    int stream_version;
    int dsd_multiplier;
    int64_t total_samples;
    WavpackConfig config;
    int wvc_flag;
    unsigned char *channel_identities;
    int current_stream;
    int num_streams;
    WavpackStream **streams;
};

#define CUR_STREAM_VERS 0x410
#define MAX_STREAM_VERS 0x410
#define NEW_MAX_STREAMS 16
#define CONFIG_COMPATIBLE_WRITE 0x1
#define CONFIG_HYBRID_FLAG 0x2
#define CONFIG_HIGH_FLAG 0x4
#define CONFIG_VERY_HIGH_FLAG 0x8
#define CONFIG_MD5_CHECKSUM 0x10
#define CONFIG_PAIR_UNDEF_CHANS 0x20
#define CONFIG_SHAPE_OVERRIDE 0x40
#define CONFIG_HYBRID_SHAPE 0x80
#define CONFIG_AUTO_SHAPING 0x100
#define CONFIG_CROSS_DECORR 0x200
#define CONFIG_OPTIMIZE_WVC 0x400
#define CONFIG_BITRATE_KBPS 0x800
#define CONFIG_JOINT_OVERRIDE 0x1000
#define CONFIG_JOINT_STEREO 0x2000
#define CONFIG_CREATE_WVC 0x4000
#define CONFIG_EXTRA_MODE 0x8000
#define CONFIG_FLOAT_DATA 0x10000
#define QMODE_DSD_AUDIO 0x1
#define DSD_FLAG 0x80000000
#define FLOAT_DATA 0x40000000
#define HYBRID_FLAG 0x20000000
#define HYBRID_BITRATE 0x10000000
#define HYBRID_BALANCE 0x8000000
#define HYBRID_SHAPE 0x4000000
#define NEW_SHAPING 0x2000000
#define CROSS_DECORR 0x1000000
#define JOINT_STEREO 0x800000
#define MONO_FLAG 0x400000
#define INITIAL_BLOCK 0x200000
#define FINAL_BLOCK 0x100000
#define SRATE_LSB 23
#define SHIFT_LSB 20

#define NUM_STEREO_PAIRS 4
static const struct {
    int a, b;
} stereo_pairs[NUM_STEREO_PAIRS] = {
    {1, 2}, {3, 4}, {5, 6}, {7, 8}
};

static const int sample_rates[15] = {
    6000, 8000, 9600, 11025, 12000, 16000, 22050, 24000,
    32000, 44100, 48000, 64000, 88200, 96000, 192000
};

#define CLEAR(x) memset(&(x), 0, sizeof(x))
#define SET_TOTAL_SAMPLES(hdr, samples) ((hdr).flags |= ((samples) ? 0x8000 : 0))