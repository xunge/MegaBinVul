#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef unsigned char u8;

typedef enum {
    GF_OK = 0,
    GF_FALSE = 0,
    GF_TRUE = 1
} GF_Err;

typedef enum {
    XMLRI_ELEMENTID,
    XMLRI_OTHER
} XMLRI_Type;

typedef struct _GF_FieldInfo {
    const char *name;
    u32 fieldIndex;
    u32 fieldType;
    void *far_ptr;
} GF_FieldInfo;

typedef struct _XMLRI {
    XMLRI_Type type;
    void *target;
} XMLRI;

typedef struct _SMIL_AttributeName {
    char *name;
    u32 type;
    u32 tag;
} SMIL_AttributeName;

typedef struct _SMIL_AnimateValue {
    void *value;
} SMIL_AnimateValue;

typedef struct _SMIL_AnimateValues {
    struct _GF_List *values;
} SMIL_AnimateValues;

typedef struct _GF_List {
    u32 count;
    void **items;
} GF_List;

typedef struct _GF_SVG_Parser {
    u32 current_ns;
} GF_SVG_Parser;

typedef struct _GF_SceneGraph GF_SceneGraph;
typedef struct _GF_Node GF_Node;

typedef struct _SVG_Element {
    struct {
        GF_SceneGraph *scenegraph;
    } *sgprivate;
} SVG_Element;

typedef struct _SVG_DeferredAnimation {
    SVG_Element *animation_elt;
    SVG_Element *target;
    char *target_id;
    u32 resolve_stage;
    void *to;
    void *from;
    void *by;
    void *values;
    u32 type;
} SVG_DeferredAnimation;

typedef enum {
    SVG_TRANSFORM_TRANSLATE,
    SVG_TRANSFORM_SCALE,
    SVG_TRANSFORM_ROTATE,
    SVG_TRANSFORM_SKEWX,
    SVG_TRANSFORM_SKEWY,
    SVG_TRANSFORM_MATRIX
} SVG_TransformType;

enum {
    TAG_XLINK_ATT_href,
    TAG_SVG_ATT_transform_type,
    TAG_SVG_ATT_attributeName,
    TAG_SVG_ATT_to,
    TAG_SVG_ATT_from,
    TAG_SVG_ATT_by,
    TAG_SVG_ATT_values,
    TAG_SVG_ATT_begin,
    TAG_SVG_ATT_end,
    TAG_SVG_animateTransform,
    TAG_SVG_animateMotion,
    TAG_SVG_discard
};

enum {
    SVG_Transform_Translate_datatype,
    SVG_Transform_Scale_datatype,
    SVG_Transform_Rotate_datatype,
    SVG_Transform_SkewX_datatype,
    SVG_Transform_SkewY_datatype,
    SVG_Transform_datatype,
    SVG_Motion_datatype,
    XMLRI_datatype
};

GF_Node *gf_sg_find_node_by_name(GF_SceneGraph *sg, const char *name);
u32 gf_node_get_tag(GF_Node *node);
u32 gf_node_get_attribute_by_tag(GF_Node *node, u32 tag, Bool create_if_not_found, Bool skip_namespace, GF_FieldInfo *info);
u32 gf_node_get_attribute_by_name(GF_Node *node, const char *name, u32 ns, Bool create_if_not_found, Bool skip_namespace, GF_FieldInfo *info);
void gf_node_register_iri(GF_SceneGraph *sg, XMLRI *iri);
void gf_node_init(GF_Node *node);
const char *gf_node_get_name(GF_Node *node);
u32 gf_sg_get_namespace_code(GF_SceneGraph *sg, const char *name);
void gf_svg_parse_attribute(GF_Node *node, GF_FieldInfo *info, void *value, u32 type);
Bool gf_svg_resolve_smil_times(GF_Node *node, SVG_Element *target, GF_List *times, Bool is_end, const char *nodeID);
void svg_report(GF_SVG_Parser *parser, u32 status, const char *format, ...);
void svg_post_process_href(GF_SVG_Parser *parser, GF_Node *target, XMLRI *iri);
char *gf_strdup(const char *str);
void gf_free(void *ptr);
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);