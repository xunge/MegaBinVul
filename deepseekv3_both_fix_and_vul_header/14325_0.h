#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef int GF_Err;

#define GF_BAD_PARAM 1
#define GF_NON_COMPLIANT_BITSTREAM 2
#define GF_IO_ERR 3
#define GF_OK 0

#define MAX_MFFIELD_ALLOC 1000

typedef struct {
    u32 count;
    char* array;
} GenMFField;

#define GF_EXPORT
#define GF_SG_VRML_MFNODE 0

GF_Err gf_sg_vrml_is_sf_field(u32 FieldType);
u32 gf_sg_vrml_get_sf_size(u32 FieldType);
void gf_sg_vrml_mf_reset(void *mf, u32 FieldType);
void* gf_malloc(size_t size);