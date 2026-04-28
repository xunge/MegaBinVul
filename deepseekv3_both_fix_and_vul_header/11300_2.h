#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define TRUE true
#define FALSE false
#define gboolean bool
#define g_free free
#define g_strcmp0 strcmp

typedef struct _GdmDisplay GdmDisplay;
typedef struct _GdmManager GdmManager;
typedef struct _GParamSpec GParamSpec;

typedef enum {
    GDM_DISPLAY_PREPARED,
    GDM_DISPLAY_MANAGED,
    GDM_DISPLAY_FAILED,
    GDM_DISPLAY_UNMANAGED,
    GDM_DISPLAY_FINISHED
} GdmDisplayStatus;

struct _GdmManagerPrivate {
    gboolean plymouth_is_running;
    gboolean ran_once;
};

struct _GdmManager {
    struct _GdmManagerPrivate *priv;
};

void g_object_get(void *obj, ...);
int gdm_display_get_status(GdmDisplay *display);
void set_up_session(GdmManager *manager, GdmDisplay *display);
void greeter_display_started(GdmManager *manager, GdmDisplay *display);
void maybe_start_pending_initial_login(GdmManager *manager, GdmDisplay *display);
#ifdef WITH_PLYMOUTH
void plymouth_quit_without_transition(void);
#endif