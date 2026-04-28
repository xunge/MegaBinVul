#include <stdint.h>
#include <stdio.h>

#define GF_EXPORT
typedef int32_t GF_Err;
#define GF_BAD_PARAM 0
#define GF_OK 0
#define GF_LOG_DEBUG 0
#define GF_LOG_CONTAINER 0
#define GF_LOG_WARNING 0
#define GF_ISOM_BOX_TYPE_MDAT 0

typedef uint64_t u64;
#define LLU "%llu"

typedef struct GF_BitStream GF_BitStream;

typedef struct GF_BoxRegistry {
    int disabled;
} GF_BoxRegistry;

typedef struct GF_Box {
    uint32_t type;
    uint64_t size;
    GF_BoxRegistry *registry;
    void *child_boxes;
} GF_Box;

GF_Err gf_isom_box_write_listing(GF_Box *a, GF_BitStream *bs);
GF_Err gf_isom_box_array_write(GF_Box *a, void *child_boxes, GF_BitStream *bs);
u64 gf_bs_get_position(GF_BitStream *bs);
void GF_LOG(int level, int category, const char *fmt, ...);
const char *gf_4cc_to_str(uint32_t type);