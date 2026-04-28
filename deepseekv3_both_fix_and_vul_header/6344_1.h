#include <stdint.h>
#include <string.h>

#define MAX_LHVC_LAYERS 64
#define GF_FALSE 0
#define GF_TRUE 1
#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2

typedef uint8_t u8;
typedef uint32_t u32;
typedef int Bool;

typedef struct {
    u8 scalability_mask[16];
    u8 layer_id_in_nuh[MAX_LHVC_LAYERS];
    u8 layer_id_in_vps[MAX_LHVC_LAYERS];
    u8 dimension_id[MAX_LHVC_LAYERS][16];
    u8 direct_dependency_flag[MAX_LHVC_LAYERS][MAX_LHVC_LAYERS];
    u32 max_layers;
    u32 max_sub_layers;
    u32 num_layer_sets;
    u32 num_layers_in_id_list[MAX_LHVC_LAYERS];
    u32 LayerSetLayerIdList[MAX_LHVC_LAYERS][MAX_LHVC_LAYERS];
    u32 LayerSetLayerIdListMax[MAX_LHVC_LAYERS];
    u32 num_output_layer_sets;
    u8 output_layer_flag[MAX_LHVC_LAYERS][MAX_LHVC_LAYERS];
    Bool necessary_layers_flag[MAX_LHVC_LAYERS][MAX_LHVC_LAYERS];
    u32 num_necessary_layers[MAX_LHVC_LAYERS];
    u32 profile_tier_level_idx[MAX_LHVC_LAYERS][MAX_LHVC_LAYERS];
    u8 alt_output_layer_flag[MAX_LHVC_LAYERS];
    u32 num_rep_formats;
    u8 rep_format_idx[MAX_LHVC_LAYERS];
    void* rep_formats[16];
    u32 num_profile_tier_level;
    Bool base_layer_internal_flag;
    Bool vps_extension_found;
    void* ext_ptl[MAX_LHVC_LAYERS];
} HEVC_VPS;

typedef struct {
    // GF_BitStream placeholder
} GF_BitStream;

static void GF_LOG(int level, int category, const char* fmt, ...);
static u32 gf_bs_read_int_log(GF_BitStream* bs, u32 num_bits, const char* name);
static u32 gf_bs_read_int_log_idx(GF_BitStream* bs, u32 num_bits, const char* name, u32 idx);
static u32 gf_bs_read_int_log_idx2(GF_BitStream* bs, u32 num_bits, const char* name, u32 idx1, u32 idx2);
static u32 gf_bs_read_ue_log(GF_BitStream* bs, const char* name);
static void hevc_profile_tier_level(GF_BitStream* bs, Bool profile_present, u32 max_sub_layers, void* ptl, u32 idx);
static u32 lhvc_get_num_views(HEVC_VPS* vps);
static void lhvc_parse_rep_format(void* rep_format, GF_BitStream* bs, u32 idx);