#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef int GF_Err;
#define GF_EXPORT
#define GF_NON_COMPLIANT_BITSTREAM 0
#define GF_BAD_PARAM 0
#define GF_OK 0

typedef struct {
    void *array;
    u32 count;
} GenMFField;

extern u32 gf_sg_vrml_get_sf_size(u32 FieldType);
extern void *gf_malloc(size_t size);
extern void gf_free(void *ptr);