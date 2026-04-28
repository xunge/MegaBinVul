#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

typedef struct {
    u32 obu_length;
    u32 obu_type;
    void* obu;
} GF_AV1_OBUArrayEntry;

typedef struct {
    u32 marker;
    u32 version;
    u32 seq_profile;
    u32 seq_level_idx_0;
    u32 seq_tier_0;
    u32 high_bitdepth;
    u32 twelve_bit;
    u32 monochrome;
    u32 chroma_subsampling_x;
    u32 chroma_subsampling_y;
    u32 chroma_sample_position;
    u32 initial_presentation_delay_present;
    u32 initial_presentation_delay_minus_one;
    void* obu_array;
} GF_AV1Config;

void* gf_malloc(size_t size);
void* gf_list_new();
u32 gf_list_count(void* list);
void* gf_list_get(void* list, u32 index);
void gf_list_add(void* list, void* item);