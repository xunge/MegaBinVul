#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef bool Bool;

#define MAX_LHVC_LAYERS 16

#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2

typedef struct {
    int state;
    u32 id;
    u32 max_layers;
    u32 max_sub_layers;
    u32 max_layer_id;
    Bool all_layers_independent;
    Bool each_layer_is_ols;
    u32 num_ptl;
    struct {
        Bool pt_present;
        u32 ptl_max_tid;
    } ptl[16];
} VVC_VPS;

typedef struct {
    VVC_VPS vps[16];
} VVCState;

typedef struct GF_BitStream GF_BitStream;

void GF_LOG(int log_level, int log_category, const char *fmt, ...);
int gf_bs_read_int_log(GF_BitStream *bs, int bits, const char *name);
int gf_bs_read_int_log_idx(GF_BitStream *bs, int bits, const char *name, u32 idx);
int gf_bs_read_int_log_idx2(GF_BitStream *bs, int bits, const char *name, u32 idx1, u32 idx2);
void gf_bs_align(GF_BitStream *bs);
void vvc_profile_tier_level(GF_BitStream *bs, void *ptl, u32 idx);