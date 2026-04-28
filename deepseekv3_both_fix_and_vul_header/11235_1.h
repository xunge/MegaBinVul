#include <stdint.h>
#include <string.h>

#define AV_RL32(x) (*(const uint32_t*)(x))
#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))

typedef struct AVIOContext AVIOContext;
typedef struct AVFormatContext AVFormatContext;

typedef struct AVCodecParameters {
    int codec_id;
    int sample_rate;
    int channels;
    int bits_per_coded_sample;
    int frame_size;
    int codec_type;
} AVCodecParameters;

typedef struct MOVTrack {
    uint32_t tag;
    int mode;
    int timescale;
    int audio_vbr;
    AVCodecParameters *par;
    int sample_size;
    int vos_len;
} MOVTrack;

typedef struct MOVMuxContext {
    int encryption_scheme;
    uint8_t encryption_kid[16];
} MOVMuxContext;

enum {
    MODE_MOV,
    MODE_MP4
};

enum AVCodecID {
    AV_CODEC_ID_PCM_U8,
    AV_CODEC_ID_PCM_S8,
    AV_CODEC_ID_ADPCM_G726,
    AV_CODEC_ID_ADPCM_MS,
    AV_CODEC_ID_ADPCM_IMA_WAV,
    AV_CODEC_ID_QDM2,
    AV_CODEC_ID_AAC,
    AV_CODEC_ID_AC3,
    AV_CODEC_ID_EAC3,
    AV_CODEC_ID_AMR_NB,
    AV_CODEC_ID_ALAC,
    AV_CODEC_ID_WMAPRO,
    AVMEDIA_TYPE_AUDIO
};

enum MOVEncryptionScheme {
    MOV_ENC_NONE
};

static int mov_get_lpcm_flags(int codec_id) { return 0; }
static int mov_pcm_le_gt16(int codec_id) { return 0; }
static int mov_pcm_be_gt16(int codec_id) { return 0; }
static int av_get_bits_per_sample(int codec_id) { return 0; }
static int get_samples_per_packet(MOVTrack *track) { return 0; }
static double av_double2int(double d) { return 0; }
static void mov_write_wave_tag(AVFormatContext *s, AVIOContext *pb, MOVTrack *track) {}
static void mov_write_esds_tag(AVIOContext *pb, MOVTrack *track) {}
static void mov_write_amr_tag(AVIOContext *pb, MOVTrack *track) {}
static void mov_write_ac3_tag(AVIOContext *pb, MOVTrack *track) {}
static void mov_write_eac3_tag(AVIOContext *pb, MOVTrack *track) {}
static void mov_write_extradata_tag(AVIOContext *pb, MOVTrack *track) {}
static void mov_write_wfex_tag(AVFormatContext *s, AVIOContext *pb, MOVTrack *track) {}
static void mov_write_glbl_tag(AVIOContext *pb, MOVTrack *track) {}
static void mov_write_chan_tag(AVFormatContext *s, AVIOContext *pb, MOVTrack *track) {}
static void ff_mov_cenc_write_sinf_tag(MOVTrack *track, AVIOContext *pb, const uint8_t *kid) {}
static void ffio_wfourcc(AVIOContext *pb, const char *tag) {}
static int64_t avio_tell(AVIOContext *pb) { return 0; }
static void avio_wb32(AVIOContext *pb, uint32_t val) {}
static void avio_wl32(AVIOContext *pb, uint32_t val) {}
static void avio_wb16(AVIOContext *pb, uint16_t val) {}
static void avio_wb64(AVIOContext *pb, uint64_t val) {}
static int update_size(AVIOContext *pb, int64_t pos) { return 0; }