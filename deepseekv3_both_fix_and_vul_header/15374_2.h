#include <stdlib.h>

typedef unsigned int u32;
typedef int GF_Err;

#define GF_EXPORT
#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_SG_VRML_MFSTRING 0
#define GF_SG_VRML_MFURL 1
#define GF_SG_VRML_MFSCRIPT 2

typedef struct GenMFField {
    void *array;
    u32 count;
} GenMFField;

typedef struct {
    void *data;
} MFString;

typedef struct {
    void *data;
} MFURL;

typedef struct {
    void *data;
} MFScript;

extern int gf_sg_vrml_is_sf_field(u32 FieldType);
extern int gf_sg_vrml_get_sf_size(u32 FieldType);
extern void gf_sg_mfstring_del(MFString mf);
extern void gf_sg_mfurl_del(MFURL mf);
extern void gf_sg_mfscript_del(MFScript mf);
extern void gf_free(void *ptr);