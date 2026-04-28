#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef int gboolean;
typedef uint32_t guint32;
typedef long glong;
typedef double gdouble;

typedef struct _GimpImage GimpImage;
typedef struct _GimpLayer GimpLayer;
typedef struct _GimpItem GimpItem;
typedef struct _GimpObject GimpObject;
typedef struct _GimpDrawable {
    struct {
        int type;
    } *private;
} GimpDrawable;
typedef struct _GimpParasite GimpParasite;
typedef uint32_t GimpTattoo;

typedef struct _GList {
    void *data;
    struct _GList *next;
    struct _GList *prev;
} GList;

typedef struct _XcfInfo {
    FILE *fp;
    long cp;
    GimpLayer *active_layer;
    GimpLayer *floating_sel;
    int floating_sel_offset;
    void *gimp;
    void *progress;
} XcfInfo;

typedef enum {
    PROP_END,
    PROP_ACTIVE_LAYER,
    PROP_FLOATING_SELECTION,
    PROP_OPACITY,
    PROP_VISIBLE,
    PROP_LINKED,
    PROP_LOCK_CONTENT,
    PROP_LOCK_ALPHA,
    PROP_APPLY_MASK,
    PROP_EDIT_MASK,
    PROP_SHOW_MASK,
    PROP_OFFSETS,
    PROP_MODE,
    PROP_TATTOO,
    PROP_PARASITES,
    PROP_TEXT_LAYER_FLAGS,
    PROP_GROUP_ITEM,
    PROP_ITEM_PATH,
    PROP_GROUP_ITEM_FLAGS
} PropType;

typedef enum {
    GIMP_LAYER_MODE_NORMAL,
    GIMP_LAYER_MODE_DISSOLVE,
    GIMP_LAYER_MODE_BEHIND,
    GIMP_LAYER_MODE_MULTIPLY,
    GIMP_LAYER_MODE_SCREEN,
    GIMP_LAYER_MODE_OVERLAY,
    GIMP_LAYER_MODE_DIFFERENCE,
    GIMP_LAYER_MODE_ADDITION,
    GIMP_LAYER_MODE_SUBTRACT,
    GIMP_LAYER_MODE_DARKEN_ONLY,
    GIMP_LAYER_MODE_LIGHTEN_ONLY,
    GIMP_LAYER_MODE_HUE,
    GIMP_LAYER_MODE_SATURATION,
    GIMP_LAYER_MODE_COLOR,
    GIMP_LAYER_MODE_VALUE,
    GIMP_LAYER_MODE_DIVIDE,
    GIMP_LAYER_MODE_DODGE,
    GIMP_LAYER_MODE_BURN,
    GIMP_LAYER_MODE_HARDLIGHT,
    GIMP_LAYER_MODE_SOFTLIGHT,
    GIMP_LAYER_MODE_GRAIN_EXTRACT,
    GIMP_LAYER_MODE_GRAIN_MERGE,
    GIMP_LAYER_MODE_COLOR_ERASE,
    GIMP_LAYER_MODE_ERASE,
    GIMP_LAYER_MODE_REPLACE,
    GIMP_LAYER_MODE_ANTI_ERASE
} GimpLayerModeEffects;

typedef enum {
    GIMP_MESSAGE_WARNING
} GimpMessageType;

#define GIMP_ITEM(layer) ((GimpItem*)(layer))
#define GIMP_OBJECT(obj) ((GimpObject*)(obj))
#define GIMP_DRAWABLE(drawable) ((GimpDrawable*)(drawable))
#define GUINT_TO_POINTER(u) ((void*)(uintptr_t)(u))
#define G_OBJECT(obj) ((void*)(obj))

/* Dummy function declarations to satisfy compiler */
static int xcf_load_prop(XcfInfo *info, PropType *prop_type, guint32 *prop_size) { return 0; }
static int xcf_read_int32(FILE *fp, void *data, int count) { return 0; }
static void gimp_layer_set_opacity(GimpLayer *layer, gdouble opacity, gboolean dummy) {}
static void gimp_item_set_visible(GimpItem *item, gboolean visible, gboolean dummy) {}
static void gimp_item_set_linked(GimpItem *item, gboolean linked, gboolean dummy) {}
static gboolean gimp_item_can_lock_content(GimpItem *item) { return FALSE; }
static void gimp_item_set_lock_content(GimpItem *item, gboolean lock, gboolean dummy) {}
static gboolean gimp_layer_can_lock_alpha(GimpLayer *layer) { return FALSE; }
static void gimp_layer_set_lock_alpha(GimpLayer *layer, gboolean lock, gboolean dummy) {}
static void gimp_item_set_offset(GimpItem *item, guint32 x, guint32 y) {}
static void gimp_layer_set_mode(GimpLayer *layer, GimpLayerModeEffects mode, gboolean dummy) {}
static void gimp_item_set_tattoo(GimpItem *item, GimpTattoo tattoo) {}
static GimpParasite *xcf_load_parasite(XcfInfo *info) { return NULL; }
static void gimp_item_parasite_attach(GimpItem *item, GimpParasite *p, gboolean dummy) {}
static void gimp_parasite_free(GimpParasite *p) {}
static void gimp_message_literal(void *gimp, void *progress, GimpMessageType type, const char *msg) {}
static GimpLayer *gimp_group_layer_new(GimpImage *image) { return NULL; }
static void gimp_object_set_name(GimpObject *obj, const char *name) {}
static const char *gimp_object_get_name(GimpObject *obj) { return NULL; }
static int gimp_drawable_type(GimpDrawable *drawable) { return 0; }
static void g_object_ref_sink(void *obj) {}
static void g_object_unref(void *obj) {}
static void g_list_free(GList *list) {}
static GList *g_list_append(GList *list, void *data) { return NULL; }
static int xcf_skip_unknown_prop(XcfInfo *info, guint32 prop_size) { return 0; }