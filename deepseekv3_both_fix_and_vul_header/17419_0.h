#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef int GF_Err;

typedef struct {
    u32 size;
    char *nameURN;
    char *location;
} GF_DataEntryURNBox;

typedef struct {
    u32 size;
} GF_Box;

typedef struct GF_BitStream GF_BitStream;

GF_Err GF_OK;
GF_Err GF_OUT_OF_MEM;
GF_Err GF_ISOM_INVALID_FILE;

void *gf_malloc(size_t size);
void gf_free(void *ptr);
void gf_bs_read_data(GF_BitStream *bs, void *data, u32 size);