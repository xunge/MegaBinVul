#include <stdlib.h>
#include <assert.h>

#define GF_SG_VRML_SFNODE 1
#define GF_SG_VRML_MFNODE 2

typedef struct _GF_ProtoInstance GF_ProtoInstance;
typedef struct _GF_SceneGraph GF_SceneGraph;
typedef struct _GF_ProtoField GF_ProtoField;
typedef struct _GF_Node GF_Node;
typedef struct _GF_ChildNodeItem GF_ChildNodeItem;
typedef struct _GF_ProtoInterface GF_ProtoInterface;
typedef struct _GF_SGPrivate GF_SGPrivate;

struct _GF_SGPrivate {
    GF_SceneGraph *scenegraph;
};

struct _GF_ProtoInterface {
    void *instances;
};

struct _GF_ProtoInstance {
    void *fields;
    void *node_code;
    GF_SGPrivate *sgprivate;
    char *proto_name;
    GF_ProtoInterface *proto_interface;
    void *scripts_to_load;
};

struct _GF_SceneGraph {
    void *pOwningProto;
};

struct _GF_ProtoField {
    int FieldType;
    void *field_pointer;
};

struct _GF_Node {
    // Node structure members
};

struct _GF_ChildNodeItem {
    GF_Node *node;
    GF_ChildNodeItem *next;
};

unsigned int gf_list_count(void *list);
void* gf_list_get(void *list, unsigned int index);
void gf_list_rem(void *list, unsigned int index);
void gf_list_del(void *list);
void gf_list_del_item(void *list, void *item);
void gf_sg_vrml_field_pointer_del(void *ptr, int type);
void gf_node_unregister(GF_Node *node, GF_Node *inst);
void gf_free(void *ptr);
void gf_node_free(GF_Node *node);
void gf_sg_reset(GF_SceneGraph *sg);
void gf_sg_del(GF_SceneGraph *sg);