#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef int Bool;
#define GF_TRUE 1
#define GF_FALSE 0

#define GF_AVC_NALU_SVC_SUBSEQ_PARAM 14

#define GF_LOG_INFO 1
#define GF_LOG_MEDIA 2

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
    struct {
        u8 par_num;
        u8 par_den;
        u8 timing_info_present_flag;
        u32 time_scale;
        u32 num_units_in_tick;
        u8 fixed_frame_rate_flag;
        u8 pic_struct_present_flag;
    } vui;
    u8 vui_parameters_present_flag;
} AVC_SPS;

typedef struct {
    u8 pic_struct;
} GF_AVCSEIPicTiming;

typedef struct {
    GF_AVCSEIPicTiming pic_timing;
} GF_AVCSEI;

typedef struct {
    u8 field_pic_flag;
} GF_AVCSliceInfo;

typedef struct {
    AVC_SPS *sps;
    GF_AVCSliceInfo s_info;
    GF_AVCSEI sei;
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
    u32 nal_length;
    Bool is_mvc;
    Bool explicit;
    Bool analyze;
    Bool notime;
    Bool interlaced;
    char *log_name;
    u32 dts;
    GF_Fraction fps;
    GF_Fraction cur_fps;
    void *sps;
    void *sps_ext;
    void *pps;
    void *pps_svc;
    GF_AVCState *avc_state;
} GF_NALUDmxCtx;

/* Function prototypes */
GF_AVCConfig *gf_odf_avc_cfg_new(void);
void gf_odf_avc_cfg_del(GF_AVCConfig *cfg);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
void gf_list_add(void *list, void *item);
void *gf_list_new(void);
void gf_list_reset(void *list);
void gf_odf_avc_cfg_write(GF_AVCConfig *cfg, u8 **dsi, u32 *dsi_size);
Bool gf_avcc_use_extensions(u8 profile);
void GF_LOG(int level, int media, const char *fmt, ...);