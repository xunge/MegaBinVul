#include <stdlib.h>

typedef struct _GSList GSList;
typedef struct _PangoContext PangoContext;

typedef struct _RsvgDrawingCtx RsvgDrawingCtx;
struct _RsvgDrawingCtx {
    void *render;
    void *state;
    GSList *drawsub_stack;
    GSList *ptrs;
    GSList *acquired_nodes;
    char *base_uri;
    PangoContext *pango_context;
};

void rsvg_render_free(void *render);
void rsvg_state_free_all(void *state);
void g_slist_free(GSList *list);
void g_warn_if_fail(int condition);
void g_free(void *ptr);
void g_object_unref(void *object);