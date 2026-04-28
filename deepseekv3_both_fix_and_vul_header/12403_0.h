#include <stdint.h>

#define MAX_LHVC_LAYERS 64
#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2

typedef int32_t s32;
typedef uint8_t u8;
typedef uint32_t u32;
typedef int Bool;
#define GF_TRUE 1

typedef struct {
    int state;
    u32 id;
    u32 max_layers;
    u32 max_sub_layers;
    u32 temporal_id_nesting;
    u32 max_layer_id;
    u32 num_layer_sets;
    u32 num_layers_in_id_list[MAX_LHVC_LAYERS];
    u32 LayerSetLayerIdList[MAX_LHVC_LAYERS][MAX_LHVC_LAYERS];
    u32 LayerSetLayerIdListMax[MAX_LHVC_LAYERS];
    int bit_pos_vps_extensions;
    u8 base_layer_internal_flag;
    u8 base_layer_available_flag;
    void *ptl;
} HEVC_VPS;

typedef struct {
    HEVC_VPS vps[16];
} HEVCState;

typedef struct GF_BitStream GF_BitStream;

void GF_LOG(int level, int category, const char *fmt, ...);
void gf_bs_align(GF_BitStream *bs);
u32 gf_bs_available(GF_BitStream *bs);
s32 gf_bs_read_int_log(GF_BitStream *bs, u32 nBits, const char *name);
s32 gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
s32 gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, u32 idx);
s32 gf_bs_read_ue_log_idx2(GF_BitStream *bs, const char *name, u32 idx1, u32 idx2);
void hevc_profile_tier_level(GF_BitStream *bs, u32 profilePresentFlag, u32 max_sub_layers_minus1, void *ptl, u32 subLayerProfilePresentFlag);
Bool hevc_parse_hrd_parameters(GF_BitStream *bs, Bool cprms_present_flag, u32 max_sub_layers_minus1, u32 idx);
Bool hevc_parse_vps_extension(HEVC_VPS *vps, GF_BitStream *bs);