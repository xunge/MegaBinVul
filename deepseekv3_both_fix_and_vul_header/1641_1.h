#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

#define AV_CODEC_ID_HEVC 173
#define HEVC_NAL_CRA_NUT 21

#define AVERROR(e) (-(e))
#define AVERROR_PATCHWELCOME (-1)
#define ENOMEM 12

#define FFMIN(a, b) ((a) > (b) ? (b) : (a))

typedef struct AVStream AVStream;
typedef struct MOVStreamContext MOVStreamContext;
typedef struct MOVSbgp MOVSbgp;

struct AVStream {
    void *priv_data;
    struct {
        int codec_id;
    } *codecpar;
};

struct MOVStreamContext {
    uint32_t sync_group_count;
    uint32_t ctts_count;
    struct {
        int count;
        int duration;
    } *ctts_data;
    int sample_offsets_count;
    int *sample_offsets;
    uint32_t open_key_samples_count;
    uint32_t *open_key_samples;
    uint32_t stts_count;
    struct {
        int duration;
    } *stts_data;
    uint32_t min_sample_duration;
    MOVSbgp *sync_group;
};

struct MOVSbgp {
    uint32_t index;
    uint32_t count;
};

static uint32_t get_sgpd_sync_index(MOVStreamContext *sc, int type);

static void av_freep(void *ptr) {
    free(*(void**)ptr);
    *(void**)ptr = NULL;
}

static void *av_calloc(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}