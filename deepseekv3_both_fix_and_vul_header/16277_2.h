#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef bool gboolean;
#define FALSE false
#define TRUE true

typedef struct _GdmDisplay GdmDisplay;
typedef struct _GdmDisplayPrivate GdmDisplayPrivate;

struct _GdmDisplayClass {
    gboolean (*prepare)(GdmDisplay *self);
};
typedef struct _GdmDisplayClass GdmDisplayClass;

#define GDM_IS_DISPLAY(obj) (1)
#define GDM_DISPLAY_GET_CLASS(obj) ((GdmDisplayClass*)0)

struct _GdmDisplayPrivate {
    char *id;
    gboolean doing_initial_setup;
};

gboolean look_for_existing_users_sync(GdmDisplay *self);
gboolean wants_initial_setup(GdmDisplay *self);
void g_object_ref(GdmDisplay *self);
void g_object_unref(GdmDisplay *self);
GdmDisplayPrivate* gdm_display_get_instance_private(GdmDisplay *self);

#define g_debug(...) fprintf(stderr, __VA_ARGS__)
#define g_return_val_if_fail(cond, val) if (!(cond)) return (val)