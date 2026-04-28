#include <stdlib.h>

typedef unsigned int u32;
typedef int GF_Err;
#define GF_OK 0
#define GF_OUT_OF_MEM -1

typedef struct {
    u32 size;
    u32 flags;
    char* URI;
    u32 scheme_type;
    u32 scheme_version;
} GF_SchemeTypeBox;

typedef struct {
    u32 size;
} GF_Box;

typedef struct {
} GF_BitStream;

u32 gf_bs_read_u32(GF_BitStream *bs);
void gf_bs_read_data(GF_BitStream *bs, char* data, u32 len);
void* gf_malloc(size_t size);

#define ISOM_DECREASE_SIZE(ptr, val) (ptr)->size -= (val)