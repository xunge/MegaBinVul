#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>

typedef struct AVStream {
    int nb_frames;
} AVStream;

typedef struct AVFormatContext {
    void *priv_data;
    void *pb;
    AVStream **streams;
    int avoid_negative_ts;
} AVFormatContext;

typedef struct AVPacket {
    int stream_index;
    uint8_t *data;
    int size;
    int64_t dts;
    int64_t pts;
    int64_t duration;
    int flags;
} AVPacket;

typedef struct AVIOContext AVIOContext;

typedef struct AVCodecParameters {
    int codec_id;
    int extradata_size;
    uint8_t *extradata;
    int frame_size;
} AVCodecParameters;

typedef struct MOVTrack {
    AVCodecParameters *par;
    int vos_len;
    uint8_t *vos_data;
    int entry;
    int entries_flushed;
    int hint_track;
    int sample_count;
    int sample_size;
    int tag;
    int flags;
    int has_keyframes;
    int has_disposable;
    int last_sample_is_subtitle_end;
    int64_t start_dts;
    int64_t track_duration;
    int64_t start_cts;
    int64_t end_pts;
    int64_t frag_start;
    int frag_discont;
    int cluster_capacity;
    int frag_interleave;
    AVIOContext *mdat_buf;
    struct {
        int64_t pos;
        unsigned int samples_in_chunk;
        int chunkNum;
        int size;
        int entries;
        int64_t dts;
        int64_t pts;
        int cts;
        int flags;
    } *cluster;
    struct {
        int aes_ctr;
    } cenc;
} MOVTrack;

typedef struct MOVMuxContext {
    int flags;
    int moov_written;
    int fragments;
    int nb_streams;
    AVIOContext *mdat_buf;
    int mdat_size;
    int use_editlist;
    int mode;
    MOVTrack *tracks;
    int frag_interleave;
} MOVMuxContext;

#define FF_MOV_FLAG_FRAGMENT 1
#define FF_MOV_FLAG_EMPTY_MOOV 2
#define FF_MOV_FLAG_DASH 4
#define FF_MOV_FLAG_GLOBAL_SIDX 8
#define MOV_INDEX_CLUSTER_SIZE 1024
#define AV_CODEC_ID_AMR_NB 0
#define AV_CODEC_ID_ADPCM_MS 0
#define AV_CODEC_ID_ADPCM_IMA_WAV 0
#define AV_CODEC_ID_AAC 0
#define AV_CODEC_ID_H264 0
#define AV_CODEC_ID_HEVC 0
#define AV_CODEC_ID_EAC3 0
#define AV_CODEC_ID_DNXHD 0
#define AV_CODEC_ID_AC3 0
#define AV_CODEC_ID_VC1 0
#define AV_CODEC_ID_MPEG2VIDEO 0
#define AVFMT_AVOID_NEG_TS_MAKE_ZERO 0
#define MODE_MOV 0
#define MODE_ISM 0
#define MOV_PARTIAL_SYNC_SAMPLE 0
#define MOV_SYNC_SAMPLE 1
#define MOV_DISPOSABLE_SAMPLE 2
#define MOV_TRACK_CTTS 1
#define MOV_TRACK_STPS 2
#define AV_NOPTS_VALUE INT64_MIN
#define AVERROR_PATCHWELCOME (-1)
#define AVERROR(err) (-(err))
#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 1
#define AV_PKT_FLAG_KEY 1
#define AV_PKT_FLAG_DISPOSABLE 2

static int check_pkt(AVFormatContext *s, AVPacket *pkt) { return 0; }
static int mov_flush_fragment_interleaving(AVFormatContext *s, MOVTrack *trk) { return 0; }
static int avio_open_dyn_buf(AVIOContext **buf) { return 0; }
static int64_t avio_tell(AVIOContext *pb) { return 0; }
static void avio_write(AVIOContext *pb, uint8_t *data, int size) {}
static void *av_malloc(size_t size) { return malloc(size); }
static int av_reallocp_array(void **ptr, size_t nmemb, size_t size) { return 0; }
static void av_free(void *ptr) { free(ptr); }
static void av_log(AVFormatContext *s, int level, const char *fmt, ...) {}
static int ff_avc_parse_nal_units_buf(uint8_t *data, uint8_t **out_data, int *out_size) { return 0; }
static int ff_avc_parse_nal_units(AVIOContext *pb, uint8_t *data, int size) { return 0; }
static int ff_mov_cenc_avc_parse_nal_units(void *cenc, AVIOContext *pb, uint8_t *data, int size) { return 0; }
static int ff_hevc_annexb2mp4_buf(uint8_t *data, uint8_t **out_data, int *out_size, int zero, void *log) { return 0; }
static int ff_hevc_annexb2mp4(AVIOContext *pb, uint8_t *data, int size, int zero, void *log) { return 0; }
static int handle_eac3(MOVMuxContext *mov, AVPacket *pkt, MOVTrack *trk) { return 0; }
static int ff_mov_cenc_avc_write_nal_units(AVFormatContext *s, void *cenc, int nal_size_length, AVIOContext *pb, uint8_t *data, int size) { return 0; }
static int ff_mov_cenc_write_packet(void *cenc, AVIOContext *pb, uint8_t *data, int size) { return 0; }
static void mov_parse_vc1_frame(AVPacket *pkt, MOVTrack *trk) {}
static void mov_parse_mpeg2_frame(AVPacket *pkt, int *flags) {}
static void ff_mov_add_hinted_packet(AVFormatContext *s, AVPacket *pkt, int hint_track, int entry, uint8_t *data, int size) {}

#define AV_RB16(x) (((x)[0] << 8) | (x)[1])
#define AV_RB24(x) (((x)[0] << 16) | ((x)[1] << 8) | (x)[2])
#define AV_RB32(x) (((x)[0] << 24) | ((x)[1] << 16) | ((x)[2] << 8) | (x)[3])
#define TAG_IS_AVCI(x) (0)
#define CONFIG_AC3_PARSER 0
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))