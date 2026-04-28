#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct AVFormatContext AVFormatContext;

typedef struct AVStream {
    struct AVCodecParameters *codecpar;
} AVStream;

typedef struct AVCodecParameters {
    uint8_t *extradata;
    int extradata_size;
} AVCodecParameters;

typedef struct PayloadContext {
    int packetization_mode;
} PayloadContext;

enum {
    AV_LOG_QUIET = -8,
    AV_LOG_PANIC = 0,
    AV_LOG_FATAL = 8,
    AV_LOG_ERROR = 16,
    AV_LOG_WARNING = 24,
    AV_LOG_INFO = 32,
    AV_LOG_VERBOSE = 40,
    AV_LOG_DEBUG = 48,
    AV_LOG_TRACE = 56
};

void av_log(AVFormatContext *s, int level, const char *fmt, ...);
void av_freep(void *ptr);

int parse_profile_level_id(AVFormatContext *s, PayloadContext *h264_data, const char *value);
int ff_h264_parse_sprop_parameter_sets(AVFormatContext *s, uint8_t **extradata, int *extradata_size, const char *value);