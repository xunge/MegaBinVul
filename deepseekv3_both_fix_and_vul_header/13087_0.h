#include <stdint.h>

typedef int32_t GF_Err;
typedef uint8_t Bool;
#define GF_TRUE 1
#define GF_FALSE 0
#define GF_OK 0
#define GF_NOT_SUPPORTED -1
#define GF_BUFFER_TOO_SMALL -2
#define GF_EOS -3

typedef struct {
    Bool is_first_frame;
} GF_AV1FrameState;

typedef struct {
    void* bs;
    uint8_t obu_type;
    GF_AV1FrameState frame_state;
} GF_AV1State;

typedef struct {
    void* bs;
    void* opid;
    uint32_t timescale;
    Bool is_playing;
    GF_AV1State state;
    int bsmode;
} GF_AV1DmxCtx;

typedef struct GF_Filter GF_Filter;

typedef uint64_t u64;

extern GF_Err aom_av1_parse_temporal_unit_from_section5(void* bs, GF_AV1State* state);
extern GF_Err aom_av1_parse_temporal_unit_from_annexb(void* bs, GF_AV1State* state);
extern GF_Err aom_av1_parse_temporal_unit_from_ivf(void* bs, GF_AV1State* state);
extern void gf_av1_reset_state(GF_AV1State* state, Bool reset_bs);
extern u64 gf_bs_get_position(void* bs);
extern void gf_bs_seek(void* bs, u64 pos);
extern void av1dmx_check_pid(GF_Filter* filter, GF_AV1DmxCtx* ctx);
extern GF_Err av1dmx_parse_flush_sample(GF_Filter* filter, GF_AV1DmxCtx* ctx);

enum {
    OBUs,
    AnnexB,
    IVF
};

enum {
    OBU_TEMPORAL_DELIMITER
};

typedef void (*GF_LOG_FUNC)(int level, int domain, const char* fmt, ...);
extern GF_LOG_FUNC GF_LOG;
#define GF_LOG_WARNING 2
#define GF_LOG_MEDIA 3