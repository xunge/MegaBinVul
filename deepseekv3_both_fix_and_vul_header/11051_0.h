#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef int GF_Err;

#define GF_OK 0

typedef struct {
    u8 profile;
    u8 level;
    u32 pathComponents;
    u32 fullRequestHost;
    u32 streamType;
    u32 containsRedundant;
    char* textEncoding;
    char* contentEncoding;
} GF_DIMSSceneConfigBox;

typedef struct GF_Box GF_Box;
typedef struct GF_BitStream GF_BitStream;

u8 gf_bs_read_u8(GF_BitStream* bs);
u32 gf_bs_read_int(GF_BitStream* bs, u32 bits);
char* gf_strdup(const char* str);
#define ISOM_DECREASE_SIZE(p, size)