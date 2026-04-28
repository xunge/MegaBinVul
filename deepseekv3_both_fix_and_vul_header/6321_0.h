#include <stdlib.h>
#include <stdint.h>

typedef uint8_t Bool;
typedef uint32_t u32;
typedef int32_t GF_Err;

#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_ODF_INVALID_DESCRIPTOR 2
#define GF_NON_COMPLIANT_BITSTREAM 3

typedef struct {
    uint8_t IPMP_ToolID[16];
    uint8_t num_alternate;
    uint8_t specificToolID[256][16];
    char* tool_url;
} GF_IPMP_Tool;

typedef struct {
    // BitStream implementation details would go here
} GF_BitStream;

u32 gf_ipmpx_array_size(GF_BitStream *bs, u32 *s);
void gf_bs_read_data(GF_BitStream *bs, char* data, u32 size);
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
void* gf_malloc(size_t size);