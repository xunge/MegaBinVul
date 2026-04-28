#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef struct GenMFField GenMFField;

struct GenMFField {
    u32 count;
    void *array;
};

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

#define GF_EXPORT
#define GF_SG_VRML_MFNODE 0

GF_Err gf_sg_vrml_is_sf_field(u32 FieldType);
u32 gf_sg_vrml_get_sf_size(u32 FieldType);