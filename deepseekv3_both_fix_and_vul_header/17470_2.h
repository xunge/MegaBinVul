#include <string.h>

#define TRUE 1
#define FALSE 0

#define ID_DUMMY 0
#define ID_DECORR_TERMS 1
#define ID_DECORR_WEIGHTS 2
#define ID_DECORR_SAMPLES 3
#define ID_ENTROPY_VARS 4
#define ID_HYBRID_PROFILE 5
#define ID_SHAPING_WEIGHTS 6
#define ID_FLOAT_INFO 7
#define ID_INT32_INFO 8
#define ID_CHANNEL_INFO 9
#define ID_CHANNEL_IDENTITIES 10
#define ID_CONFIG_BLOCK 11
#define ID_NEW_CONFIG_BLOCK 12
#define ID_SAMPLE_RATE 13
#define ID_WV_BITSTREAM 14
#define ID_WVC_BITSTREAM 15
#define ID_WVX_BITSTREAM 16
#define ID_DSD_BLOCK 17
#define ID_ALT_HEADER 18
#define ID_ALT_TRAILER 19
#define ID_RIFF_HEADER 20
#define ID_RIFF_TRAILER 21
#define ID_ALT_MD5_CHECKSUM 22
#define ID_MD5_CHECKSUM 23
#define ID_ALT_EXTENSION 24
#define ID_BLOCK_CHECKSUM 25
#define ID_OPTIONAL_DATA 0x40000000

#define OPEN_ALT_TYPES 0x1
#define CONFIG_MD5_CHECKSUM 0x1

typedef struct WavpackMetadata {
    int id;
    unsigned char *data;
    unsigned int byte_length;
} WavpackMetadata;

typedef struct WavpackStream WavpackStream;

typedef struct {
    unsigned char md5_checksum[16];
    unsigned int flags;
    int md5_read;
} WavpackConfig;

typedef struct WavpackContext {
    WavpackStream **streams;
    int current_stream;
    char error_message[80];
    unsigned int open_flags;
    WavpackConfig config;
    char file_extension[16];
    int version_five;
} WavpackContext;

int read_decorr_terms(WavpackStream *wps, WavpackMetadata *wpmd);
int read_decorr_weights(WavpackStream *wps, WavpackMetadata *wpmd);
int read_decorr_samples(WavpackStream *wps, WavpackMetadata *wpmd);
int read_entropy_vars(WavpackStream *wps, WavpackMetadata *wpmd);
int read_hybrid_profile(WavpackStream *wps, WavpackMetadata *wpmd);
int read_shaping_info(WavpackStream *wps, WavpackMetadata *wpmd);
int read_float_info(WavpackStream *wps, WavpackMetadata *wpmd);
int read_int32_info(WavpackStream *wps, WavpackMetadata *wpmd);
int read_channel_info(WavpackContext *wpc, WavpackMetadata *wpmd);
int read_channel_identities(WavpackContext *wpc, WavpackMetadata *wpmd);
int read_config_info(WavpackContext *wpc, WavpackMetadata *wpmd);
int read_new_config_info(WavpackContext *wpc, WavpackMetadata *wpmd);
int read_sample_rate(WavpackContext *wpc, WavpackMetadata *wpmd);
int init_wv_bitstream(WavpackStream *wps, WavpackMetadata *wpmd);
int init_wvc_bitstream(WavpackStream *wps, WavpackMetadata *wpmd);
int init_wvx_bitstream(WavpackStream *wps, WavpackMetadata *wpmd);
int init_dsd_block(WavpackContext *wpc, WavpackMetadata *wpmd);
int read_wrapper_data(WavpackContext *wpc, WavpackMetadata *wpmd);