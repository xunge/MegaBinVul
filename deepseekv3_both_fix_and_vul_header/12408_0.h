#include <stdint.h>

typedef int32_t s32;
typedef uint32_t u32;

typedef struct GF_BitStream GF_BitStream;

typedef struct {
    int state;
    u32 id;
    u32 sps_id;
    u32 mixed_nal_types;
    u32 width;
    u32 height;
    u32 conf_window;
    u32 cw_left;
    u32 cw_right;
    u32 cw_top;
    u32 cw_bottom;
    u32 output_flag_present_flag;
    u32 no_pic_partition_flag;
    u32 subpic_id_mapping_present_flag;
} VVC_PPS;

typedef struct {
    VVC_PPS pps[64];
    u32 sps_active_idx;
} VVCState;

s32 gf_bs_read_int_log(GF_BitStream *bs, u32 bits, const char *name);
s32 gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
s32 gf_bs_read_se_log(GF_BitStream *bs, const char *name);
u32 gf_bs_read_ue(GF_BitStream *bs);
s32 gf_bs_read_int_log_idx(GF_BitStream *bs, u32 bits, const char *name, u32 idx);

#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2
void GF_LOG(u32 level, u32 category, const char *fmt, ...);