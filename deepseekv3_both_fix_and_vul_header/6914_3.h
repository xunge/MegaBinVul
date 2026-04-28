#include <stdlib.h>
#include <stdint.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;

#define GF_OK 0
#define GF_OUT_OF_MEM 1
#define GF_ISOM_INVALID_FILE 2

#define ISOM_DECREASE_SIZE(ptr, size)

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_List GF_List;

typedef struct GF_AdobeFragmentRunEntry {
    u32 first_fragment;
    u64 first_fragment_timestamp;
    u32 fragment_duration;
    u8 discontinuity_indicator;
} GF_AdobeFragmentRunEntry;

typedef struct GF_AdobeFragmentRunTableBox {
    GF_Box *s;
    u32 timescale;
    u8 quality_entry_count;
    u32 fragment_run_entry_count;
    GF_List *quality_segment_url_modifiers;
    GF_List *fragment_run_entry_table;
    u32 size;
} GF_AdobeFragmentRunTableBox;

extern GF_List *gf_list_new();
extern void gf_list_add(GF_List *list, void *item);
extern void gf_list_insert(GF_List *list, void *item, u32 position);
extern u32 gf_bs_read_u32(GF_BitStream *bs);
extern u64 gf_bs_read_u64(GF_BitStream *bs);
extern u8 gf_bs_read_u8(GF_BitStream *bs);
extern void *gf_malloc(size_t size);