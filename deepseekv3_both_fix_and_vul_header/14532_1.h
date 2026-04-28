#include <stdlib.h>

typedef unsigned int u32;
typedef int GF_Err;
typedef struct GenMFField GenMFField;
typedef struct MFString { void *dummy; } MFString;
typedef struct MFURL { void *dummy; } MFURL;
typedef struct MFScript { void *dummy; } MFScript;

#define GF_EXPORT
#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_SG_VRML_MFSTRING 0
#define GF_SG_VRML_MFURL 1
#define GF_SG_VRML_MFSCRIPT 2

struct GenMFField {
    void *array;
    u32 count;
};

GF_Err gf_sg_vrml_is_sf_field(u32 FieldType);
u32 gf_sg_vrml_get_sf_size(u32 FieldType);
void gf_sg_mfstring_del(MFString mf);
void gf_sg_mfurl_del(MFURL mf);
void gf_sg_mfscript_del(MFScript mf);
void gf_free(void *ptr);