#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int Bool;
typedef int GF_Err;

#define GF_OK 0
#define GF_EOS 1
#define GF_FALSE 0
#define GF_TRUE 1
#define GF_FILTER_NO_TS 0
#define GF_FILTER_NO_BO 0
#define GF_FILTER_SAP_1 1
#define GF_BITSTREAM_READ 0

#define GF_LOG_WARNING 1
#define GF_LOG_DEBUG 2
#define GF_LOG_ERROR 3
#define GF_LOG_PARSER 4

static void GF_LOG(int level, int category, const char* fmt) {}

typedef struct {
    int num;
} GF_Fraction;

typedef struct {
    void *udta;
} GF_Filter;

typedef struct GF_FilterPacket GF_FilterPacket;

typedef struct {
    void *ipid;
    void *opid;
    void *vpid;
    u8 *adts_buffer;
    u32 adts_buffer_size;
    u32 adts_buffer_alloc;
    u8 *id3_buffer;
    u32 id3_buffer_size;
    u32 id3_buffer_alloc;
    u32 tag_size;
    u32 resume_from;
    u32 nb_frames;
    u64 byte_offset;
    u64 cts;
    u32 dts_inc;
    u32 timescale;
    u32 start_range;
    u32 sr_idx;
    Bool is_playing;
    Bool in_seek;
    Bool expart;
    int aacchcfg;
    GF_Fraction duration;
    void *bs;
    GF_FilterPacket *src_pck;
    struct {
        Bool is_mp2;
        Bool no_crc;
        u32 profile;
        u32 sr_idx;
        u32 nb_ch;
        u32 frame_size;
        u32 hdr_size;
    } hdr;
    struct {
        // Placeholder for acfg structure
    } acfg;
} GF_ADTSDmxCtx;

struct GF_FilterPacket {
    void *data;
};

extern GF_FilterPacket *gf_filter_pid_get_packet(void *pid);
extern void gf_filter_pid_drop_packet(void *pid);
extern Bool gf_filter_pid_is_eos(void *pid);
extern void gf_filter_pid_set_eos(void *pid);
extern GF_FilterPacket *gf_filter_pck_new_alloc(void *pid, u32 size, u8 **output);
extern void gf_filter_pck_set_dts(GF_FilterPacket *pck, u64 dts);
extern void gf_filter_pck_set_cts(GF_FilterPacket *pck, u64 cts);
extern void gf_filter_pck_set_duration(GF_FilterPacket *pck, u32 duration);
extern void gf_filter_pck_set_framing(GF_FilterPacket *pck, Bool start, Bool end);
extern void gf_filter_pck_set_sap(GF_FilterPacket *pck, u32 sap_type);
extern void gf_filter_pck_set_byte_offset(GF_FilterPacket *pck, u64 offset);
extern void gf_filter_pck_send(GF_FilterPacket *pck);
extern void gf_filter_pck_unref(GF_FilterPacket *pck);
extern void gf_filter_pck_ref_props(GF_FilterPacket **pck);
extern void gf_filter_pck_merge_properties(GF_FilterPacket *src, GF_FilterPacket *dst);
extern u8 *gf_filter_pck_get_data(GF_FilterPacket *pck, u32 *size);
extern u64 gf_filter_pck_get_byte_offset(GF_FilterPacket *pck);
extern u64 gf_filter_pck_get_cts(GF_FilterPacket *pck);
extern GF_ADTSDmxCtx *gf_filter_get_udta(GF_Filter *filter);
extern void *gf_bs_new(u8 *data, u32 size, int mode);
extern void gf_bs_reassign_buffer(void *bs, u8 *data, u32 size);
extern u32 gf_bs_read_int(void *bs, u32 numBits);
extern void gf_bs_skip_bytes(void *bs, u32 numBytes);
extern u64 gf_bs_get_position(void *bs);
extern void *gf_realloc(void *ptr, u32 size);
extern void gf_m4a_parse_program_config_element(void *bs, void *acfg);
extern void id3dmx_flush(GF_Filter *filter, u8 *data, u32 size, void *opid, void *vpid);
extern void adts_dmx_check_dur(GF_Filter *filter, GF_ADTSDmxCtx *ctx);
extern void adts_dmx_check_pid(GF_Filter *filter, GF_ADTSDmxCtx *ctx);
extern void adts_dmx_update_cts(GF_ADTSDmxCtx *ctx);

static const u32 GF_M4ASampleRates[] = {
    96000, 88200, 64000, 48000, 44100, 32000,
    24000, 22050, 16000, 12000, 11025, 8000, 7350
};