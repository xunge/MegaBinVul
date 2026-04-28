#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned char Bool;

typedef struct _gf_node {
    struct {
        u32 tag;
        u32 num_instances;
        struct _gf_scene_graph *scenegraph;
        struct _gf_parent_list *parents;
    } *sgprivate;
} GF_Node;

typedef struct _gf_scene_graph {
    GF_Node *RootNode;
    struct _gf_scene_graph *parent_scene;
    struct _gf_scene_graph *pOwningProto;
    void *userpriv;
    void (*GetExternProtoLib)(void*, void*);
    struct _gf_list *scripts;
    struct _gf_list *exported_nodes;
    struct _gf_list *routes_to_activate;
    struct _gf_list *Routes;
    struct _gf_list *protos;
    struct _gf_list *unregistered_protos;
    struct _gf_list *ns;
    struct _node_ided_item *id_node;
    void *dom_evt;
    void *dom_evt_mx;
    struct _gf_list *smil_timed_elements;
    struct _gf_node *global_qp;
    u32 simulation_tick;
    int graph_has_been_reset;
} GF_SceneGraph;

typedef struct _gf_list {
    size_t count;
    void **items;
} GF_List;

typedef struct _gf_route GF_Route;
typedef struct _gf_proto GF_Proto;
typedef struct _gf_xmlns {
    char *name;
    char *qname;
} GF_XMLNS;
typedef struct _smil_timing_rti {
    GF_Node *timed_elt;
} SMIL_Timing_RTI;
typedef struct _node_ided_item {
    GF_Node *node;
    struct _node_ided_item *next;
} NodeIDedItem;
typedef struct _gf_parent_list {
    GF_Node *node;
    struct _gf_parent_list *next;
} GF_ParentList;

#define GF_EXPORT
#define GPAC_DISABLE_SVG
#define GPAC_DISABLE_VRML
#define GPAC_HAS_QJS
#define GF_LOG(level, category, message)
#define GF_LOG_DEBUG 0
#define GF_LOG_SCENE 0
#define GF_NODE_RANGE_LAST_VRML 0

static GF_List *gf_list_new() { return calloc(1, sizeof(GF_List)); }
static u32 gf_list_count(GF_List *list) { return list ? list->count : 0; }
static void *gf_list_get(GF_List *list, u32 index) { return list && index < list->count ? list->items[index] : NULL; }
static void gf_list_rem(GF_List *list, u32 index) { if (list && index < list->count) { free(list->items[index]); list->items[index] = NULL; } }
static void gf_list_add(GF_List *list, void *item) { if (list) { list->items = realloc(list->items, ++list->count * sizeof(void*)); list->items[list->count-1] = item; } }
static void gf_list_del(GF_List *list) { if (list) { free(list->items); free(list); } }
static void gf_list_reset(GF_List *list) { if (list) { list->count = 0; free(list->items); list->items = NULL; } }
static void gf_free(void *ptr) { free(ptr); }

static void gf_node_register(GF_Node *n, void *ptr) {}
static void gf_node_unregister(GF_Node *n, void *ptr) {}
static void gf_node_replace(GF_Node *n, GF_Node *new_node, u32 flag) {}
static void gf_sg_route_del(GF_Route *r) {}
static void gf_sg_proto_del(GF_Proto *p) {}
static void gf_sg_destroy_routes(GF_SceneGraph *sg) {}
static void gf_dom_event_remove_all_listeners(void *dom_evt) {}
static void gf_dom_listener_reset_deferred(GF_SceneGraph *sg) {}
static void gf_mx_p(void *mx) {}
static void gf_mx_v(void *mx) {}
static u32 get_num_id_nodes(GF_SceneGraph *sg) { return 0; }
static void ReplaceDEFNode(GF_Node *node, GF_Node *old_node, GF_Node *new_node, u32 flag) {}
static void ReplaceIRINode(GF_Node *node, GF_Node *old_node, GF_Node *new_node) {}