#include <stdint.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#define POLKIT_ERROR 0
#define POLKIT_ERROR_FAILED 0
#define POLKIT_IS_UNIX_PROCESS(x) 0
#define POLKIT_IS_SYSTEM_BUS_NAME(x) 0
#define POLKIT_IS_UNIX_SESSION(x) 0
#define POLKIT_UNIX_PROCESS(x) ((void*)0)
#define POLKIT_SYSTEM_BUS_NAME(x) ((void*)0)
#define POLKIT_UNIX_SESSION(x) ((void*)0)

typedef int gboolean;
typedef int gint;
typedef uint32_t guint32;
typedef char gchar;
typedef void PolkitIdentity;
typedef void PolkitSubject;
typedef void GError;
typedef void GKeyFile;

struct _PolkitBackendSessionMonitor {
    GKeyFile *database;
};
typedef struct _PolkitBackendSessionMonitor PolkitBackendSessionMonitor;

int polkit_unix_process_get_uid(void*);
int polkit_unix_process_get_racy_uid__(void*, GError**);
PolkitIdentity* polkit_unix_user_new(int);
PolkitIdentity* polkit_system_bus_name_get_user_sync(void*, void*, GError**);
char* polkit_unix_session_get_session_id(void*);
gboolean ensure_database(PolkitBackendSessionMonitor*, GError**);
int g_key_file_get_integer(GKeyFile*, const char*, const char*, GError**);
void g_set_error(GError**, int, int, const char*);
void g_propagate_error(GError**, GError*);
void g_propagate_prefixed_error(GError**, GError*, const char*);
void g_prefix_error(GError**, const char*);
char* g_strdup_printf(const char*, ...);
void g_free(void*);

#define CKDB_PATH "/var/run/ConsoleKit/database"