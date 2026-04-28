#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint64_t u64;
typedef int32_t GF_Err;

#define GF_OK 0
#define GF_OUT_OF_MEM 1
#define ISOM_DECREASE_SIZE(ptr, size) 
#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#ifndef GPAC_DISABLE_ISOM_WRITE
#define GPAC_DISABLE_ISOM_WRITE 0
#endif

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_List GF_List;

typedef struct {
    u32 offset_size;
    u32 length_size;
    u32 base_offset_size;
    u32 index_size;
    u32 version;
    GF_List *location_entries;
} GF_ItemLocationBox;

typedef struct {
    u32 item_ID;
    u16 construction_method;
    u16 data_reference_index;
    u64 base_offset;
    u64 original_base_offset;
    GF_List *extent_entries;
} GF_ItemLocationEntry;

typedef struct {
    u64 extent_index;
    u64 extent_offset;
    u64 extent_length;
    u64 original_extent_offset;
} GF_ItemExtentEntry;

GF_List *gf_list_new();
void gf_list_add(GF_List *list, void *item);
u16 gf_bs_read_u16(GF_BitStream *bs);
u32 gf_bs_read_u32(GF_BitStream *bs);
int gf_bs_read_int(GF_BitStream *bs, int bits);
void *gf_malloc(size_t size);