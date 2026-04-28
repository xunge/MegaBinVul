#include <stdio.h>
#include <string.h>

typedef unsigned int u32;
typedef int GF_Err;

#define GF_OK 0
#define GF_BAD_PARAM 1

typedef struct {
    u32 fieldIndex;
    const char *name;
} GF_FieldInfo;

typedef struct {
    void *FromNode;
    void *ToNode;
    GF_FieldInfo FromField;
    GF_FieldInfo ToField;
    u32 is_setup;
    u32 ID;
    const char *name;
} GF_Route;

typedef struct {
    FILE *trace;
    u32 XMLDump;
} GF_SceneDumper;

#define DUMP_IND(x)

const char *gf_node_get_name(void *node);
const char *gf_node_get_name_and_id(void *node, u32 *id);
u32 gf_node_get_id(void *node);
void gf_node_get_field(void *node, u32 fieldIndex, GF_FieldInfo *field);
void scene_dump_vrml_route_id(GF_SceneDumper *sdump, u32 ID, const char *name);
void StartAttribute(GF_SceneDumper *sdump, const char *attr);
void EndAttribute(GF_SceneDumper *sdump);
int gf_fprintf(FILE *stream, const char *format, ...);