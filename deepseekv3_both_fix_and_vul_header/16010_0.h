#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef enum {
    GF_OK,
    GF_OUT_OF_MEM,
    GF_ISOM_INVALID_FILE
} GF_Err;

typedef struct {
    u32 size;
    u8 profile;
    u8 level;
    u32 pathComponents : 4;
    u32 fullRequestHost : 1;
    u32 streamType : 1;
    u32 containsRedundant : 2;
    char* textEncoding;
    char* contentEncoding;
} GF_DIMSSceneConfigBox;

typedef struct GF_Box {
    u32 size;
} GF_Box;

typedef struct GF_BitStream GF_BitStream;

u8 gf_bs_read_u8(GF_BitStream* bs);
int gf_bs_read_int(GF_BitStream* bs, int bits);
void* gf_malloc(size_t size);
void gf_free(void* ptr);
char* gf_strdup(const char* str);

#define ISOM_DECREASE_SIZE(p, n) (p)->size -= (n)