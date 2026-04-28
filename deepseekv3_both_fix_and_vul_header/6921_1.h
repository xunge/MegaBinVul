#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;
#define GF_TRUE 1
#define GF_FALSE 0

typedef struct {
    int num;
    int den;
} GF_Fraction;

typedef struct {
    u32 num;
    u32 den;
} GF_Fraction64;

typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_List GF_List;

typedef struct HEVC_SPS {
    u32 colour_description_present_flag;
    u32 colour_primaries;
    u32 transfer_characteristic;
    u32 matrix_coeffs;
    u32 video_full_range_flag;
} HEVC_SPS;

typedef struct AVC_VUI {
    u32 colour_description_present_flag;
    u32 colour_primaries;
    u32 transfer_characteristics;
    u32 matrix_coefficients;
    u32 video_full_range_flag;
} AVC_VUI;

typedef struct {
    GF_FilterPid *opid;
    GF_FilterPid *ipid;
    Bool analyze;
    Bool ps_modified;
    GF_List *sps;
    GF_List *pps;
    Bool notime;
    GF_Fraction cur_fps;
    GF_Fraction fps;
    u32 codecid;
    u32 width;
    u32 height;
    GF_Fraction sar;
    u32 crc_cfg;
    u32 crc_cfg_enh;
    u32 nb_slices_in_au;
    u32 timescale;
    char *log_name;
    GF_List *pck_queue;
    Bool interlaced;
    Bool explicit;
    u32 bitrate;
    GF_List *vps;
    GF_Fraction64 duration;
    Bool is_file;
    struct {
        HEVC_SPS *sps;
        u32 sps_active_idx;
    } *hevc_state;
    struct {
        struct {
            AVC_VUI vui;
            u32 vui_parameters_present_flag;
        } *sps;
        u32 sps_active_idx;
    } *avc_state;
} GF_NALUDmxCtx;

enum {
    GF_CODECID_HEVC,
    GF_CODECID_VVC,
    GF_CODECID_SVC,
    GF_CODECID_LHVC,
    GF_CODECID_AVC
};

enum {
    GF_STREAM_VISUAL
};

enum {
    GF_PROP_PID_STREAM_TYPE,
    GF_PROP_PID_UNFRAMED,
    GF_PROP_PID_ID,
    GF_PROP_PID_WIDTH,
    GF_PROP_PID_HEIGHT,
    GF_PROP_PID_WIDTH_MAX,
    GF_PROP_PID_HEIGHT_MAX,
    GF_PROP_PID_SAR,
    GF_PROP_PID_FPS,
    GF_PROP_PID_TIMESCALE,
    GF_PROP_PID_CODECID,
    GF_PROP_PID_DECODER_CONFIG,
    GF_PROP_PID_DECODER_CONFIG_ENHANCEMENT,
    GF_PROP_PID_BITRATE,
    GF_PROP_PID_DURATION,
    GF_PROP_PID_PLAYBACK_MODE,
    GF_PROP_PID_INTERLACED,
    GF_PROP_PID_COLR_PRIMARIES,
    GF_PROP_PID_COLR_TRANSFER,
    GF_PROP_PID_COLR_MX,
    GF_PROP_PID_COLR_RANGE
};

enum {
    GF_PLAYBACK_MODE_FASTFORWARD
};

typedef enum {
    GF_LOG_DEBUG,
    GF_LOG_ERROR,
    GF_LOG_WARNING
} GF_LogLevel;

typedef enum {
    GF_LOG_MEDIA
} GF_LogModule;

typedef enum {
    GF_OK
} GF_Err;

typedef struct {
    u32 value;
} PROP_UINT_T;

typedef struct {
    GF_Fraction value;
} PROP_FRAC_T;

typedef struct {
    GF_Fraction64 value;
} PROP_FRAC64_T;

typedef struct {
    Bool value;
} PROP_BOOL_T;

typedef struct {
    u8 *data;
    u32 size;
} PROP_DATA_NO_COPY_T;

#define PROP_UINT(x) ((PROP_UINT_T){x})
#define PROP_FRAC(x) ((PROP_FRAC_T){x})
#define PROP_FRAC64(x) ((PROP_FRAC64_T){x})
#define PROP_BOOL(x) ((PROP_BOOL_T){x})
#define PROP_DATA_NO_COPY(p, s) ((PROP_DATA_NO_COPY_T){p, s})

u32 gf_crc_32(const u8 *data, u32 size);
void gf_free(void *ptr);
u32 gf_list_count(const GF_List *list);
GF_FilterPid *gf_filter_pid_new(GF_Filter *filter);
void gf_filter_pid_copy_properties(GF_FilterPid *dst, GF_FilterPid *src);
void gf_filter_pid_set_property(GF_FilterPid *pid, u32 prop, void *value);
void *gf_filter_pid_get_property(GF_FilterPid *pid, u32 prop);
void GF_LOG(GF_LogLevel level, GF_LogModule module, const char *fmt, ...);

Bool naludmx_create_hevc_decoder_config(GF_NALUDmxCtx *ctx, u8 **dsi, u32 *dsi_size, u8 **dsi_enh, u32 *dsi_enh_size, 
                                      u32 *w, u32 *h, u32 *ew, u32 *eh, GF_Fraction *sar, Bool *has_hevc_base);
Bool naludmx_create_vvc_decoder_config(GF_NALUDmxCtx *ctx, u8 **dsi, u32 *dsi_size, u8 **dsi_enh, u32 *dsi_enh_size,
                                      u32 *w, u32 *h, u32 *ew, u32 *eh, GF_Fraction *sar, Bool *has_hevc_base);
Bool naludmx_create_avc_decoder_config(GF_NALUDmxCtx *ctx, u8 **dsi, u32 *dsi_size, u8 **dsi_enh, u32 *dsi_enh_size,
                                      u32 *w, u32 *h, u32 *ew, u32 *eh, GF_Fraction *sar);
void naludmx_check_dur(GF_Filter *filter, GF_NALUDmxCtx *ctx);
void naludmx_end_access_unit(GF_NALUDmxCtx *ctx);
void naludmx_enqueue_or_dispatch(GF_NALUDmxCtx *ctx, void *data, Bool flush);
GF_Err naludmx_set_hevc_oinf(GF_NALUDmxCtx *ctx, void *data);
void naludmx_set_hevc_linf(GF_NALUDmxCtx *ctx);
void naludmx_update_clli_mdcv(GF_NALUDmxCtx *ctx, Bool update);
void naludmx_set_dolby_vision(GF_NALUDmxCtx *ctx);