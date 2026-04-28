#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef int OPJ_BOOL;

#define OPJ_TRUE 1
#define OPJ_FALSE 0

typedef struct opj_flag_t opj_flag_t;
struct opj_flag_t {
    // implementation dependent
};

typedef struct opj_t1_t {
    OPJ_INT32* data;
    OPJ_UINT32 datasize;
    opj_flag_t* flags;
    OPJ_UINT32 flagssize;
    OPJ_UINT32 flags_stride;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    OPJ_BOOL encoder;
} opj_t1_t;

void* opj_aligned_malloc(size_t size);
void opj_aligned_free(void* ptr);