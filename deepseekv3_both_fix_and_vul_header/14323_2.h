#include <stdio.h>
#include <stdlib.h>

typedef int s32;
typedef unsigned int u32;
typedef int Bool;
typedef unsigned int GF_Err;
#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1

typedef struct {
    int indent;
    FILE *trace;
    void *sg;
} GF_SceneDumper;

typedef struct {
    u32 tag;
    void *in_scene;
    void *node;
    u32 RouteID;
    void *command_fields;
    u32 fromNodeID;
    u32 fromFieldIndex;
} GF_Command;

typedef struct {
    int pos;
    u32 fieldType;
    u32 fieldIndex;
    void *field_ptr;
    struct GF_Node *new_node;
    void *node_list;
} GF_CommandField;

typedef struct GF_NodePrivate {
    u32 tag;
} GF_NodePrivate;

typedef struct GF_Node {
    GF_NodePrivate *sgprivate;
} GF_Node;

typedef struct GF_ChildNodeItem {
    GF_Node *node;
    struct GF_ChildNodeItem *next;
} GF_ChildNodeItem;

typedef struct {
    void *far_ptr;
    u32 fieldIndex;
    u32 fieldType;
    char *name;
} GF_FieldInfo;

#define TAG_DOMText 0
#define GF_SG_LSR_REPLACE 0
#define GF_SG_LSR_ADD 0
#define GF_SG_LSR_INSERT 0
#define SVG_Transform_Scale_datatype 0
#define SVG_Transform_Rotate_datatype 0
#define SVG_Transform_Translate_datatype 0

int gf_fprintf(FILE *stream, const char *format, ...);
void *gf_list_get(void *list, u32 index);
void gf_free(void *ptr);

char* sd_get_lsr_namespace(void *in_scene);
char* lsr_format_node_id(GF_Node *node, u32 RouteID, char *szID);
void DUMP_IND(GF_SceneDumper *sdump);
char* gf_svg_get_attribute_name(GF_Node *node, u32 fieldIndex);
char* gf_svg_dump_attribute_indexed(GF_Node *node, GF_FieldInfo *info);
char* gf_svg_dump_attribute(GF_Node *node, GF_FieldInfo *info);
GF_Node* gf_sg_find_node(void *sg, u32 nodeID);
void gf_node_get_field(GF_Node *node, u32 fieldIndex, GF_FieldInfo *info);
void gf_dump_svg_element(GF_SceneDumper *sdump, GF_Node *node, GF_Node *parent, Bool dump_children);