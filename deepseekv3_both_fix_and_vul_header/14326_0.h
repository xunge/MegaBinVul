#include <stdlib.h>

typedef unsigned int u32;
typedef int GF_Err;
#define GF_EXPORT
#define GF_NON_COMPLIANT_BITSTREAM 0

typedef struct {
    u32 count;
} GenMFField;

extern GF_Err gf_sg_vrml_mf_insert(void *mf, u32 FieldType, void **new_ptr, u32 position);