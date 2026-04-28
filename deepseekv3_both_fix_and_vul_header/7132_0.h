#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;

#define GF_EXPORT
#define TAG_ProtoNode 0
#define GF_SG_VRML_SFTIME 0

typedef struct _GF_Node {
    struct {
        int tag;
    } *sgprivate;
} GF_Node;

typedef struct _GF_FieldInfo {
    int fieldType;
    u32 fieldIndex;
    char *name;
} GF_FieldInfo;

typedef struct _GF_Route {
    Bool IS_route;
    GF_Node *FromNode;
    struct {
        u32 fieldIndex;
    } FromField;
    GF_Node *ToNode;
    struct {
        u32 fieldIndex;
    } ToField;
} GF_Route;

typedef struct _GF_ProtoInterface {
    struct {
        void *Routes;
    } *sub_graph;
} GF_ProtoInterface;

typedef struct _GF_ProtoInstance {
    GF_Node node;
    GF_ProtoInterface *proto_interface;
} GF_ProtoInstance;

void *gf_list_enum(void *list, u32 *index);
Bool gf_node_get_field(GF_Node *node, u32 fieldIndex, GF_FieldInfo *fieldInfo);
int stricmp(const char *s1, const char *s2);