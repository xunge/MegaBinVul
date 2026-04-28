#include <stdint.h>

typedef struct GF_BitStream GF_BitStream;
typedef uint32_t u32;
typedef int32_t s32;

u32 gf_bs_read_int(GF_BitStream *bs, u32 nBits);
u32 gf_bs_available(GF_BitStream *bs);
void gf_bs_log_idx(GF_BitStream *bs, u32 nBits, const char *fname, u32 val, s32 idx1, s32 idx2, s32 idx3);
void GF_LOG(u32 log_level, u32 log_tool, const char *fmt, ...);

#define GF_LOG_ERROR 0
#define GF_LOG_CODING 0