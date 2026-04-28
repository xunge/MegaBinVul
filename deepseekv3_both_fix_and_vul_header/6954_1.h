#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
#define GF_TRUE 1
#define GF_FALSE 0

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;

typedef enum {
    GF_OK = 0,
    GF_NOT_SUPPORTED,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef struct {
    u32 width;
    u32 height;
} HEVCSPS;

typedef struct {
    u32 num_tile_columns;
    u32 num_tile_rows;
    u8 loop_filter_across_tiles_enabled_flag;
    u8 tiles_enabled_flag;
} HEVCPPS;

typedef struct {
    HEVCSPS *sps;
    HEVCPPS *pps;
    u32 pps_count;
    u32 sps_count;
    struct {
        u8 slice_type;
    } s_info;
} HEVCState;

typedef struct {
    u32 track_id;
    u32 tx;
    u32 ty;
    u32 tw;
    u32 th;
    Bool all_intra;
    u32 sample_count;
    u32 data_offset;
    void *sample_data;
    u32 nb_nalus_in_sample;
    u32 track;
} HEVCTileImport;

typedef struct {
    u32 nal_unit_size;
    void *param_array;
} GF_HEVCConfig;

typedef struct {
    u32 dataLength;
    char *data;
} GF_ISOSample;

typedef struct {
    u32 type;
    void *nalus;
} GF_NALUFFParamArray;

typedef struct {
    u32 size;
    char *data;
} GF_NALUFFParam;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_BitStream GF_BitStream;

#define GF_ISOM_SUBTYPE_HVC1 0
#define GF_ISOM_SUBTYPE_HEV1 1
#define GF_ISOM_SUBTYPE_HVC2 2
#define GF_ISOM_SUBTYPE_HEV2 3

#define GF_HEVC_NALU_PIC_PARAM 0
#define GF_HEVC_NALU_SEQ_PARAM 1
#define GF_HEVC_NALU_VID_PARAM 2
#define GF_HEVC_NALU_SLICE_TRAIL_N 3
#define GF_HEVC_NALU_SLICE_TRAIL_R 4
#define GF_HEVC_NALU_SLICE_TSA_N 5
#define GF_HEVC_NALU_SLICE_TSA_R 6
#define GF_HEVC_NALU_SLICE_STSA_N 7
#define GF_HEVC_NALU_SLICE_STSA_R 8
#define GF_HEVC_NALU_SLICE_BLA_W_LP 9
#define GF_HEVC_NALU_SLICE_BLA_W_DLP 10
#define GF_HEVC_NALU_SLICE_BLA_N_LP 11
#define GF_HEVC_NALU_SLICE_IDR_W_DLP 12
#define GF_HEVC_NALU_SLICE_IDR_N_LP 13
#define GF_HEVC_NALU_SLICE_CRA 14
#define GF_HEVC_NALU_SLICE_RADL_R 15
#define GF_HEVC_NALU_SLICE_RADL_N 16
#define GF_HEVC_NALU_SLICE_RASL_R 17
#define GF_HEVC_NALU_SLICE_RASL_N 18

#define GF_HEVC_SLICE_TYPE_I 2

#define GF_ISOM_REF_TBAS 0
#define GF_ISOM_REF_SABT 1

#define GF_ISOM_SAMPLE_GROUP_NALM 0
#define GF_ISOM_SAMPLE_GROUP_TRIF 1

#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 1
#define GF_LOG_MEDIA 2
#define GF_LOG_CONTAINER 3

#define GF_BITSTREAM_WRITE 1

#define GF_EXPORT

u32 gf_isom_get_track_count(GF_ISOFile *file);
u32 gf_isom_get_media_subtype(GF_ISOFile *file, u32 track, u32 sample);
GF_HEVCConfig *gf_isom_hevc_config_get(GF_ISOFile *file, u32 track, u32 sample);
void gf_isom_hevc_set_tile_config(GF_ISOFile *file, u32 track, u32 sample, GF_HEVCConfig *hvcc, Bool enable);
void gf_odf_hevc_cfg_del(GF_HEVCConfig *hvcc);
GF_ISOSample *gf_isom_get_sample(GF_ISOFile *file, u32 track, u32 sample, u32 *di);
void gf_isom_sample_del(GF_ISOSample **sample);
void hevc_add_trif(GF_ISOFile *file, u32 track, u32 track_id, Bool full_pic, u32 tile_type, Bool filter_disabled, u32 tx, u32 ty, u32 tw, u32 th, Bool add_tref);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
s32 gf_hevc_read_pps(char *data, u32 size, HEVCState *hevc);
s32 gf_hevc_read_sps(char *data, u32 size, HEVCState *hevc);
void gf_hevc_read_vps(char *data, u32 size, HEVCState *hevc);
s32 gf_hevc_parse_nalu(char *data, u32 size, HEVCState *hevc, u8 *nal_type, u8 *temporal_id, u8 *layer_id);
u32 gf_isom_get_track_id(GF_ISOFile *file, u32 track);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
GF_BitStream *gf_bs_new(void *data, u32 size, u32 mode);
void gf_bs_del(GF_BitStream *bs);
void gf_bs_get_content(GF_BitStream *bs, char **data, u32 *size);
void gf_bs_write_int(GF_BitStream *bs, s32 value, u32 nbits);
void gf_bs_write_u8(GF_BitStream *bs, u8 value);
void gf_bs_write_u16(GF_BitStream *bs, u16 value);
void gf_bs_write_data(GF_BitStream *bs, char *data, u32 size);
GF_Err gf_isom_clone_track(GF_ISOFile *src_file, u32 src_track, GF_ISOFile *dst_file, u32 options, u32 *dst_track);
GF_Err gf_isom_set_track_reference(GF_ISOFile *file, u32 track, u32 ref_type, u32 ref_track);
GF_Err gf_isom_update_sample(GF_ISOFile *file, u32 track, u32 sample_num, GF_ISOSample *sample, Bool is_replace);
GF_Err gf_isom_add_sample(GF_ISOFile *file, u32 track, u32 sample_num, GF_ISOSample *sample);
GF_Err gf_isom_copy_sample_info(GF_ISOFile *dst_file, u32 dst_track, GF_ISOFile *src_file, u32 src_track, u32 sample_num);
GF_Err gf_isom_add_sample_group_info(GF_ISOFile *file, u32 track, u32 group_type, u8 *data, u32 size, u32 sample_num, u32 *sdesc);
GF_Err gf_isom_add_sample_info(GF_ISOFile *file, u32 track, u32 sample_num, u32 group_type, u32 sdesc, u32 subgroup_type);
GF_Err gf_isom_remove_track(GF_ISOFile *file, u32 track);
u32 gf_isom_get_track_by_id(GF_ISOFile *file, u32 track_id);
GF_Err gf_isom_set_visual_info(GF_ISOFile *file, u32 track, u32 sample_num, u32 width, u32 height);
GF_Err gf_isom_get_track_layout_info(GF_ISOFile *file, u32 track, u32 *width, u32 *height, s32 *translation_x, s32 *translation_y, s16 *layer);
GF_Err gf_isom_set_track_layout_info(GF_ISOFile *file, u32 track, u32 width, u32 height, s32 translation_x, s32 translation_y, s16 layer);
Bool gf_isom_has_track_reference(GF_ISOFile *file, u32 track, u32 ref_type, u32 ref_track);
u32 gf_isom_get_sample_count(GF_ISOFile *file, u32 track);
const char *gf_error_to_string(GF_Err e);
void GF_LOG(u32 level, u32 module, const char *fmt, ...);
u32 hevc_get_tile_id(HEVCState *hevc, u32 *tx, u32 *ty, u32 *tw, u32 *th);