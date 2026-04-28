#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef struct GF_BitStream GF_BitStream;
typedef uint32_t u32;
typedef uint8_t u8;
typedef uint64_t u64;
typedef int64_t s64;

#define GF_EXPORT
#define GPAC_DISABLE_AV_PARSERS
#define GF_LOG(level, category, message)
#define GF_LOG_DEBUG 0
#define GF_LOG_CONTAINER 0
#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 0
#define LLU "%llu"

typedef enum {
    OBU_SEQUENCE_HEADER = 1,
    OBU_TEMPORAL_DELIMITER = 2,
    OBU_FRAME_HEADER = 3,
    OBU_TILE_GROUP = 4,
    OBU_METADATA = 5,
    OBU_FRAME = 6,
    OBU_REDUNDANT_FRAME_HEADER = 7,
    OBU_TILE_LIST = 8,
    OBU_PADDING = 15
} ObuType;

typedef struct GF_AV1Config {
    u8 marker;
    u8 version;
    u8 seq_profile;
    u8 seq_level_idx_0;
    u8 seq_tier_0;
    u8 high_bitdepth;
    u8 twelve_bit;
    u8 monochrome;
    u8 chroma_subsampling_x;
    u8 chroma_subsampling_y;
    u8 chroma_sample_position;
    u8 initial_presentation_delay_present;
    u8 initial_presentation_delay_minus_one;
    void *obu_array;
} GF_AV1Config;

typedef struct GF_AV1_OBUArrayEntry {
    void *obu;
    u64 obu_length;
    ObuType obu_type;
} GF_AV1_OBUArrayEntry;

typedef struct AV1State {
    GF_AV1Config *config;
} AV1State;

GF_AV1Config *gf_odf_av1_cfg_new(void);
void gf_odf_av1_cfg_del(GF_AV1Config *cfg);
void gf_av1_init_state(AV1State *state);
int gf_av1_parse_obu(GF_BitStream *bs, ObuType *obu_type, u64 *obu_size, void *unused, AV1State *state);
int gf_av1_reset_state(AV1State *state, int flag);
u32 gf_bs_available(GF_BitStream *bs);
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
u64 gf_bs_get_position(GF_BitStream *bs);
void gf_bs_seek(GF_BitStream *bs, u64 position);
u32 gf_bs_read_data(GF_BitStream *bs, char *buffer, u32 length);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
void *gf_list_add(void *list, void *item);
void *GF_SAFEALLOC(void *ptr, size_t size);
int av1_is_obu_header(ObuType obu_type);