#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int GF_Err;
typedef double Double;
typedef float Fixed;
typedef unsigned int u32;
typedef int s32;
typedef char Bool;
typedef char *SVG_String;

typedef struct GF_Node GF_Node;
typedef struct GF_SceneGraph GF_SceneGraph;
typedef struct GF_Command GF_Command;
typedef struct GF_CommandField GF_CommandField;
typedef struct GF_FieldInfo GF_FieldInfo;
typedef struct GF_ChildNodeItem GF_ChildNodeItem;
typedef struct GF_Proto GF_Proto;
typedef struct GF_Route GF_Route;
typedef struct SVG_Element SVG_Element;
typedef struct GF_DOMText GF_DOMText;
typedef struct GF_DOM_Event GF_DOM_Event;
typedef struct GenMFField GenMFField;
typedef struct SFCommandBuffer SFCommandBuffer;
typedef struct SVG_Point_Angle SVG_Point_Angle;
typedef struct GF_Point2D GF_Point2D;
typedef struct GF_Matrix2D GF_Matrix2D;
typedef struct SVG_Transform SVG_Transform;

struct GF_FieldInfo {
    u32 fieldType;
    void *far_ptr;
    char *name;
};

struct GF_CommandField {
    void *field_ptr;
    u32 fieldIndex;
    u32 fieldType;
    s32 pos;
    GF_Node *new_node;
    GF_ChildNodeItem *node_list;
};

struct GF_SceneGraph {
    GF_Node *RootNode;
    void *Routes;
    void *routes_to_activate;
    void *protos;
    void *unregistered_protos;
};

struct GF_Command {
    u32 tag;
    Bool never_apply;
    Bool aggregated;
    GF_Node *node;
    void *command_fields;
    void *new_proto_list;
    u32 RouteID;
    u32 fromNodeID;
    u32 toNodeID;
    u32 fromFieldIndex;
    u32 toFieldIndex;
    char *def_name;
    u32 *del_proto_list;
    u32 del_proto_list_size;
    u32 ChildNodeTag;
    u32 child_field;
    u32 send_event_name;
    s32 send_event_integer;
    Fixed send_event_x;
    Fixed send_event_y;
    void *scripts_to_load;
};

struct SFCommandBuffer {
    void *commandList;
    void *buffer;
};

struct GF_ChildNodeItem {
    GF_Node *node;
    struct GF_ChildNodeItem *next;
};

struct GF_Node {
    void *sgprivate;
    u32 tag;
};

struct SVG_Element {
    GF_ChildNodeItem *children;
};

struct SVG_Point_Angle {
    Fixed angle;
};

struct GF_Point2D {
    Fixed x, y;
};

struct GF_Matrix2D {
    Fixed m[6];
};

struct SVG_Transform {
    GF_Matrix2D mat;
};

struct GF_DOMText {
    char *textContent;
    struct {
        u32 tag;
    } *sgprivate;
};

struct GF_DOM_Event {
    u32 type;
    s32 detail;
    Fixed clientX, clientY;
};

struct GenMFField {
    u32 count;
};

struct GF_Proto {
    void *far_ptr;
};

struct GF_Route {
    char *name;
};

typedef Double SFTime;
typedef Fixed SFFloat;
typedef s32 SFInt32;
typedef Bool SFBool;

#define GF_BAD_PARAM 1
#define GF_OK 0
#define GF_SG_UNKNOWN_NODE 2
#define GF_NON_COMPLIANT_BITSTREAM 3
#define GF_NOT_SUPPORTED 4

#define GF_SG_SCENE_REPLACE 0
#define GF_SG_NODE_REPLACE 1
#define GF_SG_MULTIPLE_REPLACE 2
#define GF_SG_FIELD_REPLACE 3
#define GF_SG_MULTIPLE_INDEXED_REPLACE 4
#define GF_SG_INDEXED_REPLACE 5
#define GF_SG_ROUTE_REPLACE 6
#define GF_SG_NODE_DELETE_EX 7
#define GF_SG_NODE_DELETE 8
#define GF_SG_ROUTE_DELETE 9
#define GF_SG_INDEXED_DELETE 10
#define GF_SG_NODE_INSERT 11
#define GF_SG_ROUTE_INSERT 12
#define GF_SG_INDEXED_INSERT 13
#define GF_SG_PROTO_INSERT 14
#define GF_SG_PROTO_DELETE 15
#define GF_SG_PROTO_DELETE_ALL 16
#define GF_SG_XREPLACE 17
#define GF_SG_GLOBAL_QUANTIZER 18
#define GF_SG_LSR_NEW_SCENE 19
#define GF_SG_LSR_DELETE 20
#define GF_SG_LSR_INSERT 21
#define GF_SG_LSR_ADD 22
#define GF_SG_LSR_REPLACE 23
#define GF_SG_LSR_ACTIVATE 24
#define GF_SG_LSR_DEACTIVATE 25
#define GF_SG_LSR_SEND_EVENT 26

#define GF_SG_VRML_SFNODE 0
#define GF_SG_VRML_MFNODE 1
#define GF_SG_VRML_SFCOMMANDBUFFER 2
#define GF_SG_VRML_SFTIME 3
#define GF_SG_VRML_SFBOOL 4
#define GF_SG_VRML_SFINT32 5
#define GF_SG_VRML_SFFLOAT 6

#define DOM_String_datatype 7
#define XMLRI_datatype 8
#define SVG_TRANSFORM_SCALE 9
#define SVG_TRANSFORM_TRANSLATE 10
#define SVG_TRANSFORM_ROTATE 11

