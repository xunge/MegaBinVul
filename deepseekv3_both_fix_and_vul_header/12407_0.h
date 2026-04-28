#include <stdint.h>

typedef int32_t s32;
typedef uint32_t u32;

typedef struct {
    int log2_max_poc_lsb;
    int ph_num_extra_bits;
    int poc_msb_cycle_flag;
    int poc_msb_cycle_len;
} VVCSPS;

typedef struct {
    int sps_id;
} VVCPPS;

typedef struct {
    VVCPPS pps[64];
    VVCSPS sps[64];
} VVCState;

typedef struct {
    int irap_or_gdr_pic;
    int non_ref_pic;
    int gdr_pic;
    int inter_slice_allowed_flag;
    int intra_slice_allowed_flag;
    VVCPPS *pps;
    VVCSPS *sps;
    int poc_lsb;
    int recovery_point_valid;
    int gdr_recovery_count;
    int poc_msb_cycle_present_flag;
    int poc_msb_cycle;
} VVCSliceInfo;

typedef struct GF_BitStream GF_BitStream;

int gf_bs_read_int_log(GF_BitStream *bs, int bits, const char *name);
int gf_bs_read_ue_log(GF_BitStream *bs, const char *name);