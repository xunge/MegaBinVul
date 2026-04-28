#include <stdint.h>
#include <stdlib.h>

#define AV_NOPTS_VALUE ((int64_t)UINT64_C(0x8000000000000000))
#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
#define AVDISCARD_ALL 16
#define AVSEEK_FLAG_BACKWARD 1
#define AVSEEK_FLAG_ANY 2
#define SEEK_SET 0

typedef struct AVFormatContext AVFormatContext;
typedef struct AVStream AVStream;
typedef struct AVIOContext AVIOContext;
typedef struct AVIndexEntry AVIndexEntry;

struct AVStream {
    int discard;
    AVIndexEntry *index_entries;
    int nb_index_entries;
};

struct AVFormatContext {
    void *priv_data;
    AVStream **streams;
    AVIOContext *pb;
};

struct AVIOContext {
    // Minimal stub for compilation
};

struct AVIndexEntry {
    int64_t pos;
    int64_t timestamp;
};

typedef struct MatroskaDemuxContext MatroskaDemuxContext;
typedef struct MatroskaTrack MatroskaTrack;

struct MatroskaTrack {
    int type;
    AVStream *stream;
    struct {
        int pkt_cnt;
        int sub_packet_cnt;
        int64_t buf_timecode;
    } audio;
    int64_t end_timecode;
};

struct MatroskaDemuxContext {
    AVIOContext *pb;
    int current_id;
    int skip_to_keyframe;
    int64_t skip_to_timecode;
    int done;
    int cues_parsing_deferred;
    int64_t time_scale;
    struct {
        MatroskaTrack *elem;
        int nb_elem;
    } tracks;
};

#define MATROSKA_TRACK_TYPE_SUBTITLE 0x11

static void matroska_parse_cues(MatroskaDemuxContext *matroska);
static int matroska_parse_cluster(MatroskaDemuxContext *matroska);
static void matroska_clear_queue(MatroskaDemuxContext *matroska);
static int av_index_search_timestamp(AVStream *st, int64_t timestamp, int flags);
static void avio_seek(AVIOContext *s, int64_t offset, int whence);
static void ff_update_cur_dts(AVFormatContext *s, AVStream *st, int64_t timestamp);