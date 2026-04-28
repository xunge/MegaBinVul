#include <stdlib.h>

typedef unsigned int u32;
typedef int GF_Err;

#define GF_EXPORT
#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_SG_VRML_MFSTRING 1
#define GF_SG_VRML_MFURL 2
#define GF_SG_VRML_MFSCRIPT 3

typedef struct GenMFField {
    void *array;
    u32 count;
} GenMFField;

typedef struct {
    // Placeholder for MFString structure
} MFString;

typedef struct {
    // Placeholder for MFURL structure
} MFURL;

typedef struct {
    // Placeholder for MFScript structure
} MFScript;

int gf_sg_vrml_is_sf_field(u32 FieldType);
int gf_sg_vrml_get_sf_size(u32 FieldType);
void gf_sg_mfstring_del(MFString mf);
void gf_sg_mfurl_del(MFURL mf);
void gf_sg_mfscript_del(MFScript mf);
void gf_free(void *ptr);