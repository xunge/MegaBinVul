#include <stdint.h>
#include <stddef.h>

typedef int32_t s32;
typedef uint32_t u32;

typedef enum {
    GF_OK,
    GF_SG_UNKNOWN_NODE,
    GF_NON_COMPLIANT_BITSTREAM,
    GF_IO_ERR
} GF_Err;

typedef struct GF_LASeRCodec GF_LASeRCodec;
typedef struct GF_List GF_List;
typedef struct GF_Command GF_Command;
typedef struct GF_Node GF_Node;
typedef struct SVG_Element SVG_Element;
typedef struct GF_CommandField GF_CommandField;
typedef struct GF_FieldInfo GF_FieldInfo;

struct GF_FieldInfo {
    int fieldType;
};

struct GF_Command {
    GF_Node *node;
    u32 RouteID;
};

struct GF_CommandField {
    s32 pos;
    s32 fieldIndex;
    int fieldType;
};

struct SVG_Element {
    void *children;
};

struct GF_List {
    void *data;
};

struct GF_LASeRCodec {
    GF_List *unresolved_commands;
    void *sg;
};

#define GF_LSR_READ_INT(lsr, var, bits, desc)
#define GF_SG_LSR_DELETE 0

static s32 lsr_get_attribute_name(GF_LASeRCodec *lsr);
static u32 lsr_read_vluimsbf5(GF_LASeRCodec *lsr, const char *desc);
static u32 lsr_read_codec_IDREF_command(GF_LASeRCodec *lsr, const char *desc);
static void lsr_read_any_attribute(GF_LASeRCodec *lsr, void *ptr, int flag);
static GF_Command *gf_sg_command_new(void *sg, int type);
static GF_Node *gf_sg_find_node(void *sg, u32 idref);
static void gf_node_register(GF_Node *node, void *ptr);
static GF_CommandField *gf_sg_command_field_new(GF_Command *com);
static s32 gf_lsr_anim_type_to_attribute(s32 att_type);
static void gf_node_get_field(GF_Node *node, s32 fieldIndex, GF_FieldInfo *info);
static void *gf_node_list_get_child(void *children, s32 idx);
static int gf_node_list_del_child(void **children, GF_Node *child);
static void gf_node_unregister(GF_Node *node, GF_Node *parent);
static void gf_node_replace(GF_Node *old_node, GF_Node *new_node, int flag);
static void gf_list_add(GF_List *list, void *item);