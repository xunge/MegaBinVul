#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int32_t GF_Err;
#define GF_OK 0
#define GF_OUT_OF_MEM -1
#define GF_ISOM_INVALID_FILE -2

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;

typedef struct {
    uint32_t version;
    uint16_t item_ID;
    uint16_t item_protection_index;
    uint32_t item_type;
    char *item_name;
    char *content_type;
    char *content_encoding;
    uint64_t size;
} GF_ItemInfoEntryBox;

#define ISOM_DECREASE_SIZE(ptr, val) do { (ptr)->size -= (val); } while(0)

uint16_t gf_bs_read_u16(GF_BitStream *bs);
uint32_t gf_bs_read_u32(GF_BitStream *bs);
uint32_t gf_bs_read_data(GF_BitStream *bs, char *data, uint32_t size);
void *gf_malloc(size_t size);
void gf_free(void *ptr);

#define GF_LOG_WARNING 1
#define GF_LOG_CONTAINER 2
void GF_LOG(int level, int category, const char *format, ...);

typedef uint32_t u32;