#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef int Bool;
typedef int SFInt32;
typedef int GF_Err;

#define GF_NOT_SUPPORTED 0
#define GF_BAD_PARAM 0
#define TAG_MPEG4_Group 0
#define TAG_X3D_Group 0
#define GF_SM_LOAD_CONTEXT_READY 0
#define GF_SM_LOAD_MPEG4_STRICT 0
#define GPAC_DISABLE_X3D 0
#define GF_STREAM_OD 0
#define GF_STREAM_SCENE 0
#define GF_CODECID_OD_V1 0
#define GF_CODECID_BIFS 0
#define GF_SG_ROUTE_INSERT 0
#define GF_SG_SCENE_REPLACE 0

typedef struct GF_Node GF_Node;
typedef struct GF_Route GF_Route;
typedef struct GF_ObjectDescriptor GF_ObjectDescriptor;
typedef struct GF_SceneGraph GF_SceneGraph;

typedef struct GF_Command {
    u32 RouteID;
    char *def_name;
    GF_Node *node;
    void *new_proto_list;
} GF_Command;

typedef struct GF_AU {
    u32 timing;
    void *commands;
} GF_AU;

typedef struct GF_StreamContext {
    u16 ESID;
    void *AUs;
} GF_StreamContext;

typedef struct GF_Context {
    GF_ObjectDescriptor *root_od;
} GF_Context;

typedef struct GF_SM_Load {
    u32 flags;
    GF_SceneGraph *scene_graph;
    GF_Context *ctx;
    u32 force_es_id;
} GF_SM_Load;

typedef struct GF_BTParser {
    GF_SM_Load *load;
    GF_Command *cur_com;
    GF_StreamContext *bifs_es;
    GF_StreamContext *od_es;
    GF_AU *bifs_au;
    GF_AU *od_au;
    void *top_nodes;
    void *inserted_routes;
    void *scripts;
    u32 stream_id;
    u32 base_od_id;
    u32 base_bifs_id;
    u32 au_time;
    u32 line_pos;
    u32 line_size;
    int in_com;
    int is_wrl;
    int done;
    int au_is_rap;
    GF_Err last_error;
} GF_BTParser;

char *gf_bt_get_next(GF_BTParser *parser, int arg);
int gf_bt_check_code(GF_BTParser *parser, char code);
void gf_bt_force_line(GF_BTParser *parser);
void gf_bt_report(GF_BTParser *parser, GF_Err err, const char *fmt, ...);
GF_ObjectDescriptor *gf_bt_parse_descriptor(GF_BTParser *parser, char *str);
void gf_bt_parse_int(GF_BTParser *parser, const char *str, SFInt32 *val);
void gf_bt_parse_proto(GF_BTParser *parser, char *str, void *list);
GF_Route *gf_bt_parse_route(GF_BTParser *parser, int arg1, int arg2, GF_Command *com);
u32 gf_bt_get_route(GF_BTParser *parser, char *name);
u32 gf_bt_get_next_route_id(GF_BTParser *parser);
void gf_bt_parse_od_command(GF_BTParser *parser, char *str);
void gf_bt_parse_bifs_command(GF_BTParser *parser, char *str, void *commands);
GF_Node *gf_bt_sf_node(GF_BTParser *parser, char *str, GF_Node *root, char *name);
void gf_bt_resolve_routes(GF_BTParser *parser, int arg);
void gf_bt_check_unresolved_nodes(GF_BTParser *parser);
void gf_sg_script_load(GF_Node *n);

GF_Node *gf_node_new(GF_SceneGraph *sg, u32 tag);
void gf_node_register(GF_Node *node, char *name);
void gf_node_init(GF_Node *node);
void gf_sg_set_root_node(GF_SceneGraph *sg, GF_Node *node);
GF_Node *gf_sg_get_root_node(GF_SceneGraph *sg);
void gf_node_insert_child(GF_Node *parent, GF_Node *child, int pos);

GF_Command *gf_sg_command_new(GF_SceneGraph *sg, u32 type);
GF_StreamContext *gf_sm_stream_new(void *ctx, u16 esid, u32 type, u32 codecid);
void *gf_sm_stream_au_new(GF_StreamContext *stream, u32 time, int arg1, Bool rap);
void gf_sg_set_max_defined_route_id(GF_SceneGraph *sg, u32 id);
void gf_sg_route_set_id(GF_Route *route, u32 id);
void gf_sg_route_set_name(GF_Route *route, char *name);

char *gf_strdup(const char *str);
void *gf_list_last(void *list);
void gf_list_add(void *list, void *item);
void gf_list_rem(void *list, u32 index);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);