#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned char u8;
typedef int GF_Err;

#define GF_OK 0

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_TextConfigBox GF_TextConfigBox;

struct GF_TextConfigBox {
    u32 size;
    char *config;
};

char *gf_strdup(const char *s);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
u8 gf_bs_read_u8(GF_BitStream *bs);