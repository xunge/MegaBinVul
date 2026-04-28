#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define GF_EXPORT
typedef int GF_Err;
#define GF_BAD_PARAM 1
#define GF_OK 0
#define GF_OUT_OF_MEM 2
#define GF_IO_ERR 3
#define GF_UTF8_FAIL 4

void *gf_malloc(size_t size);
void gf_free(void *ptr);
u32 gf_utf8_wcstombs(char *dst, u32 size, const unsigned short **srcwc);