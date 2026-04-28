#include <stdlib.h>
#include <stdint.h>

typedef int GF_Err;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_XtraBox GF_XtraBox;
typedef struct GF_XtraTag GF_XtraTag;
typedef struct GF_List GF_List;

#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1
#define GF_LOG_WARNING 1
#define GF_LOG_CONTAINER 2

#define ISOM_DECREASE_SIZE_NO_ERR(ptr, size)
#define GF_SAFEALLOC(ptr, type)

struct GF_XtraBox {
    uint32_t size;
    GF_List *tags;
};

struct GF_XtraTag {
    uint32_t flags;
    char *name;
    uint32_t prop_size;
    char *prop_value;
    uint16_t prop_type;
};

typedef uint32_t u32;
typedef int32_t s32;
typedef uint16_t u16;

void gf_bs_read_data(GF_BitStream *bs, char *data, u32 size);
u32 gf_bs_read_u32(GF_BitStream *bs);
u16 gf_bs_read_u16(GF_BitStream *bs);
void *gf_malloc(size_t size);
void gf_list_add(GF_List *list, void *item);
void GF_LOG(int log_level, int log_type, const char *fmt, ...);