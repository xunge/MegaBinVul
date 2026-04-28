#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

typedef struct GF_XMLAttribute GF_XMLAttribute;
typedef struct GF_Node GF_Node;
typedef struct XMTNodeStack XMTNodeStack;
typedef struct GF_XMTParser GF_XMTParser;
typedef struct GF_Descriptor GF_Descriptor;
typedef struct __gf_list_t gf_list_t;
#define GF_List gf_list_t

enum {
    GF_SG_SCENE_REPLACE,
    XMT_STATE_INIT,
    XMT_STATE_HEAD,
    XMT_STATE_BODY,
    XMT_STATE_COMMANDS,
    XMT_STATE_ELEMENTS,
    XMT_STATE_END
};

#define GF_SM_LOAD_CONTEXT_READY 0x01

struct GF_SceneContext {
    int is_pixel_metrics;
    int scene_width;
    int scene_height;
};

struct GF_SceneLoader {
    u32 flags;
    struct GF_SceneContext *ctx;
    void *scene_graph;
};

struct GF_XMTParser {
    u32 last_error;
    void *sax_parser;
    struct {
        void *buffer;
    } *command_buffer;
    u32 doc_type;
    u32 state;
    struct GF_SceneLoader *load;
    GF_List *descriptors;
    GF_List *nodes;
    XMTNodeStack *x3d_root;
    u32 parsing_proto;
    struct {
        u32 tag;
        GF_Node *node;
    } *command;
    u32 od_command;
    GF_List *script_to_load;
};

struct XMTNodeStack {
    GF_Node *node;
};

void gf_xml_sax_suspend(void *sax_parser, int flag);
GF_List *gf_list_new();
void *gf_list_last(GF_List *list);
void gf_list_add(GF_List *list, void *item);
GF_Descriptor *xmt_parse_descriptor(GF_XMTParser *parser, char *name, const GF_XMLAttribute *attributes, u32 nb_attributes, GF_Descriptor *parent);
void xmt_parse_command(GF_XMTParser *parser, const char *name, const GF_XMLAttribute *attributes, u32 nb_attributes);
GF_Node *xmt_parse_element(GF_XMTParser *parser, char *name, const char *name_space, const GF_XMLAttribute *attributes, u32 nb_attributes, XMTNodeStack *top);
void gf_node_register(GF_Node *node, void *unused);
void gf_sg_set_scene_size_info(void *scene_graph, int a, int b, int c);
#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))