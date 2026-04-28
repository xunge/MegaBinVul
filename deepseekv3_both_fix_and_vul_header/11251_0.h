#include <stdint.h>
#include <string.h>

typedef struct MMSContext MMSContext;
typedef struct MMSStream MMSStream;

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA 1
#define AVERROR(ENOMEM) 2
#define MMS_MAX_STREAMS 10
#define PRId64 "lld"

extern const uint8_t ff_asf_header[];
extern const uint8_t ff_asf_data_header[];
extern const uint8_t ff_asf_file_header[];
extern const uint8_t ff_asf_stream_header[];
extern const uint8_t ff_asf_ext_stream_header[];
extern const uint8_t ff_asf_head1_guid[];
extern const uint8_t ff_asf_guid[16];

void av_log(void*, int, const char*, ...);
void* av_fast_realloc(void*, unsigned int*, size_t);

static inline uint32_t AV_RL32(const uint8_t *p) {
    return p[0] | p[1] << 8 | p[2] << 16 | p[3] << 24;
}

static inline uint64_t AV_RL64(const uint8_t *p) {
    return (uint64_t)AV_RL32(p) | (uint64_t)AV_RL32(p+4) << 32;
}

static inline uint16_t AV_RL16(const uint8_t *p) {
    return p[0] | p[1] << 8;
}

struct MMSStream {
    int id;
};

struct MMSContext {
    uint8_t *asf_header;
    int asf_header_size;
    int stream_num;
    int asf_packet_len;
    uint8_t in_buffer[1];
    uint8_t out_buffer[1];
    MMSStream *streams;
    unsigned int nb_streams_allocated;
};