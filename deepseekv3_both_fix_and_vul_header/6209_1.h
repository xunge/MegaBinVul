#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef int GF_Err;

#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_NOT_SUPPORTED 2
#define GF_OUT_OF_MEM 3

#define GF_ISOM_BOX_TYPE_STZ2 0x73747A32
#define GF_LOG_ERROR 1
#define GF_LOG_CONTAINER 2

#define CHECK_PACK(x) 
#define ALLOC_INC(x) x += (x>>1) + 1

typedef struct {
    u32 sampleCount;
    u32 sampleSize;
    u32 *sizes;
    u32 alloc_size;
    u32 type;
} GF_SampleSizeBox;

void *gf_malloc(size_t size);
void *gf_realloc(void *ptr, size_t size);
void gf_free(void *ptr);

void GF_LOG(int log_level, int log_tool, const char *fmt, ...);