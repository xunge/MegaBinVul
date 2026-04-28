#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char Bool;
#define GF_FALSE 0
#define GF_TRUE 1

typedef unsigned int u32;
typedef unsigned long long u64;

typedef int GF_Err;
#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_IO_ERR 2

typedef struct {
    u32 input_udta;
    u32 caps;
    u32 timescale;
    void* decoder_config;
    GF_Err (*output_ctrl)(void*, u32, void*);
} GF_ESInterface;

typedef struct {
    u32 flags;
    u32 mpeg2_af_descriptors_size;
    char* mpeg2_af_descriptors;
    u64 cts;
    u64 dts;
    u32 data_len;
    char* data;
    u32 duration;
} GF_ESIPacket;

typedef struct {
    u32 IsRAP;
    u64 DTS;
    u64 CTS_Offset;
    u32 dataLength;
    char* data;
} GF_ISOSample;

typedef struct {
    GF_ISOSample* sample;
    u32 track;
    u32 sample_number;
    u32 sample_count;
    u32 ts_offset;
    u32 is_repeat;
    u32 timeline_id;
    u32 insert_ntp;
    char* temi_url;
    char* last_temi_url;
    u32 cts_dts_shift;
    u32 dsi_size;
    void* dsi;
    u32 mtype;
    u32 mstype;
    u32 nb_repeat_last;
    u32 image_repeat_ms;
    void* mp4;
    struct {
        u32 samples_done;
        u32 samples_count;
        u32 nb_real_streams;
        u32 real_time;
    } *source;
    u32 loop;
} GF_ESIMP4;

typedef struct {
    char* text;
} GF_WebVTTCue;

typedef struct __tag_list GF_List;

#define LLU "%llu"
#define Double double

static u32 temi_disable_loop = 0;
static u32 temi_offset = 0;
static u32 temi_period = 0;
static u64 temi_period_last_dts = 0;
static Bool temi_on = 0;
static Bool request_temi_toggle = 0;
static Bool temi_single_toggle = 0;

static u32 format_af_descriptor(char* data, u32 id, u64 tc, u32 timescale, u64 ntp, char* url, char** last_url) {
    return 0;
}

static GF_List* gf_webvtt_parse_iso_cues(GF_ISOSample* sample, u64 start) {
    return NULL;
}

static void gf_webvtt_cue_del(GF_WebVTTCue* cue) {}

static void gf_list_del(GF_List* list) {}
static void gf_list_rem(GF_List* list, u32 index) {}
static u32 gf_list_count(GF_List* list) { return 0; }
static void* gf_list_get(GF_List* list, u32 index) { return NULL; }

static GF_ISOSample* gf_isom_get_sample(void* mp4, u32 track, u32 sample_number, void* unused) {
    return NULL;
}

static void gf_isom_sample_del(GF_ISOSample** sample) {}

static u32 gf_isom_get_sample_duration(void* mp4, u32 track, u32 sample_number) {
    return 0;
}

static void gf_net_get_ntp(u32* sec, u32* frac) {}

static void gf_set_progress(const char* msg, u32 done, u32 total) {}

static u32 gf_isom_get_media_timescale(void* mp4, u32 track) {
    return 0;
}

static u32 gf_isom_get_timescale(void* mp4) {
    return 0;
}

static u64 gf_isom_get_duration(void* mp4) {
    return 0;
}

static void gf_free(void* ptr) {}

#define GF_ESI_INPUT_DATA_FLUSH 0
#define GF_ESI_INPUT_DESTROY 1
#define GF_ESI_OUTPUT_DATA_DISPATCH 2

#define GF_ESI_DATA_AU_START 0x01
#define GF_ESI_DATA_HAS_CTS 0x02
#define GF_ESI_DATA_AU_RAP 0x04
#define GF_ESI_DATA_REPEAT 0x08
#define GF_ESI_DATA_HAS_DTS 0x10
#define GF_ESI_DATA_AU_END 0x20

#define GF_ESI_STREAM_IS_OVER 0x01

#define GPAC_DISABLE_TTXT 0
#define GPAC_DISABLE_VTT 0

#define GF_ISOM_MEDIA_TEXT 0
#define GF_ISOM_SUBTYPE_WVTT 0

#define GF_LOG_DEBUG 0
#define GF_LOG_CONTAINER 0
typedef void (*GF_LOG_FUNC)(u32 level, u32 category, const char* fmt, ...);
static GF_LOG_FUNC GF_LOG = NULL;