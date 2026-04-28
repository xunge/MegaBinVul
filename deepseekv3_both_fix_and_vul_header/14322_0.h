#include <stdint.h>

typedef int32_t s32;

typedef struct {
    int cpb_removal_delay_length_minus1;
    int dpb_output_delay_length_minus1;
    int time_offset_length;
} AVC_HRD;

typedef struct GF_BitStream GF_BitStream;

int gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
int gf_bs_read_int_log(GF_BitStream *bs, int bits, const char *name);
int gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, int idx);
int gf_bs_read_int_log_idx(GF_BitStream *bs, int bits, const char *name, int idx);

#define GF_LOG_WARNING 1
#define GF_LOG_CODING 1
void GF_LOG(int level, int category, const char *fmt, ...);