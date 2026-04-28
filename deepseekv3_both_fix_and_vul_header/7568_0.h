#include <stdlib.h>
#include <assert.h>

typedef struct GF_Node GF_Node;
typedef void (*GF_UserCallback)(GF_Node *, void *, int);
typedef void (*GF_NodeCallback)(void *, int, GF_Node *, void *);
typedef void (*GF_NodeModifiedCallback)(void *, GF_Node *, void *, void *);

enum {
    GF_SG_CALLBACK_NODE_DESTROY
};

typedef struct GF_SGPrivate {
    GF_UserCallback UserCallback;
    struct {
        void *userpriv;
        GF_NodeCallback NodeCallback;
        GF_NodeModifiedCallback on_node_modified;
    } *scenegraph;
    struct {
        void *routes;
        void *dom_evt;
        void *animations;
        struct {
            void *fields;
        } *js_binding;
    } *interact;
    void *parents;
} GF_SGPrivate;

struct GF_Node {
    GF_SGPrivate *sgprivate;
};

void gf_list_del(void *);
void gf_dom_event_remove_all_listeners(void *);
void gf_dom_event_target_del(void *);
void gf_free(void *);

#define GPAC_DISABLE_SVG
#define GPAC_HAS_QJS