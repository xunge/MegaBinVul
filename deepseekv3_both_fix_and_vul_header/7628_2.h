#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int GF_Err;
#define GF_OK 0
#define GF_OUT_OF_MEM -1

typedef uint32_t u32;

typedef struct {
    size_t size;
} GF_Box;

typedef struct {
    GF_Box box;
    char* content_script_types;
} GF_DIMSScriptTypesBox;

typedef struct {
} GF_BitStream;

void* gf_malloc(size_t size);
void gf_bs_read_data(GF_BitStream* bs, void* data, size_t size);
unsigned char gf_bs_read_u8(GF_BitStream* bs);
char* gf_strdup(const char* str);
#define ISOM_DECREASE_SIZE(p, i) ((p)->box.size -= (i))