#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef bool Bool;

#define GF_TRUE true
#define GF_FALSE false
#define GF_AVC_NALU_SVC_SUBSEQ_PARAM 14

enum {
    GF_LOG_INFO,
    GF_LOG_MEDIA
};

typedef struct {
    int num;
    int den;
} GF_Fraction;

typedef struct {
    u8 profile_idc;
    u8 prof_compat;
    u8 level_idc;
    u8 chroma_format;
    u8 luma_bit_depth_m8;
    u8 chroma_bit_depth_m8;
    u32 width;
    u32 height;
    u8 frame_mbs_only_flag;
    u8 vui_parameters_present_flag;
    struct {
        u32 par_num;
        u32 par_den;
        u8 timing_info_present_flag;
        u32 time_scale;
        u32 num_units_in_tick;
        u8 fixed_frame_rate_flag;
        u8 pic_struct_present_flag;
    } vui;
} AVC_SPS;

typedef struct {
    AVC_SPS *sps;
    struct {
        u8 field_pic_flag;
    } s_info;
    struct {
        struct {
            u8 pic_struct;
        } pic_timing;
    } sei;
} GF_AVCState;

typedef struct {
    u8 *data;
    u32 id;
} GF_NALUFFParam;

typedef struct {
    u8 configurationVersion;
    u8 AVCProfileIndication;
    u8 profile_compatibility;
    u8 AVCLevelIndication;
    u8 chroma_format;
    u8 luma_bit_depth;
    u8 chroma_bit_depth;
    u8 nal_unit_size;
    void *sequenceParameterSets;
    void *sequenceParameterSetExtensions;
    void *pictureParameterSets;
} GF_AVCConfig;

typedef struct {
    Bool analyze;
    Bool explicit;
    Bool is_mvc;
    Bool notime;
    Bool interlaced;
    u32 nal_length;
    u32 dts;
    GF_Fraction fps;
    GF_Fraction cur_fps;
    char *log_name;
    GF_AVCState *avc_state;
    void *sps;
    void *pps;
    void *sps_ext;
    void *pps_svc;
} GF_NALUDmxCtx;

GF_AVCConfig *gf_odf_avc_cfg_new();
void gf_odf_avc_cfg_del(GF_AVCConfig *cfg);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
void gf_list_add(void *list, void *item);
void gf_list_reset(void *list);
void *gf_list_new();
Bool gf_avcc_use_extensions(u8 profile);
void gf_odf_avc_cfg_write(GF_AVCConfig *cfg, u8 **dsi, u32 *dsi_size);
void GF_LOG(int level, int media, const char *fmt, ...);