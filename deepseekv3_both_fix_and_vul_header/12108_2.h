#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef bool Bool;

#define GF_FALSE false
#define GF_TRUE true
#define GF_STREAM_VISUAL 0
#define GF_STREAM_AUDIO 1
#define GF_STREAM_TEXT 2
#define GF_FILTER_NO_TS 0
#define MP4MX_MODE_FRAG 0
#define CENC_NEED_SETUP 0
#define CENC_CONFIG 0
#define GPAC_DISABLE_ISOM_FRAGMENTS 0
#define GF_LOG_WARNING 1
#define GF_LOG_CONTAINER 2

struct _service_info {
    u32 nb_non_sparse;
    u32 nb_non_sparse_ready;
    u32 nb_sparse;
    u32 nb_sparse_ready;
    u64 first_ts_min;
};

typedef struct {
    u32 store;
    Bool tsalign;
    Bool config_timing;
    void *tracks;
    u32 config_retry_start;
    u64 wait_dts_plus_one;
    u32 wait_dts_timescale;
    void *file;
    Bool nofragdef;
    Bool wait_sap;
} GF_MP4MuxCtx;

typedef struct {
    Bool fake_track;
    u32 nb_samples;
    u64 ts_shift;
    u32 src_timescale;
    void *ipid;
    u32 track_num;
    u32 stream_type;
    u32 cenc_state;
    void *dgl_copy;
    u32 track_id;
    Bool si_min_ts_plus_one;
    Bool wait_sap;
} TrackWriter;

typedef struct {
} GF_List;
typedef struct {
} GF_FilterPacket;
typedef struct {
} GF_PropertyValue;
typedef enum {
    GF_SAP_NONE = 0,
    GF_SAP_1 = 1,
    GF_SAP_2 = 2,
    GF_SAP_3 = 3
} GF_FilterSAPType;

void gf_list_del_item(GF_List *list, u32 index);
GF_List *gf_list_new();
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
void *gf_filter_pid_get_packet(void *pid);
Bool gf_filter_pid_is_eos(void *pid);
Bool gf_filter_pck_is_blocking_ref(void *pck);
GF_FilterSAPType gf_filter_pck_get_sap(void *pck);
Bool gf_filter_pck_get_seek_flag(void *pck);
void gf_filter_pid_drop_packet(void *pid);
u64 gf_filter_pck_get_dts(void *pck);
u64 gf_filter_pck_get_cts(void *pck);
Bool gf_timestamp_less(u64 ts1, u32 timescale1, u64 ts2, u32 timescale2);
u64 gf_timestamp_rescale(u64 ts, u32 src_timescale, u32 dst_timescale);
void *gf_filter_pid_get_property(void *pid, u32 prop);
void gf_isom_setup_track_fragment_template(void *file, u32 track_id, void *data, u32 size, Bool nofragdef);
void gf_filter_pck_discard(void *pck);
u32 gf_list_find(GF_List *list, void *item);
u32 gf_sys_clock();
void GF_LOG(u32 level, u32 category, const char *fmt, ...);

struct _service_info *get_service_info(GF_List *services, TrackWriter *tkw);
void del_service_info(GF_List *services);
void mp4_mux_cenc_update(GF_MP4MuxCtx *ctx, TrackWriter *tkw, void *pck, u32 mode, u64 cts, u64 duration);
void mp4_mux_update_init_edit(GF_MP4MuxCtx *ctx, TrackWriter *tkw, u64 first_ts_min, Bool keep_edit);