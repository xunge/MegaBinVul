#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
typedef int gboolean;
typedef char gchar;

struct GList {
    void *data;
    struct GList *next;
};
typedef struct GList GList;

struct GError {
    char *message;
};
typedef struct GError GError;

typedef struct {
    void *unused;
} PolkitSubject;

typedef struct {
    gchar *id;
    gchar *action_id;
    PolkitSubject *subject;
} TemporaryAuthorization;

typedef struct {
    GList *authorizations;
} TemporaryAuthorizationStore;

#define POLKIT_IS_SUBJECT(obj) (1)
#define POLKIT_IS_SYSTEM_BUS_NAME(obj) (0)
#define POLKIT_SYSTEM_BUS_NAME(obj) ((void*)obj)

#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)

static PolkitSubject* polkit_system_bus_name_get_process_sync(void* name, void* unused, GError** error) { return NULL; }
static char* polkit_system_bus_name_get_name(void* name) { return ""; }
static int polkit_subject_equal(PolkitSubject *a, PolkitSubject *b) { return 0; }
static void g_object_unref(void *obj) {}
static void* g_object_ref(void *obj) { return obj; }
static void g_printerr(const char *fmt, ...) {}
static void g_error_free(GError *error) {}