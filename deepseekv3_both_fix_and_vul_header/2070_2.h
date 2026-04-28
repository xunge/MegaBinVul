#include <syslog.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct _GDBusMethodInvocation GDBusMethodInvocation;
typedef struct _PolkitSubject PolkitSubject;
typedef int GPid;
typedef char gchar;
typedef int gint;
typedef void* gpointer;
typedef bool gboolean;

gboolean get_caller_pid(GDBusMethodInvocation *context, GPid *pid);
gboolean get_caller_uid(GDBusMethodInvocation *context, gint *uid);
gchar *get_cmdline_of_pid(GPid pid);
gchar *g_strdup_vprintf(const gchar *format, va_list args);
gchar *g_strdup_printf(const gchar *format, ...);
void g_free(gpointer mem);
void g_object_unref(gpointer object);
PolkitSubject *polkit_system_bus_name_new(const gchar *name);
gchar *polkit_subject_to_string(PolkitSubject *subject);
const gchar *g_dbus_method_invocation_get_sender(GDBusMethodInvocation *context);