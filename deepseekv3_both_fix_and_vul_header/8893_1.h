#include <stdint.h>
#include <limits.h>
#include <inttypes.h>
#include <stddef.h>

#define AV_LOG_WARNING 24
#define AV_LOG_ERROR 16
#define AV_LOG_TRACE 56
#define AV_CODEC_ID_AAC 86018
#define AVMEDIA_TYPE_AUDIO 1
#define AVMEDIA_TYPE_VIDEO 0
#define AVINDEX_KEYFRAME 1

#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))

typedef struct MOVContext MOVContext;
typedef struct AVStream AVStream;
typedef struct MOVStreamContext MOVStreamContext;
typedef struct MOVElst MOVElst;
typedef struct AVIndexEntry AVIndexEntry;

struct MOVElst {
    int64_t time;
    int64_t duration;
};

struct AVIndexEntry {
    int64_t pos;
    int64_t timestamp;
    int size;
    unsigned int min_distance;
    int flags;
};

struct MOVStreamContext {
    int elst_count;
    MOVElst *elst_data;
    int64_t time_scale;
    int64_t time_offset;
    int ctts_count;
    struct {
        int duration;
    } *ctts_data;
    int stts_count;
    struct {
        int duration;
        int count;
    } *stts_data;
    int wrong_dts;
    int64_t dts_shift;
    int sample_count;
    int chunk_count;
    int64_t *chunk_offsets;
    int stsc_count;
    struct {
        int first;
        int count;
        int id;
    } *stsc_data;
    int stsz_sample_size;
    int sample_size;
    int *sample_sizes;
    int keyframe_absent;
    int keyframe_count;
    int *keyframes;
    int stps_count;
    int *stps_data;
    int rap_group_count;
    struct {
        int index;
        int count;
    } *rap_group;
    int pseudo_stream_id;
    int samples_per_frame;
    int bytes_per_frame;
    int start_pad;
    void *priv_data;
};

struct AVStream {
    int nb_index_entries;
    AVIndexEntry *index_entries;
    size_t index_entries_allocated_size;
    int index;
    int64_t duration;
    struct {
        int codec_type;
        int codec_id;
        int bit_rate;
        int video_delay;
    } *codecpar;
    MOVStreamContext *priv_data;
};

struct MOVContext {
    void *fc;
    int64_t time_scale;
};

void av_log(void*, int, const char*, ...);
int64_t av_rescale(int64_t, int64_t, int64_t);
int av_reallocp_array(void**, size_t, size_t);
void ff_rfps_add_frame(void*, AVStream*, int64_t);
void avpriv_request_sample(void*, const char*, ...);