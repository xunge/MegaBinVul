#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int64_t s64;
typedef uint8_t u8;
typedef bool Bool;

#define GF_TRUE true
#define GF_FALSE false
#define GF_OK 0
#define GF_NOT_SUPPORTED -1
#define GF_OUT_OF_MEM -2

#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_CONTAINER 3

#define GF_ISOM_BRAND_ISO6 0x69736F36
#define GF_ISOM_BRAND_ISO5 0x69736F35
#define GF_ISOM_BRAND_ISOM 0x69736F6D
#define GF_ISOM_BRAND_ISO1 0x69736F31
#define GF_ISOM_BRAND_ISO2 0x69736F32
#define GF_ISOM_BRAND_ISO3 0x69736F33
#define GF_ISOM_BRAND_ISO4 0x69736F34
#define GF_ISOM_BRAND_AVC1 0x61766331
#define GF_ISOM_BRAND_MP41 0x6D703431
#define GF_ISOM_BRAND_MP42 0x6D703432
#define GF_ISOM_BRAND_DSMS 0x64736D73
#define GF_ISOM_BRAND_DASH 0x64617368
#define GF_ISOM_BRAND_MSIX 0x6D736978

#define GF_ISOM_FRAG_DEF_IS_SYNC 1
#define GF_ISOM_FRAG_USE_SYNC_TABLE 2
#define GF_ISOM_TFHD_FORCE_MOOF_BASE_OFFSET 1
#define GF_ISOM_BOX_TYPE_FREE 0x66726565
#define GF_BITSTREAM_WRITE 1
#define GF_4CC(a,b,c,d) ((a)<<24|(b)<<16|(c)<<8|(d))
#define GF_4CC_MSIZE 4
#define GF_FILTER_NO_TS 0xFFFFFFFFFFFFFFFF
#define GPAC_VERSION "1.0.0"

typedef struct {
    int64_t num;
    uint32_t den;
} GF_Fraction64;

typedef struct {
    u32 track_id;
    u32 track_num;
    u32 src_timescale;
    u32 tk_timescale;
    u32 stsd_idx;
    u32 codecid;
    u32 stream_type;
    u32 raw_audio_bytes_per_sample;
    u32 cenc_state;
    u64 tfdt_offset;
    GF_Fraction64 pid_dur;
    void *ipid;
    void *dgl_copy;
    Bool fake_track;
    Bool box_patched;
} TrackWriter;

typedef struct {
    void *file;
    void *tracks;
    void *opid;
    void *dst_pck;
    char *boxpatch;
    char *styp;
    char *cur_file_suffix;
    GF_Fraction64 dur;
    GF_Fraction64 tfdt;
    GF_Fraction64 cdur;
    GF_Fraction64 dash_dur;
    u32 cur_file_idx_plus_one;
    u32 moovts;
    u32 sidx_max_size;
    u32 sidx_chunk_offset;
    u32 current_offset;
    u32 current_size;
    u32 media_dur;
    u32 subs_sidx;
    u64 next_frag_start;
    u64 adjusted_next_frag_start;
    Bool single_file;
    Bool noinit;
    Bool notify_filename;
    Bool dash_mode;
    Bool cmaf;
    Bool nofragdef;
    Bool refrag;
    Bool abs_offset;
    Bool init_movie_done;
    Bool fragment_started;
    Bool first_pck_sent;
    Bool store_output;
    Bool sidx_size_exact;
    Bool chain_sidx;
    Bool ssix;
    Bool box_patched;
    void *mvex;
    void *sseg;
    void *ref_tkw;
    void *ctrn;
    void *ctrni;
    int vodcache;
} GF_MP4MuxCtx;

enum {
    GF_CODECID_PNG,
    GF_CODECID_JPEG,
    GF_CODECID_J2K,
    GF_CODECID_HEVC,
    GF_CODECID_HEVC_TILES
};

enum {
    GF_STREAM_AUDIO,
    GF_STREAM_TEXT,
    GF_STREAM_VISUAL
};

enum {
    CENC_NEED_SETUP,
    CENC_CONFIG
};

enum {
    MP4MX_DASH_VOD
};

enum {
    MP4MX_VODCACHE_REPLACE,
    MP4MX_VODCACHE_ON
};

enum {
    GF_PROP_PCK_FILENUM,
    GF_PROP_PCK_FILESUF,
    GF_PROP_PCK_FILENAME,
    GF_PROP_PID_DURATION,
    GF_PROP_PID_CONSTANT_DURATION,
    GF_PROP_PID_HAS_SYNC,
    GF_PROP_PID_ISOM_TREX_TEMPLATE,
    GF_PROP_PID_DASH_SEGMENTS
};

