#include <stdlib.h>

typedef struct _gf_list GF_List;
typedef struct _GF_Node GF_Node;

typedef struct _GF_DOMEventTarget {
    GF_List *listeners;
} GF_DOMEventTarget;

typedef struct _GF_SceneGraph {
    GF_List *exported_nodes;
} GF_SceneGraph;

unsigned int gf_list_count(const GF_List *ptr);
void *gf_list_get(const GF_List *ptr, unsigned int position);
int gf_list_find(const GF_List *ptr, void *item);
void gf_list_rem(GF_List *ptr, unsigned int position);
void gf_dom_listener_del(GF_Node *n, GF_DOMEventTarget *event_target);