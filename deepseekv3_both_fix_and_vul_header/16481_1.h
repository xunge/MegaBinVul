#include <stdint.h>
#include <stddef.h>

typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef unsigned char OPJ_BYTE;

#define OPJ_TRUE 1
#define OPJ_FALSE 0

typedef struct opj_tcd_cblk_enc_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y0;
    OPJ_UINT32 y1;
    OPJ_UINT32 data_size;
    OPJ_BYTE* data;
} opj_tcd_cblk_enc_t;

void* opj_malloc(size_t size);
void opj_free(void* ptr);