typedef struct {
    uint32_t type;
    union {
        uint32_t uint;
        char *string;
        void *ptr;
        size_t size;
        GF_Fraction64 lfrac;
        struct {
            void *ptr;
            size_t size;
        } data;
        bool boolean;
    } value;
} GF_PropertyValue;

typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_BitStream GF_BitStream;

void gf_list_del_item(void *list, void *item);
void* gf_list_get(void *list, u32 index);
u32 gf_list_count(void *list);
void gf_list_insert(void *list, void *item, u32 index);
GF_FilterPacket* gf_filter_pid_get_packet(void *pid);
bool gf_filter_pid_is_eos(void *pid);
void gf_filter_pck_discard(GF_FilterPacket *pck);
GF_PropertyValue* gf_filter_pck_get_property(GF_FilterPacket *pck, u32 prop);
GF_PropertyValue* gf_filter_pid_get_property(void *pid, u32 prop);
GF_PropertyValue* gf_filter_pid_get_property_str(void *pid, const char *prop);
u32 gf_filter_pck_get_duration(GF_FilterPacket *pck);
u64 gf_filter_pck_get_dts(GF_FilterPacket *pck);
u64 gf_filter_pck_get_cts(GF_FilterPacket *pck);
u32 gf_filter_pck_get_timescale(GF_FilterPacket *pck);
void gf_filter_pck_get_data(GF_FilterPacket *pck, u32 *size);
GF_FilterPacket* gf_filter_pck_new_alloc(void *pid, u32 size, u8 **output);
void gf_filter_pck_set_framing(GF_FilterPacket *pck, bool arg1, bool arg2);
void gf_filter_pck_send(GF_FilterPacket *pck);
char* gf_strdup(const char *str);
char* gf_4cc_to_str(u32 fourcc);
GF_Err gf_isom_setup_track_fragment(void *file, u32 track_id, u32 stsd_idx, u32 def_pck_dur, u32 def_samp_size, u8 def_is_rap, u32 arg6, u32 arg7, bool arg8);
GF_Err gf_isom_setup_track_fragment_template(void *file, u32 track_id, void *data, size_t size, bool nofragdef);
void gf_isom_set_fragment_option(void *file, u32 arg1, u32 option, bool value);
void gf_isom_get_brand_info(void *file, u32 *major, u32 *minor, u32 *count);
u32 gf_isom_get_alternate_brand(void *file, u32 index, u32 *brand);
void gf_isom_set_brand_info(void *file, u32 brand, u32 version);
void gf_isom_modify_alternate_brand(void *file, u32 brand, bool add);
void gf_isom_purge_track_reference(void *file, u32 track_num);
GF_Err gf_isom_finalize_for_fragment(void *file, bool dash_mode, void *mvex);
GF_Err gf_isom_apply_box_patch(void *file, u32 track_id, const char *patch, bool arg3);
void gf_isom_set_movie_duration(void *file, u64 duration, bool arg2);
void gf_isom_allocate_sidx(void *file, int subs_sidx, bool chain_sidx, u32 arg4, void *arg5, void *arg6, void *arg7, bool ssix);
void gf_isom_enable_traf_inherit(void *file, u32 track_id, u32 inherit_from);
GF_BitStream* gf_bs_new(void *data, u32 size, u32 mode);
void gf_bs_write_u32(GF_BitStream *bs, u32 value);
void gf_bs_write_data(GF_BitStream *bs, const char *data, u32 size);
void gf_bs_del(GF_BitStream *bs);
const char* gf_error_to_string(GF_Err err);
void GF_LOG(u32 level, u32 category, const char *fmt, ...);
u64 gf_timestamp_rescale(u64 ts, u32 old_timescale, u32 new_timescale);
bool gf_timestamp_greater(u64 ts1, u32 scale1, u64 ts2, u32 scale2);
GF_Err mp4_mux_cenc_update(GF_MP4MuxCtx *ctx, TrackWriter *tkw, GF_FilterPacket *pck, u32 config, u32 arg4, u32 arg5);
GF_Err mp4_mux_set_hevc_groups(GF_MP4MuxCtx *ctx, TrackWriter *tkw);
GF_Err mp4_mux_track_writer_del(TrackWriter *tkw);
GF_Err mp4_mux_flush_seg(GF_MP4MuxCtx *ctx, bool arg1, u32 arg2, u32 arg3, bool arg4);
GF_Err mp4mx_setup_dash_vod(GF_MP4MuxCtx *ctx, void *arg1);