#define TAG_DOMText 12
#define TAG_SVG_ATT_transform 13
#define TAG_LSR_ATT_scale 14
#define TAG_LSR_ATT_translation 15
#define TAG_LSR_ATT_rotation 16

#define GF_SG_SVG_XLINK_HREF_DIRTY 1

#define GF_LOG_ERROR 1
#define GF_LOG_CODEC 2

#define FIX2FLT(x) ((float)(x))
#define SG_CheckFieldChange(node, field)

#define GF_EXPORT

/* Function prototypes */
GF_Err gf_node_unregister(GF_Node *node, void *ptr);
u32 gf_list_count(void *list);
void gf_list_rem(void *list, u32 index);
void *gf_list_get(void *list, u32 index);
void gf_sg_route_del(GF_Route *route);
void gf_sg_proto_del(GF_Proto *proto);
void *gf_list_new();
void gf_list_del_item(void *list, void *item);
void gf_list_add(void *list, void *item);
GF_Err gf_node_replace(GF_Node *node, GF_Node *new_node, Bool flag);
void *gf_list_enum(void *list, u32 *index);
GF_Err gf_node_get_field(GF_Node *node, u32 fieldIndex, GF_FieldInfo *field);
GF_Err gf_node_register(GF_Node *node, GF_Node *parent);
GF_Err gf_node_unregister_children(GF_Node *node, GF_ChildNodeItem *children);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
GF_SceneGraph *gf_node_get_graph(GF_Node *node);
GF_Command *gf_sg_vrml_command_clone(GF_Command *com, GF_SceneGraph *sg, Bool flag);
Bool gf_sg_vrml_is_sf_field(u32 fieldType);
GF_Err gf_sg_vrml_mf_reset(void *ptr, u32 fieldType);
GF_Err gf_sg_vrml_field_copy(void *dst, void *src, u32 fieldType);
GF_Err gf_node_replace_child(GF_Node *node, GF_ChildNodeItem **children, s32 pos, GF_Node *new_node);
GF_Err gf_sg_vrml_mf_alloc(void *ptr, u32 fieldType, u32 count);
GF_Err gf_sg_vrml_mf_get_item(void *ptr, u32 fieldType, void **slot_ptr, s32 pos);
u32 gf_sg_vrml_get_sf_type(u32 fieldType);
GF_Route *gf_sg_route_find(GF_SceneGraph *graph, u32 routeID);
GF_Node *gf_sg_find_node(GF_SceneGraph *graph, u32 nodeID);
GF_Route *gf_sg_route_new(GF_SceneGraph *graph, GF_Node *fromNode, u32 fromFieldIndex, GF_Node *toNode, u32 toFieldIndex);
void gf_sg_route_set_id(GF_Route *route, u32 routeID);
void gf_sg_route_set_name(GF_Route *route, char *name);
GF_Err gf_sg_route_del_by_id(GF_SceneGraph *graph, u32 routeID);
GF_Err gf_sg_vrml_mf_remove(void *ptr, u32 fieldType, s32 pos);
GF_Err gf_node_insert_child(GF_Node *node, GF_Node *new_node, s32 pos);
void gf_node_event_out(GF_Node *node, u32 fieldIndex);
void gf_node_changed(GF_Node *node, void *ptr);
GF_Err gf_sg_vrml_mf_append(void *ptr, u32 fieldType, void **slot_ptr);
GF_Err gf_sg_vrml_mf_insert(void *ptr, u32 fieldType, void **slot_ptr, s32 pos);
void gf_node_list_add_child(GF_ChildNodeItem **children, GF_Node *node);
void gf_node_list_insert_child(GF_ChildNodeItem **children, GF_Node *node, s32 pos);
GF_Proto *gf_sg_find_proto(GF_SceneGraph *graph, u32 protoID, void *ptr);
GF_Node *gf_node_list_get_child(GF_ChildNodeItem *children, s32 pos);
GF_Err gf_sg_vrml_field_clone(void *dst, void *src, u32 fieldType, GF_SceneGraph *graph);
void gf_node_deactivate(GF_Node *node);
void gf_node_activate(GF_Node *node);
void GF_LOG(u32 level, u32 codec, const char *msg);
void gf_node_unregister_children_deactivate(GF_Node *node, GF_ChildNodeItem *children);
GF_Err gf_node_get_field_by_name(GF_Node *node, const char *name, GF_FieldInfo *field);
Bool gf_mx2d_decompose(GF_Matrix2D *mx, GF_Point2D *scale, Fixed *rotate, GF_Point2D *translate);
void gf_mx2d_init(GF_Matrix2D mx);
void gf_mx2d_add_scale(GF_Matrix2D *mx, Fixed x, Fixed y);
void gf_mx2d_add_rotation(GF_Matrix2D *mx, Fixed x, Fixed y, Fixed angle);
void gf_mx2d_add_translation(GF_Matrix2D *mx, Fixed x, Fixed y);
char *gf_strdup(const char *str);
void gf_dom_add_text_node(GF_Node *node, char *str);
GF_Err gf_node_get_attribute_by_tag(GF_Node *node, u32 tag, Bool create, Bool from_proto, GF_FieldInfo *field);
GF_Err gf_svg_attributes_copy(GF_FieldInfo *dst, GF_FieldInfo *src, Bool clone);
GF_Err gf_svg_attributes_add(GF_FieldInfo *dst, GF_FieldInfo *src, GF_FieldInfo *result, Bool clone);
void gf_node_dirty_set(GF_Node *node, u32 flag, Bool value);
void gf_dom_event_fire(GF_Node *node, GF_DOM_Event *evt);
void gf_sg_script_load(GF_Node *script);
void gf_list_del(void *list);