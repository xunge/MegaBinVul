#include <stdlib.h>
#include <stdint.h>

typedef int32_t GF_Err;
typedef struct GF_Box GF_Box;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_AdobeFragRandomAccessBox GF_AdobeFragRandomAccessBox;
typedef struct GF_AfraEntry GF_AfraEntry;
typedef struct GF_GlobalAfraEntry GF_GlobalAfraEntry;
typedef struct GF_List GF_List;

#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1
#define GF_OUT_OF_MEM 2

#define ISOM_DECREASE_SIZE(ptr, size) 

struct GF_AdobeFragRandomAccessBox {
    uint32_t size;
    uint8_t long_ids;
    uint8_t long_offsets;
    uint8_t global_entries;
    uint8_t reserved;
    uint32_t time_scale;
    uint32_t entry_count;
    GF_List *local_access_entries;
    uint32_t global_entry_count;
    GF_List *global_access_entries;
};

struct GF_AfraEntry {
    uint64_t time;
    uint64_t offset;
};

struct GF_GlobalAfraEntry {
    uint64_t time;
    uint32_t segment;
    uint32_t fragment;
    uint64_t afra_offset;
    uint64_t offset_from_afra;
};

uint8_t gf_bs_read_int(GF_BitStream *bs, int bits);
uint32_t gf_bs_read_u32(GF_BitStream *bs);
uint16_t gf_bs_read_u16(GF_BitStream *bs);
uint64_t gf_bs_read_u64(GF_BitStream *bs);
void *gf_malloc(size_t size);
void gf_list_insert(GF_List *list, void *item, unsigned int position);