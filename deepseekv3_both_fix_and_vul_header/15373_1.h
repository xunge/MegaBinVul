#include <stdlib.h>
#include <assert.h>

typedef unsigned int u32;
typedef struct _GF_Node GF_Node;

typedef struct {
    char *buffer;
} SFString;

typedef void* SFImage;
typedef void* SFCommandBuffer;
typedef void* MFBool;
typedef void* MFFloat;
typedef void* MFDouble;
typedef void* MFTime;
typedef void* MFInt32;
typedef void* MFString;
typedef void* MFVec3f;
typedef void* MFVec2f;
typedef void* MFVec3d;
typedef void* MFVec2d;
typedef void* MFColor;
typedef void* MFColorRGBA;
typedef void* MFRotation;
typedef void* SFURL;
typedef void* MFURL;
typedef void* MFAttrRef;
typedef void* MFScript;

#define GF_EXPORT
#define GF_SG_VRML_SFBOOL 0
#define GF_SG_VRML_SFFLOAT 1
#define GF_SG_VRML_SFDOUBLE 2
#define GF_SG_VRML_SFTIME 3
#define GF_SG_VRML_SFINT32 4
#define GF_SG_VRML_SFVEC3F 5
#define GF_SG_VRML_SFVEC3D 6
#define GF_SG_VRML_SFVEC2F 7
#define GF_SG_VRML_SFVEC2D 8
#define GF_SG_VRML_SFCOLOR 9
#define GF_SG_VRML_SFCOLORRGBA 10
#define GF_SG_VRML_SFROTATION 11
#define GF_SG_VRML_SFATTRREF 12
#define GF_SG_VRML_SFSTRING 13
#define GF_SG_VRML_SFIMAGE 14
#define GF_SG_VRML_SFNODE 15
#define GF_SG_VRML_SFCOMMANDBUFFER 16
#define GF_SG_VRML_MFBOOL 17
#define GF_SG_VRML_MFFLOAT 18
#define GF_SG_VRML_MFDOUBLE 19
#define GF_SG_VRML_MFTIME 20
#define GF_SG_VRML_MFINT32 21
#define GF_SG_VRML_MFSTRING 22
#define GF_SG_VRML_MFVEC3F 23
#define GF_SG_VRML_MFVEC2F 24
#define GF_SG_VRML_MFVEC3D 25
#define GF_SG_VRML_MFVEC2D 26
#define GF_SG_VRML_MFCOLOR 27
#define GF_SG_VRML_MFCOLORRGBA 28
#define GF_SG_VRML_MFROTATION 29
#define GF_SG_VRML_MFVEC4F 30
#define GF_SG_VRML_SFURL 31
#define GF_SG_VRML_MFURL 32
#define GF_SG_VRML_MFATTRREF 33
#define GF_SG_VRML_MFNODE 34
#define GF_SG_VRML_MFSCRIPT 35
#define GF_SG_VRML_SFSCRIPT 36

void gf_free(void *ptr);
void gf_node_del(GF_Node *node);
void gf_sg_sfimage_del(SFImage img);
void gf_sg_sfcommand_del(SFCommandBuffer cmd);
void gf_sg_mfbool_del(MFBool mf);
void gf_sg_mffloat_del(MFFloat mf);
void gf_sg_mfdouble_del(MFDouble mf);
void gf_sg_mftime_del(MFTime mf);
void gf_sg_mfint32_del(MFInt32 mf);
void gf_sg_mfstring_del(MFString mf);
void gf_sg_mfvec3f_del(MFVec3f mf);
void gf_sg_mfvec2f_del(MFVec2f mf);
void gf_sg_mfvec3d_del(MFVec3d mf);
void gf_sg_mfvec2d_del(MFVec2d mf);
void gf_sg_mfcolor_del(MFColor mf);
void gf_sg_mfcolorrgba_del(MFColorRGBA mf);
void gf_sg_mfrotation_del(MFRotation mf);
void gf_sg_sfurl_del(SFURL url);
void gf_sg_mfurl_del(MFURL mf);
void gf_sg_mfattrref_del(MFAttrRef mf);
void gf_sg_mfscript_del(MFScript mf);