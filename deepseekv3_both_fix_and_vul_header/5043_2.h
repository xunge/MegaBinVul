#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef int gboolean;
typedef char gchar;

typedef struct _GList GList;
struct _GList {
    void *data;
    GList *next;
};

typedef struct _GError GError;
struct _GError {
    char *message;
};

typedef struct _PolkitSubject PolkitSubject;
typedef struct _PolkitSystemBusName PolkitSystemBusName;

typedef struct _TemporaryAuthorization TemporaryAuthorization;
typedef struct _TemporaryAuthorizationStore TemporaryAuthorizationStore;

struct _TemporaryAuthorization {
    gchar *id;
    gchar *action_id;
    PolkitSubject *subject;
};

struct _TemporaryAuthorizationStore {
    GList *authorizations;
};

#define POLKIT_IS_SUBJECT(obj) (1)
#define POLKIT_IS_SYSTEM_BUS_NAME(obj) (1)
#define POLKIT_SYSTEM_BUS_NAME(obj) ((PolkitSystemBusName*)obj)

#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)
#define g_printerr(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#define g_error_free(error) free(error)
#define g_object_ref(obj) (obj)
#define g_object_unref(obj) (void)(obj)

PolkitSubject* polkit_system_bus_name_get_process_sync(PolkitSystemBusName *name, void *cancellable, GError **error);
const char* polkit_system_bus_name_get_name(PolkitSystemBusName *name);
int polkit_subject_equal(PolkitSubject *a, PolkitSubject *b);